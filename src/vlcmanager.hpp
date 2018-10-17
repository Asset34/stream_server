#ifndef VLCMANAGER_HPP
#define VLCMANAGER_HPP

#include <QObject>

#include <soutbuilder.hpp>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class VlcManager : public QObject
{
    Q_OBJECT

public:
    explicit VlcManager(QObject *parent = nullptr);
    virtual ~VlcManager();

    void openMedia(const QString &path);

    SoutBuilder &getSoutBuilder();

    void playStream();
    void pauseStream();
    void resumeStream();
    void stopStream();

private:
    bool checkMediaFile(const QString &path) const;

    void clearMedia();
    void setMedia(const QString &path);
    void resetMedia(const QString &path);

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;

    SoutBuilder m_soutBuilder;

signals:
    void mediaStateChanged();
    void errorOccured(const QString &error);

};

#endif // VLCMANAGER_HPP
