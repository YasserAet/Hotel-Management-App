#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    roomListWidget = new QListWidget(this);

    QPushButton *availableRoomsButton = new QPushButton("Available Rooms");
    QPushButton *reserveRoomButton = new QPushButton("Make Reservation");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(availableRoomsButton);
    layout->addWidget(reserveRoomButton);
    layout->addWidget(roomListWidget);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(availableRoomsButton, &QPushButton::clicked, this, &MainWindow::showAvailableRooms);
    connect(reserveRoomButton, &QPushButton::clicked, this, &MainWindow::makeReservation);

    // Add some sample rooms
    chambreList.append(Chambre(101, "Single", 1, 100.0));
    chambreList.append(Chambre(102, "Double", 2, 150.0));
    chambreList.append(Chambre(103, "Suite", 4, 250.0));
}

MainWindow::~MainWindow()
{
}

void MainWindow::showAvailableRooms()
{
    roomListWidget->clear();
    for (const Chambre &chambre : chambreList) {
        roomListWidget->addItem(QString("Room %1: %2 - Capacity: %3 - Tariff: %4")
                                    .arg(chambre.getNumero())
                                    .arg(chambre.getType())
                                    .arg(chambre.getCapacite())
                                    .arg(chambre.getTarif()));
    }
}

void MainWindow::makeReservation()
{
    ReservationDialog dialog(chambreList, this);
    if (dialog.exec() == QDialog::Accepted) {
        // Process the reservation
        // You can add the logic to store the reservation details here
    }
}
