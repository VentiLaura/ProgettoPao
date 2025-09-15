#include "SortWidget.h"

SortWidget::SortWidget(QWidget *parent):QWidget(parent){
    QFormLayout *sortLayout = new QFormLayout;
    sort = new QLabel("Ordina per:", this);
    sortMenu = new QComboBox(this);
    sortMenu->addItem("Nome");      
    sortMenu->addItem("Prezzo più basso");
    sortMenu->addItem("Prezzo più alto");
    sortMenu->addItem("Disponibilità");
    sortLayout->addRow(sort, sortMenu);
    setLayout(sortLayout);
    connect(sortMenu, &QComboBox::currentTextChanged, this, &SortWidget::onSortChanged);
}

void SortWidget::onSortChanged(const QString& text) {
    emit SortChanged(text); 
}

