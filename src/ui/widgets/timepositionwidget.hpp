#ifndef TIMEPOSITIONWIDGET_HPP
#define TIMEPOSITIONWIDGET_HPP

#include <QWidget>
#include <QTime>

class QHBoxLayout;
class QLabel;

class TimePositionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimePositionWidget(const QTime &timeLimit = QTime(0, 0, 0, 0),
                                QWidget *parent = nullptr);
    virtual ~TimePositionWidget();

    void setTimeLimit(const QTime &time);

public slots:
    void updateTime(QTime time);
    void reset();

private:
    QHBoxLayout *m_layout;

    QLabel *m_timePosLabel;
    QLabel *m_separatorLabel;
    QLabel *m_timeLimitLabel;

};

#endif // TIMEPOSITIONWIDGET_HPP
