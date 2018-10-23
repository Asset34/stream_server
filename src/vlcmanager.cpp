#include "vlcmanager.hpp"

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MetaManager.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Error.h>

VlcManager &VlcManager::getInstance()
{
    static VlcManager instance;

    return instance;
}

void VlcManager::setMedia(const QString &path)
{
    resetMedia(path);
    parseMedia();
}

void VlcManager::setStreamName(const QString &name)
{
    m_streamName = name;
}

const QString &VlcManager::getStreamName() const
{
    return m_streamName;
}

QString VlcManager::getMediaPath() const
{
    if (m_media) {
        return m_media->currentLocation();
    }
    else {
        return QString();
    }
}

QString VlcManager::getMediaTitle() const
{
    if (m_media) {
        VlcMetaManager metaManager(m_media);
        return metaManager.title();
    }
    else {
        return QString();
    }
}

QString VlcManager::getMediaDescription() const
{
    if (m_media) {
        VlcMetaManager metaManager(m_media);
        return metaManager.description();
    }
    else {
        return QString();
    }
}

QTime VlcManager::getMediaDuration() const
{
    return QTime(0, 0 ,0 ,0).addMSecs(m_media->duration());
}

SoutBuilder &VlcManager::getSoutBuilder()
{
    return m_soutBuilder;
}

void VlcManager::playStream()
{
    m_media->setOption(m_soutBuilder.buildSout());
    m_mediaPlayer->open(m_media);

    emit mediaStarted();
}

void VlcManager::pauseStream()
{
    m_mediaPlayer->pause();
}

void VlcManager::resumeStream()
{
    m_mediaPlayer->resume();
}

void VlcManager::stopStream()
{
    m_mediaPlayer->stop();

    emit mediaStopped();
}

VlcManager::VlcManager(QObject *parent)
    : QObject(parent),
      m_media(nullptr)
{
    QStringList args;
    args << "--no-osd"
         << "--drop-late-frames"
         << "--skip-frames"
         << "--no-keyboard-events"
         << "--no-mouse-events"
         << "--no-loop";

    // Create vlc objects
    m_instance = new VlcInstance(args);
    m_mediaPlayer = new VlcMediaPlayer(m_instance);

    // Create connections
    connect(m_mediaPlayer, &VlcMediaPlayer::error,
            [this](){
        emit errorOccured(VlcError::errmsg());
    });
    connect(m_mediaPlayer, &VlcMediaPlayer::timeChanged,
            [this](int ms){
        emit mediaTimeChanged(QTime(0, 0, 0, 0).addMSecs(ms));
    });
}

VlcManager::~VlcManager()
{
    delete m_mediaPlayer;
    delete m_media;
    delete m_instance;
}

void VlcManager::createMedia(const QString &path)
{
    m_media = new VlcMedia(path, true, m_instance);
    connect(m_media, &VlcMedia::stateChanged,
            [this](const Vlc::State &state){
        emit mediaStateChanged(Vlc::state(state));
    });

    connect(m_media, static_cast<void (VlcMedia::*)(bool)>(&VlcMedia::parsedChanged),
            [this](bool status){
        if (!status) {
          clearMedia();
        }

        emit mediaSetted(status);
    });
}

void VlcManager::clearMedia()
{
    m_media->deleteLater();
    m_media = nullptr;
}

void VlcManager::resetMedia(const QString &path)
{
    clearMedia();
    createMedia(path);
}

void VlcManager::parseMedia()
{
    m_media->parse();
}
