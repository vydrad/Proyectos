#ifndef SUBMENUSALAS_H_INCLUDED
#define SUBMENUSALAS_H_INCLUDED

#include "modificarSalas.h"
#include "funcionesGlobales.h"
///void SubMenuSalas();

void SubMenuSalas(){
    Salas aux;
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- --- -> SUB-MENU SALAS <- --- --- --- ---"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        ShowTime(" --- --- --- AGREGAR SALA             --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MOSTRAR SALAS            --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MOSTRAR SALAS POR ID     --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- MODIFICAR SALAS          --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- ELIMINAR SALA            --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- RECUPERAR SALA ELIMINADA --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- VOLVER AL MENU PRINCIPAL --- --- --- ",4,12,y==6);
        rlutil::locate (4,13);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;

        switch(rlutil::getkey()){
            case 14: ///UP
                rlutil::locate(2,6+y);
                std::cout<<"  "<<std::endl;
                y--;
                if(y<0){
                y=0;}
                    break;

            case 15: ///DOWN
                rlutil::locate(2,6+y);
                std::cout<<"  "<<std::endl;
                y++;
                if(y>6){
                y=6;}
                break;

            case 1: ///ENTER
                system("cls");
                switch(y+1){
                    case 1:
                        aux.cargar();
                        if(aux.grabarEnDisco()==1){
                            cout<<"-------------------------"<<endl;
                            cout<<"REGISTRO AGREAGADO! "<<endl;
                            cout<<"-------------------------"<<endl;
                        }
                        else{
                            cout<<"----------------------"<<endl;
                            cout<<"ERROR AL GRABAR! "<<endl;
                            cout<<"----------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 2:
                        mostrarDeDiscoSALA();
                        system("pause");
                        break;
                    case 3:
                        mostrarsalasporID();
                        system("pause");
                        break;
                    case 4:
                        modificarSalas();
                        break;
                    case 5:
                        aux.EliminarDeDisco();
                        system("pause");
                        break;
                    case 6:
                        DardealtaSala();
                        system("pause");
                        break;
                    case 7:
                        return ;
                        break;
                    default:
                        cout<<"---------------------"<<endl;
                        cout<<"OPCION INCORRECTA! "<<endl;
                        cout<<"---------------------"<<endl;
                        break;
                }
        cout <<endl;
    }
}while (true);

return;

}
#endif // SUBMENUSALAS_H_INCLUDED
