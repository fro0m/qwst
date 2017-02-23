import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import quest.model 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    DataModel {
        id: dataModel

    }
    property var titleGenerator: dataModel.titleGenerator


    title: titleGenerator.title

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
            onClicked: {
                dataModel.stateMachine.submitEvent("Transition_3")
            }
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }
}
