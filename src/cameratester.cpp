#include "cameratester.h"

//#include <hybris/camera/camera_compatibility_layer_capabilities.h >  // for constants

void CameraTester::connectToCamera()
{
    emit logHappened("connecting");
//    memset(&listener, 0, sizeof(m_listener));  // not sure while it's needed, but test example does this nullification
//    m_cc = android_camera_connect_to(BACK_FACING_CAMERA_TYPE,
//                                     &listener);
    emit logHappened("connected");
}

void CameraTester::turnFlashToTorch()
{
    emit logHappened("trying torch");
//    android_camera_set_flash_mode(m_cc, FLASH_MODE_TORCH);
    emit logHappened("tried torch");
}

void CameraTester::turnFlashToOn()
{
    emit logHappened("trying on");
//    android_camera_set_flash_mode(m_cc, FLASH_MODE_ON);
    emit logHappened("tried on");
}

void CameraTester::startPreview()
{
    emit logHappened("starting preview");
//    android_camera_start_preview(m_cc);
    emit logHappened("started preview");
}

void CameraTester::stopPreview()
{
    emit logHappened("stopping preview");
//    android_camera_stop_preview(m_cc);
    emit logHappened("stopped preview");
}

void CameraTester::disconnectCamera()
{
    emit logHappened("disconnecting");
//    android_camera_disconnect(m_cc);
    emit logHappened("disconnected");
}

CameraTester::CameraTester(QObject *parent) :
    QObject(parent)
{
}
