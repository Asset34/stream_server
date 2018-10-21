#ifndef SAMPLERATECOMBOBOX_HPP

#include <QComboBox>

class SampleRateComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit SampleRateComboBox(QWidget *parent = nullptr);
    virtual ~SampleRateComboBox();

    int getCurrentSampleRate() const;

private:

};

#endif // QUALITYCOMBOBOX_HPP
