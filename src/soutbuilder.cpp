#include "soutbuilder.hpp"

SoutBuilder::SoutBuilder()
    : m_sap(false)
{
    rtp = "rtp{"
        "mux=ts"  ","
        "%1"      ","
        "dst=%2"  ","
        "port=%3" ","
        "name=%4"
    "}";
}

void SoutBuilder::setIp(const QString &ip)
{
    m_ip = ip;
}

void SoutBuilder::setPort(const QString &port)
{
    m_port = port;
}

void SoutBuilder::setSapName(const QString &name)
{
    m_sapName = name;
}

void SoutBuilder::setSapStatus(bool status)
{
    m_sap = status;
}

QString SoutBuilder::getSout() const
{
    /* Hadle flags */
    QString sap;
    if (m_sap) {
        sap = "sap";
    }

    /* Fill rtp module with arguments */
    return "sout=#" + rtp.arg(sap, m_ip, m_port, m_sapName);
}
