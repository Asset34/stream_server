#ifndef QUALITYCOMBOBOX_HPP
#define QUALITYCOMBOBOX_HPP

#include <QComboBox>

class QualityComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit QualityComboBox(QWidget *parent = nullptr);
    virtual ~QualityComboBox();

    int getCurrentQuality() const;

private:

};

#endif // QUALITYCOMBOBOX_HPP
