#include "cameratester.h"

//!!! Uncomment < > version if you have system libhybris
//#include <hybris/camera/camera_compatibility_layer_capabilities.h>  // for constants
#include "hybris/camera/camera_compatibility_layer_capabilities.h"  // for constants

//// inspired by https://github.com/libhybris/libhybris/blob/master/compat/camera/direct_camera_test.cpp

void CameraTester::connectToCamera()
{
    emit logHappened("connecting");
    memset(&m_listener, 0, sizeof(m_listener));  // not sure while it's needed, but test example does this nullification
    m_cc = android_camera_connect_to(BACK_FACING_CAMERA_TYPE,
                                     &m_listener);
    if (m_cc == NULL) {
        emit logHappened("Problem connecting to camera");
    } else {
        emit logHappened("connected");
    }
    m_listener.context = m_cc;
}

void CameraTester::turnFlashToTorch()
{
    emit logHappened("trying torch");
    android_camera_set_flash_mode(m_cc, FLASH_MODE_TORCH);
    emit logHappened("tried torch");
}

void CameraTester::turnFlashToOn()
{
    emit logHappened("trying on");
    android_camera_set_flash_mode(m_cc, FLASH_MODE_ON);
    emit logHappened("tried on");
}

void CameraTester::startPreview()
{
    emit logHappened("starting preview");
    android_camera_start_preview(m_cc);
    emit logHappened("started preview");
}

void CameraTester::stopPreview()
{
    emit logHappened("stopping preview");
    android_camera_stop_preview(m_cc);
    emit logHappened("stopped preview");
}

void CameraTester::disconnectCamera()
{
    emit logHappened("disconnecting");
    android_camera_disconnect(m_cc);
    emit logHappened("disconnected");
}

CameraTester::CameraTester(QObject *parent) :
    QObject(parent)
{
}
