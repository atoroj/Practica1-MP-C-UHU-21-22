#include <cstring>
#include <cstdio>
#include <string>

#include "Cliente.h"

using namespace std;

Cliente::Cliente(long int d, char *nom, Fecha f):fechaAlta(f) {
    this->dni = d;

    this->nombre = new char[strlen(nom)+1];
    strcpy(this->nombre, nom);
}

Cliente::~Cliente() {
    delete [] this->nombre;
}
//CORREGIR AL HACER EL DELETE
void Cliente::setNombre(char *nom){
    delete [] this->nombre;
    this->nombre = new char [strlen(nom)];
    strcpy(this->nombre, nom);
}

void Cliente::setFecha(Fecha f){
    this->fechaAlta = f;
}

Cliente& Cliente::operator=(const Cliente& c) {
    if (this != &c){
        this->dni = c.dni;
        delete [] this->nombre;
        this->nombre = new char[strlen(c.nombre)+1];
        strcpy(this->nombre, c.nombre);
        this->fechaAlta = c.fechaAlta;
    }
    return *this;
}

bool Cliente::operator==(Cliente c) const {
    if(this->dni!=c.dni) return false;
    if(strcmp(this->nombre,c.nombre) != 0) return false;
    if(this->fechaAlta.getDia() != c.fechaAlta.getDia() ||
        this->fechaAlta.getMes() != c.fechaAlta.getMes() ||
        this->fechaAlta.getAnio() != c.fechaAlta.getAnio()) return false;
    return true;
}

ostream &operator<<(ostream &s, const Cliente &c)
{
    s << c.getNombre() << "  (" << c.getDni() << " - " << c.getFecha() << ")";
    return s;
}

