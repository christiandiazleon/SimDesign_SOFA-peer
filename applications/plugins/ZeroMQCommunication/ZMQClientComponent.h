#include <sofa/core/behavior/BaseController.h>
#include <zmq.hpp>
#include <sys/time.h>
#include "PointNet.h"

// #include <sofa/core/objectmodel/Data.h>
// using sofa::core::objectmodel::Data;

#include <sofa/defaulttype/VecTypes.h>
// #include "SofaTypeMessages.h"

// To Quat datatype
#include <sofa/defaulttype/Quat.h>
using sofa::defaulttype::Quat;

using std::string;

namespace sofa
{

namespace component
{

namespace controller
{

struct instrumentData
{
  typedef sofa::defaulttype::Vec3d Vec3d;
  Vec3d pos;
  Quat quat;
  int btnState;
  float openInst;
  bool blnDataReady;
};

struct attachingData
{
  std::vector<PointNet> vPointsAttach;
  std::vector<int> vIdTriangles;
  std::vector<int> vIdInstTriangles;
  string strMechanicalModel;
  string strSurfaceModel;
  int nContactPoints;
  bool blnAttachContact;
  bool blnDeAtacchContact;
  float fDist;
};

class ZMQClientComponent : public sofa::core::behavior::BaseController
{
  public:
    SOFA_CLASS(ZMQClientComponent, sofa::core::behavior::BaseController);
    // Data<double> myparam;
    // Data<std::string> d_address;
    // typedef sofa::defaulttype::Vec3d Vec3d;
    //typedef defaulttype::Quat Quat;
    

    ZMQClientComponent();
    virtual ~ZMQClientComponent();
    
    /* Conect to ZMQ external Server  */
    void setupConnection();
    // void setupConnectionAttachingData();

    /* Send some data to ZMQ external Server  */
    void instrumentDataSend(instrumentData a);
    void attachingDataToSend(attachingData b);


    /* Get some response from ZMQ external Server */
    //void getResponseFromServer();

    /* Initialize ZMQ Internal Server and receive some data */
    // void receiveRequests();
    // void sendReplyToClient();
    void init();

    virtual void draw();
    virtual void draw(const core::visual::VisualParams *) override;

  private:
    struct timeval t_before, t_after;
    string replyMessage;
};


}

}

}