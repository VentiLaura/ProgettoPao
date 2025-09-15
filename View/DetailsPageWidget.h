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

class DetailsPageWidget: public QWidget {
    Q_OBJECT
    public:
    DetailsPageWidget(QWidget* =nullptr);
    void ShowDetailsOf(product::Product*);
    void DeleteDetails();
    void ModifyClicked();
    void Return();
    void Updateproduct();
    void DeleteProduct();
    void DeleteAll();
    private:
    product::Product* selected;
    QWidget* details;
    QWidget* bar;
    QVBoxLayout* pageLayout;
    QHBoxLayout* topBarLayout;
    QHBoxLayout* detailsLayout;
    QVBoxLayout* infoLayout;
    QPushButton* modifyButton;
    QPushButton* deleteButton;
    QPushButton* quitButton;
    ModifyPageWidget* mpw;
    WritableWidget* ModifyPage;
    signals:
    void quitClicked();
    void ReturnToGrid();
    void DeleteGridProduct();
};
#endif