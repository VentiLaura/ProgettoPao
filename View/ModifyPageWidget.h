#ifndef MODIFYPAGEWIDGET_H
#define MODIFYPAGEWIDGET_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include <QStringList>
#include "WritableWidget.h"
#include "CreateWidget.h"

class ModifyPageWidget: public QWidget {
    Q_OBJECT
    public:
    ModifyPageWidget(QWidget* =nullptr);
    void ModifyInfoOf(product::Product*);
    void DeleteDetails();
    void Updateproduct();
    void CreateProduct(const QString&);
    private:
    product::Product* selected;
    QWidget* ModifyDetails;
    QWidget* bar;
    QVBoxLayout* pageLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* cancelButton;
    QHBoxLayout* detailsLayout;
    QVBoxLayout* infoLayout;
    QPushButton* acceptButton;
    QVBoxLayout* modifylayout;
    WritableWidget* ModifyPage=nullptr;
    CreateWidget* CreatePage=nullptr;
    QString Type;
    signals:
    void cancelClicked();
    void acceptClicked();
    void update();

};
#endif