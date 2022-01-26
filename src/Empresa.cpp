#include <cstring>

#include "Empresa.h"

//el constructor de la clase empresa debe crear un array dinámico de tamaño inicial 10
//debe inicializar a 0 los contadores de clientes (ncli) y contratos (ncon)
//y debe inicializar la constante nmaxcli a 100 y la variable nmaxcon a 10
Empresa::Empresa():nmaxcli(100)
{
    this->ncli=0;
    this->ncon=0;
    this->contratos=new Contrato *[10]; //inicialmente capacidad para 10 Contratos
    this->nmaxcon=10;
}
//el destructor debe, además de eliminar el array dinámico creado en el constructor,
//eliminar los objetos clientes y contratos apuntados por ambos arrays
Empresa::~Empresa()
{
    for(int i=0; i<this->ncon; i++)   //primero elimino los objetos contratos
    {
        delete this->contratos[i];
    }
    delete [] this->contratos; //luego elimino el array de punteros
    for(int i=0; i<this->ncli; i++)   //primero elimino los objetos contratos
    {
        delete this->clientes[i];
    }
//delete [] this->clientes; //ERROR el array clientes no es dinámico
}
void Empresa::cargarDatos()
{
    Fecha f1(29,2,2001), f2(31,1,2002), f3(1,2,2002);
    this->clientes[0] = new Cliente(75547001, "Peter Lee", f1);
    this->clientes[1] = new Cliente(45999000, "Juan Perez", Fecha(29,2,2000));
    this->clientes[2] = new Cliente(37000017, "Luis Bono", f2);
    this->ncli=3;
    this->contratos[0] = new ContratoMovil(75547001, f1, 0.12, 110, "DANES"); //habla 110m a 0.12€/m
    this->contratos[1] = new ContratoMovil(75547001, f2, 0.09, 170, "DANES"); //habla 170m a 0.09€/m
    this->contratos[2] = new ContratoTP(37000017, f3, 250); //habla 250m (300m a 10€, exceso 0.15€/m)
    this->contratos[3] = new ContratoTP(75547001, f1, 312); //habla 312m (300m a 10€, exceso 0.15€/m)
    this->contratos[4] = new ContratoMovil(45999000, f2, 0.10, 202, "ESPAÑOL"); //habla 202m a 0.10/m
    this->contratos[5] = new ContratoMovil(75547001, f2, 0.15, 80, "DANES"); //habla 80m a 0.15€/m
    this->contratos[6] = new ContratoTP(45999000, f3, 400); //habla 400m (300m a 10€, exceso 0.15€/m)
    this->ncon=7;
}
//método auxiliar usado por el método crearContrato
int Empresa::buscarCliente(long int dni) const{
    //si no existe devuelve -1 y si existe
    bool encontrado = false;
    int i = 0;
    while(!encontrado && i<ncli){
        if(this->clientes[i]->getDni() == dni){
            encontrado = true;
        }else{
            i++;
        }
    }
    if(!encontrado){
        return -1;
    }else{
        return i;
    }

}

/*int Empresa::buscarContrato(long int dni) const   //si no existe devuelve -1 y si existe
{
    for(int i = 0; i < this->ncli, i++){
        if(this->clientes[i]->getDni() == dni){
            return i;
        }
    }
    return -1;
}*/

