#include "client.h"

Client::Client(QString nom, QString prenom, QString coordonnees)
    : nom(nom), prenom(prenom), coordonnees(coordonnees)
{
}

QString Client::getNom() const
{
    return nom;
}

QString Client::getPrenom() const
{
    return prenom;
}

QString Client::getCoordonnees() const
{
    return coordonnees;
}
