#ifndef TEXTINPUTBOX_HPP
#define TEXTINPUTBOX_HPP

#include <QWidget>

class QHBoxLayout;
class QString;
class QLabel;
class QLineEdit;
class QValidator;

class InputBox : public QWidget
{
    Q_OBJECT

public:
    explicit InputBox(const QString &name = QString(),
                      const QString &text = QString(),
                      QWidget *parent = nullptr);

    QString getName() const;
    void setName(const QString &name);

    QString getText() const;

    const QValidator *getValidator() const;
    void setValidator(const QValidator *v);

public slots:
    void setText(const QString &text);

private:
    QHBoxLayout *m_layout;
    QLabel *m_nameLabel;
    QLineEdit *m_lineEdit;

signals:
    void textChanged();

};

#endif // TEXTINPUTBOX_HPP
