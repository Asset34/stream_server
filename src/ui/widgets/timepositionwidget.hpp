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
    explicit TimePositionWidget(QWidget *parent = nullptr);
    virtual ~TimePositionWidget();

    void setMaximum(const QTime &time);

public slots:
    void updateTime(const QTime &time);

private:
    QHBoxLayout *m_layout;

    QLabel *m_timePosLabel;
    QLabel *m_separatorLabel;
    QLabel *m_timeMaxLabel;

};

#endif // TIMEPOSITIONWIDGET_HPP
