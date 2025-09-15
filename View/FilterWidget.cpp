#include "FilterWidget.h"
#include <QFormLayout>

FilterWidget::FilterWidget(QWidget *parent): QWidget(parent){
    QFormLayout *filterLayout = new QFormLayout;
    filter = new QLabel("Filtro:", this);
    filterMenu = new QComboBox(this);
    filterMenu->addItem("Tutti");      
    filterMenu->addItem("Console");
    filterMenu->addItem("Videogiochi");
    filterMenu->addItem("Accessori");
    filterMenu->addItem("Collezionabili");
    filterMenu->addItem("Magliette");
    filterLayout->addRow(filter, filterMenu);
    setLayout(filterLayout);
    connect(filterMenu, &QComboBox::currentTextChanged, this, &FilterWidget::FilterChanged);
}