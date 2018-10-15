#include "rtpsoutbuilder.hpp"

RtpSoutBuilder::RtpSoutBuilder()
    : m_sap(false)
{
    sout = "rtp{"
        "mux=ts"  ","
        "%1"      ","
        "dst=%2"  ","
        "port=%3" ","
        "name=%4"
    "}";
}

void RtpSoutBuilder::setIp(const QString &ip)
{
    m_ip = ip;
}

void RtpSoutBuilder::setPort(const QString &port)
{
    m_port = port;
}

void RtpSoutBuilder::setSapName(const QString &name)
{
    m_sapName = name;
}

void RtpSoutBuilder::setSapStatus(bool status)
{
    m_sap = status;
}

QString RtpSoutBuilder::getSout() const
{
    /* Hadle flags */
    QString sap;
    if (m_sap) {
        sap = "sap";
    }

    return sout.arg(sap, m_ip, m_port, m_sapName);
}
