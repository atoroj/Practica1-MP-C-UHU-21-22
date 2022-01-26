#ifndef CONTRATO_H
#define CONTRATO_H
#include <iostream>
#include "Fecha.h"

using namespace std;

class Contrato
{
    static int contador;
    const int idContrato;
    long int dniContrato;
    Fecha fechaContrato;

    public:
        Contrato(long int dni, Fecha f);
        Contrato(const Contrato &c);

        int getIdContrato() const {return this->idContrato;}
        long int getDniContrato() const {return this->dniContrato;}
        Fecha getFechaContrato() const {return this->fechaContrato;}
        void setFechaContrato(Fecha f) {this->fechaContrato=f;}
        void setDniContrato(long int dni) {this->dniContrato=dni;}

        virtual void ver() const;
};

ostream& operator<<(ostream &s, const Contrato &c);

#endif // CONTRATO_H
