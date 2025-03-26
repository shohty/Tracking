/////////////////////////////////////////////////////////////////
////
//// Shower for Magnetic filed map
//// Authors:
//// Y.Zhang zhangyao@ihep.ac.cn
//// T.Y. Xing xingty@ihep.ac.cn
//// Z.K.Zhang zkzhang@ihep.ac.cn
///////////////////////////////////////////////////////////////////
#include "IShowerMagMap.hxx"

#include "AnalysisTree/MagTree.hxx"
#include "IGenfitFitter.hxx"
#include "IGenfitTrack.hxx"
#include "IGenfitTrackMemento.hxx"
#include "IGenfitField.hxx"

#include <HEPUnits.hxx>
#include <IGenfitUnit.hxx>
#include <IFieldManager.hxx>
#include <FieldManager.h>
#include <ConstField.h>

#include <TTree.h>

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace COMET;
using namespace std;

IShowerMagMap::IShowerMagMap(const char* name, const char* title)
:IReconCyDetAlgorithmBase(name, title)
{
  fDebug=GetParameterI("Debug");
}

IShowerMagMap::~IShowerMagMap() {;}

bool IShowerMagMap::ReconCyDetProcess(){
     ICOMETEvent& event = GetEvent();
     //cout<<__FILE__<<__LINE__<<endl;
     COMETNamedDebug(GetName(),"ReconCyDetProcess");
     //cout<<__FILE__<<__LINE__<<endl;
     std::string filePath = GetParameterS("OutputMapFile");
     double degree = GetParameterD("Degree");
     std::ofstream outFile(filePath);
     if (!outFile.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return false;
     }
     outFile<<"grid X0=4000.0 Y0=-1050.0 Z0=6600.0 nX=401 nY=211 nZ=211 dX=10.0 dY=10.0 dZ=10.0"<< std::endl;
     outFile<<"data"<<std::endl;
     double Bx = 0;
     double By = 0;
     double Bz = 0;
      // 定义旋转角度
     double angle = degree * M_PI / 180.0; // 度（-180，180）转换为弧度
     outFile << "angle = " << angle << std::endl;
     double cosAngle = std::cos(angle);
     double sinAngle = std::sin(angle);
 
     //loop
     for(double z = 6600; z <= 8700;z = z + 10){
        for(double y = -1050; y <= 1050; y = y + 10){
           for(double x = 8000; x >= 4000; x = x - 10){
      //for(double z = 6600; z <= 8700;z = z + 300){
      //  for(double y = -1000; y <= 1000; y = y + 1000){
      //     for(double x = 8000; x >= 4000; x = x  - 400){
             double global_xyz[3]={x,y,z};
             double B[6];
             //初始化B
             B[0] = 10;
             B[1] = 20;
             B[2] = 30;
             B[3] = B[4] = B[5] = 0;

            
            ////先变换到local坐标系
            // double local_xyz[3] = {-global_xyz[2]+7650, global_xyz[1], global_xyz[0]-6000};

            ////local坐标系下与z轴的夹角
            // double angle_z = std::atan2(local_xyz[0], local_xyz[2]);
            ////旋转后与z轴的夹角
            // double angle_rot = angle_z - angle;
            // double cosAngle_rot = std::cos(angle_rot);
            // double sinAngle_rot = std::sin(angle_rot);
            //// 将磁场绕y轴逆时针旋转，所以要取坐标顺时针旋转处的磁场值
            // double local_x_rot = std::sqrt(local_xyz[0]*local_xyz[0] + local_xyz[2]*local_xyz[2]) * sinAngle_rot;

            // double local_y_rot = local_xyz[1];

            // double local_z_rot = std::sqrt(local_xyz[0]*local_xyz[0] + local_xyz[2]*local_xyz[2]) * cosAngle_rot;
            //
            ////再变换到global坐标系
            // double global_xyz_rot[3] = {local_z_rot+6000, local_y_rot, -local_x_rot+7650};
         
            // COMET::IFieldManager::GetObject()->GetFieldValue(global_xyz_rot, B);
      
            ////对取到的磁场值同样要进行变换
            // double B_rot[3];
            // B_rot[0] = B[0] * cosAngle + B[2] * sinAngle;
            // B_rot[1] = B[1];
            // B_rot[2] = -B[0] * sinAngle + B[2] * cosAngle;
             
             
             COMET::IFieldManager::GetObject()->GetFieldValue(global_xyz, B);
             double B_rot[3];
             B_rot[0] = B[0] * cosAngle + B[1] * sinAngle;
             B_rot[1] = B[1];
             B_rot[2] = B[2];

            outFile << std::defaultfloat;
            outFile << std::fixed << std::setprecision(0) <<global_xyz[0] / unit::mm<<" "<< global_xyz[1] / unit::mm<<" "<< global_xyz[2] / unit::mm
                     << " " << std::scientific<< std::setprecision(3) << B_rot[0] / unit::tesla << " " << B_rot[1] / unit::tesla << " " << B_rot[2] / unit::tesla 
                     << std::defaultfloat<< std::endl;
               
       }
      }
     }
     outFile.close();
return true;
}//end of Process

void IShowerMagMap::Initialize(){
     COMETNamedDebug(GetName(),"Initialize");
     //cout<<__FILE__<<__LINE__<<endl; 
     //fMagTree=new MagTree(GetName(),GetTitle());
     //cout<<__FILE__<<__LINE__<<endl;
     //fTree=NewOutputTTree(GetName(),GetTitle(),
      //dynamic_cast<ICyDetAnalysisBaseTree*> (fMagTree));
     //cout<<__FILE__<<__LINE__<<endl;
     
return;
}

void IShowerMagMap::Finalize(ICOMETOutput* const file){
     COMETNamedDebug(GetName(),"Finalize");

     //WriteDeleteOutputTTree(fTree);

  return;
}



