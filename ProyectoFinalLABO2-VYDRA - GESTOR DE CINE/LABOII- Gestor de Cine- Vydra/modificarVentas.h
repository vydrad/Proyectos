#ifndef MODIFICARVENTAS_H_INCLUDED
#define MODIFICARVENTAS_H_INCLUDED

void modificarVenta();
bool modificarFechaVenta();
bool modificarFormaDePago();
bool modificarSalaP();
bool modificarCantEntradas();


void modificarVenta(){
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- --- --- ---> SUB-MENU MODIFICAR VENTAS <--- --- --- --- --- --- "<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
        ShowTime(" --- --- --- MODIFICAR FECHA DE VENTAS                       --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MODIFICAR FORMA DE PAGO                         --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MODIFICAR CANTIDAD DE ENTRADAS                  --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- VOLVER A VENTAS                                 --- --- --- ",4,9,y==3);
        rlutil::locate (4,10);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- "<<endl;

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
                        if (modificarFechaVenta()==true){
                            cout<<"------------------------------------------------------"<<endl;
                            cout<<"  LA FECHA DE VENTA HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                            cout<<"------------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 2:
                        if(modificarFormaDePago()==true){
                            cout<<"-----------------------------------------------------------------"<<endl;
                            cout<<"  LA FORMA DE PAGO Y EL TOTAL HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"-----------------------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 3:
                        if(modificarCantEntradas()==true){
                            cout<<"------------------------------------------------------------"<<endl;
                            cout<<"   LA CANTIDAD DE ENTRADAS HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                            cout<<"------------------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 4:
                        return;
                        break;
                    default:
                        cout<<"----------------------------"<<endl;
                        cout<<"   OPCION INCORRECTA"<<endl;
                        cout<<"----------------------------"<<endl;
                        break;
                } ///Switch del menu
        }///switch del UP DOWN ENTER
    }while(true);///DO WHILE

return;

}

bool modificarFechaVenta(){
    ventas obj;
    int pos=0;
    Fecha fechaVenta;
    int id;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL ID DE VENTA PARA MODIFICAR LA FECHA O 0 (cero) PARA SALIR:"<<endl;
    cin>> id;
        if(id==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return false;
        }
        while(validacionIDventa(id)==0){
            cout<<"------------------------------------------------------------"<<endl;
            cout <<" EL ID DE VENTA INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE NUEVAMENTE EL ID DE VENTA PARA MODIFICAR LA FECHA O 0 (cero) PARA SALIR:";
            cin>>id;
            if(id==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return false;
        }
        }
        while(obj.leerEnDisco(pos++)){
            if(id==obj.getNventa()&& obj.getEstado()==true){
                obj.mostrar();
                cout<<"INGRESE LA NUEVA FECHA DE LA VENTA: "<<endl;
                fechaVenta.Cargar2();
                obj.setFechaVenta(fechaVenta);
                obj.ModificarEnDisco(pos-1);
                return true;
            }
        }
    return false;
}

bool modificarFormaDePago(){
    ventas obj;
    Salas aux;
    int pos=0, pos1=0;
    int id, pago;
    float totalNuevo, importe;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL ID DE VENTA PARA MODIFICAR LA FORMA DE PAGO O 0 (cero) PARA SALIR:"<<endl;
    cin>>id;
        if(id==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
        return false;
        }
        while(validacionIDventa(id)==0){
            cout<<"----------------------------------------------------------"<<endl;
            cout <<" EL ID DE VENTA INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESAR EL ID DE VENTA PARA MODIFICAR LA FORMA DE PAGO O 0 (cero) PARA SALIR:"<<endl;
            cin>>id;

            if(id==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return false;
        }
        }
        while(obj.leerEnDisco(pos++)){
            if(id==obj.getNventa() && obj.getEstado()==true){
                obj.mostrar();
                cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]"<<endl;
                cin >>pago;

                while ((pago<=0) || (pago>=4)){
                    system("cls");
                    cout<<"-----------------------------------------------------------------------------------------"<<endl;
                    cout<<"EL NUMERO DE METODO DE PAGO INGRESADO ESTA FUERA DEL RANGO (1 A 3), INGRESE UN NUMERO NUEVAMENTE"<<endl;
                    cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]: "<<endl;
                    cin>>pago;
                }
                obj.setPago(pago);

                while (aux.leerEnDisco(pos1++)==1){
                    if(aux.getidSala()==obj.getidSala()){
                        importe=aux.getPrecio();
                    }
                }
                totalNuevo=validacionPrecio(importe,pago);
                totalNuevo=totalNuevo*obj.getCantEntradas();
                obj.setTotal(totalNuevo);
                obj.ModificarEnDisco(pos-1);
                return true;
            }
        }
    return false;
}


