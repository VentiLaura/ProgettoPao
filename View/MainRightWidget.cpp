#include "MainRightWidget.h"
#include <QLineEdit>
#include <QGuiApplication>
#include <QScreen>
#include <vector>
MainRightWidget::MainRightWidget(QWidget *p): QWidget(p),MainRightWidgetLayout(new QVBoxLayout(this)), sbw(new SearchBarWidget(this))/*, pcw(new PageContainerWidget(this))*/ {
    QString Path="JSON/Products.json";
    memory::Memory& m=memory::Memory::getCentralMemoryInstance();
    m.Add(json::JsonReader(Path));
    pcw=new PageWidget(m.getCatalog());
    qDebug() << m.getCatalog().size();
    MainRightWidgetLayout->addWidget(sbw);
    MainRightWidgetLayout->addWidget(pcw);
    MainRightWidgetLayout->setStretch(0, 1);  
    MainRightWidgetLayout->setStretch(1, 9);
    setLayout(MainRightWidgetLayout);
}