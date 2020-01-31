import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page {

  Component.onCompleted: {
    //Try to find arduino and set it as current device.
    console.log(serialPortManager.availablePorts())
    let ports = serialPortManager.availablePorts()
    for (var port in ports) {
      // TODO: replace with saved id.
      if (serialPortManager.getManufacturer(ports[port]).includes("Arduino")) {
        console.log("Setting port to:", ports[port])
        serialPortManager.setCurrentPort(ports[port])
        break
      } else {

        //alert user that no arduino was found.
      }
    }
  }

  ColumnLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    height: parent.height

    Item {
      Layout.fillHeight: true
    }

    Label {
      text: "BeerWatcher"
      color: "#F3CA3E"
      font.pixelSize: 36
      Layout.alignment: Qt.AlignHCenter
    }

    Item {
      height: 15
    }

    Button {
      text: qsTr("Start")
      highlighted: true
      font.pixelSize: 14
      Layout.alignment: Qt.AlignHCenter
      implicitHeight: 48
      height: 48
      implicitWidth: 168
      onClicked: {
        console.log("Start clicked")
        stackView.push("Dashboard.qml")
      }
    }

    Item {
      Layout.fillHeight: true
    }
  }
}
