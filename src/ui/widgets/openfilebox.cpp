#include "openfilebox.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>

OpenFileBox::OpenFileBox(const QString &name,
                         const QString &startDir,
                         const QString &filter,
                         QWidget *parent)
    : QWidget(parent),
      m_startDir(startDir),
      m_filter(filter)
{
    /* Name label */
    m_nameLabel = new QLabel(name + ":");

    /* Path text edit */
    m_pathLineEdit = new QLineEdit;

    /* File button */
    m_fileDialogButton = new QPushButton("...");

    /* Layout */
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_nameLabel);
    m_layout->addWidget(m_pathLineEdit);
    m_layout->addWidget(m_fileDialogButton);

    /* Widget */
    setLayout(m_layout);

    /* Connections */
    connect(m_fileDialogButton, &QPushButton::clicked, this, &OpenFileBox::slotSelectFile);
}

QString OpenFileBox::getName() const
{
    return m_nameLabel->text();
}

void OpenFileBox::setName(const QString &name)
{
    m_nameLabel->setText(name + ":");
}

const QString &OpenFileBox::getStartDir() const
{
    return m_startDir;
}

void OpenFileBox::setStartDir(const QString &startDir)
{
    m_startDir = startDir;
}

const QString &OpenFileBox::getFilter() const
{
    return m_filter;
}

void OpenFileBox::setFilter(const QString &filter)
{
    m_filter = filter;
}

QString OpenFileBox::getPath() const
{
    return m_pathLineEdit->text();
}

void OpenFileBox::slotSelectFile()
{
    QString path = QFileDialog::getOpenFileName(
                this,
                "Open file",
                m_startDir,
                m_filter
                );

    m_pathLineEdit->setText(path);

    emit selected(path);
}
