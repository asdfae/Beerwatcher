import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Drawer {
  id: drawer
  height: window.height * 0.20
  width: window.width
  edge: Qt.TopEdge
  dragMargin: 40

  Row {
    anchors.fill: parent

    ItemDelegate {
      text: qsTr("Settings")
      height: parent.height
      onClicked: {
        stackView.push("Settings.qml")
        drawer.close()
      }
    }
    ItemDelegate {
      text: qsTr("Page 2")
      height: parent.height
      onClicked: {
        drawer.close()
      }
    }
  }
}
