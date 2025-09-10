#ifndef DETAILSPAGEWIDGET_H
#define DETAILSPAGEWIDGET_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "ModifyPageWidget.h"
#include "WritableWidget.h"
#include "../LogicModel/Catalog/Memory.h"

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
    void DeleteProduct();
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
    WritableWidget* ModifyPage;
    signals:
    void quitClicked();
    void ReturnToGrid();
    void DeleteGridProduct();
    //void callMe();

};
#endif