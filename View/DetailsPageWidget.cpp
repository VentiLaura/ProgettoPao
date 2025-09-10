#include "DetailsPageWidget.h"
DetailsPageWidget::DetailsPageWidget(QWidget* parent): QWidget(parent) {
    pageLayout = new QVBoxLayout(this); // layout principale della pagina
    // Barra in alto con pulsante Quit
    mpw= new ModifyPageWidget;
    bar=new QWidget;
    topBarLayout = new QHBoxLayout(bar);
    quitButton = new QPushButton("Quit");
    modifyButton=new QPushButton("Modify");
    deleteButton=new QPushButton("Delete");
    topBarLayout->addStretch();           // spinge il pulsante a destra
    topBarLayout->addWidget(modifyButton);
    topBarLayout->addWidget(deleteButton);
    topBarLayout->addWidget(quitButton);
    //pageLayout->insertStretch(0, 1);           // Inserisce lo stretch a sinistra
            // Spazio vuoto = 9  
    bar->setLayout(topBarLayout);  // aggiunge il pulsante
    pageLayout->addWidget(bar, 1);  // aggiunge la barra in alto al layout principale
    connect(quitButton, &QPushButton::clicked, this, &DetailsPageWidget::quitClicked);
    connect(quitButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteDetails);
    connect(modifyButton, &QPushButton::clicked, this, &DetailsPageWidget::ModifyClicked);
    connect(mpw, &ModifyPageWidget::cancelClicked, this, &DetailsPageWidget::Return);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &DetailsPageWidget::Return);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &DetailsPageWidget::ReturnToGrid);
    connect(mpw, &ModifyPageWidget::acceptClicked, this, &DetailsPageWidget::Updateproduct);

    
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteGridProduct);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteProduct);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::ReturnToGrid);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::quitClicked);
    connect(deleteButton, &QPushButton::clicked, this, &DetailsPageWidget::DeleteDetails);
    
    





    qDebug()<<"funziona";
    setLayout(pageLayout);
}

