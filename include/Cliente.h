#ifndef CLIENTE_H
#define CLIENTE_H

#include <ostream>

#include "Fecha.h"

using namespace std;

class Cliente
{
    long int dni;
    char *nombre;
    Fecha fechaAlta;

    public:

        Cliente(long int dni, char *nombre, Fecha fechaAlta);
        virtual ~Cliente();
        Cliente& operator=(const Cliente& c);

        long int getDni() const {return this->dni;};
        const char* getNombre() const {return nombre;};
        Fecha getFecha() const {return fechaAlta;};

        void setNombre(char *nom);
        void setFecha(Fecha f);

        bool operator==(Cliente c) const;
};

ostream& operator<<(ostream &s, const Cliente &c);

#endif // CLIENTE_H
