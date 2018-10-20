#ifndef INPUTVALUEBOX_HPP
#define INPUTVALUEBOX_HPP

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QLabel;
class QSpinBox;

class InputValueBox : public QWidget
{
    Q_OBJECT

public:
    explicit InputValueBox(const QString &name = QString(),
                          int value = 0,
                          QWidget *parent = nullptr);

    QString getName() const;
    void setName(const QString &name);

    int getMax() const;
    void setMax(int max);

    int getMin() const;
    void SetMin(int min);

    void setRange(int min, int max);

public slots:
    void setValue(int value);

private:
    QHBoxLayout *m_layout;
    QLabel *m_nameLabel;
    QSpinBox *m_valueSpinBox;

signals:
    void valueChanged(int value);

};

#endif // INPUTVALUEBOX_HPP
