#include "vlcmanager.hpp"

#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
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

const SoutBuilder &VlcManager::getSoutBuilder()
{
    return m_soutBuilder;
}

void VlcManager::openMedia(const QString &path)
{
    // Check path
    if (!checkMediaFile(path)) {
        emit errorOccured("Invalid file");
        return;
    }

    resetMedia(path);
}

void VlcManager::playStream()
{
    QString option = m_soutBuilder.getSout();
    m_media->setOption(option);

    m_mediaPlayer->play();
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

void VlcManager::clearMedia()
{
    delete m_media;
    m_media = nullptr;
}

void VlcManager::setMedia(const QString &path)
{
    m_media = new VlcMedia(path, true, m_instance);
}

void VlcManager::resetMedia(const QString &path)
{
    clearMedia();
    setMedia(path);
}
