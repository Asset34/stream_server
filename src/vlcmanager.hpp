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

    void setMedia(const QString &path);

    SoutBuilder &getSoutBuilder();

    void playStream();
    void pauseStream();
    void resumeStream();
    void stopStream();

private:
    bool checkMediaFile(const QString &path) const;

    void createMedia(const QString &path);
    void clearMedia();
    void resetMedia(const QString &path);
    void parseMedia();

    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;

    SoutBuilder m_soutBuilder;

private slots:
    void handleParseResult(bool status);
    void handleStateChange(const Vlc::State &state);

signals:
    void mediaSetted(bool setted);
    void mediaStateChanged(QString state);
    void errorOccured(QString error);

};

#endif // VLCMANAGER_HPP
