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

class ModifyPageWidget: public QWidget {
    Q_OBJECT
    public:
    ModifyPageWidget(QWidget* =nullptr);
    void ModifyInfoOf(product::Product*);
    void DeleteDetails();
    private:
    product::Product* selected;
    QWidget* details;
    QWidget* bar;
    QVBoxLayout* pageLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* cancelButton;
    QHBoxLayout* detailsLayout;
    QVBoxLayout* infoLayout;
    QPushButton* acceptButton;
    signals:
    void cancelClicked();

};
#endif