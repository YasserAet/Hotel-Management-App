#ifndef CLIENT_H
#define CLIENT_H

#include <QString>

class Client
{
public:
    Client(QString nom, QString prenom, QString coordonnees);

    QString getNom() const;
    QString getPrenom() const;
    QString getCoordonnees() const;

private:
    QString nom;
    QString prenom;
    QString coordonnees;
};

#endif // CLIENT_H
