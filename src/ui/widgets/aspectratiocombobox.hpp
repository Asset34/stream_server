#ifndef ASPECTRATIOCOMBOBOX_HPP
#define ASPECTRATIOCOMBOBOX_HPP

#include <QComboBox>

#include <VLCQtCore/Enums.h>

class AspectRatioComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit AspectRatioComboBox(QWidget *parent = nullptr);
    virtual ~AspectRatioComboBox();

    Vlc::Ratio getCurrentAspectRatio() const;

private:

};

#endif // ASPECTRATIOCOMBOBOX_HPP
