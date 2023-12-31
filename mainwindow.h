#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "chambre.h"
#include "reservationdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAvailableRooms();
    void makeReservation();

private:
    QListWidget *roomListWidget;
    QList<Chambre> chambreList;
};

#endif // MAINWINDOW_H
