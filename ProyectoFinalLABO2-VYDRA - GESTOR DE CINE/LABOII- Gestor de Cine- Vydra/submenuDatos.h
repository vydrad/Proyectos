#ifndef SUBMENUDATOS_H_INCLUDED
#define SUBMENUDATOS_H_INCLUDED
#include "funcionesGlobales.h"
///void SubMenuDatos();

void SubMenuDatos(){

    datos reg;
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- --- --- -> SUB-MENU REPORTES <--- --- --- --- --- --"<<endl;
        rlutil::locate(4,5);
         cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        ShowTime(" --- --- --- MOSTRAR RECAUDACION POR CADA PELICULA --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MOSTRAR RECAUDACION POR CADA DIRECTOR --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- LA PELICULA CON MAYOR RECAUDACION     --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- EL DIRECTOR CON MAYOR RECAUDACION     --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- SALA CON MAS RECAUDACION              --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- EL TIPO DE SALA CON MAS RECAUDACION   --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- RECAUDACION TOTAL DE '~333~CINEMA~'    --- --- --- ",4,12,y==6);
        ShowTime(" --- --- --- LA PELICULA CON MENOR RECAUDACION     --- --- --- ",4,13,y==7);
        ShowTime(" --- --- --- EL DIRECTOR CON MENOR RECAUDACION     --- --- --- ",4,14,y==8);
        ShowTime(" --- --- --- VOLVER AL MENU PRINCIPAL              --- --- --- ",4,15,y==9);
        rlutil::locate (4,16);
       cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;

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
                if(y>9){
                    y=9;
                }
                break;

            case 1: ///ENTER
                system("cls");
                switch(y+1){
                    case 1:
                        reg.recaudacionpeliculas();
                        break;

                    case 2:
                        reg.recaudaciondirector();
                        break;

                    case 3:
                        reg.peliculamayorVentas();
                        break;

                    case 4:
                        reg.directormayorVentas();
                        break;

                    case 5:
                        reg.salaConMasRecaudacion() ;
                        break;

                    case 6:
                        reg.TiposalaConMasRecaudacion();
                        break;
                    case 7:
                        reg.RecaudacionCine();
                        break;
                    case 8:
                        reg.peliculaMenorVentas();
                        break;
                    case 9:
                        reg.directorMenorVentas();
                        break;
                        case 10:
                            return;
                            break;
                    default:
                        cout<<"--------------------------"<<endl;
                        cout<<"     OPCION INCORRECTA! "<<endl;
                        cout<<"--------------------------"<<endl;
                        return;
                        break;
                }system("pause");
            cout <<endl;
        }


    }while(true);
    return ;
}


#endif // SUBMENUDATOS_H_INCLUDED
