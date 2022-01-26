#include "ContratoTP.h"

int ContratoTP::minutosTP = 300;
float ContratoTP::precioTP = 10;
const float ContratoTP::precioExcesoMinutos = 0.15;

ContratoTP::ContratoTP(long int dni, Fecha f, int m):Contrato(dni, f){
    this-> minutosHablados = m;
}

void ContratoTP::setTarifaPlana( int m, float p) {
    ContratoTP::minutosTP = m;
    ContratoTP::precioTP = p;
}

float ContratoTP::factura() const{
        float f = 0;
        f = ContratoTP::precioTP + ((this->minutosHablados - ContratoTP::minutosTP)*ContratoTP::precioExcesoMinutos);
    return f;
}

void ContratoTP::setMinutosHablados(const int m){
    this->minutosHablados = m;
}

void ContratoTP::ver() const{
    Contrato::ver();
    cout << " " << this->minutosHablados << "m, " << ContratoTP::minutosTP << "(" << ContratoTP::precioTP << ")" << factura();
}

ostream& operator<<(ostream &s, const ContratoTP &c){
    s << (Contrato &)c;
    s << " " << c.getMinutosHablados() << "m, " << c.getLimiteMinutos() << " (" << c.getPrecio() << ") " << "-";
    s << c.factura() << "€";
}

