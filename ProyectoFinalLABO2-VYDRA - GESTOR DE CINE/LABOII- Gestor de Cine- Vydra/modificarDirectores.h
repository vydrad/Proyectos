#ifndef MODIFICARDIRECTORES_H_INCLUDED
#define MODIFICARDIRECTORES_H_INCLUDED
void modificarDirector();
bool modificarNombre();
bool modificarNacionalidad();
bool modificarFnacimiento();

void modificarDirector(){

    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- ----> SUB-MENU MODIFICAR DIRECTOR <---- --- --- -"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;
        ShowTime(" --- --- --- MODIFICAR NOMBRE              --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MODIFICAR NACIONALIDAD        --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MODIFICAR FECHA DE NACIMIENTO --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- VOLVER A DIRECTORES           --- --- --- ",4,9,y==3);
        rlutil::locate (4,10);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;

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
                        if( modificarNombre()==true){
                            cout<<"--------------------------------------------------------"<<endl;
                            cout<<"  EL NOMBRE HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"--------------------------------------------------------"<<endl;
                        }
                            system("pause");
                        break;
                    case 2:
                        if(modificarNacionalidad()==true){
                            cout<<"--------------------------------------------------------"<<endl;
                            cout<<"  LA NACIONALIDAD HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                            cout<<"--------------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 3:
                        if (modificarFnacimiento()==true){
                            cout<<"-----------------------------------------------------------"<<endl;
                            cout<<"  LA FECHA DE NACIMIENTO HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                            cout<<"-----------------------------------------------------------"<<endl;

                        }
                        system("pause");
                            break;
                    case 4:
                        return;
                        break;
                    default:
                        cout<<"----------------------------"<<endl;
                        cout<<"  OPCION INCORRECTA"<<endl;
                        cout<<"----------------------------"<<endl;
                        system("pause");
                        break;

                }
        }

}while(true);
return;

}

bool modificarNombre(){
    director obj;
    int pos=0,id;
    char nombre[30];
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR PARA MODIFICAR EL NOMBRE O 0 (cero) PARA SALIR AL MENU ANTERIOR: ";
    cin>>id;

    if(id==0){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"  USTED A INGRESADO 0, USTED ESTA SALIENDO"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
                return false;}
    else{
    while(validacionDir(id)==0){
        cout<<"--------------------------------------------------------"<<endl;
        cout <<" EL ID DE DIRECTOR NO EXISTE O ESTA DADO DE BAJA! "<< endl;
        system("pause");
        system("cls");
        cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR PARA MODIFICAR EL NOMBRE O 0 (cero) PARA SALIR AL MENU ANTERIOR: ";
        cin>>id;
        if(id==0){
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"  USTED A INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                return false;}

    }
    while(obj.leerEnDisco(pos++)){
        if(id==obj.getidDirector()&& obj.getEstado()==true){
            obj.mostrar();
            cout<<"INGRESE EL NUEVO NOMBRE DEL DIRECTOR: ";
            cargarCadena(nombre,29);
            obj.setnombreDirector(nombre);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
    }
}

bool modificarNacionalidad(){
    director obj;
    int pos=0,id;
    char nac[20];
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR PARA MODIFICAR LA NACIONALIDAD O 0 (cero) PARA SALIR AL MENU ANTERIOR: ";
    cin>>id;
    if(id==0){
            cout<<"----------------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"----------------------------------------------------"<<endl;
                return false;}
    else{
        while(validacionDir(id)==0){
            cout<<"--------------------------------------------------------"<<endl;
            cout <<" EL ID DE DIRECTOR NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR PARA MODIFICAR LA NACIONALIDAD O 0 (cero) PARA SALIR AL MENU ANTERIOR: ";
            cin>>id;
            if(id==0){
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                return false;
            }
        }
        while(obj.leerEnDisco(pos++)){
            if(id==obj.getidDirector()){
                if(obj.getEstado()==true){
                obj.mostrar();
                cout<<"INGRESE LA NUEVA NACIONALIDAD DEL DIRECTOR: ";
                cargarCadena(nac,19);
                obj.setNacionalidad(nac);
                obj.ModificarEnDisco(pos-1);
                return true;
                }

            }
        }

    }
    return false;
}

bool modificarFnacimiento(){
    director obj;
    int pos=0,id;
    Fecha nac;
    cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR PARA MODIFICAR FECHA DE NACIMIENTO O 0 (cero) PARA SALIR AL MENU ANTERIOR: ";
    cin>>id;
    if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
    else{
    while(validacionDir(id)==0){
        cout<<"-----------------------------------------------------"<<endl;
        cout <<" EL ID DE DIRECTOR NO EXISTE O ESTA DADO DE BAJA! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR PARA MODIFICAR FECHA DE NACIMIENTO O 0 (cero) PARA SALIR AL MENU ANTERIOR: ";
        cin>>id;
            if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}

    }
    while(obj.leerEnDisco(pos++)){
        if(id==obj.getidDirector()&& obj.getEstado()==true){
            obj.mostrar();
            cout<<"INGRESE LA NUEVA FECHA DE NACIMIENTO DEL DIRECTOR: ";
            nac.Cargar3();
            obj.setFechaNacimiento(nac);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
    }
}


#endif // MODIFICARDIRECTORES_H_INCLUDED
