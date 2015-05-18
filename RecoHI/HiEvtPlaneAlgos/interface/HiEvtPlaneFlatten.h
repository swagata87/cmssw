#ifndef __HiEvtPlaneFlatten__
#define __HiEvtPlaneFlatten__
// -*- C++ -*-
//
// Package:    HiEvtPlaneFlatten
// Class:      HiEvtPlaneFlatten
// 

//
//
// Original Author:  Stephen Sanders
//         Created:  Mon Jun  7 14:40:12 EDT 2010
//
//

// system include files
#include <memory>
#include <iostream>
#include <string>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "DataFormats/HeavyIonEvent/interface/EvtPlane.h"

#include <vector>
#include <cmath>

//
// class declaration
//

class HiEvtPlaneFlatten {
public:

  explicit HiEvtPlaneFlatten()
  {
    hbins_ = 1;
    hOrder_ = 9;
    vorder_ = 2;    //sets default order of event plane
    minvtx_ = -25;
    delvtx_ = 5;
    nvtxbins_ = 10;
    soff_ = 0.;
    coff_ = 0.;
  }


  void init(int order, int nbins,   std::string tag, int vord)
  {
    hOrder_ = order;  //order of flattening
    vorder_ = vord;   //1(v1), 2(v2), 3(v3), 4(v4)	
    caloCentRefMinBin_ = -1;
    caloCentRefMaxBin_ = -1;
    hbins_ = nbins*nvtxbins_*hOrder_;
    obins_ = nbins*nvtxbins_;
    if(hbins_>MAXCUT) {
      hbins_ = 1;
      hOrder_ = 9;
    }
    for(int i = 0; i<hbins_; i++) {
      flatX_[i]=0;
      flatY_[i]=0;
      flatXDB_[i]=0;
      flatYDB_[i]=0;
      flatCnt_[i]=0;
    }
    for(int i = 0; i<obins_; i++) {
      xoff_[i]=0;
      yoff_[i]=0;
      xoffDB_[i]=0;
      yoffDB_[i]=0;
      xyoffcnt_[i]=0;
      xyoffmult_[i]=0;
      pt_[i]=0;
      pt2_[i]=0;
      ptDB_[i]=0;
      pt2DB_[i]=0;
      ptcnt_[i]=0;
    }
  }

  int getCutIndx(int centbin, double vtx, int iord) const
  {
    int cut;
    if(centbin < 0 ) return -1;
    int ibin = centbin;
    int ivtx = (vtx-minvtx_)/delvtx_;
    if(vtx < minvtx_ || ivtx >= nvtxbins_) return -1;
    cut = hOrder_*nvtxbins_*ibin + hOrder_*ivtx + iord;
    if(cut<0 || cut>=hbins_) return -1;
    return cut;
  }

  int getOffsetIndx(int centbin, double vtx) const
  {
    int cut;
    if(centbin < 0 ) return -1;
    //int ietbin = hfetbins*log10( 9.*(et/scale)+1.);
    //if(ietbin>hfetbins) ietbin=hfetbins-1;
    int ibin = centbin;
    int ivtx = (vtx-minvtx_)/delvtx_;
    if(ivtx < 0 || ivtx > nvtxbins_) return -1;
    cut = nvtxbins_*ibin + ivtx ;
    if(cut<0 || cut>hbins_) return -1;
    return cut;
  }

  void fill(double psi, double vtx, int centbin)
  {
    if(fabs(psi)>4 ) return;
    for(int k = 0; k<hOrder_; k++) {
      double fsin = sin(vorder_*(k+1)*psi);
      double fcos = cos(vorder_*(k+1)*psi);
      int indx = getCutIndx(centbin,vtx,k);
      if(indx>=0) {
	flatX_[indx]+=fcos;
	flatY_[indx]+=fsin;
	++flatCnt_[indx];
      }
    }
  }
  void fillOffset(double s, double c, uint m, double vtx, int centbin)
  {
    int indx = getOffsetIndx(centbin,vtx);
    if(indx>=0) {
      xoff_[indx]+=c;
      yoff_[indx]+=s;
      xyoffmult_[indx]+=m;
      ++xyoffcnt_[indx];
    }
  }
  void fillPt(double ptval, double vtx, int centbin)
  {
    int indx = getOffsetIndx(centbin,vtx);
    if(indx>=0) {
      pt_[indx]+=ptval;
      pt2_[indx]+=ptval*ptval;
      ++ptcnt_[indx];
    }
  }

  void setCaloCentRefBins(const int caloCentRefMinBin, const int caloCentRefMaxBin) {
    caloCentRefMinBin_ = caloCentRefMinBin;
    caloCentRefMaxBin_ = caloCentRefMaxBin;
    caloCentRefVal_ = 1.;
  }

