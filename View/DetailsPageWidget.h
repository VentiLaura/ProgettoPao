#ifndef DETAILSPAGEWIDGET_H
#define DETAILSPAGEWIDGET_H
#include <iostream>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include "ProductWidget.h"
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "PageWidget.h"
#include "ModifyPageWidget.h"

class ModifyPageWidget;

class DetailsPageWidget: public QWidget {
    Q_OBJECT
    public:
    DetailsPageWidget(QWidget* =nullptr);
    void ShowDetailsOf(product::Product*);
    void DeleteDetails();
    void ModifyClicked();
    void Return();
    void Updateproduct();
    void UpdateDetails();
    private:
    product::Product* selected;
    QWidget* details;
    QWidget* bar;
    QVBoxLayout* pageLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* quitButton;
    QHBoxLayout* detailsLayout;
    QVBoxLayout* infoLayout;
    QPushButton* modifyButton;
    QPushButton* deleteButton;
    ModifyPageWidget* mpw;
    signals:
    void quitClicked();
    void ReturnToGrid();
    //void callMe();

};
#endif