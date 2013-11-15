import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: "Show Page 2"
                onClicked: pageStack.push(Qt.resolvedUrl("SecondPage.qml"))
            }
        }

        // Tell SilicaFlickable the height of its content.
        contentHeight: column.height

        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            id: column

            width: page.width
            spacing: Theme.paddingLarge
            PageHeader {
                title: "Test libhybris flash"
            }
            TextArea {
                id: logArea
                height: 200
                width: parent.width
            }
            Button {
                text: "Connect to Camera"
                onClicked: {
                    cameraTester.connectToCamera()
                }
            }
            Button {
                text: "Flash to Torch!"
                onClicked: {
                    cameraTester.turnFlashToTorch()
                }
            }
            Button {
                text: "Flash to On!"
                onClicked: {
                    cameraTester.turnFlashToOn()
                }
            }

            Button {
                text: "Start cam preview"
                onClicked: {
                    cameraTester.startPreview()
                }
            }
            Button {
                text: "Stop cam preview"
                onClicked: {
                    cameraTester.stopPreview()
                }
            }
            Button {
                text: "Disconnect cam"
                onClicked: {
                    cameraTester.disconnectCamera()
                }
            }

        }
    }

    Connections {
        target: cameraTester
        onLogHappened: log(msg)
    }

    Component.onCompleted: {
    }

    function log(msg) {
        console.log(msg)
        logArea.text = msg + "\n" + logArea.text
    }
}
