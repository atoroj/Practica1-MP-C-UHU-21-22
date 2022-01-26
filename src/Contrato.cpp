#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#include "Contrato.h"

using namespace std;

int Contrato::contador = 1;

Contrato::Contrato(long int dni, Fecha f):idContrato(contador), fechaContrato(f){
    this->dniContrato=dni;
    Contrato::contador++;
}

Contrato::Contrato(const Contrato &c):idContrato(contador), fechaContrato(c.fechaContrato){
    this->dniContrato=c.dniContrato;
    Contrato::contador++;
}

void Contrato::ver() const {
    cout << this->dniContrato << " (" << this->idContrato << " - ";
    this->fechaContrato.ver();
    cout << ")";
}

ostream& operator<<(ostream &s, const Contrato &c) {
    s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << ")";
    return s;
}
