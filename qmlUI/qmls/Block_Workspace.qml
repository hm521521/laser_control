import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import yel 1.0

Item {
    anchors.fill: parent
    Rectangle{anchors.fill: parent;color: "#ececec"}
    Item{
        id: wsList
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 7
        anchors.bottomMargin:7
        anchors.left: parent.left
        anchors.leftMargin: 7
        implicitWidth: 256
        clip: true

        property int itemHeight: 42

        ListModel {
            id: contactModel
            ListElement {
                name: "Bill Smith"
                number: "555 3264"
            }
            ListElement {
                name: "John Brown"
                number: "555 8426"
            }
            ListElement {
                name: "Sam Wise"
                number: "555 0473"
            }

        }
//        Timer{
//            interval: 1000
//            running: true
//            repeat: true
//            onTriggered: {
//                console.log(UC_Workspace)
//                console.log(UC_Workspace.workspace)
//            }
//        }

        ListView{
            anchors.fill: parent
            model: UC_Workspace.workspace.categories
            delegate: Item{
                id: _catItem
                anchors.left: parent.left
                anchors.right: parent.right
                height: childrenRect.height
                required property var modelData
                property bool open: true


                Item{
                    id: _header
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: wsList.itemHeight
                    Rectangle{anchors.fill: parent;radius:4;color: "white"}
                    Image {
                        id:_arrow
                        anchors.left: parent.left
                        anchors.leftMargin: 4
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.height*0.57
                        width: height
                        source: "qrc:/leftBar/leftBar13.png"
                        rotation: _catItem.open? 0:-90
                    }
                    Image {
                        id:_icon
                        anchors.left: _arrow.right
                        anchors.leftMargin: 4
                        anchors.verticalCenter: parent.verticalCenter
                        height: parent.height*0.85
                        width: height
                        source: "qrc:/leftBar/leftBar7.png"
                    }
                    Text {
                        anchors.left: _icon.right
                        anchors.right: parent.right
                        anchors.leftMargin: 7
                        height: wsList.itemHeight
                        text: modelData.name
                        font.bold: true
                        verticalAlignment: Text.AlignVCenter
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            _catItem.open=!_catItem.open
                        }
                    }
                }
                ListView{
                    id: _pagesList
                    visible: _catItem.open?true:false
                    anchors.top: _header.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: childrenRect.height
                    model: _catItem.modelData.pages

                    property int selectedPageIndex: -1

                    delegate: Item{
                        id:_pageItem
                        required property var modelData
                        required property int index
                        property bool selected: _pagesList.selectedPageIndex===index
                        anchors.left: parent.left
                        anchors.right: parent.right
                        height: wsList.itemHeight
                        Rectangle{anchors.fill: parent;radius:4;color: selected?"#f7d7c5":"white"}
                        Rectangle{visible:_piArea.containsMouse?true:false; anchors.fill: parent;radius:4;color: "#27000000";}
                        Image {
                            id:_sub_icon
                            anchors.left: parent.left
                            anchors.leftMargin: 70
                            anchors.verticalCenter: parent.verticalCenter
                            height: parent.height*0.7
                            width: height
                            source: "qrc:/leftBar/leftBar1.png"
                        }
                        Text {
                            anchors.left: _sub_icon.right
                            anchors.right: parent.right
                            anchors.leftMargin: 7
                            height: wsList.itemHeight
                            text: modelData.name
                            verticalAlignment: Text.AlignVCenter
                        }
                        MouseArea{
                            id: _piArea
                            anchors.fill: parent
                            onClicked: {
                                _pagesList.selectedPageIndex = index
                                UC_Workspace.setGridCuesByPage(modelData)
                            }
                            hoverEnabled: true

                        }
                    }
                }
            }
        }
    }


    GridLayout {
        id:_gridRoot
        anchors.left: wsList.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 7
        clip: true
         //cellHeight: 192
         //cellWidth: 256

        columns: 10

        property int selectedIndex : 0


         Repeater{

         model: UC_Workspace.gridCues
         delegate: Item {
             id:_itemRoot
             clip: true
             Layout.minimumHeight: 96
             Layout.minimumWidth: 96
             Layout.fillWidth: true
             Layout.fillHeight: true
             required property var modelData
             required property int index
             property bool isPlaying: false
             property bool isControlling: false
             property bool selected: _gridRoot.selectedIndex===index

             onSelectedChanged: {
                if(!selected && isControlling){
                    isControlling = false
                    isPlaying = false
                    modelData.stop()
                }
             }


             MouseArea{
                 id: gridArea
                anchors.fill: parent;
                hoverEnabled: true
                onEntered: {
                    if(!_itemRoot.isControlling){
                        _itemRoot.modelData.preview()
                    }
                }
                onExited: {
                    if(!_itemRoot.isControlling){
                        _itemRoot.modelData.stop()
                    }
                }
                onClicked: {
                    _gridRoot.selectedIndex = _itemRoot.index //_itemRoot.selected = true
                    _itemRoot.isControlling = !_itemRoot.isControlling
                    console.log("   :",_itemRoot.isControlling )
                    if(_itemRoot.isControlling) {
                        _itemRoot.isPlaying = true
                        _itemRoot.modelData.start()
                    }
                    else {
                        _itemRoot.isPlaying = false
                        _itemRoot.modelData.stop()
                        _itemRoot.modelData.preview()
                    }
                }
             }

             Rectangle{
                 anchors.fill: parent;
                 color: "#bebebe"
                 anchors.margins: 1
                 Text {
                     font.bold: true
                     font.pixelSize: 36
                     x:4
                     text: modelData.shortcut
                     color: "white"
                 }
                 ColorLineStrip {
                     visible: modelData.cue!==null
                     anchors.fill: parent
                     pointsData: if(modelData!==null)modelData.pointsData
                 }
                  clip: true
                 Item {
                     height: 32
                     anchors.bottom: parent.bottom
                     anchors.left: parent.left
                     anchors.right: parent.right
                     Rectangle{
                         visible:!_itemRoot.isControlling && width > 128
                         anchors.fill: parent;
                         color:"#707f7f7f"
                         Text {
                             width: parent.width
                             height: parent.height
                             verticalAlignment: Text.AlignVCenter
                             horizontalAlignment: Text.AlignHCenter
                             text: if(modelData.cue) modelData.cue.name
                             color: "white"
                         }
                     }
                     Rectangle{
                         visible: _itemRoot.isControlling
                         anchors.fill: parent;
                         color:"#f7d7c5"

                         Row{
                             width: childrenRect.width
                             height:parent.height*0.75
                             //anchors.horizontalCenter: parent.horizontalCenter
                             anchors.left: parent.left
                             anchors.leftMargin: 7
                             anchors.verticalCenter: parent.verticalCenter
                             spacing: 14
                             Image {
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-停止.png"
                             }
                             Image {
                                 height: parent.height
                                 width: height
                                 source: _itemRoot.isPlaying?"qrc:/首页 icon-24_选中1-暂停.png":"qrc:/首页 icon-24_选中1-开始.png"
                                 MouseArea{
                                    anchors.fill: parent;
                                    onClicked: {
                                        if(_itemRoot.isPlaying){
                                            _itemRoot.isPlaying=false
                                            _itemRoot.modelData.pause()
                                        }
                                        else{
                                            _itemRoot.isPlaying=true
                                            _itemRoot.modelData.play()
                                        }
                                    }
                                 }
                             }
                             Image {
                                 visible: _itemRoot.width>128
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-大小.png"
                                 MouseArea{
                                    anchors.fill: parent;
                                    cursorShape: Qt.SizeVerCursor
                                    property var lastY
                                    onPressed: {
                                        lastY = mouseY
                                    }
                                    onPositionChanged: {
                                        if(!pressed) return
                                        var d = (mouseY-lastY)/100;
                                        _itemRoot.modelData.cue.sizeX= d+_itemRoot.modelData.cue.sizeX
                                        _itemRoot.modelData.cue.sizeY= d+_itemRoot.modelData.cue.sizeY
                                        lastY=mouseY
                                    }
                                 }
                             }
                             Image {
                                 visible: _itemRoot.width>128
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-位置.png"
                                 MouseArea{
                                    anchors.fill: parent;
                                    cursorShape: Qt.SizeAllCursor
                                    property var lastX
                                    property var lastY
                                    onPressed: {
                                        lastX = mouseX
                                        lastY = mouseY
                                    }
                                    onPositionChanged: {
                                        if(!pressed) return
                                        var dx = (mouseX-lastX)/_itemRoot.width*255;
                                        var dy = (mouseY-lastY)/_itemRoot.height*255;
                                        _itemRoot.modelData.cue.positionX= dx+_itemRoot.modelData.cue.positionX
                                        _itemRoot.modelData.cue.positionY= dy+_itemRoot.modelData.cue.positionY
                                        lastX=mouseX
                                        lastY=mouseY
                                    }
                                 }
                             }
                             Image {
                                 visible: _itemRoot.width>128
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-Z轴.png"
                                 MouseArea{
                                    anchors.fill: parent;
                                    cursorShape: Qt.SizeVerCursor
                                    property var lastY
                                    onPressed: {
                                        lastY = mouseY
                                    }
                                    onPositionChanged: {
                                        if(!pressed) return
                                        var d = (mouseY-lastY)/2;
                                        _itemRoot.modelData.cue.rotation= d+_itemRoot.modelData.cue.rotation
                                        lastY=mouseY
                                    }
                                 }
                             }
                             Image {
                                 visible: _itemRoot.width>128
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-XY轴.png"
                             }
                         }

                         Text {
                             visible: _itemRoot.isControlling && modelData.cue!==null
                             width: parent.width
                             height: parent.height*0.7
                             y:-height
                             font.pixelSize: 21
                             font.bold: true
                             verticalAlignment: Text.AlignVCenter
                             horizontalAlignment: Text.AlignHCenter
                             text: _itemRoot.modelData.time.toFixed(1)
                             color: "white"
                         }
                     }
                 }
                 Rectangle{
                     anchors.fill: parent;
                     color: "transparent"
                     border.width: _itemRoot.selected?4:0
                     border.color: _itemRoot.selected?"#ed7717":"transparent"
                 }
             }
         }

         }
    }


}
