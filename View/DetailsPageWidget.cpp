#include "DetailsPageWidget.h"
DetailsPageWidget::DetailsPageWidget(QWidget* parent): QWidget(parent) {
    pageLayout = new QVBoxLayout(this);
    mpw= new ModifyPageWidget;
    bar=new QWidget;
    topBarLayout = new QHBoxLayout(bar);
    quitButton = new QPushButton("Quit");
    modifyButton=new QPushButton("Modify");
    deleteButton=new QPushButton("Delete");
    topBarLayout->addStretch();
    topBarLayout->addWidget(modifyButton);
    topBarLayout->addWidget(deleteButton);
    topBarLayout->addWidget(quitButton);
    bar->setLayout(topBarLayout);
    pageLayout->addWidget(bar, 1);
    setLayout(pageLayout);
    connect(quitButton, &QPushButton::clicked, this, &DetailsPageWidget::quitClicked);
    connect(quitButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteDetails);
    connect(modifyButton, &QPushButton::clicked, this, &DetailsPageWidget::ModifyClicked);
    connect(DetailsPageWidget::mpw, &ModifyPageWidget::cancelClicked, this, &DetailsPageWidget::Return);
    connect(DetailsPageWidget::mpw, &ModifyPageWidget::acceptClicked, this, &DetailsPageWidget::Return);
    connect(DetailsPageWidget::mpw, &ModifyPageWidget::acceptClicked, this, &DetailsPageWidget::ReturnToGrid);
    connect(DetailsPageWidget::mpw, &ModifyPageWidget::acceptClicked, this, &DetailsPageWidget::Updateproduct);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteGridProduct);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteProduct);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::ReturnToGrid);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::quitClicked);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteDetails);
}

