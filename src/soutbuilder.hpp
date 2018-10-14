#ifndef SOUTBUILDER_HPP
#define SOUTBUILDER_HPP

#include <QString>

class SoutBuilder
{
public:
    SoutBuilder();

    void setIp(const QString &ip);
    void setPort(const QString &port);
    void setSapName(const QString &name);

    void setSapStatus(bool status);

    QString getSout() const;

private:
    /* Modules */
    QString rtp;

    /* Flags */
    bool m_sap;

    /* Values */
    QString m_ip;
    QString m_port;
    QString m_sapName;
};

//sout=#rtp{mux=ts, sap, dst=224.2.2.4, port=60000, name=channel_test, caching=15000}"

#endif // SOUTBUILDER_HPP
