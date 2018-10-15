#ifndef VLCMANAGER_HPP
#define VLCMANAGER_HPP

#include <QObject>

#include <rtpsoutbuilder.hpp>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class VlcManager : public QObject
{
    Q_OBJECT

public:
    explicit VlcManager(QObject *parent = nullptr);
    virtual ~VlcManager();

    RtpSoutBuilder &getRtpSoutBuilder();

    void openMedia(const QString &path);

    void playStream();
    void pauseStream();
    void resumeStream();
    void stopStream();

private:
    QString buildResultSout();

    bool checkMediaFile(const QString &path) const;

    void clearMedia();
    void setMedia(const QString &path);
    void resetMedia(const QString &path);

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;

    RtpSoutBuilder m_rtpSoutBuilder;

signals:
    void mediaStateChanged();
    void errorOccured(const QString &error);

};

#endif // VLCMANAGER_HPP
