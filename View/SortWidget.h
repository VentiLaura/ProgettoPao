#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>

class SortWidget: public QWidget{
    Q_OBJECT
    public:
        SortWidget(QWidget *parent = nullptr);
    private:
        QLabel *sort;
        QComboBox* sortMenu;
    private slots:
        void onSortChanged(const QString&);   
    signals:
        void SortChanged(const QString& sortChosen);
};

#endif