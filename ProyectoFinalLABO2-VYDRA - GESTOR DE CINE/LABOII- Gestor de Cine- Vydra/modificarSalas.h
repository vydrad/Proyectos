#ifndef MODIFICARSALAS_H_INCLUDED
#define MODIFICARSALAS_H_INCLUDED
#include "funcionesGlobales.h"
void modificarSalas();
bool modificarTipoSala();
bool modificarCantButacas();
bool modificarPrecioSala();

void modificarSalas(){
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- --- > SUB-MENU MODIFICAR SALAS <--- --- --- ---"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        ShowTime(" --- --- ---  MODIFICAR TIPO DE SALA         --- --- --- ",4,6,y==0);
        ShowTime(" --- --- ---  MODIFICAR CANTIDAD DE BUTACAS  --- --- --- ",4,7,y==1);
        ShowTime(" --- --- ---  MODIFICAR PRECIO DE LA SALA    --- --- --- ",4,8,y==2);
        ShowTime(" --- --- ---  VOLVER MENU SALAS              --- --- --- ",4,9,y==3);
        rlutil::locate (4,10);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;

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
                if(y>3){
                y=3;}
                break;

            case 1: ///ENTER
                system("cls");

                switch(y+1){
                    case 1:
                        if( modificarTipoSala()==true){
                            cout<<"--------------------------------------------------"<<endl;
                            cout<<"EL TIPO DE SALA HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"--------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 2:
                        if( modificarCantButacas()==true){
                            cout<<"---------------------------------------------------------"<<endl;
                            cout<<"LA CANTIDAD DE BUTACAS HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                            cout<<"---------------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 3:
                        if(modificarPrecioSala()==true){
                            cout<<"--------------------------------------------------------"<<endl;
                            cout<<" EL PRECIO DE SALA HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"--------------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 4:
                        return;
                        break;

                    default:
                        cout<<"-----------------------------------"<<endl;
                        cout<<"   ELIJA UNA OPCION VALIDA"<<endl;
                        cout<<"-----------------------------------"<<endl;
                        break;
                }
        }

    }while(true);

return;
}

bool modificarTipoSala(){
    Salas obj;
    int pos=0,id;

    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout <<"INGRESE EL NUMERO DE ID DE LA SALA PARA MODIFICARLE EL TIPO (2d,3d,4d) O 0 (cero) PARA SALIR : ";
    cin>>id;

    if(id==0){  cout<<"---------------------------------------------"<<endl;
                cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                cout<<"---------------------------------------------"<<endl;
                return false;}
    else{
        while(validacionSala(id)==0){
            cout<<"------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE SALA INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
            cout <<"INGRESE EL NUMERO DE ID DE LA SALA PARA MODIFICARLE EL TIPO (2d,3d,4d) O 0 (cero) PARA SALIR : ";
            cin>>id;
                if(id==0){  cout<<"---------------------------------------------"<<endl;
                cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                cout<<"---------------------------------------------"<<endl;
                return false;}
        }
        while(obj.leerEnDisco(pos++)){
            if(id==obj.getidSala()&& obj.getEstado()==true){
                obj.mostrar();

                obj.cargarmodificar(obj.getidSala());

                obj.ModificarEnDisco(pos-1);
                return true;
            }
        }
    return false;

    }
}

bool modificarCantButacas(){
    Salas obj;
    int pos=0,id;
        cout<<"------------------------------------------------------------------------------------------------------"<<endl;
        cout <<"INGRESE EL NUMERO DE ID DE LA SALA PARA MODIFICARLE LA CANTIDAD DE BUTACAS O 0 (cero) PARA SALIR : ";
        cin>>id;
        if(id==0){  cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        else{

        while(validacionSala(id)==0){
            cout<<"-------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE SALA INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"------------------------------------------------------------------------"<<endl;
            cout <<"INGRESE EL NUMERO DE ID DE LA SALA PARA MODIFICARLE LA CANTIDAD DE BUTACAS O 0 (cero) PARA SALIR : ";
            cin>>id;
            if(id==0){  cout<<"---------------------------------------------"<<endl;
                        cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                        cout<<"---------------------------------------------"<<endl;
                return false;}
        }
        while(obj.leerEnDisco(pos++)){
            if(id==obj.getidSala()&& obj.getEstado()==true){
                obj.mostrar();

                int Cant;
                cout<<"INGRESE LA NUEVA CANTIDAD DE BUTACAS: ";
                cin>>Cant;
                while(Cant>300 || Cant<=0){
                if(Cant>300){
                cout<<"----------------------------------------"<<endl;
                cout <<" SE PUEDEN PONER UN MAXIMO DE 300 BUTACAS"<< endl;
                cout<<"----------------------------------------"<<endl;
                }
                else if(Cant<=1){
                    cout<<"------------------------------------------------------"<<endl;
                    cout <<" NO SE PUEDEN PONER NUMEROS DE BUTACAS NEGATIVOS o 0"<< endl;
                    cout<<"------------------------------------------------------"<<endl;}
                    cout<<"INGRESE LA CANTIDAD DE ENTRADAS NUEVAMENTE: " ;
                    cin>>Cant;
            }

                obj.setPlazas(Cant);
                obj.ModificarEnDisco(pos-1);
                return true;
            }
        }
    return false;
        }
}

bool modificarPrecioSala(){
    Salas obj;
    int pos=0,id;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DE LA SALA PARA MODIFICAR EL PRECIO O 0 (cero) PARA SALIR: ";
    cin>>id;

        if(id==0){ cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        else{
        while(validacionSala(id)==0){
            cout<<"------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE SALA INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"--------------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE EL NUMERO DE ID DE LA SALA PARA MODIFICAR EL PRECIO O 0 (cero) PARA SALIR: ";
            cin>>id;

                if(id==0){  cout<<"---------------------------------------------"<<endl;
                            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                            cout<<"---------------------------------------------"<<endl;
                return false;}
        }
        while(obj.leerEnDisco(pos++)){
            if(id==obj.getidSala()&& obj.getEstado()==true){
                obj.mostrar();


                int pre;
                cout<<"INGRESE EL NUEVO PRECIO DE SALA : ";
                cin>>pre;
                while(pre>2000 || pre<0){
                if(pre>2000){
                cout<<"----------------------------------------"<<endl;
                cout <<" SE PUEDE COBRAR UN MAXIMO DE $2000"<< endl;
                cout<<"----------------------------------------"<<endl;
                }
                else if(pre<0){
                    cout<<"-----------------------------------------------------"<<endl;
                    cout <<"NO SE PUEDE ASIGNAR UN PRECIO NEGATIVO PERO SI 0"<< endl;
                    cout<<"-----------------------------------------------------"<<endl;}
                    cout<<"INGRESE EL PRECIO DE LA SALA NUEVAMENTE: " ;
                    cin>>pre;
            }


                obj.setPrecio(pre);
                obj.ModificarEnDisco(pos-1);
                return true;
            }
        }
    return false;
        }
}



#endif // MODIFICARSALAS_H_INCLUDED
