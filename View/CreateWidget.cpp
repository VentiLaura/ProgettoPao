#include "CreateWidget.h"

CreateWidget::CreateWidget(const QString& type) {
    qDebug()<<"costruisco create";
    pageLayout = new QVBoxLayout(this); // pageLayout principale della pagina
    // Barra in alto con pulsante Quit
    /*bar=new QWidget;
    topBarLayout = new QHBoxLayout(bar);
    //cancelButton = new QPushButton("Cancel");
    //acceptButton=new QPushButton("Accept");
    topBarLayout->addStretch();           // spinge il pulsante a destra
    //topBarLayout->addWidget(acceptButton);
    //topBarLayout->addWidget(cancelButton); 
    bar->setLayout(topBarLayout);  // aggiunge il pulsante
    pageLayout->addWidget(bar, 1);  // aggiunge la barra in alto al pageLayout principale
    setLayout(pageLayout);
    /*connect(cancelButton, &QPushButton::clicked, this, &CreateWidget::cancelClicked);
    connect(cancelButton, &QPushButton::clicked, this, &CreateWidget::DeleteDetails);
    connect(acceptButton, &QPushButton::clicked, this, &CreateWidget::CreateProduct);
    connect(acceptButton, &QPushButton::clicked, this, &CreateWidget::acceptClicked);
    connect(acceptButton, &QPushButton::clicked, this, &CreateWidget::DeleteDetails);*/


    if(type!="Console") {
    pageLayout->addWidget(new QLabel("Name:"));
    nameEdit = new QLineEdit();
    pageLayout->addWidget(nameEdit);
    }

    pageLayout->addWidget(new QLabel("Price:"));
    priceEdit = new QLineEdit();
    pageLayout->addWidget(priceEdit);

    pageLayout->addWidget(new QLabel("ID product:"));
    idEdit = new QLineEdit();
    pageLayout->addWidget(idEdit);

    pageLayout->addWidget(new QLabel("Image Path:"));
    imageEdit = new QLineEdit();
    pageLayout->addWidget(imageEdit);

    pageLayout->addWidget(new QLabel("Copies Available:"));
    copiesEdit = new QLineEdit();
    pageLayout->addWidget(copiesEdit);
    setLayout(pageLayout);

qDebug()<<"prima chiamata Window specifica";
    if (type=="Videogame") VideogameWindow();
    if (type=="Console") ConsoleWindow();
    if (type=="T-shirt") TshirtWindow();
    if (type=="Collectible") CollectibleWindow();
    if (type=="Accessory") AccessoryWindow();
    qDebug()<<"fine costruzione";
}


void CreateWidget::VideogameWindow() {
    pageLayout->addWidget(new QLabel("Producer:"));
    producerEdit = new QLineEdit();
    pageLayout->addWidget(producerEdit);

    pageLayout->addWidget(new QLabel("Compatibility (comma-separated):"));
    CompatibilityEdit = new QLineEdit();
    pageLayout->addWidget(CompatibilityEdit);

    pageLayout->addWidget(new QLabel("Genres (comma-separated):"));
    QStringList genreList;
    GenreEdit = new QLineEdit();
    pageLayout->addWidget(GenreEdit);  

}
void CreateWidget::ConsoleWindow() {
    pageLayout->addWidget(new QLabel("Serie:"));
    serieComboBox = new QComboBox();
    for (int i = static_cast<int>(product::Console_type::Xbox); i <= static_cast<int>(product::Console_type::Nintendo_Switch_2); ++i) {
        product::Console_type type = static_cast<product::Console_type>(i);
        serieComboBox->addItem(QString::fromStdString(product::ConsoleTypeToString(type)));
    }
    pageLayout->addWidget(serieComboBox);

    pageLayout->addWidget(new QLabel("Memory:"));
    memoryEdit = new QLineEdit();
    pageLayout->addWidget(memoryEdit);
}

