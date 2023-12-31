#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <QString>

class Chambre
{
public:
    Chambre(int numero, QString type, int capacite, double tarif);

    int getNumero() const;
    QString getType() const;
    int getCapacite() const;
    double getTarif() const;

private:
    int numero;
    QString type;
    int capacite;
    double tarif;
};

#endif // CHAMBRE_H
