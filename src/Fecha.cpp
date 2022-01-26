#include <iostream>

#include "Fecha.h"

using namespace std;

Fecha::Fecha(const int &dia, const int mes, const int &anio){
    this->setFecha(dia, mes, anio);
}

void Fecha::setFecha(const int &dia, const int &mes, const int &anio){
    int diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30 ,31 ,30 ,31};

    //Asignacion año
    this->anio=anio;

    //Saber si es bisiesto
    if (this->bisiesto()){
        diaMes[2]=29;
    }

    //Asignacion mes
    if (mes < 1){
            this->mes=1;
        }else if (mes > 12){
            this->mes=12;
    }else{
        this->mes = mes;
    }

    //Asignacion dia
    if (dia < 1){
            this->dia=1;
        }else if (dia > diaMes[this->mes]){
            this->dia= diaMes[this->mes];
    }else{
        this->dia = dia;
    }
}

bool Fecha::bisiesto() const{
    if (this->anio%4==0 && this->anio%100!=0 || this->anio%400==0){
        return true;
    }else{
        return false;
    }
}
//Sumar 1 dia
Fecha Fecha::operator++(){ //++f
    int dmax, diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30 ,31 ,30 ,31};

    if (this->bisiesto()){
        diaMes[2]=29;
    }

    dmax=diaMes[this->mes];

    this->dia++;

    if(this->dia > dmax){
        this->dia = 1;
        this->mes++;
        if(this->mes>12){
            this->mes = 1;
            this->anio++;
        }
    }
    return *this;
}

Fecha Fecha::operator++(int i){//f++
    int diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30 ,31 ,30 ,31};
    Fecha F(dia, mes, anio);
    this-> dia++;

    if(bisiesto()){
        diaMes[2] = 29;
    }

    if(this-> dia > diaMes[mes]){
        this->dia = 1;
        this->mes++;

        if(this->mes==13){
            this->mes=1;
            this->anio++;
        }
    }
    return F;
}

Fecha Fecha::operator+(const int &i) {
    Fecha sumaFecha(0,0,0);
    bool salida = false;
    int diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30 ,31 ,30 ,31};

    sumaFecha.dia = this->dia + i;

    if(bisiesto()){
        diaMes[2] = 29;
    }
    while(!salida){
        if(sumaFecha.dia > diaMes[this->mes]){
            sumaFecha.dia = sumaFecha.dia - diaMes[this->mes];
            this->mes++;
            if(this->mes==13){
                this->mes=1;
                this->anio++;
            }
        }else{
            salida = true;
        }
    }

    sumaFecha.mes = this->mes;
    sumaFecha.anio = this->anio;

    return sumaFecha;
}

Fecha operator+(const int &i, const Fecha &f){
    Fecha sumaFecha(0,0,0);
    bool salida= false;
    int diaMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31 ,30 ,31 ,30 ,31};

    sumaFecha.dia = f.dia + i;

    if(f.bisiesto())
        diaMes[2] = 29;

    while(!salida)
    {
        if(sumaFecha.dia > diaMes[f.mes])
        {
            sumaFecha.dia = sumaFecha.dia - diaMes[f.mes];
            sumaFecha.mes = f.mes+1;

            if(f.mes==13)
                {
                    sumaFecha.mes = 1;
                    sumaFecha.anio = f.anio+1;
                }
        }else
        {
            salida = true;
        }
    }

    sumaFecha.anio = f.anio;

    return sumaFecha;
}

void Fecha::ver() const {
    cout << this->dia << "/" << this->mes << "/" << this->anio;
}

ostream &operator<<(ostream &s, const Fecha &f)
{
    char *meses[][1] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};
    s << f.getDia() << " " << *meses[f.getMes()-1] << " " << f.getAnio();
    return s;
}
