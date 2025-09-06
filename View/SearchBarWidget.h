#ifndef SEARCHBARWIDGET_H
#define SEARCHBARWIDGET_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
class SearchBarWidget:public QWidget {
    private:
    QHBoxLayout* searchLayout;
    QLineEdit* searchBar;
    public:
    SearchBarWidget(QWidget* = nullptr);    
};
#endif