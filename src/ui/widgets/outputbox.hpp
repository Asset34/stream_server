#ifndef VALUEOUTPUTBOX_HPP
#define VALUEOUTPUTBOX_HPP

#include <QWidget>

class QHBoxLayout;
class QString;
class QLabel;

class OutputBox : public QWidget
{
    Q_OBJECT

public:
    explicit OutputBox(const QString &name = QString(),
                       const QString &output = QString(),
                       QWidget *parent = nullptr);

    QString getName() const;
    void setName(const QString &name);

public slots:
    void setText(const QString &text);
    void setValue(int value);
    void setValue(double value);
    void clear();

private:
    QHBoxLayout *m_layout;
    QLabel *m_nameLabel;
    QLabel *m_outputLabel;

};

#endif // VALUEOUTPUTBOX_HPP