void DetailsPageWidget::ShowDetailsOf(product::Product* product) {
    qDebug()<<"funzione chiamata";
    selected=product;
    details=new QWidget;
    detailsLayout = new QHBoxLayout(details);
    details->setLayout(detailsLayout);
    QLabel* imageLabel = new QLabel;
    QPixmap pix(QString::fromStdString(product->getImage()));
    imageLabel->setPixmap(pix.scaled(400, 400, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    imageLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout* infoLayout = new QVBoxLayout;
    QLabel* name = new QLabel(QString::fromStdString(product->getName()));
    name->setFont(QFont("Arial", 14, QFont::Bold));
    QLabel* price = new QLabel(QString("Prezzo: €%1").arg(product->getPrice(), 0, 'f', 2));
    infoLayout->addWidget(name);
    infoLayout->addWidget(price);

    if (auto vg = dynamic_cast<product::Videogame*>(product)) {
    QLabel* producerLabel = new QLabel("Produttore: " + QString::fromStdString(vg->getProducer()));
    infoLayout->addWidget(producerLabel);

    QStringList compatibilityList;
    for (auto c : vg->getCompatibility()) {
        compatibilityList << QString::fromStdString(ConsoleTypeToString(c));
    }
    QLabel* compatLabel = new QLabel("Compatibilità: " + compatibilityList.join(", "));
    infoLayout->addWidget(compatLabel);

    QStringList genresList;
    for (auto g : vg->getGenres()) {
        genresList << QString::fromStdString(GenreToString(g));
    }
    QLabel* genresLabel = new QLabel("Generi: " + genresList.join(", "));
    infoLayout->addWidget(genresLabel);
}
else if (auto acc = dynamic_cast<product::Accessory*>(product)) {
    QLabel* nameLabel = new QLabel("Nome accessorio: " + QString::fromStdString(acc->getName()));
    infoLayout->addWidget(nameLabel);

    QLabel* dimLabel = new QLabel(QString("Dimensioni (HxLxP): %1 x %2 x %3 cm")
        .arg(acc->getHeight(), 0, 'f', 2)
        .arg(acc->getLenght(), 0, 'f', 2)
        .arg(acc->getDepth(), 0, 'f', 2));
    infoLayout->addWidget(dimLabel);

    QLabel* weightLabel = new QLabel(QString("Peso: %1 kg").arg(acc->getWeight(), 0, 'f', 2));
    infoLayout->addWidget(weightLabel);

    QStringList compatList;
    for (auto c : acc->getCompatibility()) {
        compatList << QString::fromStdString(ConsoleTypeToString(c));
    }
    QLabel* compatLabel = new QLabel("Compatibilità: " + compatList.join(", "));
    infoLayout->addWidget(compatLabel);
}
else if (auto col = dynamic_cast<product::Collectible*>(product)) {
    QLabel* catLabel = new QLabel("Categoria: " + QString::fromStdString(col->GetCategory()));
    infoLayout->addWidget(catLabel);

    QLabel* franLabel = new QLabel("Franchise: " + QString::fromStdString(col->GetFranchise()));
    infoLayout->addWidget(franLabel);

    QLabel* prodLabel = new QLabel("Produttore: " + QString::fromStdString(col->GetProducer()));
    infoLayout->addWidget(prodLabel);
}
else if (auto con = dynamic_cast<product::Console*>(product)) {
    QLabel* serieLabel = new QLabel("Serie console: " + QString::fromStdString(ConsoleTypeToString(con->getSerie())));
    infoLayout->addWidget(serieLabel);

    QLabel* memLabel = new QLabel("Memoria: " + QString::fromStdString(con->getMemory()));
    infoLayout->addWidget(memLabel);
}
else if (auto tshirt = dynamic_cast<product::T_shirt*>(product)) {
    QLabel* franchiseLabel = new QLabel("Franchise: " + QString::fromStdString(tshirt->getFranchise()));
    infoLayout->addWidget(franchiseLabel);

    QLabel* sizeLabel = new QLabel("Taglia: " + QString::fromStdString(SizeToString(tshirt->getSize())));
    infoLayout->addWidget(sizeLabel);

    QLabel* chest = new QLabel(QString("Torace: %1 cm").arg(tshirt->getChestSize()));
    QLabel* waist = new QLabel(QString("Vita: %1 cm").arg(tshirt->getWaistSize()));
    QLabel* hips = new QLabel(QString("Fianchi: %1 cm").arg(tshirt->getHipsSize()));
    QLabel* sleeve = new QLabel(QString("Manica: %1 cm").arg(tshirt->getSleeveLength()));

    infoLayout->addWidget(chest);
    infoLayout->addWidget(waist);
    infoLayout->addWidget(hips);
    infoLayout->addWidget(sleeve);
}

    qDebug()<<"dopo if";
    detailsLayout->addWidget(imageLabel, 2);
    detailsLayout->addLayout(infoLayout, 3);
    pageLayout->addWidget(details, 9);
    qDebug()<<"fine funz";
}

void DetailsPageWidget::DeleteDetails() {
    pageLayout->removeWidget(details);
    delete details;
}

void DetailsPageWidget::ModifyClicked() {
    layout()->removeWidget(details);    // Rimuove la griglia (se presente)
    details->hide();
    layout()->removeWidget(bar);
    bar->hide();

    mpw->ModifyInfoOf(selected);   // Prepara la pagina dettagliata

    layout()->addWidget(mpw);      // Aggiunge la pagina dettagliata
    mpw->show();  
}
void DetailsPageWidget::Return() {
    layout()->removeWidget(mpw);    // Rimuove la griglia (se presente)
    mpw->hide();

    //ShowDetailsOf(selected);   // Prepara la pagina dettagliata

    
    pageLayout->addWidget(bar, 1);      // Aggiunge la pagina dettagliata
    bar->show();
    pageLayout->addWidget(details, 9);      // Aggiunge la pagina dettagliata
    details->show(); 
}

void DetailsPageWidget::Updateproduct() {
    qDebug()<< "dentro update in details";
    DeleteDetails();
    ShowDetailsOf(selected);
}

void DetailsPageWidget::DeleteProduct() {
    memory::Memory& mem=memory::Memory::getCentralMemoryInstance();
    //std::vector<product::Product*> catalog=mem.getCatalog();
    qDebug()<<"prima eliminato";
    mem.Remove(selected->getIdProduct());
    qDebug()<<"prima delete";
    //delete selected;
    qDebug()<<"eliminato";
}