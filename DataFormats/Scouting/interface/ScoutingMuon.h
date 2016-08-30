#ifndef DataFormats_ScoutingMuon_h
#define DataFormats_ScoutingMuon_h

#include <vector>

// Class for holding muon information, for use in data scouting
// IMPORTANT: the content of this class should be changed only in backwards compatible ways!
class ScoutingMuon
{
    public:
        //constructor with values for all data fields
        ScoutingMuon(float pt, float eta, float phi, float m, float ecalIso, float hcalIso,
                     float trackIso, float chi2, float ndof, int charge, float dxy, float dz,
                     int nValidMuonHits, int nValidPixelHits, int nMatchedStations,
                     int nTrackerLayersWithMeasurement, int type, int nValidStripHits, float trk_qoverp, float trk_theta, 
		     float trk_lambda, float trk_pt, float trk_vx, float trk_vy, float trk_vz, 
		     float trk_phi, float trk_eta, float dxyError, float dzError):
            pt_(pt), eta_(eta), phi_(phi), m_(m),
            ecalIso_(ecalIso), hcalIso_(hcalIso), trackIso_(trackIso),
            chi2_(chi2), ndof_(ndof), charge_(charge), dxy_(dxy), dz_(dz),
	    nValidMuonHits_(nValidMuonHits), nValidPixelHits_(nValidPixelHits), 
            nMatchedStations_(nMatchedStations),
	    nTrackerLayersWithMeasurement_(nTrackerLayersWithMeasurement), type_(type), nValidStripHits_(nValidStripHits), trk_qoverp_(trk_qoverp), 
	    trk_theta_(trk_theta), trk_lambda_(trk_lambda), trk_pt_(trk_pt), 
	    trk_vx_(trk_vx), trk_vy_(trk_vy), trk_vz_(trk_vz),
	    trk_phi_(trk_phi), trk_eta_(trk_eta), dxyError_(dxyError), dzError_(dzError) {}
        //default constructor
        ScoutingMuon():pt_(0), eta_(0), phi_(0), m_(0), ecalIso_(0), hcalIso_(0), trackIso_(0),
                chi2_(0), ndof_(0), charge_(0), dxy_(0), dz_(0), nValidMuonHits_(0),
     	      nValidPixelHits_(0), nMatchedStations_(0), nTrackerLayersWithMeasurement_(0), type_(0), nValidStripHits_(0), trk_qoverp_(0), trk_theta_(0),
              trk_lambda_(0), trk_pt_(0), trk_vx_(0), trk_vy_(0), trk_vz_(0), 
	      trk_phi_(0), trk_eta_(0), dxyError_(0), dzError_(0) {}

        //accessor functions
        float pt() const { return pt_; }
        float eta() const { return eta_; }
        float phi() const { return phi_; }
        float m() const { return m_; }
        float ecalIso() const { return ecalIso_; }
        float hcalIso() const { return hcalIso_; }
        float trackIso() const { return trackIso_; }
        float chi2() const { return chi2_; }
        float ndof() const { return ndof_; }
        int charge() const { return charge_; }
        float dxy() const { return dxy_; }
        float dz() const { return dz_; }
        int nValidMuonHits() const { return nValidMuonHits_; }
        int nValidPixelHits() const { return nValidPixelHits_; }
        int nMatchedStations() const { return nMatchedStations_; }
        int nTrackerLayersWithMeasurement() const { return nTrackerLayersWithMeasurement_; }
        int type() const { return type_; }
        bool isGlobalMuon() const { return type_ & 1<<1; }
        bool isTrackerMuon() const { return type_ & 1<<2; }
	int nValidStripHits() const { return nValidStripHits_; }
	float trk_qoverp() const { return trk_qoverp_; }
	float trk_theta() const { return trk_theta_; }
	float trk_lambda() const { return trk_lambda_; }
	float trk_pt() const { return trk_pt_; }
	float trk_vx() const { return trk_vx_; }
	float trk_vy() const { return trk_vy_; }
	float trk_vz() const { return trk_vz_; }
	float trk_phi() const { return trk_phi_; }
	float trk_eta() const { return trk_eta_; }
        float dxyError() const { return dxyError_; }
        float dzError() const { return dzError_; }

    private:
        float pt_;
        float eta_;
        float phi_;
        float m_;
        float ecalIso_;
        float hcalIso_;
        float trackIso_;
        float chi2_;
        float ndof_;
        int charge_;
        float dxy_;
        float dz_;
        int nValidMuonHits_;
        int nValidPixelHits_;
        int nMatchedStations_;
        int nTrackerLayersWithMeasurement_;
        int type_;
	int nValidStripHits_;
	float trk_qoverp_;
	float trk_theta_;
	float trk_lambda_;
	float trk_pt_;
	float trk_vx_;
	float trk_vy_;
	float trk_vz_;
        float trk_phi_;
	float trk_eta_;
	float dxyError_;
	float dzError_;
};

typedef std::vector<ScoutingMuon> ScoutingMuonCollection;

#endif
