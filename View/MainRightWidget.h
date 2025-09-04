#ifndef MAINRIGHTWIDGET_H
#define MAINRIGHTWIDGET_H
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "SearchBarWidget.h"
#include "PageContainerWidget.h"
#include "../LogicModel/Catalog/Memory.h"
#include "../JSON/JSONReader.h"
class MainRightWidget: public QWidget {
    Q_OBJECT
    public:
        MainRightWidget(QWidget* = nullptr);
    private:
    QVBoxLayout* MainRightWidgetLayout;
    PageContainerWidget* pcw;
    SearchBarWidget* sbw;
};
#endif