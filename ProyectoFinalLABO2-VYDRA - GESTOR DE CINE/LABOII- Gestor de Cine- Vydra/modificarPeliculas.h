#ifndef MODIFICARPELICULAS_H_INCLUDED
#define MODIFICARPELICULAS_H_INCLUDED

void modificarPeliculas();
bool modificarNombrePeliculas();
bool modificarGenero();
bool modificarIdioma();
bool modificarDuracion();
bool modificarFechaInicial(int id);
bool modificarFechaFin(int id);
bool modificarFechas(int id);
bool modificarFecha();


void modificarPeliculas(){
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;

    do {
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- ---> SUB-MENU MODIFICAR PELICULAS <--- --- ---"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --"<<endl;
        ShowTime(" --- --- --- MODIFICAR NOMBRE DE PELICULA --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MODIFICAR GENERO             --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MODIFICAR IDIOMA             --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- MODIFICAR DURACION           --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- VOLVER A PELICULAS           --- --- --- ",4,10,y==4);
        rlutil::locate (4,11);
         cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --"<<endl;

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
                if(y>4){
                y=4;}
                break;

            case 1: ///ENTER
                system("cls");

                switch(y+1){
                    case 1:
                        if(modificarNombrePeliculas()==true){
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"  EL NOMBRE HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 2:
                        if(modificarGenero()==true){
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"EL GENERO HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 3:
                        if (modificarIdioma()==true){
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"EL IDIOMA HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                            cout<<"------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 4:
                        if (modificarDuracion()==true){
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"LA DURACION HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                            cout<<"------------------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 5:
                        return;
                        break;
                    default:
                        cout<<"------------------------------"<<endl;
                        cout<<"    OPCION INCORRECTA"<<endl;
                        cout<<"------------------------------"<<endl;
                        break;

                }
    }///FIN switch UP ,DOWN & ENTER
}while(true);
return;

}

bool modificarNombrePeliculas(){
    pelicula obj;
    int pos=0,id;
    char nombrePelicula[30];
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR EL NOMBRE O 0(cero) PARA SALIR: ";
    cin>>id;

        if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        else{
        while(validacionIDpelicula(id)==0){
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE PELICULA NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR EL NOMBRE O 0(cero) PARA SALIR: "<<endl;
            cin>>id;
            if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}

        }
    while(obj.leerEnDisco(pos++)){
        if(id==obj.getidPelicula()){
            obj.mostrar();
            cout<<"INGRESE EL NUEVO NOMBRE DE PELICULA: ";
            cargarCadena(nombrePelicula,29);
            obj.setNombrePelicula(nombrePelicula);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
        }
}

bool modificarGenero(){
    pelicula obj;
    int pos=0,id;
    char genero[20];
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR EL GENERO O 0 (cero) PARA SALIR: ";
    cin>>id;

        if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        else{
        while(validacionIDpelicula(id)==0){
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE PELICULA NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR EL GENERO O 0 (cero) PARA SALIR: "<<endl;
            cin>>id;
            if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}

        }
    while(obj.leerEnDisco(pos++)){
        if(id==obj.getidPelicula()&& obj.getEstado()==true){
            obj.mostrar();
            cout<<"INGRESE EL NUEVO GENERO: ";
            cargarCadena(genero,19);
            obj.setGenero(genero);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
        }
}

bool modificarIdioma(){
    pelicula obj;
    int pos=0,id;
    int idioma;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR EL IDIOMA O (cero) PARA SALIR: ";
    cin>>id;

        if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        else{
        while(validacionIDpelicula(id)==0){
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE PELICULA NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR EL IDIOMA O (cero) PARA SALIR: "<<endl;
            cin>>id;
            if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        }
    while(obj.leerEnDisco(pos++)){
        if(id==obj.getidPelicula()&& obj.getEstado()==true){
            obj.mostrar();

            cout<<"-------------------------------------------"<<endl;
            cout<<"INGRESE EL IDIOMA [ (1=Castellano) , (2=Subtitulado) ] :"<<endl;
            cin>>idioma;
            while ((idioma<=0) || (idioma>=3)){
            cout<<"-------------------------------------------------------------------------------"<<endl;
            cout<<"EL NUMERO DE IDIOMA ESTA FUERA DEL RANGO (1 A 2), INGRESE UN NUMERO NUEVAMENTE"<<endl;
            cout<<"INGRESE EL IDIOMA [ (1=Castellano) , (2=Subtitulado) ] : "<<endl;
            cin>>idioma;
            }

            obj.setIdioma(idioma);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
    }
}

bool modificarDuracion(){
    pelicula obj;
    int pos=0,id;
    int duracion;
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR LA DURACION O (cero) PARA SALIR: ";
    cin>>id;

    if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
    else{
        while(validacionIDpelicula(id)==0){
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout <<" EL ID DE PELICULA NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            system("pause");
            system("cls");
            cout<<"-------------------------------------------------------------------------------------"<<endl;
            cout<<"INGRESE EL NUMERO DE ID DE PELICULA PARA MODIFICAR LA DURACION O (cero) PARA SALIR: "<<endl;
            cin>>id;
            if(id==0){
                    cout<<"---------------------------------------------"<<endl;
                    cout<<"  USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"---------------------------------------------"<<endl;
                return false;}
        }
    while(obj.leerEnDisco(pos++)){
        if(id==obj.getidPelicula()&& obj.getEstado()==true){
            obj.mostrar();
            cout<<"INGRESE LA NUEVA DURACION (EN MINUTOS): ";
            cin>>duracion;

            while(duracion>240 || duracion<1){
                if(duracion>240){
                cout<<"----------------------------------------------------------------------"<<endl;
                cout <<" SE PUEDE PONER UNA DURACION DE PELICULA MAXIMO DE 240 MIN (4 HORAS)"<< endl;
                cout<<"----------------------------------------------------------------------"<<endl;
                }
                else if(duracion<1){
                    cout<<"----------------------------------------------------"<<endl;
                    cout <<"  NO SE PUEDE PONER UN VALOR DE DURACION NEGATIVA "<< endl;
                    cout<<"----------------------------------------------------"<<endl;}
                    cout<<"INGRESE LA DURACION NUEVAMENTE (EN MINUTOS)  " ;
                    cin>>duracion;
            }

            obj.setDuracion(duracion);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
    }
}

#endif // MODIFICARPELICULAS_H_INCLUDED
