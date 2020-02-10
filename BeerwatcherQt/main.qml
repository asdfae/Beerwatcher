import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.2
import QtQuick.VirtualKeyboard.Settings 2.2
import QtQuick.Layouts 1.12

import aEneroth.SerialPortManager 1.0
import aEneroth.DBConnection 1.0

ApplicationWindow {
  id: window
  visible: true
  width: 640
  height: 480
  title: qsTr("Stack")

  contentOrientation: Qt.InvertedPortraitOrientation



  MainDrawer {
    id: drawer
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

      DBconnection{
        id: dbConnection
        Component.onCompleted: dbConnection.connect()
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
