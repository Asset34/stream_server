#include "qualitycombobox.hpp"

QualityComboBox::QualityComboBox(QWidget *parent)
    : QComboBox(parent)
{
    addItem("240" , 240 );
    addItem("360" , 360 );
    addItem("480" , 480 );
    addItem("720" , 720 );
    addItem("1080", 1080);
}

QualityComboBox::~QualityComboBox()
{
}

int QualityComboBox::getCurrentQuality() const
{
    return currentData().toInt();
}
