#include "timepositionwidget.hpp"

#include <QHBoxLayout>
#include <QLabel>

TimePositionWidget::TimePositionWidget(const QTime &timeLimit, QWidget *parent)
    : QWidget(parent)
{
    // Create time position label
    m_timePosLabel = new QLabel(QTime(0, 0, 0, 0).toString());
    m_timePosLabel->setAlignment(Qt::AlignCenter);

    // Create separator label
    m_separatorLabel = new QLabel("/");
    m_separatorLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // Create time maximum label
    m_timeLimitLabel = new QLabel(timeLimit.toString());
    m_timeLimitLabel->setAlignment(Qt::AlignCenter);

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_timePosLabel);
    m_layout->addWidget(m_separatorLabel);
    m_layout->addWidget(m_timeLimitLabel);

    // Create widget
    setLayout(m_layout);
}

void TimePositionWidget::setTimeLimit(const QTime &time)
{
    m_timeLimitLabel->setText(time.toString());
}

void TimePositionWidget::updateTime(QTime time)
{
    m_timePosLabel->setText(time.toString());
}

void TimePositionWidget::reset()
{
    m_timePosLabel->setText(QTime(0, 0, 0, 0).toString());
}
