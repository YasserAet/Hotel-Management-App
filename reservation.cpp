#include "reservation.h"

Reservation::Reservation(QDate dateArrivee, QDate dateDepart, Client client, Chambre chambre)
    : dateArrivee(dateArrivee), dateDepart(dateDepart), client(client), chambre(chambre)
{
}

QDate Reservation::getDateArrivee() const
{
    return dateArrivee;
}

QDate Reservation::getDateDepart() const
{
    return dateDepart;
}

Client Reservation::getClient() const
{
    return client;
}

Chambre Reservation::getChambre() const
{
    return chambre;
}
