#include "chambre.h"

Chambre::Chambre(int numero, QString type, int capacite, double tarif)
    : numero(numero), type(type), capacite(capacite), tarif(tarif)
{
}

int Chambre::getNumero() const
{
    return numero;
}

QString Chambre::getType() const
{
    return type;
}

int Chambre::getCapacite() const
{
    return capacite;
}

double Chambre::getTarif() const
{
    return tarif;
}
