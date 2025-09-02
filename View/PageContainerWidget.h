#ifndef PAGECONTAINERWIDGET_H
#define PAGECONTAINERWIDGET_H
#include <QMainWindow>
#include <QPushButton>
#include "PageWidget.h"
#include "../LogicModel/Products/Product.h"
class PageContainerWidget: public QWidget {
    Q_OBJECT
    public:
        PageContainerWidget(QWidget* = nullptr, std::vector<product::Product*>);
        int getPageNumber();
    private:
    std::vector<PageWidget*> Pages;
};
#endif