#ifndef RESERVATIONDIALOG_H
#define RESERVATIONDIALOG_H

#include <QDateEdit>
#include <QDialog>
#include <QDate>
#include <QComboBox>
#include "chambre.h"
#include "client.h"

class ReservationDialog : public QDialog
{
    Q_OBJECT

public:
    ReservationDialog(const QList<Chambre> &chambreList, QWidget *parent = nullptr);
    ~ReservationDialog();

private slots:
    void acceptReservation();

private:
    QComboBox *roomComboBox;
    QLineEdit *nameLineEdit;
    QLineEdit *surnameLineEdit;
    QLineEdit *contactLineEdit;
    QDateEdit *arrivalDateEdit;
    QDateEdit *departureDateEdit;
    QPushButton *okButton;

    QList<Chambre> chambreList;
};

#endif // RESERVATIONDIALOG_H
