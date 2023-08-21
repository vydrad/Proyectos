#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <time.h>
#include <ctime>
#include "FuncionesG.h"
#include "rlutil.h"


/// Nombre: David Thomas
/// Apellido: Vydra
/// Legajo: 26191
/// Tema: Trabajo Practico Integrador -Juego- "La Generala".



int main(){

rlutil::setBackgroundColor(rlutil::BLACK);
int  y=0;
bool a=true;
int  puntajemax1p=0,puntajemax2p=0;
char puntajemaximo1p[30]= "aaaaaaaaaaaaaa";
char puntajemaximo2p[30]= "aaaaaaaaaaaaaa";


do {


    rlutil::setColor(rlutil::WHITE);
    rlutil::hidecursor();

    rlutil::locate(4,2);
    std::cout << "--------------------********------------------------"<<std::endl;
    rlutil::locate(4,3);
    std::cout << "---------------------*MENU*-------------------------"<<std::endl;
    rlutil::locate(4,4);
    ShowTime("----------------*MODO 1 JUGADOR*--------------------",4,4,y==0);
    ShowTime("---------------*MODO 2 JUGADORES*-------------------",4,5,y==1);
    ShowTime("---------*PUNTAJES MAS ALTOS MODO 1P/2P*------------",4,6,y==2);
    ShowTime("--------------------*SALIR*-------------------------",4,7,y==3);

    rlutil::locate(4,8);
    std::cout << "----------------------***---------------------------"<<std::endl;

    rlutil::locate(4,14);
    std::cout << (char)60<<std::endl; ///IZQ
    rlutil::locate(8,14);
    std::cout << (char)62<<" para mover el cursor"<<std::endl; ///DER
    rlutil::locate(6,13);
    std::cout << (char)94<<std::endl;///UP
    rlutil::locate(6,14);
    std::cout << (char)118<<std::endl; ///DOWN

    rlutil::locate(33,14);
    std::cout << (char)254<<(char)254<<" ENTER para selecccionar"<<std::endl;






        switch(rlutil::getkey()){


            case 14: ///UP
                rlutil::locate(2,4+y);
                std::cout<<"  "<<std::endl;
                y--;
                if(y<0){
                y=0;}
                    break;

            case 15: ///DOWN
                rlutil::locate(2,4+y);
                std::cout<<"  "<<std::endl;
                y++;
                if(y>3){
                y=3;}
                break;

            case 1: ///ENTER

                switch (y){

                    case 0:
                        oneplayer(puntajemaximo1p,puntajemax1p);

                        system("cls");
                        ///std::cout<<"name"<<puntajemaximo1p<<" puntaje:"<<puntajemax1p<<std::endl;    ///1 jugador
                        break;

                    case 1:
                        twoplayers(puntajemaximo2p,puntajemax2p);

                        system("cls");
                        cin.ignore();   ///2 jugadores
                            break;

                    case 2:

                        rlutil::setColor(rlutil::YELLOW);
                        system("cls");

                        rlutil::locate(4,3);
                        cout<<"******************************************************************************************"<<endl;
                        rlutil::locate(4,4);
                        cout<<"*******************************SALA DE RECORDS********************************************"<<endl;
                        rlutil::locate(4,5);
                        cout<<"******************************************************************************************"<<endl;
                        rlutil::locate(4,6);
                        std::cout << "EL RECORD EN MODO 1 JUGADOR ES: "<< puntajemaximo1p<< " con " <<puntajemax1p<<" pts."<<std::endl;
                        rlutil::locate(4,7);
                        std::cout << "------------------------------------------------------------------------------"<<std::endl;
                        rlutil::locate(4,8);
                        std::cout << "EL RECORD EN MODO 2 JUGADORES ES: "<<puntajemaximo2p<<" con " <<puntajemax2p<<" pts."<<std::endl;
                        rlutil::locate(4,9);
                        cout<<"******************************************************************************************"<<endl;

                        system("pause");
                        system("cls");
                            break;
                    case 3:

                        return a=false;
                            break;
                }
        }
} while(a==true);

}

///DAVID THOMAS VYDRA
