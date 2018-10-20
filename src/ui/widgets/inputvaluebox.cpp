#include "inputvaluebox.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>

InputValueBox::InputValueBox(const QString &name,
                        int value,
                        QWidget *parent)
    : QWidget(parent)
{
    // Name label
    m_nameLabel = new QLabel(name + ":");

    // Value spin box
    m_valueSpinBox = new QSpinBox;
    m_valueSpinBox->setValue(value);

    // Layout
    m_layout = new QHBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_nameLabel);
    m_layout->addWidget(m_valueSpinBox);

    // Widget
    setLayout(m_layout);

    // Connections
    connect(m_valueSpinBox,
            static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this,
            &InputValueBox::valueChanged);
}

QString InputValueBox::getName() const
{
    return m_nameLabel->text();
}

void InputValueBox::setName(const QString &name)
{
    m_nameLabel->setText(name + ":");
}

int InputValueBox::getMax() const
{
    return m_valueSpinBox->maximum();
}

void InputValueBox::setMax(int max)
{
    m_valueSpinBox->setMaximum(max);
}

int InputValueBox::getMin() const
{
    return m_valueSpinBox->minimum();
}

void InputValueBox::SetMin(int min)
{
    m_valueSpinBox->setMinimum(min);
}

void InputValueBox::setRange(int min, int max)
{
    m_valueSpinBox->setRange(min, max);
}

void InputValueBox::setValue(int value)
{
    m_valueSpinBox->setValue(value);
}