void DetailsPageWidget::ShowDetailsOf(product::Product* product) {
    selected = product;
    details = new QWidget;
    detailsLayout = new QHBoxLayout(details);
    details->setLayout(detailsLayout);
    QLabel* imageLabel = new QLabel;
    QPixmap pix(QString::fromStdString(product->getImage()));
    imageLabel->setPixmap(pix.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    imageLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout* infoLayout = new QVBoxLayout;
    QLabel* name = new QLabel("Name: " + QString::fromStdString(product->getName()));
    name->setFont(QFont("Arial", 14, QFont::Bold));
    infoLayout->addWidget(name);
    QLabel* price = new QLabel(QString("Price: €%1").arg(product->getPrice(), 0, 'f', 2));
    infoLayout->addWidget(price);
    QLabel* id = new QLabel("ID product: " + QString::fromStdString(product->getIdProduct()));
    infoLayout->addWidget(id);
    QLabel* copies = new QLabel("Copies Available: " + QString::number(product->getAvailability()));
    infoLayout->addWidget(copies);

    if (auto vg = dynamic_cast<product::Videogame*>(product)) {
        QLabel* producerLabel = new QLabel("Producer: " + QString::fromStdString(vg->getProducer()));
        infoLayout->addWidget(producerLabel);
        QStringList compatibilityList;
        for (auto c : vg->getCompatibility())
            compatibilityList << QString::fromStdString(ConsoleTypeToString(c));
        QLabel* compatLabel = new QLabel("Compatibility: " + compatibilityList.join(", "));
        infoLayout->addWidget(compatLabel);
        QStringList genresList;
        for (auto g : vg->getGenres())
            genresList << QString::fromStdString(GenreToString(g));
        QLabel* genresLabel = new QLabel("Genres: " + genresList.join(", "));
        infoLayout->addWidget(genresLabel);
    }
    else if (auto acc = dynamic_cast<product::Accessory*>(product)) {
        QLabel* dimLabel = new QLabel(QString("Height (in cm): %1").arg(acc->getHeight(), 0, 'f', 2));
        infoLayout->addWidget(dimLabel);
        dimLabel = new QLabel(QString("Length (in cm): %1").arg(acc->getLenght(), 0, 'f', 2));
        infoLayout->addWidget(dimLabel);
        dimLabel = new QLabel(QString("Depth (in cm): %1").arg(acc->getDepth(), 0, 'f', 2));
        infoLayout->addWidget(dimLabel);
        QLabel* weightLabel = new QLabel(QString("Weight (in grams): %1").arg(acc->getWeight(), 0, 'f', 2));
        infoLayout->addWidget(weightLabel);
        QStringList compatList;
        for (auto c : acc->getCompatibility())
            compatList << QString::fromStdString(ConsoleTypeToString(c));
        QLabel* compatLabel = new QLabel("Compatibility: " + compatList.join(", "));
        infoLayout->addWidget(compatLabel);
    }
    else if (auto col = dynamic_cast<product::Collectible*>(product)) {
        QLabel* catLabel = new QLabel("Category: " + QString::fromStdString(col->GetCategory()));
        infoLayout->addWidget(catLabel);
        QLabel* franLabel = new QLabel("Franchise: " + QString::fromStdString(col->GetFranchise()));
        infoLayout->addWidget(franLabel);
        QLabel* prodLabel = new QLabel("Producer: " + QString::fromStdString(col->GetProducer()));
        infoLayout->addWidget(prodLabel);
    }
    else if (auto con = dynamic_cast<product::Console*>(product)) {
        QLabel* serieLabel = new QLabel("Serie: " + QString::fromStdString(ConsoleTypeToString(con->getSerie())));
        infoLayout->addWidget(serieLabel);
        QLabel* memLabel = new QLabel("Memory: " + QString::fromStdString(con->getMemory()));
        infoLayout->addWidget(memLabel);
    }
    else if (auto tshirt = dynamic_cast<product::T_shirt*>(product)) {
        QLabel* franchiseLabel = new QLabel("Franchise: " + QString::fromStdString(tshirt->getFranchise()));
        infoLayout->addWidget(franchiseLabel);
        QLabel* sizeLabel = new QLabel("Size: " + QString::fromStdString(SizeToString(tshirt->getSize())));
        infoLayout->addWidget(sizeLabel);
        QLabel* chest = new QLabel(QString("Chest (cm): %1").arg(tshirt->getChestSize()));
        QLabel* waist = new QLabel(QString("Waist (cm): %1").arg(tshirt->getWaistSize()));
        QLabel* hips = new QLabel(QString("Hips (cm): %1").arg(tshirt->getHipsSize()));
        QLabel* sleeve = new QLabel(QString("Sleeve length (cm): %1").arg(tshirt->getSleeveLength()));
        infoLayout->addWidget(chest);
        infoLayout->addWidget(waist);
        infoLayout->addWidget(hips);
        infoLayout->addWidget(sleeve);
    }
    detailsLayout->addWidget(imageLabel, 2);
    detailsLayout->addLayout(infoLayout, 3);
    pageLayout->addWidget(details, 9);
    qDebug() << "fine funz";
}

void DetailsPageWidget::DeleteDetails() {
    pageLayout->removeWidget(details);
    delete details;
}

void DetailsPageWidget::ModifyClicked() {
    layout()->removeWidget(details);    
    details->hide();
    layout()->removeWidget(bar);
    bar->hide();
    mpw->ModifyInfoOf(selected);   
    layout()->addWidget(mpw);      
    mpw->show();  
}

void DetailsPageWidget::Return() {
    layout()->removeWidget(mpw);    
    mpw->hide();
    pageLayout->addWidget(bar, 1);      
    bar->show();
    pageLayout->addWidget(details, 9);
    details->show(); 
}

void DetailsPageWidget::Updateproduct() {
    DeleteDetails();
    ShowDetailsOf(selected);
}

void DetailsPageWidget::DeleteProduct() {
    memory::Memory& mem=memory::Memory::getCentralMemoryInstance();
    mem.Remove(selected->getIdProduct());
}
void DetailsPageWidget::DeleteAll() {
    if(!mpw->isHidden()) {
        mpw->DeleteDetails();
        Return();
    }
    if(!details->isHidden()) {
        DeleteDetails();
    }
}