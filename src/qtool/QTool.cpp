
#include "QTool.h"
#include <iostream>
#include <QScrollArea>

namespace qtool {

using data::DataManager;
using data::DataLoader;
using colorcreator::ColorCreator;
using viewer::LogViewer;

QTool::QTool() : QMainWindow(),
        toolTabs(new QTabWidget()),
        dataManager(new DataManager()),
        dataLoader(new DataLoader(dataManager)),
        colorCreator(new ColorCreator(dataManager)),
        logViewer(new LogViewer(dataManager)),
        scrollbar(new QScrollArea()){

    this->setWindowTitle(tr("HackTool"));

    this->setCentralWidget(toolTabs);

    scrollbar->setWidget(colorCreator);

    toolTabs->addTab(scrollbar, tr("Color Creator"));
    toolTabs->addTab(dataLoader, tr("Data Loader"));
    toolTabs->addTab(logViewer, tr("Log Viewer"));

    dataManager->addSubscriber(colorCreator, man::memory::MIMAGE_ID);
}

QTool::~QTool() {
    delete colorCreator;
    delete dataLoader;
    delete toolTabs;
}

}
