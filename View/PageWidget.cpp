#include "PageWidget.h"
#include "ProductWidget.h"
#include <QMainWindow>
#include <QPushButton>

PageWidget::PageWidget(std::vector<product::Product*> products, QWidget* parent): QWidget(parent) {
    QGridLayout* gridLayout = new QGridLayout;
    const int columns = 4;
    for (int i=0; i < products.size(); ++i) {
        ProductWidget* widget = new ProductWidget(products[i], this);
        Productwidgets.push_back(widget);
        int row = i / columns;
        int column = i % columns;
        gridLayout->addWidget(widget, row, column);
        gridLayout->setColumnStretch(column, 1);
        gridLayout->setRowStretch(row, 1);
    }
    setLayout(gridLayout);
}