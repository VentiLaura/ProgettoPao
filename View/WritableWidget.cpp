#include "WritableWidget.h"
void WritableWidget::createProduct(product::Product* product) {
    selected=product;
    layout = new QVBoxLayout(this);
    if(!dynamic_cast<product::Console*> (product)) {
    layout->addWidget(new QLabel("Name:"));
    nameEdit = new QLineEdit(QString::fromStdString(product->getName()));
    layout->addWidget(nameEdit);
    }

    layout->addWidget(new QLabel("Price:"));
    priceEdit = new QLineEdit(QString::number(product->getPrice(), 'f', 2));
    layout->addWidget(priceEdit);

    layout->addWidget(new QLabel("ID product:"));
    idEdit = new QLineEdit(QString::fromStdString(product->getIdProduct()));
    layout->addWidget(idEdit);

    layout->addWidget(new QLabel("Image Path:"));
    imageEdit = new QLineEdit(QString::fromStdString(product->getImage()));
    layout->addWidget(imageEdit);

    layout->addWidget(new QLabel("Copies Available:"));
    copiesEdit = new QLineEdit(QString::number(product->getAvailability()));
    layout->addWidget(copiesEdit);
    setLayout(layout);
}

void WritableWidget::visitVideogame(product::Videogame* videogame) {
    qDebug()<<"dentro videogame";
    createProduct(videogame);

    layout->addWidget(new QLabel("Producer:"));
    producerEdit = new QLineEdit(QString::fromStdString(videogame->getProducer()));
    layout->addWidget(producerEdit);

    layout->addWidget(new QLabel("Compatibility (comma-separated):"));
    QStringList compatList;
    for (auto c : videogame->getCompatibility())
        compatList << QString::fromStdString(ConsoleTypeToString(c));
    CompatibilityEdit = new QLineEdit(compatList.join(", "));
    layout->addWidget(CompatibilityEdit);

    layout->addWidget(new QLabel("Genres (comma-separated):"));
    QStringList genreList;
    qDebug()<<videogame->getGenres().size();
    for (auto g : videogame->getGenres()) {
        qDebug()<<"genere pushato dentro:";
    qDebug()<<QString::fromStdString(GenreToString(g));
        genreList << QString::fromStdString(GenreToString(g));
    }
    GenreEdit = new QLineEdit(genreList.join(", "));
    layout->addWidget(GenreEdit);  
}
void WritableWidget::visitTshirt(product::T_shirt* tshirt) {
    createProduct(tshirt);
    layout->addWidget(new QLabel("Franchise:"));
    franchiseEdit = new QLineEdit(QString::fromStdString(tshirt->getFranchise()));
    layout->addWidget(franchiseEdit);

    layout->addWidget(new QLabel("Size:"));
    sizeComboBox = new QComboBox();
    for (int i = static_cast<int>(product::Sizes::XS); i <= static_cast<int>(product::Sizes::XL); ++i) {
        product::Sizes size = static_cast<product::Sizes>(i);
        sizeComboBox->addItem(QString::fromStdString(product::SizeToString(size)));
        if (size == tshirt->getSize()) {
            sizeComboBox->setCurrentIndex(sizeComboBox->count() - 1);
        }
    }
    layout->addWidget(sizeComboBox);

}

void WritableWidget::visitCollectible(product::Collectible* coll) {
    createProduct(coll);

    layout->addWidget(new QLabel("Category:"));
    categoryEdit = new QLineEdit(QString::fromStdString(coll->GetCategory()));
    layout->addWidget(categoryEdit);

    layout->addWidget(new QLabel("Franchise:"));
    franchiseEdit = new QLineEdit(QString::fromStdString(coll->GetFranchise()));
    layout->addWidget(franchiseEdit);

    layout->addWidget(new QLabel("Producer:"));
    producerEdit = new QLineEdit(QString::fromStdString(coll->GetProducer()));
    layout->addWidget(producerEdit);
}

void WritableWidget::visitConsole(product::Console* console) {
    createProduct(console);

    layout->addWidget(new QLabel("Serie:"));
    serieComboBox = new QComboBox();
    for (int i = static_cast<int>(product::Console_type::Xbox); i <= static_cast<int>(product::Console_type::Nintendo_Switch_2); ++i) {
        product::Console_type type = static_cast<product::Console_type>(i);
        serieComboBox->addItem(QString::fromStdString(product::ConsoleTypeToString(type)));
        if (type == console->getSerie()) {
            serieComboBox->setCurrentIndex(serieComboBox->count() - 1);
        }
    }
    layout->addWidget(serieComboBox);

    layout->addWidget(new QLabel("Memory:"));
    memoryEdit = new QLineEdit(QString::fromStdString(console->getMemory()));
    layout->addWidget(memoryEdit);

}
void WritableWidget::visitAccessory(product::Accessory* acc) {
    createProduct(acc);

    layout->addWidget(new QLabel("Height (in cm):"));
    heightEdit = new QLineEdit(QString::number(acc->getHeight()));
    layout->addWidget(heightEdit);

    layout->addWidget(new QLabel("Length (in cm):"));
    lengthEdit = new QLineEdit(QString::number(acc->getLenght()));
    layout->addWidget(lengthEdit);

    layout->addWidget(new QLabel("Depth (in cm):"));
    depthEdit = new QLineEdit(QString::number(acc->getDepth()));
    layout->addWidget(depthEdit);

    layout->addWidget(new QLabel("Weight (in grams):"));
    weightEdit = new QLineEdit(QString::number(acc->getWeight()));
    layout->addWidget(weightEdit);

    layout->addWidget(new QLabel("Compatibility (comma-separated):"));
    QStringList compatList;
    for (auto c : acc->getCompatibility()) {
        compatList << QString::fromStdString(ConsoleTypeToString(c));
    }
    CompatibilityEdit = new QLineEdit(compatList.join(", "));
    layout->addWidget(CompatibilityEdit);
    
}

void WritableWidget::Updateproduct() {
    if(dynamic_cast<product::Videogame*>(selected)) {
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
    } else if(dynamic_cast<product::Console*>(selected)) {
        qDebug()<<QString::fromStdString(product::ConsoleTypeToString(product::StringToConsoleType(serieComboBox->currentText().toStdString())));
        newProduct = new product::Console(
        product::StringToConsoleType(serieComboBox->currentText().toStdString()),
        memoryEdit->text().toStdString(),
        imageEdit->text().toStdString(),
        priceEdit->text().toDouble(),
        idEdit->text().toStdString(),
        copiesEdit->text().toInt());

    } else if(dynamic_cast<product::Accessory*>(selected)) {
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
    } else if(dynamic_cast<product::Collectible*>(selected)) {
        newProduct=new product::Collectible(categoryEdit->text().toStdString(), 
        franchiseEdit->text().toStdString(), producerEdit->text().toStdString(), 
        imageEdit->text().toStdString(), 
        nameEdit->text().toStdString(), 
        priceEdit->text().toDouble(), 
        idEdit->text().toStdString(), 
        copiesEdit->text().toInt());
    } else if(dynamic_cast<product::T_shirt*>(selected)) {
        newProduct = new product::T_shirt(
        product::StringToSize(sizeComboBox->currentText().toStdString()),
        franchiseEdit->text().toStdString(),
        imageEdit->text().toStdString(),
        nameEdit->text().toStdString(),
        priceEdit->text().toDouble(),
        idEdit->text().toStdString(),
        copiesEdit->text().toInt());
    }
    mem.UpdateProduct(selected->getIdProduct(), newProduct);
    //*selected = *newProduct;
}