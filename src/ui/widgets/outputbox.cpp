#include "outputbox.hpp"

#include <QHBoxLayout>
#include <QString>
#include <QLabel>

OutputBox::OutputBox(const QString &name, const QString &output, QWidget *parent)
    : QWidget(parent)
{
    /* Name label */
    m_nameLabel = new QLabel(name + ":");

    /* Value label */
    m_outputLabel = new QLabel(output);

    /* Layout */
    m_layout = new QHBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_nameLabel);
    m_layout->addWidget(m_outputLabel);

    /* Configurate widget */
    setLayout(m_layout);
    setFixedHeight(25);
}

QString OutputBox::getName() const
{
    return m_nameLabel->text();
}

void OutputBox::setName(const QString &name)
{
    m_nameLabel->setText(name + ":");
}

void OutputBox::setText(const QString &text)
{
    m_outputLabel->setText(text);
}

void OutputBox::setValue(int value)
{
    m_outputLabel->setText(QString::number(value));
}

void OutputBox::setValue(double value)
{
    m_outputLabel->setText(QString::number(value));
}
