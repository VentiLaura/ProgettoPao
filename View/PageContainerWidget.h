#ifndef PAGECONTAINERWIDGET_H
#define PAGECONTAINERWIDGET_H
#include <QMainWindow>
#include <QPushButton>
#include "PageWidget.h"
#include "../LogicModel/Products/Product.h"
class PageContainerWidget: public QWidget {
    Q_OBJECT
    public:
        PageContainerWidget(std::vector<product::Product*>, QWidget* = nullptr);
        int getPageNumber();
    private:
    std::vector<PageWidget*> Pages;
};
#endif