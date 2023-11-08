import QtQuick 2.15

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
        ListView{
            anchors.fill: parent
            model: contactModel
            delegate: Item{
                anchors.left: parent.left
                anchors.right: parent.right
                height: childrenRect.height

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
                        text: qsTr("动物")
                        font.bold: true
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                ListView{
                    anchors.top: _header.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: childrenRect.height
                    model: contactModel
                    delegate: Item{
                        anchors.left: parent.left
                        anchors.right: parent.right
                        height: wsList.itemHeight
                        Rectangle{anchors.fill: parent;radius:4;color: "#f7d7c5"}
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
                            text: qsTr("动物")
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
            }
        }
    }

    GridView {
        anchors.left: wsList.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.margins: 7
         cellHeight: 192
         cellWidth: 256


         model: ['A','B']
         delegate: Item {
             id:_itemRoot
             height: 192
             width: 256
             property bool start: true
             property bool selected: true
             Rectangle{
                 anchors.fill: parent;
                 color: "#bebebe"
                 anchors.margins: 1
                 Text {
                     font.bold: true
                     font.pixelSize: 36
                     x:4
                     text: modelData
                     color: "white"
                 }
                 Image {
                     anchors.fill: parent
                     source: "qrc:/leftBar/leftBar7.png";
                 }
                 Item {
                     height: 32
                     anchors.bottom: parent.bottom
                     anchors.left: parent.left
                     anchors.right: parent.right
                     Rectangle{
                         visible:!_itemRoot.start
                         anchors.fill: parent;
                         color:"#707f7f7f"
                         Image {
                             x: 24
                             height: parent.height*0.75
                             width: height
                             anchors.verticalCenter: parent.verticalCenter
                             source: "qrc:/首页 icon-24_选中1-停止.png"
                         }
                         Text {
                             width: parent.width
                             height: parent.height
                             verticalAlignment: Text.AlignVCenter
                             horizontalAlignment: Text.AlignHCenter
                             text: qsTr("text")
                             color: "white"
                         }
                     }
                     Rectangle{
                         visible: _itemRoot.start
                         anchors.fill: parent;
                         color:"#f7d7c5"
                         Row{
                             width: childrenRect.width
                             height:parent.height*0.75
                             anchors.horizontalCenter: parent.horizontalCenter
                             anchors.verticalCenter: parent.verticalCenter
                             spacing: 21
                             Image {
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-停止.png"
                             }
                             Image {
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-暂停.png"
                             }
                             Image {
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-大小.png"
                             }
                             Image {
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-Z轴.png"
                             }
                             Image {
                                 height: parent.height
                                 width: height
                                 source: "qrc:/首页 icon-24_选中1-XY轴.png"
                             }
                         }

                         Text {
                             width: parent.width
                             height: parent.height*0.7
                             y:-height
                             font.pixelSize: 21
                             font.bold: true
                             verticalAlignment: Text.AlignVCenter
                             horizontalAlignment: Text.AlignHCenter
                             text: qsTr("01:45.30")
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
