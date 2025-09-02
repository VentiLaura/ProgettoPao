#include "PageWidget.h"
#include "ProductWidget.h"
#include <QMainWindow>
#include <QPushButton>
<<<<<<< HEAD
PageWidget::PageWidget(QWidget* parent, std::vector<product::Product*> products): QWidget(parent) {
    for(std::vector<product::Product*>::iterator it=products.begin(); it!=products.end(); it++) {
        ProductWidget* product=new ProductWidget(*it);
        productwidgets.push_back(product);
    }
=======
PageWidget::PageWidget(std::vector<product::Product*>, QWidget* parent): QWidget(parent) {

>>>>>>> 9d7102153eff095c150b67d7a68c376707a62b51
}