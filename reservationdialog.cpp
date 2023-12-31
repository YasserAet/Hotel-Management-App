#include "reservationdialog.h"
#include "reservation.h"

#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>

ReservationDialog::ReservationDialog(const QList<Chambre> &chambreList, QWidget *parent)
    : QDialog(parent), chambreList(chambreList)
{
    roomComboBox = new QComboBox;
    for (const Chambre &chambre : chambreList) {
        roomComboBox->addItem(QString("Room %1 - %2").arg(chambre.getNumero()).arg(chambre.getType()));
    }

    nameLineEdit = new QLineEdit;
    surnameLineEdit = new QLineEdit;
    contactLineEdit = new QLineEdit;
    arrivalDateEdit = new QDateEdit(QDate::currentDate());
    departureDateEdit = new QDateEdit(QDate::currentDate().addDays(1));
    okButton = new QPushButton("OK");

    connect(okButton, &QPushButton::clicked, this, &ReservationDialog::acceptReservation);

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Room:", roomComboBox);
    layout->addRow("Name:", nameLineEdit);
    layout->addRow("Surname:", surnameLineEdit);
    layout->addRow("Contact:", contactLineEdit);
    layout->addRow("Arrival Date:", arrivalDateEdit);
    layout->addRow("Departure Date:", departureDateEdit);
    layout->addWidget(okButton);

    setLayout(layout);
}

ReservationDialog::~ReservationDialog()
{
}

void ReservationDialog::acceptReservation()
{
    // Validate input and process the reservation
    if (nameLineEdit->text().isEmpty() || surnameLineEdit->text().isEmpty() || contactLineEdit->text().isEmpty()) {
        // Show an error message or handle validation as needed
        return;
    }

    int selectedRoomIndex = roomComboBox->currentIndex();
    if (selectedRoomIndex < 0 || selectedRoomIndex >= chambreList.size()) {
        // Show an error message or handle validation as needed
        return;
    }

    Chambre selectedRoom = chambreList[selectedRoomIndex];
    Client client(nameLineEdit->text(), surnameLineEdit->text(), contactLineEdit->text());
    QDate arrivalDate = arrivalDateEdit->date();
    QDate departureDate = departureDateEdit->date();

    // Create a Reservation object with the entered data
    Reservation reservation(arrivalDate, departureDate, client, selectedRoom);

    // Optionally, emit a signal to inform the main window about the new reservation
    accept();
}