bool modificarCantEntradas(){
    ventas obj;

    Salas aux;
    int pos=0, pos1=0,pos2=0;
    int id,cantEntradas, butacasSala=0, butacasVendidas=0, butacasTotal=0;
    float totalNuevo, importe;
    cout<<"--------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESAR EL ID DE VENTA PARA MODIFICAR LA CANTIDAD DE ENTRADAS O 0 (cero) PARA SALIR:";
    cin>>id;
        if(id==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
        return false;
        }
        while(validacionIDventa(id)==0){
            cout<<"------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE VENTA INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"------------------------------------------------------------------------"<<endl;
            cout<<" INGRESAR EL ID DE VENTA PARA MODIFICAR LA CANTIDAD DE ENTRADAS O 0 (cero) PARA SALIR:"<<endl;
            cin>>id;
            if(id==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return false;
            }

        }
        while(obj.leerEnDisco(pos++)){
            if(obj.getNventa()==id){
                obj.mostrar();
            }
        }
        while(obj.leerEnDisco(pos1++)){

            if(obj.getNventa()==id && obj.getEstado()==true){
                butacasSala=cantButacasSala(obj.getidSala());
                butacasVendidas=calcularVentas(obj.getidSala());
                butacasTotal=butacasSala-butacasVendidas;
                cout<<"-------------------------------------------------"<<endl;
                cout<<"CANTIDAD DE BUTACAS DISPONIBLES: "<<butacasTotal<<endl;
                if(butacasTotal<=0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"LA SALA YA SE ENCUENTRA COMPLETA"<<endl;
                    system("pause");
                    system("cls");
                    return modificarCantEntradas();
                }
                cout<<"-------------------------------------------"<<endl;
                cout<<"INGRESE UNA CANTIDAD DE ENTRADAS"<<endl;
                cin>>cantEntradas;
                while(cantEntradas>10 || cantEntradas<1){
                    if(cantEntradas>10){
                        cout<<"----------------------------------------"<<endl;
                        cout <<" SE PUEDEN COMPRAR HASTA 10 ENTRADAS! "<< endl;
                        cout<<"----------------------------------------"<<endl;
                    }
                    else if(cantEntradas<1){
                            cout<<"----------------------------------------------------"<<endl;
                            cout <<" LA MENOR CANTIDAD PERMITIDA DE ENTRADAS ES 1  -.-'' "<< endl;
                            cout<<"----------------------------------------------------"<<endl;}
                            cout<<"INGRESE LA CANTIDAD DE ENTRADAS NUEVAMENTE: " ;
                            cin>>cantEntradas;
                }

                while(cantEntradas>butacasTotal){
                cout<<"-------------------------------------------"<<endl;
                cout <<"NO HAY SUFICIENTES BUTACAS!"<< endl;
                cout<<"CANTIDAD DE BUTACAS DISPONIBLES:"<<butacasTotal<<endl;
                cout<<"-------------------------------------------"<<endl;
                system("pause");
                system("cls");
                cout<<"------------------------------------------"<<endl;
                cout<<"INGRESE LA CANTIDAD DE ENTRADAS: " <<endl;
                cout<<"-------------------------------------    ----"<<endl;
                cin>>cantEntradas;
                }
                obj.setCantEntradas(cantEntradas);
                while (aux.leerEnDisco(pos2++)==1){
                    if(aux.getidSala()==obj.getidSala()){
                        importe=aux.getPrecio();
                    }
                }
                totalNuevo=validacionPrecio(importe,obj.getPago());
                totalNuevo=totalNuevo*obj.getCantEntradas();
                obj.setTotal(totalNuevo);
                obj.setCantEntradas(cantEntradas);
                obj.ModificarEnDisco(pos1-1);
                return true;

            }
        }
        return false;
}





#endif // MODIFICARVENTAS_H_INCLUDED
