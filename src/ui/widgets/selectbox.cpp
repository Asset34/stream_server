#include "selectbox.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

SelectBox::SelectBox(const QString &name,
                     QWidget *parent)
    : QWidget(parent)
{
    // Name label
    m_nameLabel = new QLabel(name + ":");

    // Select box
    m_selectBox = new QComboBox;

    // Layout
    m_layout = new QHBoxLayout;
    m_layout->setMargin(0);
    m_layout->addWidget(m_nameLabel);
    m_layout->addWidget(m_selectBox);

    // Widget
    setLayout(m_layout);
    setFixedHeight(25);
}

SelectBox::~SelectBox()
{
}

QString SelectBox::getName() const
{
    return m_nameLabel->text();
}

void SelectBox::setName(const QString &name)
{
    m_nameLabel->setText(name + ":");
}

void SelectBox::addItem(const QString &text, const QVariant &userData)
{
    m_selectBox->addItem(text, userData);
}

int SelectBox::currentIndex() const
{
    return m_selectBox->currentIndex();
}

QString SelectBox::currentText() const
{
    return m_selectBox->currentText();
}

QVariant SelectBox::currentData() const
{
    return m_selectBox->currentData();
}