void CreateWidget::TshirtWindow() {
    pageLayout->addWidget(new QLabel("Franchise:"));
    franchiseEdit = new QLineEdit();
    pageLayout->addWidget(franchiseEdit);

    pageLayout->addWidget(new QLabel("Size:"));
    sizeComboBox = new QComboBox();
    for (int i = static_cast<int>(product::Sizes::XS); i <= static_cast<int>(product::Sizes::XL); ++i) {
    product::Sizes size = static_cast<product::Sizes>(i);
    sizeComboBox->addItem(QString::fromStdString(product::SizeToString(size)));
}

    pageLayout->addWidget(sizeComboBox);

}
void CreateWidget::CollectibleWindow() {
    pageLayout->addWidget(new QLabel("Category:"));
    categoryEdit = new QLineEdit();
    pageLayout->addWidget(categoryEdit);

    pageLayout->addWidget(new QLabel("Franchise:"));
    franchiseEdit = new QLineEdit();
    pageLayout->addWidget(franchiseEdit);

    pageLayout->addWidget(new QLabel("Producer:"));
    producerEdit = new QLineEdit();
    pageLayout->addWidget(producerEdit);

}
void CreateWidget::AccessoryWindow() {
    pageLayout->addWidget(new QLabel("Height (in cm):"));
    heightEdit = new QLineEdit();
    pageLayout->addWidget(heightEdit);

    pageLayout->addWidget(new QLabel("Length (in cm):"));
    lengthEdit = new QLineEdit();
    pageLayout->addWidget(lengthEdit);

    pageLayout->addWidget(new QLabel("Depth (in cm):"));
    depthEdit = new QLineEdit();
    pageLayout->addWidget(depthEdit);

    pageLayout->addWidget(new QLabel("Weight (in grams):"));
    weightEdit = new QLineEdit();
    pageLayout->addWidget(weightEdit);

    pageLayout->addWidget(new QLabel("Compatibility (comma-separated):"));
    CompatibilityEdit = new QLineEdit();
    pageLayout->addWidget(CompatibilityEdit);

}


product::Product* CreateWidget::CreateProduct(const QString& type) {
    qDebug()<<"fa due volte anche la funzione?";
    if(type=="Videogame") {
        QStringList genreLines = GenreEdit->text().split(", ");
        std::vector<product::Genre> genres;
        for (const QString& line : genreLines) {
            qDebug()<<line;
            genres.push_back(product::StringToGenre(line.toStdString()));
        }
        QStringList compatLines = CompatibilityEdit->text().split(", ");
        std::vector<product::Console_type> compatibility;
        for (const QString& line : compatLines) {
            compatibility.push_back(product::StringToConsoleType(line.toStdString()));
        }
        qDebug()<<"prima creazione";
        newProduct=new product::Videogame(compatibility, 
        producerEdit->text().toStdString(), 
        genres, imageEdit->text().toStdString(), 
        nameEdit->text().toStdString(), 
        priceEdit->text().toDouble(), 
        idEdit->text().toStdString(), 
        copiesEdit->text().toInt());
        qDebug()<<"dopo Creazione";
    } else if(type=="Console") {
        qDebug()<<QString::fromStdString(product::ConsoleTypeToString(product::StringToConsoleType(serieComboBox->currentText().toStdString())));
        newProduct = new product::Console(
        product::StringToConsoleType(serieComboBox->currentText().toStdString()),
        memoryEdit->text().toStdString(),
        imageEdit->text().toStdString(),
        priceEdit->text().toDouble(),
        idEdit->text().toStdString(),
        copiesEdit->text().toInt());

    } else if(type=="Accessory") {
        QStringList compatLines = CompatibilityEdit->text().split(", ");
        std::vector<product::Console_type> compatibility;
        for (const QString& line : compatLines) {
            compatibility.push_back(product::StringToConsoleType(line.toStdString()));
        }
        newProduct=new product::Accessory(heightEdit->text().toDouble(), 
        lengthEdit->text().toDouble(), 
        depthEdit->text().toDouble(), 
        weightEdit->text().toDouble(), 
        compatibility, 
        imageEdit->text().toStdString(), 
        nameEdit->text().toStdString(), 
        priceEdit->text().toDouble(), 
        idEdit->text().toStdString(), 
        copiesEdit->text().toInt());
    } else if(type=="Collectible") {
        newProduct=new product::Collectible(categoryEdit->text().toStdString(), 
        franchiseEdit->text().toStdString(), producerEdit->text().toStdString(), 
        imageEdit->text().toStdString(), 
        nameEdit->text().toStdString(), 
        priceEdit->text().toDouble(), 
        idEdit->text().toStdString(), 
        copiesEdit->text().toInt());
    } else if(type=="T-shirt") {
        qDebug()<<"viene fatto 2 volte anche tshirt?";
        newProduct = new product::T_shirt(
        product::StringToSize(sizeComboBox->currentText().toStdString()),
        franchiseEdit->text().toStdString(),
        imageEdit->text().toStdString(),
        nameEdit->text().toStdString(),
        priceEdit->text().toDouble(),
        idEdit->text().toStdString(),
        copiesEdit->text().toInt());
    }
    //memory::Memory& mem=memory::Memory::getCentralMemoryInstance();
    qDebug()<<"isunique";
    qDebug()<<mem.IsUnique(newProduct->getIdProduct());
    mem.Add(newProduct);
    qDebug()<<"fine createProduct";
    return newProduct;
    //*selected = *newProduct;
}


/*void CreateWidget::DeleteDetails() {
    delete this;
    //delete ModifyPage;
}*/