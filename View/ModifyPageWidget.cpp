#include "ModifyPageWidget.h"
ModifyPageWidget::ModifyPageWidget(QWidget* parent): QWidget(parent) {
    pageLayout = new QVBoxLayout(this); // layout principale della pagina
    // Barra in alto con pulsante Quit
    bar=new QWidget;
    topBarLayout = new QHBoxLayout(bar);
    cancelButton = new QPushButton("Cancel");
    acceptButton=new QPushButton("Accept");
    topBarLayout->addStretch();           // spinge il pulsante a destra
    topBarLayout->addWidget(acceptButton);
    topBarLayout->addWidget(cancelButton); 
    bar->setLayout(topBarLayout);  // aggiunge il pulsante
    pageLayout->addWidget(bar, 1);  // aggiunge la barra in alto al layout principale
    setLayout(pageLayout);
    connect(cancelButton, &QPushButton::clicked, this, &ModifyPageWidget::cancelClicked);
    connect(cancelButton, &QPushButton::clicked, this, &ModifyPageWidget::DeleteDetails);
    connect(acceptButton, &QPushButton::clicked, this, &ModifyPageWidget::Updateproduct);
    connect(acceptButton, &QPushButton::clicked, this, &ModifyPageWidget::acceptClicked);
    connect(acceptButton, &QPushButton::clicked, this, &ModifyPageWidget::DeleteDetails);
}
void ModifyPageWidget::ModifyInfoOf(product::Product* product) {
    ModifyDetails=new QWidget;
    modifylayout = new QVBoxLayout(ModifyDetails);
    modifylayout->addWidget(new QLabel("Modify product:"), 1);
    cwow=new CreateWritableObjectWidget();
    product->accept(cwow);
    modifylayout->addWidget(cwow, 9);
    pageLayout->addWidget(ModifyDetails);
}
void ModifyPageWidget::DeleteDetails() {
    pageLayout->removeWidget(ModifyDetails);
    delete ModifyDetails;
    //delete cwow;
}
void ModifyPageWidget::Updateproduct() {
    qDebug()<<"Dentro update modifywidget";
    cwow->Updateproduct();
}