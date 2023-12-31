#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDate>
#include "chambre.h"
#include "client.h"

class Reservation
{
public:
    Reservation(QDate dateArrivee, QDate dateDepart, Client client, Chambre chambre);

    QDate getDateArrivee() const;
    QDate getDateDepart() const;
    Client getClient() const;
    Chambre getChambre() const;

private:
    QDate dateArrivee;
    QDate dateDepart;
    Client client;
    Chambre chambre;
};

#endif // RESERVATION_H
