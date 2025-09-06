#ifndef PAGECONTAINERWIDGET_H
#define PAGECONTAINERWIDGET_H
#include <QStackedLayout>
#include <QMainWindow>
#include <QPushButton>
#include "PageWidget.h"
#include "../LogicModel/Products/Product.h"
class PageContainerWidget: public QWidget {
    public:
        PageContainerWidget(QWidget* = nullptr);
        PageContainerWidget(std::vector<product::Product*>, QWidget* = nullptr);
        int getPageNumber();
        void AddPage(PageWidget*);
        void updateProducts(const std::vector<product::Product*>& products);

    private:
    std::vector<PageWidget*> Pages;
    QStackedLayout* stackedLayout;
};
#endif