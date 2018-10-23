#ifndef SAMPLERATECOMBOBOX_HPP

#include <QComboBox>

class SampleRateComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit SampleRateComboBox(QWidget *parent = nullptr);

    int getCurrentSampleRate() const;

private:

};

#endif // QUALITYCOMBOBOX_HPP
