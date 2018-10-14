#include "inputbox.hpp"

#include <QHBoxLayout>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QValidator>

InputBox::InputBox(const QString &name,
                   const QString &text,
                   QWidget *parent)
    : QWidget(parent)
{
    /* Name label */
    m_nameLabel = new QLabel(name + ":");

    /* Text edit */
    m_lineEdit = new QLineEdit(text);

    /* Configurate layout */
    m_layout = new QHBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_nameLabel);
    m_layout->addWidget(m_lineEdit);

    /* Configurate widget */
    setLayout(m_layout);
    setFixedHeight(25);

    /* Set connections */
    connect(m_lineEdit, &QLineEdit::textChanged, this, &InputBox::textChanged);
}

QString InputBox::getName() const
{
    return m_nameLabel->text();
}

void InputBox::setName(const QString &name)
{
    m_nameLabel->setText(name + ":");
}

QString InputBox::getText() const
{
    return m_lineEdit->text();
}

void InputBox::setText(const QString &text)
{
    m_lineEdit->setText(text);
}

const QValidator *InputBox::getValidator() const
{
    return m_lineEdit->validator();
}

void InputBox::setValidator(const QValidator *v)
{
    m_lineEdit->setValidator(v);
}