  double getEtScale(double vtx, int centbin) const {
    if(caloCentRefMinBin_<0) return 1.;
    int indx = getOffsetIndx(centbin,vtx);
    int refmin = getOffsetIndx(caloCentRefMinBin_,vtx);
    int refmax = getOffsetIndx(caloCentRefMaxBin_,vtx);
    caloCentRefVal_ = 0;
    for(int i = refmin; i<=refmax; i++) {
      caloCentRefVal_+=getPtDB(i);
    }
    caloCentRefVal_/=refmax-refmin+1.;
    if(caloCentRefVal_==0 || getPtDB(indx)==0) return 1.;
    return caloCentRefVal_/getPtDB(indx);
   }

  double getW(double pt, double vtx, int centbin) const
  {
    int indx = getOffsetIndx(centbin,vtx);
    if(indx>=0) {
      double scale = getEtScale(vtx,centbin);
      double ptval = getPtDB(indx)*scale;
      double pt2val = getPt2DB(indx)*pow(scale,2);
      if(ptval>0) return pt*scale-pt2val/ptval;
    }
    return 0.;
  }

  double getFlatPsi(double psi, double vtx, int centbin) const
  {
    double correction = 0;
    for(int k = 0; k<hOrder_; k++) {
      int indx = getCutIndx(centbin,vtx,k);
      if(indx>=0) correction+=(2./(double)((k+1)*vorder_))*(flatXDB_[indx]*sin(vorder_*(k+1)*psi)-flatYDB_[indx]*cos(vorder_*(k+1)*psi));
    }
    psi+=correction;
    psi=bounds(psi);
    psi=bounds2(psi);
    return psi;
  }

  double OffsetPsi(double s, double c, double w, uint m,  double vtx, int centbin)
  {
    int indx = getOffsetIndx(centbin,vtx);
    double snew = s-yoffDB_[indx];
    double cnew = c-xoffDB_[indx];
    double psi = atan2(snew,cnew)/vorder_;
    if((fabs(snew)<1e-4) && (fabs(cnew)<1e-4)) psi = 0.;
    psi=bounds(psi);
    psi=bounds2(psi);
    soff_ = snew;
    coff_ = cnew;
    w_ = w;
    mult_ = m;

    return psi;
  }

  ~HiEvtPlaneFlatten(){}
  int getHBins() const {return hbins_;}
  int getOBins() const {return obins_;}
  int getNvtx() const {return nvtxbins_;}
  double getVtxMin() const {return minvtx_;}
  double getVtxMax() const {return minvtx_+nvtxbins_*delvtx_;}
  int getNcent() const {return hbins_;}

  double getX(int bin) const {return flatX_[bin];}
  double getY(int bin) const {return flatY_[bin];}
  double getXoff(int bin) const {return xoff_[bin];}
  double getYoff(int bin) const {return yoff_[bin];}
  double getXoffDB(int bin) const {return xoffDB_[bin];}
  double getYoffDB(int bin) const {return yoffDB_[bin];}
  double getXYoffcnt(int bin) const {return xyoffcnt_[bin];}
  double getXYoffmult(int bin) const {return xyoffmult_[bin];}
  double getPt(int bin) const {return pt_[bin];}
  double getPt2(int bin) const {return pt2_[bin];}
  double getPtDB(int bin) const {return ptDB_[bin];}
  double getPt2DB(int bin) const {return pt2DB_[bin];}
  double getPtcnt(int bin) const {return ptcnt_[bin];}
  double getXDB(int bin)  const {return flatXDB_[bin];}
  double getYDB(int bin)  const {return flatYDB_[bin];}


  double getCnt(int bin)  const {return flatCnt_[bin];}
  void setXDB(int indx, double val) {flatXDB_[indx]=val;}
  void setYDB(int indx, double val) {flatYDB_[indx]=val;}
  void setXoffDB(int indx, double val) {xoffDB_[indx]=val;}
  void setYoffDB(int indx, double val) {yoffDB_[indx]=val;}
  void setPtDB(int indx, double val) {ptDB_[indx]=val;}
  void setPt2DB(int indx, double val) {pt2DB_[indx]=val;}
  double sumSin() const { return soff_; }
  double sumCos() const { return coff_; }
  double sumw()  const { return w_; }
  uint mult()  const {return mult_;}
  double      qx()      const { return (w_>0)? coff_/w_:0.;};
  double      qy()      const { return (w_>0)? soff_/w_:0.;};
  double      q()      const { return ((pow(qx(),2)+pow(qy(),2))>0)? sqrt(pow(qx(),2)+pow(qy(),2)): 0.;};
  double bounds(double ang) const {
    if(ang<-M_PI) ang+=2.*M_PI;
    if(ang>M_PI)  ang-=2.*M_PI;
    return ang;
  }
  double bounds2(double ang) const {
    double range = pi/(double) vorder_;
    while(ang<-range) { ang+=2*range; }
    while(ang>range)  {ang-=2*range; }
    return ang;
  }
  void setCentRes1(int bin, double res, double err){ if(bin<100 && bin>=0) {centRes1_[bin]=res; centResErr1_[bin]=err;}}
  void setCentRes2(int bin, double res, double err){ if(bin<50 && bin>=0) {centRes2_[bin]=res; centResErr2_[bin]=err;}}
  void setCentRes5(int bin, double res, double err){ if(bin<20 && bin>=0) {centRes5_[bin]=res; centResErr5_[bin]=err;}}
  void setCentRes10(int bin, double res, double err){ if(bin<10 && bin>=0) {centRes10_[bin]=res; centResErr10_[bin]=err;}}
  void setCentRes20(int bin, double res, double err){ if(bin<5 && bin>=0) {centRes20_[bin]=res; centResErr20_[bin]=err;}}
  void setCentRes25(int bin, double res, double err){ if(bin<4 && bin>=0) {centRes25_[bin]=res; centResErr25_[bin]=err;}}
  void setCentRes30(int bin, double res, double err){ if(bin<3 && bin>=0) {centRes30_[bin]=res; centResErr30[bin]=err;}}
  void setCentRes40(int bin, double res, double err){ if(bin<2 && bin>=0) {centRes40_[bin]=res; centResErr40_[bin]=err;}}

