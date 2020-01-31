import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page {
  title: "Landing"
  padding: 10

  ColumnLayout {
    anchors.fill: parent

    Button {
        text: qsTr("Back")
        onClicked: stackView.pop()
    }

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
            serialLabel.serial = serialPortManager.getSerialNumber(currentText)
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

    Item {
      Layout.fillHeight: true
    }

    TextField {
      id: testField
      placeholderText: "woop"
    }
  }
}
