#ifndef MAINRIGHTWIDGET_H
#define MAINRIGHTWIDGET_H
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include "SearchBarWidget.h"
#include "PageContainerWidget.h"
#include "../LogicModel/Catalog/Memory.h"
#include "../JSON/JSONReader.h"
#include "../XML/XMLReader.h"
class MainRightWidget: public QWidget {
    Q_OBJECT
    public:
        MainRightWidget(QWidget* = nullptr);
        //void updateProducts(const std::vector<product::Product*>&);
    private:
        QVBoxLayout* MainRightWidgetLayout;
        PageWidget* pcw;
        SearchBarWidget* sbw;
        public slots:
        void updateProducts(const std::vector<product::Product*>& products);


};
#endif

