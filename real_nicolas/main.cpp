#include <iostream>
#include <string.h>
using namespace std;
#include "clases_p.h"



class puntoA
{

private:
    int _codigoRestaurante;
    char _nombreRes[30];
    int _cantidadDeReservas;

public:
    int leerDeDisco(int pos)
    {
        FILE *p;
        p=fopen("restaurantesNuevo.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, sizeof(puntoA)*pos,0);
        int leyo=fread(this, sizeof *this,1, p);
        fclose(p);
        return leyo;
    }

    void setCodigo(int codigo)
    {
        _codigoRestaurante = codigo;

    }

    void setNombreRestaurante(const char *nombreRestaurante)
    {
        strcpy(_nombreRes,nombreRestaurante);

    }

    void setCantidadDeReservas(int  cantidadDeReservas)
    {
        _cantidadDeReservas = cantidadDeReservas;


    }

    int  getCodigo()
    {
        return _codigoRestaurante;

    }

    int grabarEnDisco()
    {
        FILE *p;
        p=fopen("restaurantesNuevo.dat", "ab");
        if(p==NULL) return -1;
        int grabo=fwrite(this, sizeof *this,1, p);
        fclose(p);
        return grabo;
    }


    void mostrar()
    {
        cout << _codigoRestaurante << endl;

        cout << _nombreRes[0]<< endl ;


        cout << _cantidadDeReservas << endl;




    }







};



/*
Dado un nombre de restaurante que se ingresa por teclado, generar un archivo con las reservas de ese restaurante.

Cada registro debe tener el siguiente formato:

Código de restaurante, nombre de restaurante y cantidad de reservas.


*/


void PrimerEjercicioNuevo()
{

    puntoA puntoA;
    Reserva reserva;
    Restaurante restaurante;
    int codigoDeRestaurante;
    char nombreDeRestaurante[30];
    int cantidadDeReservas = 0;
    int i = 0;
    int j = 0;
    cout << "ingrese nombre del restaurante :" << endl;
    cin >> nombreDeRestaurante;

    while (restaurante.leerDeDisco(i) == 1)
    {
        if ( strcmp( nombreDeRestaurante, restaurante.getNombre() ) == 0  )
        {

          cout <<"encotre restaurante" << endl;
            puntoA.setCodigo(restaurante.getCodigoRestaurante() ) ;
            puntoA.setNombreRestaurante(  restaurante.getNombre() );


        }

        i++;
    }
    while (reserva.leerDeDisco(j) == 1 )
    {


        if ( reserva.getCodigoRestaurante() == puntoA.getCodigo()  )
        {

            cantidadDeReservas++;
        }



        j++;
    }
    puntoA.setCantidadDeReservas(cantidadDeReservas);


    puntoA.grabarEnDisco();
    puntoA.leerDeDisco(0);
    puntoA.mostrar();



}



































void primerEjercicio()
{
    char nombreRestaurante[30];
    puntoA puntoA;
    Restaurante res;
    Reserva reserva;
    int cantidadDeReservas = 0;



    cout <<"ingrese nombre del restaurante"<< endl;
    cin >> nombreRestaurante;
    int i = 0;
    while ( res.leerDeDisco(i) == 1 )
    {

        if ( strcmp(nombreRestaurante, res.getNombre()) == 0)
        {

            puntoA.setCodigo (res.getCodigoRestaurante());
            puntoA.setNombreRestaurante (res.getNombre());


        }

        i++;
    }

    i = 0;
    while (   reserva.leerDeDisco(i) == 1)
    {

        if ( reserva.getCodigoRestaurante() == puntoA.getCodigo())
        {
            cantidadDeReservas++;
        }
        i++;
    }

    puntoA.setCantidadDeReservas(cantidadDeReservas);
    puntoA.grabarEnDisco();
    puntoA.leerDeDisco(0);
    puntoA.mostrar();
}


//Informar las provincias que no tengan restaurantes de la categoría 1.
void segundoEjercicio()
{
    Restaurante res;
    int i = 0;
    int flag;
    for (int x = 0; x< 24; x++)
    {
        flag = 1;
        i = 0;

        while (res.leerDeDisco(i) == 1)
        {
            if (   res.getProvincia() == x + 1  &&   res.getCategoriaRestaurante() != 1 && flag == 1 )
            {
                cout << "la provincia " << x + 1 << " no tiene categoria 1" << endl;
                flag = 0;

            }

            i++;
        }


    }

}

int main()
{


    Restaurante res;


    PrimerEjercicioNuevo();



    return 0;
}








/*
class Triangulo : public figuraGeometrica
{
private:
float _base;
float _altura;


public:
int getBase(){
return _base;
}

int getAltura(){
return _altura;
}

void setBase( float base){
_base = base;

}

void setAltura(float altura){
_altura = altura;
}

};
*/


