import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtCharts 2.3
import aEneroth.SerialPortManager 1.0

Page {
  Connections {
    target: serialPortManager
    onTemp: {
      //check that data is either blurps or temp
        if(!isNaN(data)){
            console.log("Adding", data, " to temp series")
            tempSeries.add(data)
        }else {
            console.log("Unable to parse int.")
        }
    }
    onVibrations: {
        //check that data is either blurps or temp
          if(!isNaN(data)){
              console.log("Adding", data, " to vibration series")
              vibrationSeries.add(data)
          }else {
              console.log("Unable to parse int.")
          }
    }
  }

  ColumnLayout {
    anchors.fill: parent

    ChartView {
      id: chartView
      width: parent.width
      height: parent.height
      theme: ChartView.ChartThemeBrownSand
      antialiasing: true

      ValueAxis {
        id: axisX
        min: tempSeries.currentCount - 10
        max: tempSeries.currentCount
        tickCount: 12
        labelFormat: "%.0f"
      }

      ValueAxis {
        id: axisYTemp
        min: 10
        max: 30
        tickCount: 12
        labelFormat: "%.0f"
      }

      ValueAxis {
        id: axisYVib
        min: -5
        max: 200
        tickCount: 12
        labelFormat: "%.0f"
      }


      SplineSeries {
        id: tempSeries
        name: qsTr("Temp")
        axisX: axisX
        axisY: axisYTemp
        property int currentCount: 0
        function add(temp) {
          append(currentCount, temp)
          currentCount++
            if(temp > axisYTemp.max){
                axisYTemp.max = temp + 5
            }
            if(currentCount > 10){
                remove(0);
            }
        }
      }

      SplineSeries {
        id: vibrationSeries
        name: "Beats"
        axisX: axisX
        axisY: axisYVib
        property int currentCount: 0
        function add(vib) {
          append(currentCount, vib)
          currentCount++
            if(vib > axisYVib.max){
                axisYVib.max = vib + 20
            }
            if(currentCount > 10){
                remove(0);
            }
            //check if higher then max?
        }
      }
    }
  }
}
