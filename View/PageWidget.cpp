#include "PageWidget.h"
#include "ProductWidget.h"
#include <QMainWindow>
#include <QPushButton>
PageWidget::PageWidget(std::vector<product::Product*> products, QWidget* parent): QWidget(parent) {
    /*for(std::vector<product::Product*>::iterator it=products.begin(); it!=products.end(); it++) {
        ProductWidget* product=new ProductWidget(*it);
        Productwidgets.push_back(product);
    }*/
QGridLayout* gridLayout = new QGridLayout;
const int columns = 4; // Numero di colonne che vuoi (es. 3 prodotti per riga)
for (int i=0; i < products.size(); ++i) {
    ProductWidget* widget = new ProductWidget(products[i], this);
    Productwidgets.push_back(widget);
    int row = i / columns;
    int column = i % columns;
    gridLayout->addWidget(widget, row, column);
}
setLayout(gridLayout);

    /*QVBoxLayout* layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignTop);
    for(std::vector<ProductWidget*>::iterator it=Productwidgets.begin(); it!=Productwidgets.end(); it++) {
        layout->addWidget(*it);
    }
    setLayout(layout);*/
}