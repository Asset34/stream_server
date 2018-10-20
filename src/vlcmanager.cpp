#include "vlcmanager.hpp"

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MetaManager.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Error.h>

#include <QDebug>
#include <QFileInfo>

VlcManager::VlcManager(QObject *parent)
    : QObject(parent),
      m_instance(nullptr),
      m_media(nullptr),
      m_mediaPlayer(nullptr)
{
    QStringList args;
    args << "--no-osd"
         << "--drop-late-frames"
         << "--skip-frames"
         << "--no-keyboard-events"
         << "--no-mouse-events"
         << "--no-loop";

    m_instance = new VlcInstance(args);
    m_mediaPlayer = new VlcMediaPlayer(m_instance);
}

VlcManager::~VlcManager()
{
    delete m_mediaPlayer;
    delete m_media;
    delete m_instance;
}

void VlcManager::setMedia(const QString &path)
{
    // Check path
    if (!checkMediaFile(path)) {
        emit errorOccured("Invalid file");
        return;
    }

    resetMedia(path);
    parseMedia();
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
}

bool VlcManager::checkMediaFile(const QString &path) const
{
    return QFileInfo::exists(path) &&
           QFileInfo(path).isFile();
}

void VlcManager::createMedia(const QString &path)
{
    m_media = new VlcMedia(path, true, m_instance);
    connect(m_media, &VlcMedia::stateChanged, this, &VlcManager::handleStateChange);
    connect(
        m_media,
        static_cast<void (VlcMedia::*)(bool)>(&VlcMedia::parsedChanged),
        this,
        &VlcManager::handleParseResult
    );
}

void VlcManager::clearMedia()
{
    delete m_media;
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

void VlcManager::handleParseResult(bool status)
{
    if (!status) {
        clearMedia();
    }

    emit mediaSetted(status);
}

void VlcManager::handleStateChange(const Vlc::State &state)
{
    emit mediaStateChanged(Vlc::state(state));
}
