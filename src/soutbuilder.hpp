#ifndef SOUTBUILDER_HPP
#define SOUTBUILDER_HPP

#include <QString>
#include <QMap>

#include <VLCQtCore/Enums.h>

class SoutBuilder
{
public:
    SoutBuilder();
    SoutBuilder(const SoutBuilder &other) = delete;
    SoutBuilder operator=(const SoutBuilder &other) = delete;

    void setSapEnabled(bool enabled);
    void setTranscodeEnabled(bool enabled);

    void setRtpIp(const QString &ip);
    void setRtpPort(int port);
    void setRtpName(const QString &name);
    void setTrcVideoCodec(Vlc::VideoCodec codec);
    void setTrcVideoBitrate(int bitrate);
    void setTrcVideoQuality(int height);
    void setTrcVideoAspectRatio(Vlc::Ratio ratio);
    void setTrcVideoFrameRate(int frameRate);
    void setTrcAudioCodec(Vlc::AudioCodec codec);
    void setTrcAudioBitrate(int bitrate);
    void setTrcAudioSampleRate(int sampleRate);

    QString buildSout();

private:
    int computeVideoWidth() const;

    /* Templates */
    QString m_generalTemplate;
    QString m_rtpTemplate;
    QString m_transcodeTemplate;

    /* Flags */
    bool m_sap = false;
    bool m_transcode = false;

    /* Values */
    QString m_rtpIp;
    int m_rtpPort;
    QString m_rtpName;
    Vlc::VideoCodec m_trcVCodec;
    int m_trcVBitrate;
    int m_trcVHeight;
    Vlc::Ratio m_trcVAspectRatio;
    int m_trcVFrameRate;
    Vlc::AudioCodec m_trcACodec;
    int m_trcABitrate;
    int m_trcASampleRate;

};

#endif // SOUTBUILDER_HPP
