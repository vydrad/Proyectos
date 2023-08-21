#ifndef SUBMENUDIRECTORES_H_INCLUDED
#define SUBMENUDIRECTORES_H_INCLUDED
#include "modificarDirectores.h"
#include "funcionesGlobales.h"
///void SubMenuDirector();

void SubMenuDirector(){

    director reg;
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;

    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- ---> SUB-MENU DIRECTORES <--- --- --- --- -"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        ShowTime(" --- --- --- AGREGAR DIRECTOR             --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MOSTRAR DIRECTORES           --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MOSTRAR DIRECTORES POR ID    --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- MODIFICAR DIRECTORES         --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- ELIMINAR DIRECTOR            --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- RECUPERAR DIRECTOR ELIMINADO --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- VOLVER AL MENU PRINCIPAL     --- --- --- ",4,12,y==6);
        rlutil::locate (4,13);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;

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
                if(y>6){
                    y=6;
                }
                break;

            case 1: ///ENTER
                system("cls");
                switch(y+1){
                    case 1:


                        reg.cargar();
                        if(reg.grabarEnDisco()==1){
                            cout<<"--------------------------"<<endl;
                            cout<<"     REGISTRO AGREGADO"<<endl;
                            cout<<"--------------------------"<<endl;
                        }
                        else{
                            cout<<"--------------------------"<<endl;
                            cout<<"    ERROR AL GRABAR"<<endl;
                            cout<<"--------------------------"<<endl;
                        }
                        system("pause");
                        break;

                    case 2:
                        mostrardirectores();
                        system("pause");
                        break;
                    case 3:
                        mostrardirectoresporID();
                        system("pause");
                        break;
                    case 4:
                        modificarDirector();
                        break;

                    case 5:
                        reg.EliminarDeDisco();
                        system("pause");
                        break;
                    case 6:
                        DardealtaDirector();
                        system("pause");
                        break;
                    case 7:
                        return ;
                        break;

                    default:
                        cout<<"-------------------------"<<endl;
                        cout<<"      OPCION INCORRECTA"<<endl;
                        cout<<"--------------------------"<<endl;
                        break;
                }
            cout <<endl;

        }

    }while(true);

    return ;
}

#endif // SUBMENUDIRECTORES_H_INCLUDED
