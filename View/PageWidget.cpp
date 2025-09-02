#include "PageWidget.h"
#include "ProductWidget.h"
#include <QMainWindow>
#include <QPushButton>
PageWidget::PageWidget(std::vector<product::Product*> products, QWidget* parent): QWidget(parent) {
    for(std::vector<product::Product*>::iterator it=products.begin(); it!=products.end(); it++) {
        ProductWidget* product=new ProductWidget(*it);
        productwidgets.push_back(product);
    }