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

    const SoutBuilder &getSoutBuilder();

    void openMedia(const QString &path);

    void playStream();
    void pauseStream();
    void resumeStream();

private:
    VlcInstance *m_instance;
    VlcMedia *m_media;
    VlcMediaPlayer *m_mediaPlayer;

    SoutBuilder m_soutBuilder;

};

#endif // VLCMANAGER_HPP
