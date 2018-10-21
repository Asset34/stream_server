#ifndef OPENFILEBOX_HPP
#define OPENFILEBOX_HPP

#include <QWidget>
#include <QString>

class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class QFileDialog;

class OpenFileBox : public QWidget
{
    Q_OBJECT

public:
    explicit OpenFileBox(const QString &name = QString(),
                         const QString &startDir = QString(),
                         const QString &filter = QString(),
                         QWidget *parent = nullptr);

    QString getName() const;
    void setName(const QString &name);

    const QString &getStartDir() const;
    void setStartDir(const QString &startDir);

    const QString &getFilter() const;
    void setFilter(const QString &filter);

    QString getPath() const;

private:
    QHBoxLayout *m_layout;
    QLabel *m_nameLabel;
    QLineEdit *m_pathLineEdit;
    QPushButton *m_fileDialogButton;

    QString m_filter;
    QString m_startDir;

private slots:
    void slotSelectFile();

signals:
    void selected(const QString &path);

};

#endif // OPENFILEBOX_HPP
