#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H
#include <QMainWindow>
#include <QPushButton>
#include "ProductWidget.h"
#include "../LogicModel/Products/Product.h"
class PageWidget: public QWidget {
    Q_OBJECT
    public:
        PageWidget(std::vector<product::Product*>, QWidget* = nullptr);
    private:
    std::vector<ProductWidget*> productwidgets;
};
#endif