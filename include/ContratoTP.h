#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream>
#include "Fecha.h"
#include "Contrato.h"

using namespace std;

//Para herencias :public:protected:private *NombreClase*
class ContratoTP: public Contrato {
    static int minutosTP;
    static float precioTP;
    int minutosHablados;

    static const float precioExcesoMinutos;

    public:
        ContratoTP(long int dni, Fecha f, int m);

        static int getLimiteMinutos() { return ContratoTP::minutosTP;}
        static float getPrecio() { return ContratoTP::precioTP;}
        int getMinutosHablados() const {return this->minutosHablados;}

        static void setTarifaPlana(int m, float p);
        void setMinutosHablados(const int m);

        float factura() const;
        void ver() const;
        //FALTAN METODOS A AÑADIR
};

ostream& operator<<(ostream &s, const ContratoTP &c);

#endif // CONTRATOTP_H
