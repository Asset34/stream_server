#ifndef RTPSOUTBUILDER_HPP
#define RTPSOUTBUILDER_HPP

#include <QString>

class RtpSoutBuilder
{
public:
    RtpSoutBuilder();
    RtpSoutBuilder(const RtpSoutBuilder &other) = delete;
    RtpSoutBuilder &operator=(const RtpSoutBuilder &other) = delete;

    void setIp(const QString &ip);
    void setPort(const QString &port);
    void setSapName(const QString &name);

    void setSapStatus(bool status);

    QString getSout() const;

private:
    QString sout;

    /* Flags */
    bool m_sap;

    /* Values */
    QString m_ip;
    QString m_port;
    QString m_sapName;

};

#endif // RTPSOUTBUILDER_HPP
