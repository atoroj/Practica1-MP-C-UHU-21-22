#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#include "Contrato.h"
#include "ContratoMovil.h"

using namespace std;

ContratoMovil::ContratoMovil(long int dni, Fecha f, float precio, int minuto, char *nac):Contrato(dni,f){
    this->precioMinuto = precio;
    this->minutosHablados = minuto;
    this->nacionalidad=new char [strlen(nac)+1];
    strcpy(this->nacionalidad, nac);
}

ContratoMovil::~ContratoMovil(){
    delete [] nacionalidad;
    //Borrar espacio de memoria reservado para nac (nacionalidad) delete
}

ContratoMovil::ContratoMovil(const ContratoMovil &c):Contrato(c.getDniContrato(), c.getFechaContrato()){
    this-> precioMinuto = c.precioMinuto;
    this-> minutosHablados = c.minutosHablados;
    this-> nacionalidad = new char [strlen(c.nacionalidad)+1];
    strcpy(this->nacionalidad, c.nacionalidad);
}

void ContratoMovil::ver() const {
    Contrato::ver();
    cout << " " << this->minutosHablados << "m, " << this->nacionalidad << " " << this->precioMinuto;
}

float ContratoMovil::factura() const{
        float factura = 0;
        factura = precioMinuto * minutosHablados;
    return factura;
}
void ContratoMovil::setNacionalidad(char *nac){
    delete [] nacionalidad;
    this -> nacionalidad = new char [strlen(nac)];
    strcpy(nacionalidad, nac);
}
//Set nacionalidad y tema de facturas para casita

ostream& operator<<(ostream &s, const ContratoMovil &c){
    s << (Contrato &)c; //Convierto c en Contrato, dps muestro solo lo que es del hijo
    s << " " << c.getMinutosHablados() << "m, " << c.getNacionalidad() << " " << c.getPrecioMinuto() << "-";
    s << c.factura() << "€";
    return s;
}
