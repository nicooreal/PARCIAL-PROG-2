#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

using namespace std;
#include <iostream>
#include <string.h>




class Fecha{
    private:
        int dia, mes, anio;
    public:
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
        void Cargar(){}
        void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
};



class Restaurante{
    private:
        int codigoRestaurante;
        char nombre[30];
        int provincia;
        char nombreGerente[30];
        int categoriaRestaurante;
        bool estado;
    public:
        int getCodigoRestaurante(){return codigoRestaurante;}
        const char *getNombre(){return nombre;}
        int getProvincia(){return provincia;}
        const char *getNombreGerente(){return nombreGerente;}
        int getCategoriaRestaurante(){return categoriaRestaurante;}
        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("restaurantes.dat","rb");
            if(p==NULL) return false;
            fseek(p,pos*sizeof *this, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
        bool grabarEnDisco(){return true;}
        void Cargar(){}
        void Mostrar(){
            cout<<"CODIGO: "<<codigoRestaurante<<endl;
            cout<<"NOMBRE: "<<nombre<<endl;
            cout<<"PROVINCIA: "<<provincia<<endl;
            cout<<"GERENTE: "<<nombreGerente<<endl;
            cout<<"CATEGORIA: "<<categoriaRestaurante<<endl;
        }
};

class Reserva{
    private:
        int codigoRestaurante;
        int DNI;
        Fecha fechaReserva;
        int hora;
        bool estado;

    public:
        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("reservas.dat","rb");
            if(p==NULL) return false;
            fseek(p,pos*sizeof *this, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
        int getCodigoRestaurante(){return codigoRestaurante;}
        int getDNI(){return DNI;}
        Fecha getFechaReserva(){return fechaReserva;}
        int getHora(){return hora;}
        bool grabarEnDisco(){}
        void Cargar(){}
        void Mostrar(){
        cout<<"CODIGO: "<<codigoRestaurante<<endl;
        cout<<"DNI: "<<DNI<<endl;
        fechaReserva.Mostrar();
        cout<<"HORA: "<<hora<<endl;
        }
};

class Cliente{
   private:
        int DNI;
        char nombre [30];
        int medioPago, tipoCliente, edad;
        bool estado;
    public:
        ///gets() y sets()
        int getDNI(){return DNI;}
        const char *getNombre(){return nombre;}
        int getMedioPago(){return medioPago;}
        int getTipoCliente(){return tipoCliente;}
        int getEdad(){return edad;}
        bool grabarEnDisco(){return true;}
        void Cargar(){}
        void Mostrar(){
        cout<<"DNI: "<<DNI<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"MEDIO DE PAGO: "<<medioPago<<endl;
        cout<<"TIPO DE CLIENTE: "<<tipoCliente<<endl;
        cout<<"EDAD: "<<edad<<endl;
        }
        bool leerDeDisco(int pos){
            FILE *p;
            p=fopen("clientes.dat","rb");
            if(p==NULL) return false;
            fseek(p,pos*sizeof *this, 0);
            bool leyo=fread(this, sizeof *this, 1, p);
            fclose(p);
            return leyo;
        }
};



#endif // CLASES_H_INCLUDED
