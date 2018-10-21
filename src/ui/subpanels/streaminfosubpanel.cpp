#include "streaminfosubpanel.hpp"

#include <QFormLayout>
#include <QLabel>

#include <ui/widgets/timepositionwidget.hpp>

StreamInfoSubpanel::StreamInfoSubpanel(VlcManager *vlcManager,
                                       QWidget *parent)
    : QGroupBox(parent),
      m_vlcManager(vlcManager)
{
    // Create name label
    m_nameLabel = new QLabel;

    // Create status label
    m_stateLabel = new QLabel;

    // Create time position widget
    m_timePostWidget = new TimePositionWidget;

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Name:"  , m_nameLabel     );
    m_layout->addRow("Status:", m_stateLabel    );
    m_layout->addRow("Time:"  , m_timePostWidget);

    // Create widget
    setTitle("Info");
    setContentsMargins(5, 20, 5, 5);
    setLayout(m_layout);

    // Create connections
    connect(m_vlcManager, &VlcManager::mediaTimeChanged,
            m_timePostWidget, &TimePositionWidget::updateTime);
    connect(m_vlcManager, &VlcManager::mediaStartedPlay,
            [this](){
        m_nameLabel->setText(m_vlcManager->getStreamName());
        m_timePostWidget->setTimeLimit(m_vlcManager->getMediaDuration());
    });
    connect(m_vlcManager, &VlcManager::mediaStateChanged,
            [this](QString state) {
        m_stateLabel->setText(state);
    });
}

StreamInfoSubpanel::~StreamInfoSubpanel()
{
}
