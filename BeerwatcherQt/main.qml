import QtQuick 2.13
import QtQuick.Controls 2.13
import aEneroth.SerialPortManager 1.0

//import aEneroth.SerialPortReader 1.0
ApplicationWindow {
  id: window
  visible: true
  width: 640
  height: 480
  title: qsTr("Stack")

  //Keep for future use
  header: ToolBar {
    contentHeight: toolButton.implicitHeight
    visible: false

    ToolButton {
      id: toolButton
      text: stackView.depth > 1 ? "\u25C0" : "\u2630"
      font.pixelSize: Qt.application.font.pixelSize * 1.6
      onClicked: {
        if (stackView.depth > 1) {
          stackView.pop()
        } else {
          drawer.open()
        }
      }
    }

    Label {
      text: stackView.currentItem.title
      anchors.centerIn: parent
    }
  }

  Drawer {
    id: drawer
    width: window.width * 0.66
    height: window.height

    Column {
      anchors.fill: parent

      ItemDelegate {
        text: qsTr("Page 1")
        width: parent.width
        onClicked: {
          drawer.close()
        }
      }
      ItemDelegate {
        text: qsTr("Page 2")
        width: parent.width
        onClicked: {
          drawer.close()
        }
      }
    }
  }

  StackView {
    id: stackView
    anchors.fill: parent
    initialItem: Page {
      title: "Landing"
      padding: 10

      Column {
        anchors.fill: parent

        Row {
          spacing: 10
          ComboBox {
            id: serialPortComboBox
            model: serialPortManager.availablePorts()
            onCurrentTextChanged: {
              if (currentText != "") {
                vendorLabel.vendor = serialPortManager.getVendor(currentText)
                productLabel.product = serialPortManager.getProductIdentifier(
                      currentText)
                manufacturerLabel.manufacturer = serialPortManager.getManufacturer(
                      currentText)
                serialLabel.serial = serialPortManager.getSerialNumber(
                      currentText)
              }
            }
          }

          Button {
            text: qsTr("Refresh")
            highlighted: true
            onClicked: {
              serialPortComboBox.model = serialPortManager.availablePorts()
            }
          }

          Button {
            text: qsTr("Use")
            highlighted: true
            onClicked: {
              console.log("set to: ", serialPortComboBox.currentText)
              serialPortManager.setCurrentPort(serialPortComboBox.currentText)
            }
          }
        }
        Row {
          spacing: 10
          Label {
            id: vendorLabel
            text: "Vendor: " + vendor
            property string vendor
          }

          Label {
            id: productLabel
            text: "Product: " + product
            property string product
          }

          Label {
            id: manufacturerLabel
            text: "Manufacturer: " + manufacturer
            property string manufacturer
          }

          Label {
            id: serialLabel
            text: "Serial: " + serial
            property string serial
          }
        }

        Row {
          TextField {
            id: senderTextField
            placeholderText: qsTr("Message")
            Keys.onEnterPressed: send(event)
            Keys.onReturnPressed: send(event)
            function send(e) {
              if (text != "") {
                serialPortManager.send(text)
                text = ""
              }
            }
          }
        }

        Row {
          Button {
            text: qsTr("Read")
            onClicked: serialPortManager.read()
          }
        }
      }
    }
  }

  SerialPortManager {
    id: serialPortManager
  }

  //  SerialPortReader {
  //    Component.onCompleted: console.log("done")
  //  }
}
