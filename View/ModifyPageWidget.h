#ifndef MODIFYPAGEWIDGET_H
#define MODIFYPAGEWIDGET_H
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
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QStringList>
#include "CreateWritableObjectWidget.h"

class ModifyPageWidget: public QWidget {
    Q_OBJECT
    public:
    ModifyPageWidget(QWidget* =nullptr);
    void ModifyInfoOf(product::Product*);
    void DeleteDetails();
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
    CreateWritableObjectWidget* cwow;
    signals:
    void cancelClicked();

};
#endif