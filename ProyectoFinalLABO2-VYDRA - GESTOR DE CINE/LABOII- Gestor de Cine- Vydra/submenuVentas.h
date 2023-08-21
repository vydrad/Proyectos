#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

#include "modificarVentas.h"
///void SubMenuVentas();

void SubMenuVentas(){

    ventas lol;
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- -- --> SUB-MENU VENTAS <-- --- --- --- --- -"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;
        ShowTime(" --- --- --- AGREGAR VENTA               --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MOSTRAR VENTAS              --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MOSTRAR VENTAS POR ID       --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- MODIFICAR VENTAS            --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- ELIMINAR VENTAS             --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- RECUPERAR VENTAS ELIMINADAS --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- VOLVER AL MENU PRINCIPAL    --- --- --- ",4,12,y==6);
        rlutil::locate (4,13);
       cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;

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
                    case 1: lol.cargar();
                        if(lol.grabarEnDisco()==true){
                            cout<<"----------------------"<<endl;
                            cout << "REGISTRO AGREGADO! "<<endl;
                            cout<<"----------------------"<<endl;
                        }
                        else{
                            cout<<"-----------------------------"<<endl;
                            cout <<"ERROR AL AGREGAR REGISTRO! "<<endl;
                            cout<<"-----------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 2: lol.mostrarVentas();
                    system("pause");
                        break;
                    case 3:
                        mostrarventasporID();
                        system("pause");
                        break;
                    case 4:
                        modificarVenta();
                        break;
                    case 5:
                        lol.EliminarDeDisco();
                        system("pause");
                        break;
                    case 6:
                        DardealtaVentas();
                        system("pause");
                        break;
                    case 7:
                        return;
                        break;
                    default:
                        cout<<"------------------------"<<endl;
                        cout<<"OPCION INCORRECTA"<<endl;
                        cout<<"------------------------"<<endl;
                        break;
                }
        cout <<endl;
    }

}while(true);

return ;
}
#endif // SUBMENUVENTAS_H_INCLUDED
