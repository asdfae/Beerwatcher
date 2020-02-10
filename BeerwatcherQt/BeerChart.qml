import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtCharts 2.3
import aEneroth.SerialPortManager 1.0
import aEneroth.DBConnection 1.0
import QtQuick.Controls.Material 2.12

ChartView {
  id: chartView
  theme: ChartView.ChartThemeDark
  antialiasing: true
  legend.visible: false
  backgroundColor: Material.background
  width: parent.width
  height: parent.height

  Connections {
    target: serialPortManager
    onTemp: {
      //check that data is either blurps or temp
      if (!isNaN(data)) {
        //console.log("Adding", data, " to temp series")
        tempSeries.add(data)
        dbConnection.addDataPoint(data.toFixed(2), DBconnection.TEMPERATURE)
      } else {
        console.log("Unable to parse int.")
      }
    }
    onVibrations: {
      //check that data is either blurps or temp
      if (!isNaN(data)) {
        //console.log("Adding", data, " to vibration series")
        vibrationSeries.add(data)
        dbConnection.addDataPoint(data.toFixed(2), DBconnection.VIBRATIONS)
      } else {
        console.log("Unable to parse int.")
      }
    }
  }

  ValueAxis {
    id: axisX
    min: tempSeries.currentCount - 100
    max: tempSeries.currentCount
    tickCount: 1
    labelFormat: "%.0f"
    visible: false
    labelsVisible: false
    gridVisible: false
  }

  ValueAxis {
    id: axisYTemp
    min: 10
    max: 30
    tickCount: 3
    visible: false
    labelFormat: "%.0f"
    labelsVisible: false
    gridVisible: false

  }

  ValueAxis {
    id: axisYVib
    min: -5
    max: 200
    tickCount: 12
    visible: false
    labelFormat: "%.0f"
  }

  LineSeries {
    id: tempSeries
    name: qsTr("Temp")
    axisX: axisX
    axisY: axisYTemp
    onClicked: {
      console.log("temp clicked")
    }
    property int currentCount: 0
    function add(temp) {
      append(currentCount, temp)
      currentCount++
      if (temp > axisYTemp.max) {
        axisYTemp.max = temp + 5
      }
      if (currentCount > 100) {
        remove(0)
      }
    }
  }

  LineSeries {
    id: vibrationSeries
    name: "Beats"
    axisX: axisX
    axisY: axisYVib
    onClicked: {
      console.log("vib clicked")
    }
    property int currentCount: 0
    function add(vib) {

      append(currentCount, vib)
      currentCount++
      if (vib > axisYVib.max) {
        axisYVib.max = vib + 20
      }
      if (currentCount > 100) {
        remove(0)
      }
      //check if higher then max?
    }
  }
}
