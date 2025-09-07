#ifndef DETAILSPAGEWIDGET_H
#define DETAILSPAGEWIDGET_H
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

class DetailsPageWidget: public QWidget {
    Q_OBJECT
    public:
    DetailsPageWidget(QWidget* =nullptr);
    void ShowDetailsOf(product::Product*);
    private:
    QWidget* details;
    QWidget* bar;
    QVBoxLayout* pageLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* quitButton;
    QHBoxLayout* detailsLayout;
    QVBoxLayout* infoLayout;
    
    signals:
    void quitClicked();

};
#endif