  double getCentRes1(int bin) const { if(bin<100 && bin>=0) {return centRes1_[bin];} else {return 0.;}}
  double getCentRes2(int bin) const { if(bin<50 && bin>=0)  {return centRes2_[bin];} else {return 0.;}}
  double getCentRes5(int bin) const { if(bin<20 && bin>=0)  {return centRes5_[bin];} else {return 0.;}}
  double getCentRes10(int bin) const { if(bin<10 && bin>=0) {return centRes10_[bin];} else {return 0.;}}
  double getCentRes20(int bin) const { if(bin<5 && bin>=0)  {return centRes20_[bin];} else {return 0.;}}
  double getCentRes25(int bin) const { if(bin<4 && bin>=0)  {return centRes25_[bin];} else {return 0.;}}
  double getCentRes30(int bin) const { if(bin<3 && bin>=0)  {return centRes30_[bin];} else {return 0.;}}
  double getCentRes40(int bin) const { if(bin<2 && bin>=0)  {return centRes40_[bin];} else {return 0.;}}

  double getCentResErr1(int bin) const { if(bin<100 && bin>=0) {return centResErr1_[bin];} else {return 0.;}}
  double getCentResErr2(int bin) const { if(bin<50 && bin>=0)  {return centResErr2_[bin];} else {return 0.;}}
  double getCentResErr5(int bin) const { if(bin<20 && bin>=0)  {return centResErr5_[bin];} else {return 0.;}}
  double getCentResErr10(int bin) const { if(bin<10 && bin>=0) {return centResErr10_[bin];} else {return 0.;}}
  double getCentResErr20(int bin) const { if(bin<5 && bin>=0)  {return centResErr20_[bin];} else {return 0.;}}
  double getCentResErr25(int bin) const { if(bin<4 && bin>=0)  {return centResErr25_[bin];} else {return 0.;}}
  double getCentResErr30(int bin) const { if(bin<3 && bin>=0)  {return centResErr30[bin];} else {return 0.;}}
  double getCentResErr40(int bin) const { if(bin<2 && bin>=0)  {return centResErr40_[bin];} else {return 0.;}}

private:
  static const MAXCUT = 10000;
  static const MAXCUTOFF = 1000;
  double flatX_[MAXCUT];
  double flatY_[MAXCUT];
  double flatXDB_[MAXCUT];
  double flatYDB_[MAXCUT];
  double flatCnt_[MAXCUT];



  double xoff_[MAXCUTOFF];
  double yoff_[MAXCUTOFF];
  double xoffDB_[MAXCUTOFF];
  double yoffDB_[MAXCUTOFF];
  double xyoffcnt_[MAXCUTOFF];
  uint xyoffmult_[MAXCUTOFF];

  double pt_[MAXCUTOFF];
  double pt2_[MAXCUTOFF];
  double ptDB_[MAXCUTOFF];
  double pt2DB_[MAXCUTOFF];
  double ptcnt_[MAXCUTOFF];

  double centRes1_[100];
  double centResErr1_[100];

  double centRes2_[50];
  double centResErr2_[50];

  double centRes5_[20];
  double centResErr5_[20];

  double centRes10_[10];
  double centResErr10_[10];

  double centRes20_[5];
  double centResErr20_[5];

  double centRes25_[4];
  double centResErr25_[4];

  double centRes30_[3];
  double centResErr30_[3];

  double centRes40_[2];
  double centResErr40_[2];


  int hOrder_;    //flattening order
  int hbins_; //number of bins needed for flattening
  int obins_; //number of (x,y) offset bins
  int vorder_; //order of flattened event plane
  int caloCentRefMinBin_; //min ref centrality bin for calo weight scale
  int caloCentRefMaxBin_; //max ref centrality bin for calo weight scale
  double caloCentRefVal_; //reference <pt> or <et>

  int nvtxbins_;
  double minvtx_;
  double delvtx_;
  double soff_ ;
  double coff_ ;
  double w_ ;
  uint mult_ ;

};



#endif
