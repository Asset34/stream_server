#include "timepositionwidget.hpp"

#include <QHBoxLayout>
#include <QLabel>

TimePositionWidget::TimePositionWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create time position label
    m_timePosLabel = new QLabel(QTime(0, 0, 0, 0).toString());
    m_timePosLabel->setAlignment(Qt::AlignCenter);

    // Create separator label
    m_separatorLabel = new QLabel("/");
    m_separatorLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Create time maximum label
    m_timeMaxLabel = new QLabel(QTime(0, 0, 0, 0).toString());
    m_timeMaxLabel->setAlignment(Qt::AlignCenter);

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_timePosLabel);
    m_layout->addWidget(m_separatorLabel);
    m_layout->addWidget(m_timeMaxLabel);

    // Create widget
    setLayout(m_layout);
}

TimePositionWidget::~TimePositionWidget()
{
}

void TimePositionWidget::setMaximum(const QTime &time)
{
    m_timeMaxLabel->setText(time.toString());
}

void TimePositionWidget::updateTime(QTime time)
{
    m_timePosLabel->setText(time.toString());
}
