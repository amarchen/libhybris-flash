# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = libhybris-flash

CONFIG += sailfishapp
#LIBS += -lcamera

# !!! Is needed for local headers only. If your platform has libhybris sources,
# you should comment this line out and use whichever's the proper real include
INCLUDEPATH += ext/libhybris/hybris/include

SOURCES += src/libhybris-flash.cpp \
    src/cameratester.cpp

OTHER_FILES += qml/libhybris-flash.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    qml/pages/SecondPage.qml \
    rpm/libhybris-flash.spec \
    rpm/libhybris-flash.yaml \
    libhybris-flash.desktop

HEADERS += \
    src/cameratester.h

