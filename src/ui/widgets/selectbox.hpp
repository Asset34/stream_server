#ifndef SELECTBOX_HPP
#define SELECTBOX_HPP

#include <QWidget>
#include <QVariant>

class QHBoxLayout;
class QLabel;
class QComboBox;
class QString;

class SelectBox : public QWidget
{
    Q_OBJECT

public:
    explicit SelectBox(const QString &name = QString(),
                       QWidget *parent = nullptr);
    virtual ~SelectBox();

    QString getName() const;
    void setName(const QString &name);

    void addItem(const QString &text, const QVariant &userData = QVariant());

    int currentIndex() const;
    QString currentText() const;
    QVariant currentData() const;

private:
    QHBoxLayout *m_layout;
    QLabel *m_nameLabel;
    QComboBox *m_selectBox;

};

#endif // SELECTBOX_HPP
