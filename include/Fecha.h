#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
    public:
        Fecha(const int &dia, const int mes, const int &anio);
        int getDia() const {return this->dia;}
        int getMes() const {return this->mes;}
        int getAnio() const {return this->anio;}

        void setFecha(const int &dia, const int &mes, const int &anio);
        void ver() const;
        bool bisiesto() const;

        Fecha operator++(); //+ff
        Fecha operator++(int i); //f++
        Fecha operator+(const int &i);//Sumar i dias a una fecha

        friend Fecha operator+(const int &i, const Fecha &f);

    private:
        int dia;
        int mes;
        int anio;
};

ostream &operator<<(ostream &s, const Fecha &f);
#endif // FECHA_H
