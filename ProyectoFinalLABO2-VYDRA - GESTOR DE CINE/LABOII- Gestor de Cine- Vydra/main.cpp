#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <windows.h>

using namespace std;

#include "rlutil.h"
#include "protoFunciones.h"
#include "fecha.h"
#include "directores.h"
#include "salas.h"
#include "peliculas.h"
#include "peliculasSalas.h"
#include "ventas.h"
#include "Datos.h"
#include "submenuSalas.h"
#include "submenuPeliculas.h"
#include "submenuDirectores.h"
#include "submenuPeliculasSala.h"
#include "submenuVentas.h"
#include "submenuDatos.h"
#include "submenuConfiguracion.h"
#include "funcionesGlobales.h"
#include "modificarDirectores.h"
#include "modificarSalas.h"
#include "modificarPeliculas.h"
#include "modificarVentas.h"

//Materia: Laboratorio II
//Alumno: David Thomas Vydra
//Legajo: 26191

int main(){

    director obj;
    ventas lol;
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;

    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- --->>> MENU PRINCIPAL <<<--- --- --- --"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        ShowTime(" --- --- --- MENU DIRECTORES          --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MENU SALAS               --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MENU PELICULAS           --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- MENU PELICULAS POR SALA  --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- MENU VENTAS ENTRADAS     --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- MENU REPORTES            --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- MENU CONFIGURACION       --- --- --- ",4,12,y==6);
        ShowTime(" --- --- --- SALIR DEL PROGRAMA       --- --- --- ",4,13,y==7);
        rlutil::locate (4,14);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;

        rlutil::locate(4,18);
        std::cout << (char)60<<std::endl; ///IZQ
        rlutil::locate(8,18);
        std::cout << (char)62<<" para mover el cursor"<<std::endl; ///DER
        rlutil::locate(6,17);
        std::cout << (char)94<<std::endl;///UP
        rlutil::locate(6,18);
        std::cout << (char)118<<std::endl; ///DOWN

        rlutil::locate(33,18);
        std::cout << (char)254<<(char)254<<" ENTER para selecccionar"<<std::endl;


        switch(rlutil::getkey()){
            case 14: ///UP
                rlutil::locate(2,6+y);
                std::cout<<"  "<<std::endl;
                y--;
                if(y<0){
                    y=0;
                }
                break;

            case 15: ///DOWN
                rlutil::locate(2,6+y);
                std::cout<<"  "<<std::endl;
                y++;
                if(y>7){
                    y=7;
                }
                break;

            case 1: ///ENTER
                system("cls");
                switch(y+1){
                    case 1:
                        SubMenuDirector();
                        break;
                    case 2:
                        SubMenuSalas();
                        break;
                    case 3:
                        SubMenuPeliculas();
                        break;
                    case 4:
                        SubMenuPeliculasSalas();
                        break;
                    case 5:
                        SubMenuVentas();
                        break;
                    case 6:
                        SubMenuDatos();
                        break;
                    case 7:
                        SubmenuConfiguracion();
                        break;
                    case 8:
                         rlutil::setColor(rlutil::YELLOW);
                        system("cls");

                        rlutil::locate(4,3);
                        cout<<"**************************************************************************"<<endl;
                        rlutil::locate(4,4);
                        cout<<"*********************         LABORATORIO II          ********************"<<endl;
                        rlutil::locate(4,5);
                        cout<<"*********************    PROYECTO: GESTOR DE CINE     ********************"<<endl;
                        rlutil::locate(4,6);
                        cout<<"**************************************************************************"<<endl;
                        rlutil::locate(4,7);
                        std::cout <<"*******       PROFESOR: DANIEL KLOSTER                             *******"<<std::endl;
                        rlutil::locate(4,8);
                        std::cout <<"*******       PROFESOR AYUDANTE: MAXIMILIANO WENNER                *******"<<std::endl;
                        rlutil::locate(4,9);
                        std::cout <<"*******       ALUMNO: DAVID THOMAS VYDRA                           *******"<<std::endl;
                        rlutil::locate(4,10);
                        std::cout <<"*******       LEGAJO: 26191                                        *******"<<std::endl;
                        rlutil::locate(4,11);
                        std::cout <<"*******               QUE TENGAN UNA BUENA JORNADA!!!              *******"<<std::endl;
                        rlutil::locate(4,12);
                        cout<<"**************************************************************************"<<endl;

                        system("pause");
                        system("cls");
                        return 0;
                        break;
                    default:
                        cout<<"OPCION INCORRECTA"<<endl;
                    break;
                }
            cout <<endl;

        }

    }///FIN DEL WHILE
    while(true);
    return 0;
}

