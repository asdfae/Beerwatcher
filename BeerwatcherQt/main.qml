import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.2
import QtQuick.VirtualKeyboard.Settings 2.2
import QtQuick.Layouts 1.12

import aEneroth.SerialPortManager 1.0
import aEneroth.DBConnection 1.0
import aEneroth.SystemActions 1.0

ApplicationWindow {
  id: window
  visible: true
  width: 640
  height: 480
  title: qsTr("Stack")

  MainDrawer {
    id: drawer
  }

  MouseArea {
    id: screenMouseArea
    anchors.fill: parent
    z: 10

    propagateComposedEvents: true
    onClicked: {
      mouse.accepted = false

    }
    onPressed:{
      mouse.accepted = false
      console.log("screen pressed")
      systemActions.setBrightness(120)
      systemActions.setScreenState(SystemActions.ON)

      screensaverTimer.restart()
      screenOffTimer.stop()
    }
    onReleased: mouse.accepted = false
    onDoubleClicked: mouse.accepted = false
    onPositionChanged: mouse.accepted = false
    onPressAndHold: mouse.accepted = false

    Timer {
      id: screensaverTimer
      interval: 12000
      running: true
      onTriggered: {
        systemActions.setBrightness(30)
        screenOffTimer.start()
      }
    }

    Timer {
      id: screenOffTimer
      interval: 30000
      running: false
      onTriggered: {
        systemActions.setScreenState(SystemActions.OFF)
      }
    }
  }

  Shortcut {
    sequence: "ESC"
    context: Qt.ApplicationShortcut
    onActivated: stackView.pop()
  }

  Item {
    id: root
    width: window.width
    height: window.height
    rotation: 180

    Item {
      id: appContainer
      anchors.left: parent.left
      anchors.top: parent.top
      anchors.right: parent.right
      anchors.bottom: inputPanel.top

      StackView {
        id: stackView
        anchors.fill: parent
        anchors.centerIn: parent
        initialItem: Landing {}
      }

      SerialPortManager {
        id: serialPortManager
      }

      DBconnection {
        id: dbConnection
      }

      SystemActions {
        id: systemActions
      }
    }

    InputPanel {
      id: inputPanel
      y: Qt.inputMethod.visible ? parent.height - inputPanel.height : parent.height
      anchors.left: parent.left
      anchors.right: parent.right
    }
  }
}
