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
    ModifyPage=new WritableWidget();
    product->accept(ModifyPage);
    modifylayout->addWidget(ModifyPage, 9);
    pageLayout->addWidget(ModifyDetails, 9);
}

void ModifyPageWidget::CreateProduct(const QString& type) {
    Type=type;
    ModifyDetails=new QWidget;
    modifylayout = new QVBoxLayout(ModifyDetails);
    QLabel* title = new QLabel("Create product: " + type);
    modifylayout->addWidget(title, 1);
    CreatePage=new CreateWidget(type);
    modifylayout->addWidget(CreatePage, 9);
    pageLayout->addWidget(ModifyDetails, 9);
}

void ModifyPageWidget::DeleteDetails() {
    pageLayout->removeWidget(ModifyDetails);
    delete ModifyDetails;
    /*if(selected) {
    pageLayout->removeWidget(ModifyDetails);
    delete ModifyDetails;
    }else{
    pageLayout->removeWidget(CreatePage);
    delete CreatePage;*/
    //}
    //delete ModifyPage;
}
void ModifyPageWidget::Updateproduct() {
    if(ModifyPage)
    ModifyPage->Updateproduct();
    if(CreatePage) {
        CreatePage->CreateProduct(Type);
    }
   
}