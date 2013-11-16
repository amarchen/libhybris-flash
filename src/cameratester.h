#ifndef CAMERATESTER_H
#define CAMERATESTER_H

#include <QObject>
//!!! Uncomment < > version if you have system libhybris
//#include <hybris/camera/camera_compatibility_layer.h>
#include "hybris/camera/camera_compatibility_layer.h"

class CameraTester : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void connectToCamera();
    Q_INVOKABLE void turnFlashToTorch();
    Q_INVOKABLE void turnFlashToOn();
    Q_INVOKABLE void startPreview();
    Q_INVOKABLE void stopPreview();
    Q_INVOKABLE void disconnectCamera();
    explicit CameraTester(QObject *parent = 0);

signals:
    void logHappened(QString msg);

public slots:

private:
    CameraControlListener m_listener;
    CameraControl* m_cc;

};

#endif // CAMERATESTER_H
