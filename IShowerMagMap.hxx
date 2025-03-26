/////////////////////////////////////////////////////////////////
////
//// This class provide magntic filed map for fittting
//// Authors:
//// Yao Zhang <zhangyao@ihep.ac.cn>
//// Tianyu Xing <xingty@ihep.ac.cn>
//// Zhaoke Zhang <zkzhang@ihep.ac.cn>   
////
///////////////////////////////////////////////////////////////////


#ifndef ReconCyDet_IShowerMagMap_hxx_seen
#define ReconCyDet_IShowerMagMap_hxx_seen

#include "IReconCyDetAlgorithmBase.hxx"

class TTree;

namespace COMET {

class IGenfitFitter;
class IGenfitTrack;
//class MagTree;

class IShowerMagMap : public COMET::IReconCyDetAlgorithmBase{
  public:
    IShowerMagMap(const char*name="IShowerMagMap", const char* title="IShowerMagMap");
    virtual ~IShowerMagMap();

    bool ReconCyDetProcess();
    
    void Initialize();

    void Finalize(ICOMETOutput * const file);
private:
   //Output fitting result
    //TTree* fTree=nullptr;
    //MagTree* fMagTree=nullptr;
    };
}
#endif
    




