#include "aspectratiocombobox.hpp"

AspectRatioComboBox::AspectRatioComboBox(QWidget *parent)
    : QComboBox(parent)
{
    addItem("4:3"   , Vlc::R_4_3    );
    addItem("5:3"   , Vlc::R_5_3    );
    addItem("5:4"   , Vlc::R_5_4    );
    addItem("16:9"  , Vlc::R_16_9   );
    addItem("16:10" , Vlc::R_16_10  );
    addItem("1.85:1", Vlc::R_185_100);
    addItem("2.21:1", Vlc::R_221_100);
    addItem("2.35:1", Vlc::R_235_100);
    addItem("2.39:1", Vlc::R_239_100);
}

AspectRatioComboBox::~AspectRatioComboBox()
{
}

Vlc::Ratio AspectRatioComboBox::getCurrentAspectRatio() const
{
    return static_cast<Vlc::Ratio>(currentData().toInt());
}