void Empresa::crearContrato()   //EL ALUMNO DEBE TERMINAR DE IMPLEMENTAR ESTE METODO
{
    long int dni;
    int pos;
    cout << "Introduce DNI: ";
    cin >> dni;
        //supongo que hay un metodo buscarCliente(dni) que devuelve -1 si no existe y si
        //existe devuelve la posicion del cliente en el array this->cli
    pos=this->buscarCliente(dni); //OJO ESTE METODO HAY QUE IMPLEMENTARLO
    if (pos==-1)   //el cliente no existe y hay que darlo de alta
    {
        int dia, mes, anio;
        char nombre[100];
        Cliente *c; //NO CREO NINGUN CLIENTE SINO SOLO UN PUNTERO A CLIENTE
        cout << "Introduce Nombre: ";
        cin.ignore();
        cin.getline(nombre, 40); // Para los nombres compuestos
        cout << "Introduce Fecha (dd mm aaaa): ";
        cin >> dia >> mes >> anio;
        c=new Cliente(dni, nombre, Fecha(dia, mes, anio));
        pos=this->altaCliente(c); //OJO HAY QUE IMPLEMENTARLO
    }
            //viendo cuanto vale la variable pos sé si el cliente se ha dado de alta o no
    if (pos!=-1)   //el cliente existe o se ha dado de alta
    {
        int tipo;
        cout << "\nTipo de Contrato a abrir (1-Tarifa Plana, 2-Movil):";
        cin >> tipo;

        if(ncon == nmaxcon){
                //Incremento nmaxcon si ncon es mas grande
                Contrato **aux = new Contrato* [nmaxcon*2];
                if(aux!=NULL){
                    nmaxcon *= 2; //nmaxcon = nmaxcon * 2
                    for(int j=0; j<nmaxcon; j++){
                        aux[j] = contratos[j];
                    }

                    for(int i=0; i<this->ncon; i++){
                        delete this->contratos[i];
                    }
                    delete [] this->contratos;
                    contratos = aux;
                }
            }
        if(tipo == 2){
                int minutoshablados, dia, mes, anio;
                float preciominuto;
                char* nacionalidad = new char [20];
                char* nac = new char [20];

                cout << "\n----------Ha elegido un contrato movil------------- ";
                cout << "\nFecha del contrato";
                cout << "\ndia: "; cin >> dia; cout << " mes: "; cin >> mes; cout << " anio:"; cin >> anio;
                cout << "\nMinutos Hablados: "; cin >> minutoshablados;
                cout << "\nPrecio por minuto: "; cin >> preciominuto;
                cout << "\nNacionalidad: "; cin>>nac;

                delete [] nacionalidad;
                nacionalidad = new char [strlen(nac + 1)];
                strcpy(nacionalidad, nac);
                delete [] nac;

                Fecha f(dia, mes, anio);

                Contrato *c = new ContratoMovil(clientes[pos]->getDni(), f, preciominuto, minutoshablados, nacionalidad);

                contratos[ncon] = c;
                ncon++;
                cout << "CONTRATO CREADO" << endl;

            }else if(tipo == 1){
                int minutosHablados, dia, mes, anio;
                cout << "\n----------Ha elegido un contrato de tarifa plana------------- ";
                cout << "\nFecha del contrato";
                cout << "\ndia: "; cin >> dia; cout << " mes: "; cin >> mes; cout << " anio:"; cin >> anio;
                cout << "\nMinutos Hablados: "; cin >> minutosHablados;

                Fecha f(dia, mes, anio);

                Contrato *c = new ContratoTP(clientes[pos]->getDni(), f, minutosHablados);

                contratos[ncon] = c;
                ncon++;
                cout << "CONTRATO CREADO" << endl;

            }else{
                system("cls");
                cout << "LETRA INCORRECTA. POR FAVOR, ELIGA UNA DE LAS DOS PROPUESTAS (A o B)";
            }
    }
}

int Empresa::altaCliente(Cliente *c){
    int pos=-1;
    if(this->ncli<this->nmaxcli){
        this->clientes[ncli]=c;
        pos = this->ncli;
        this->ncli++;
    }else{
        cout << "El numero de clientes es mayor al aceptado" << endl;
    }
    return pos;
}

int Empresa::altaContrato(Contrato *c){
    if(this->ncon>=this->nmaxcon){
        Contrato **aux=this->contratos;
        nmaxcon*=2; // duplico tamaño
        //FALTAN COSAS
    }
}

int Empresa::descuento(float porcentaje) const {
    int ncm=0;
    for(int i = 0; i<this->ncon; i++){
        if(ContratoMovil *cm = dynamic_cast<ContratoMovil *>(this->contratos[i])){
            cm -> setPrecioMinuto(cm->getPrecioMinuto()*(1-porcentaje/100));
            ncm++;
        }
    }
    return ncm;
}

int Empresa::nContratosTP() const {
    int nca=0;
    for(int i=0; i<this->ncon; i++){
        if(typeid(*this->contratos[i])==typeid(ContratoTP)){
            nca++;
        }
    }
    return nca;
}
bool Empresa::cancelarContrato(int idContrato){
    bool encontrado = false;
    int i = 0;
    while( i < this->ncon && !encontrado){
        if(contratos[i]->getIdContrato() == idContrato){
            encontrado = true;
        }else{
            i++;
        }
    }
    if(encontrado == true){
        Contrato* aux = contratos[i];
        while(i<ncon-1){
            contratos[i] = contratos[i+1];
            i++;
        }
        delete aux;
        ncon--;
    }
    return encontrado;
}

bool Empresa::bajaCliente(long int dni){
    bool encontrado = false;
    int pos = buscarCliente(dni);

    if(pos!=-1){
        Cliente* aux = clientes[pos];
        while(pos<this->ncli){
            clientes[pos] = clientes[pos+1];
            pos++;
        }
        delete aux;
        ncli--;
        cancelarContratos(dni);
        encontrado = true;
    }

    return encontrado;
}

int Empresa::cancelarContratos(long int dni){
    for(int i = 0; i<this->ncon; i++){
        if(contratos[i]->getDniContrato()==dni){
            cancelarContrato(contratos[i]->getIdContrato());
            i--;
        }
    }
}

void Empresa::ver() const{
    cout << "\nLa Empresa tiene " << this->ncli << " clientes y " << this->ncon << " " << endl;
    cout << "\nClientes: \n";
    for(int i = 0; i<this->ncli; i++){
        cout << *this->clientes[i] << endl;
    }
    cout << "\nContratos: \n";
    for(int i = 0; i<this->ncon; i++){
        if(typeid(*this->contratos[i])==typeid(ContratoTP)){
            cout << *(ContratoTP *)this->contratos[i] << endl;
        }else{
            ContratoMovil *cm=(ContratoMovil *)this->contratos[i];
            cout << *cm << endl;
        }
    }
}
