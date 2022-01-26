#ifndef EMPRESA_H
#define EMPRESA_H
#include "Cliente.h" // definicion clase Cliente
#include "Contrato.h" // definicion de la clase Contrato
#include "ContratoTP.h" // definicion de la clase ContratoTP
#include "ContratoMovil.h" // definicion de la clase ContratoMovil

class Empresa
{
    Cliente *clientes[100];
    Contrato **contratos;
    int ncli, nmaxcli;
    int ncon, nmaxcon;

    int altaCliente(Cliente *c);
    int altaContrato(Contrato *c);
    int buscarCliente(long int dni) const;
    int buscarContrato(int idContrato) const;

    public:
        Empresa();
        virtual ~Empresa();
        void crearContrato();
        bool cancelarContrato(int idContrato); //Cancela un contrato especifico
        int cancelarContratos(long int dni); //Cancela todos los contratos de un cliente

        bool bajaCliente(long int dni); //Da de baja un cliente y elimina todos los contratos

        int descuento(float porcentaje) const;
        int nContratosTP() const;

        void listarClientesContratos() const;
        void listarContratos(long int dni) const;

        void ver() const;
        void cargarDatos();
};

#endif // EMPRESA_H
