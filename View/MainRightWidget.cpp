#include "MainRightWidget.h"
#include <QLineEdit>
#include <QGuiApplication>
#include <QScreen>
#include <vector>
MainRightWidget::MainRightWidget(QWidget *p): QWidget(p),MainRightWidgetLayout(new QVBoxLayout(this)), sbw(new SearchBarWidget(this))/*, pcw(new PageContainerWidget(this))*/ {
    //QString Path="JSON/Products.json";
    QString Path="XML/Products.xml";  
    memory::Memory& m=memory::Memory::getCentralMemoryInstance();
    //m.Add(json::JsonReader(Path));
    m.Add(xml::XMLReader(Path));

    pcw = new PageWidget(m.getCatalog());
    qDebug() << m.getCatalog().size();
    MainRightWidgetLayout->addWidget(sbw);
    MainRightWidgetLayout->addWidget(pcw);
    MainRightWidgetLayout->setStretch(0, 1);  
    MainRightWidgetLayout->setStretch(1, 9);
    setLayout(MainRightWidgetLayout);
}
void MainRightWidget::updateProducts(const std::vector<product::Product*>& products) {
    pcw->updateProducts(products); // pcw = PageContainerWidget o PageWidget
}

/*void MainRightWidget::updateProducts(const std::vector<product::Product*>& products) {
    // Pulire le pagine precedenti:
    MainRightWidgetLayout->removeWidget(pcw);
    delete pcw;
    pcw=new PageWidget(products);
    MainRightWidgetLayout->addWidget(pcw);
}*/
/*void MainRightWidget::updateProducts(const std::vector<product::Product*>& products) {
   // if (pcw) {
      //  pcw->updateProducts(products); 
   // }
}
*/
