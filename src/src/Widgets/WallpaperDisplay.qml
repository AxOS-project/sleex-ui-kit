import QtQuick
import QtMultimedia

Item {
    id: root

    property string source:   ""
    property int    fillMode: Image.PreserveAspectCrop
    property bool   playing:  true
    property size   targetSize: Qt.binding(() => Qt.size(Screen.width * Screen.devicePixelRatio, Screen.height * Screen.devicePixelRatio))

    readonly property string resolvedSource: source.startsWith("/") ? "file://" + source : source
    readonly property bool isReady: _isAnimated 
        ? animImg.status === AnimatedImage.Ready
        : _isVideo
            ? (videoLoader.item ? videoLoader.item.status === MediaPlayer.LoadedMedia : false)
            : staticImg.status === Image.Ready
    
    readonly property bool _isAnimated: {
        const s = source.toLowerCase()
        return s.endsWith(".gif") || s.endsWith(".webp") || s.endsWith(".apng")
    }

    readonly property bool _isVideo: {
        const s = source.toLowerCase()
        return s.endsWith(".mp4") || s.endsWith(".mkv") || s.endsWith(".webm")
    }

    onPlayingChanged: {
        if (_isVideo && videoLoader.item) {
            playing ? videoLoader.item.play() : videoLoader.item.pause()
        }
    }

    Image {
        id: staticImg
        anchors.fill: parent
        fillMode: root.fillMode
        source: root._isAnimated || root._isVideo ? "" : root.resolvedSource
        sourceSize: root.targetSize
        visible: !root._isAnimated && !root._isVideo
    }

    AnimatedImage {
        id: animImg
        anchors.fill: parent
        fillMode: root.fillMode
        source: root._isAnimated ? root.resolvedSource : ""
        sourceSize: root.targetSize
        visible: root._isAnimated
        playing: root._isAnimated && root.playing
    }

    Loader {
        id: videoLoader
        active: root._isVideo
        anchors.fill: parent
        visible: root._isVideo
        
        sourceComponent: Item {
            id: videoContainer
            property int status: mediaplayer.status
            function play() { mediaplayer.play() }
            function pause() { mediaplayer.pause() }

            MediaPlayer {
                id: mediaplayer
                source: root.resolvedSource
                loops: MediaPlayer.Infinite
                videoOutput: videoOutput
                
                onErrorOccurred: (error, errorString) => {
                    console.log("ERROR Multimedia:", error, errorString)
                }
                
                audioOutput: AudioOutput {
                    muted: true 
                }

                onSourceChanged: if (root.playing) play()
                Component.onCompleted: if (root.playing) play()
            }

            VideoOutput {
                id: videoOutput
                anchors.fill: parent
                fillMode: root.fillMode
            }
        }
    }
}
