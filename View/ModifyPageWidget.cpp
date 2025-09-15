#include "ModifyPageWidget.h"
ModifyPageWidget::ModifyPageWidget(QWidget* parent): QWidget(parent) {
    pageLayout = new QVBoxLayout(this); 
    bar=new QWidget;
    topBarLayout = new QHBoxLayout(bar);
    cancelButton = new QPushButton("Cancel");
    acceptButton=new QPushButton("Accept");
    topBarLayout->addStretch();        
    topBarLayout->addWidget(acceptButton);
    topBarLayout->addWidget(cancelButton); 
    bar->setLayout(topBarLayout); 
    pageLayout->addWidget(bar, 1);  
    setLayout(pageLayout);
    connect(cancelButton, &QPushButton::clicked, this, &ModifyPageWidget::cancelClicked);
    connect(cancelButton, &QPushButton::clicked, this, &ModifyPageWidget::DeleteDetails);
    connect(acceptButton, &QPushButton::clicked, this, &ModifyPageWidget::Updateproduct);
    connect(this, &ModifyPageWidget::CorrectlyGenerated, this, &ModifyPageWidget::acceptClicked);
    connect(this, &ModifyPageWidget::CorrectlyGenerated, this, &ModifyPageWidget::DeleteDetails);
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
}

void ModifyPageWidget::Updateproduct() {
    if(ModifyPage) {
        if(ModifyPage->Updateproduct()) 
            emit CorrectlyGenerated();
    }
    if(CreatePage) {
        if(CreatePage->CreateProduct(Type)) 
            emit CorrectlyGenerated();
    }
}