#include "soutbuilder.hpp"

SoutBuilder::SoutBuilder()
{
    /* Create templates */
    m_generalTemplate = "sout=#%1%2%3";
    m_rtpTemplate = "rtp{"
        "mux=ts"  ","
        "%1"      ","
        "dst=%2"  ","
        "port=%3" ","
        "name=%4"
    "}";
    m_transcodeTemplate = "transcode{"
        "vcodec=%1"   ","
        "vb=%2"       ","
        "height=%3"   ","
        "width=%4"    ","
        "fps=%5"      ","
        "acodec=%6"   ","
        "ab=%7"       ","
        "samplerate=%8"
    "}";
}

void SoutBuilder::setSapEnabled(bool enabled)
{
    m_sap = enabled;
}

void SoutBuilder::setTranscodeEnabled(bool enabled)
{
    m_transcode = enabled;
}

void SoutBuilder::setRtpIp(const QString &ip)
{
    m_rtpIp = ip;
}

void SoutBuilder::setRtpPort(int port)
{
    m_rtpPort = port;
}

void SoutBuilder::setRtpName(const QString &name)
{
    m_rtpName = name;
}

void SoutBuilder::setTrcVideoCodec(Vlc::VideoCodec codec)
{
    m_trcVCodec = codec;
}

void SoutBuilder::setTrcVideoBitrate(int bitrate)
{
    m_trcVBitrate = bitrate;
}

void SoutBuilder::setTrcVideoHeight(int height)
{
    m_trcVHeight = height;
}

void SoutBuilder::setTrcVideoAspectRatio(Vlc::Ratio ratio)
{
    m_trcVAspectRatio = ratio;
}

void SoutBuilder::setTrcVideoFrameRate(int frameRate)
{
    m_trcVFrameRate = frameRate;
}

void SoutBuilder::setTrcAudioCodec(Vlc::AudioCodec codec)
{
    m_trcACodec = codec;
}

void SoutBuilder::setTrcAudioBitrate(int bitrate)
{
    m_trcABitrate = bitrate;
}

void SoutBuilder::setTrcAudioSampleRate(int sampleRate)
{
    m_trcASampleRate = sampleRate;
}

QString SoutBuilder::buildSout()
{
    /* Build rtp sout */
    QString rtpSout = m_rtpTemplate
    .arg(m_sap ? "sap" : "")
    .arg(m_rtpIp)
    .arg(m_rtpPort)
    .arg(m_rtpName);

    /* Build transcode sout */
    QString trcSout;
    if (m_transcode) {
        trcSout = m_transcodeTemplate
        .arg(Vlc::videoCodec(m_trcVCodec))
        .arg(m_trcVBitrate)
        .arg(m_trcVHeight)
        .arg(computeVideoWidth())
        .arg(m_trcVFrameRate)
        .arg(m_trcACodec)
        .arg(m_trcABitrate)
        .arg(m_trcASampleRate);
    }

    /* Build full sout */
    QString sout = m_generalTemplate
    .arg(trcSout)
    .arg(m_transcode ? ":" : "")
    .arg(rtpSout);

    return sout;
}

int SoutBuilder::computeVideoWidth() const
{
    QSizeF aspectRatio = Vlc::ratioSize(m_trcVAspectRatio);
    double factor = aspectRatio.width() / aspectRatio.height();

    return m_trcVHeight * factor;
}
//m_transcodeTemplate = "transcode{"
//    "vcodec=%1"   ","
//    "vb=%2"       ","
//    "width=%3"    ","
//    "height=%4"   ","
//    "fps=%5"      ","
//    "acodec=%6"   ","
//    "ab=%7"       ","
//    "channels=%8" ","
//    "samplerate=%9"
//"}";
