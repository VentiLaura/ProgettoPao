#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>

class SortWidget: public QWidget{
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