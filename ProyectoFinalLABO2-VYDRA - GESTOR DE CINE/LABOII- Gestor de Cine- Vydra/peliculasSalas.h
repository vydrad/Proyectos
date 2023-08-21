#ifndef PELICULASSALAS_H_INCLUDED
#define PELICULASSALAS_H_INCLUDED

class SalasPorPelicula{
private:
    int idPelicula, idSala;
    char nombrePelicula[30];
    bool estado;
public:
    ///sets()
    void setidPelicula (int idP){idPelicula=idP;}
    void setidSala(int S){idSala=S;}
    void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
    void setEstado(bool e){estado=e;}

    ///gets()
    int getidPelicula (){return idPelicula;}
    int getidSala(){return idSala;}
    const char *getNombrePelicula (){return nombrePelicula;}
    bool getEstado(){return estado;}

    ///disco
    void EliminarDeDisco();
    int ModificarEnDisco(int pos);
    int grabarEnDisco();
    int leerEnDisco(int);

    bool cargarSalasPorPelicula(){
        FILE *p;
        SalasPorPelicula reg;
        bool escribio;
        p=fopen("salasPorPelicula.dat","ab");
        if (p==NULL) return false;
        cargar();
        escribio=fwrite(this,sizeof reg, 1,p);
        fclose(p);
        return escribio;
    }

    void modificarPeliculasPorSala(){
        SalasPorPelicula obj;
        Salas sala;
        SalasPorPelicula salax;

        int pos=0, pos2=0, pos3=0,idSala, idNuevo;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE SALA PARA MODIFICARO 0 (cero) PARA SALIR: "<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cin>>idSala;

        if(idSala==0){
                cout<<"--------------------------------------------"<<endl;
                cout<<" USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                cout<<"--------------------------------------------"<<endl;

                return;}
        while(validacionSala(idSala)==0){
            cout<<"----------------------------------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO UN NUMERO DE ID DE SALA INEXISTENTE O DADO DE BAJA "<<endl;
            cout<<"INGRESE NUEVAMENTE EL ID DE SALA PARA MODIFICARO 0 (cero) PARA SALIR: "<<endl;
            cin>>idSala;
            if(idSala==0){
                cout<<"--------------------------------------------------------"<<endl;
                cout<<"   USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                cout<<"--------------------------------------------------------"<<endl;

                    return;}
        }


        while(obj.leerEnDisco(pos++)){
            if(obj.getidSala()==idSala){

                obj.mostrar();
            }
        }

        int cont1=0;
        int cont2=0;
        bool aux=true, aux2=true;
        cout<<"-----------------------------------------------"<<endl;
        cout<<" SALAS DISPONIBLES PARA ASIGNAR UNA PELICULA: "<<endl;
        cout<<"-----------------------------------------------"<<endl;
        while(sala.leerEnDisco(pos2++)){
            cont1++;
        }

        while(salax.leerEnDisco(pos3++)){
        cont2++;
        }

            for (int i=0;i<cont1;i++){
                sala.leerEnDisco(i);/// va a COMPARAR CADA SALA
                if(sala.getEstado()){
                    for(int e=0;e<cont2;e++){
                    salax.leerEnDisco(e);

                        if(sala.getidSala()==salax.getidSala() && salax.getEstado()==true){
                            aux=false;
                        }
                    }
                }
                else {aux=false;}

                if(aux){ /// YO SOLO QUIERO MOSTRAR SI EXISTE LA SALA POR PELICULA EN FALSE
                    sala.mostrar();
                    aux2=false;
                }
                aux=true;

            }
            if(aux2){
                cout<<"-----------------------------------------------------------"<<endl;
                cout<<"NO HAY SALAS DISPONIBLES, POR FAVOR AGREGUE UNA NUEVA SALA"<<endl;
                cout<<"-----------------------------------------------------------"<<endl;
                return ;}

                cout<<"INGRESE EL NUEVO ID DE SALA: ";
                cin>>idNuevo;

               while(validacionModificarPeliculasPorSala(idNuevo)==0){
                    cout<<"----------------------------------------------------------------------------------------------"<<endl;
                    cout <<" EL ID DE SALA  ES INVALIDO O 0 (cero) PARA SALIR "<< endl;
                    cout<<"INGRESE EL ID DE SALA NUEVO : " <<endl;
                    cin>>idNuevo;
                    if(idNuevo==0){
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"   USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                        cout<<"--------------------------------------------------------"<<endl;

                    return ;}

               }
                while(validacionSala(idNuevo)!=1){
                    cout<<"------------------------------------------------------------"<<endl;
                    cout<<"EL ID DE SALA NO ES VALIDO O ESTA DADO DE BAJA " <<endl;
                    cout<<"INGRESE EL ID DE LA SALA DONDE QUIERE REGISTRAR LA PELICULA NUEVAMENTE o 0 (cero) PARA SALIR: " <<endl;
                    cin>>idNuevo;
                    if(idNuevo==0){
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"   USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        return ;
                    }
                }

                while(validacionSalasPorPelicula(idNuevo)==1){
                    cout<<"------------------------------------------------------------"<<endl;
                    cout<<"    LA SALA ESTA SIENDO UTILIZADA POR OTRA PELICULA"<<endl;
                    cout<<"------------------------------------------------------------"<<endl;
                    return ;
                }


                int pos4=0, posaux=-2, posaux2=-2;
                char namefilm[30];
                ///TENGOEL ID DE SALA, TENGO QUE COMPARAR SI EXISTE EN EL REGISTRO Y TENGO QUE AGREGARLO PERO EN SU LUGAR
                while(salax.leerEnDisco(pos4++)==1){
                    if(idNuevo == salax.getidSala() && salax.getEstado()==false){
                       /// cout<<"posicion del registro:"<<pos4<<endl;
                        posaux=pos4;///GRABARLO EN ESTA POSICION
                    }
                    if(idSala==salax.getidSala()){///SACO LOS DATOS DE LA SALA "VIEJA"
                       posaux2=salax.getidPelicula();
                       strcpy(namefilm,salax.getNombrePelicula());
                       }

                }

                salax.leerEnDisco(posaux-1);
                salax.setidPelicula(posaux2);
                salax.setNombrePelicula(namefilm);
                salax.setEstado(true);

                if(posaux==-2){

                    salax.setidSala(idNuevo);

                 ///   cout<<" AGREGUE EN EL DISCO"<<endl;
                    salax.grabarEnDisco();}
                else{
                  ///  cout<<"MODIFIQUE EN DISCO"<<endl;
                    salax.ModificarEnDisco(posaux-1);
                }
                cout<<"---------------------------------"<<endl;
                cout<<"    SALA MODIFICADA"<<endl;
                cout<<"---------------------------------"<<endl;

                return;
            }





    bool cargar(){
        estado=true;
        pelicula obj;
        Salas sala;
        SalasPorPelicula salax;
        int pos=0, pos2=0, pos3=0;
        cout<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE LA PELICULA PARA CARGARLO DESPUES A UNA SALA DISPONIBLE: ";
        cin>>idPelicula;
        cout<<"------------------------------------------------------------"<<endl;
        while(validacionIDpelicula(idPelicula)==0){
            cout <<"EL ID INGRESADO NO EXISTE O ESTA DADO DE BAJA  "<< endl;
            cout<<"INGRESE NUEVAMENTE EL ID DE LA PELICULA PARA CARGARLO DESPUES A UNA SALA: ";
            cin>>idPelicula;
        }

       while(obj.leerEnDisco(pos++)){
            if(obj.getidPelicula()==idPelicula){
                setNombrePelicula(obj.getNombrePelicula());
                obj.mostrar();
            }
        }


        int cont1=0;
        int cont2=0;
        while(sala.leerEnDisco(pos2++)){
        cont1++;
        }

        while(salax.leerEnDisco(pos3++)){
        cont2++;
        }

        bool aux=true, aux2=true;

        cout<<"-----------------------------------------------"<<endl;
        cout<<" SALAS DISPONIBLES PARA ASIGNAR UNA PELICULA: "<<endl;
       cout<<"-----------------------------------------------"<<endl;

              for (int i=0;i<cont1;i++){
                sala.leerEnDisco(i);
                 if(sala.getEstado()){
                    for(int e=0;e<cont2;e++){
                        salax.leerEnDisco(e);
                        if(sala.getidSala()==salax.getidSala() && salax.getEstado()==true){
                            aux=false;
                        }

                    }
                }
                else {aux=false;}

        if(aux){ sala.mostrar();///YO SOLO QUIERO MOSTRAR CUANDO SALAS POR PELICULA ESTA DADO DE BAJA
        aux2=false;
        }

        aux=true;

        }
        if(aux2){   cout<<"-----------------------------------------------------------"<<endl;
                    cout<<"NO HAY SALAS DISPONIBLES, POR FAVOR AGREGUE UNA NUEVA SALA"<<endl;
                    cout<<"-----------------------------------------------------------"<<endl;
                    return false;}

        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE LA SALA DONDE QUIERE REGISTRAR LA PELICULA: " <<endl;
        cin>>idSala;
        while(validacionSala(idSala)!=1){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"EL ID DE SALA NO ES VALIDO O ESTA DADO DE BAJA " <<endl;
            cout<<"INGRESE EL ID DE LA SALA DONDE QUIERE REGISTRAR LA PELICULA NUEVAMENTE o 0 (cero) PARA SALIR: " <<endl;
            cin>>idSala;
            if(idSala==0){
                    cout<<"------------------------------------------------"<<endl;
                    cout<<"   USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                    cout<<"------------------------------------------------"<<endl;
                return false;
            }
        }

        while(validacionSalasPorPelicula(idSala)==1){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"LA SALA ESTA SIENDO UTILIZADA POR OTRA PELICULA"<<endl;
            cout<<"------------------------------------------------------------"<<endl;
            system("pause");
            system("cls");
            return cargar();
        }

        int pos4=0, posaux=-2, posaux2=-2;
        ///TENGOEL ID DE SALA, TENGO QUE COMPARAR SI EXISTE EN EL REGISTRO Y TENGO QUE AGREGARLO PERO EN SU LUGAR
        while(salax.leerEnDisco(pos4++)==1){
            if(idSala == salax.getidSala() && salax.getEstado()==false){
                   /// cout<<"posicion del registro:"<<pos4<<endl;
                    posaux=pos4;///GRABARLO EN ESTA POSICION
            }
            if(idPelicula== salax.getidPelicula()){
                posaux2=pos4;
             ///  strcpy(nombrePelicula,salax.getNombrePelicula());
            }
        }


            salax.leerEnDisco(posaux2-1);
            salax.setidSala(idSala);
            salax.setEstado(true);
        if(posaux==-2){
          ///  cout<<" AGREGUE EN EL DISCO"<<endl;
            salax.grabarEnDisco();}
        else{
           /// cout<<"MODIFIQUE EN DISCO"<<endl;
            salax.ModificarEnDisco(posaux-1);
        }


        return true;
    }


    void mostrar(){
        if(estado==true){
            cout<<"-------------------------------------------------"<<endl;
            Salas sala;
            pelicula peli;
            director dire;
            int pos=0, pos1=0,pos2=0;
            int posi1=0,posi2=0;
            int flag1=0, flag2=0;
            while(sala.leerEnDisco(posi1++)==1){
                if(sala.getidSala()==idSala && sala.getEstado()==true){
                    flag1++;
                }
            }

            while(peli.leerEnDisco(posi2++)==1){
                if(peli.getidPelicula()==idPelicula &&peli.getEstado()==true){
                    flag2++;
                }
            }

            if((flag1+flag2)==0){
                        cout<<"EN LA SALA "<<idSala<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"   LA SALA Y LA PELICULA SE ENCUENTRAN DADAS DE BAJA "<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                }
            else {if(flag1==0){
                        cout<<"EN LA SALA "<<idSala<<endl;
                        cout<<"------------------------------------"<<endl;
                        cout<<" LA SALA SE ENCUENTRA DADA DE BAJA!"<<endl;
                        cout<<"------------------------------------"<<endl;
                }
                if(flag2==0){
                        cout<<"EN LA SALA "<<idSala<<endl;
                        cout<<"---------------------------------------"<<endl;
                        cout<<" LA PELICULA SE ENCUENTRA DADA DE BAJA"<<endl;
                        cout<<"---------------------------------------"<<endl;
                }
            }

           if((flag2+flag1)==2){
            cout<<"SALA EN LA QUE SE ENCUENTRA DISPONIBLE: SALA "<<idSala<<""<<endl;
            cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
            cout<<"NOMBRE DE LA PELICULA: ";
            cout<<nombrePelicula<<endl;
            while(peli.leerEnDisco(pos2++)==1){
                if(peli.getidPelicula()==idPelicula){
                    while(dire.leerEnDisco(pos1++)==1){
                        if(dire.getidDirector()== peli.getidDirector()){
                            cout<<"DIRECTOR: "<<dire.getnombreDirector()<<endl;
                        }
                    }
                }
            }
            while(sala.leerEnDisco(pos++)==1){
                if(sala.getidSala()==idSala && sala.getEstado()==true){
                    cout<<"TIPO DE PELICULA: "<<sala.getTipo()<<endl;
                    cout<<"PRECIO: $"<<sala.getPrecio()<<endl;
                }
            }
        }
        }

    }


      void mostrarfalse(){
        if(estado==false){
            cout<<"-------------------------------------------------"<<endl;
            Salas sala;
            pelicula peli;
            director dire;
            int pos=0, pos1=0,pos2=0;
            int posi1=0,posi2=0;
            int flag1=0, flag2=0;
            while(sala.leerEnDisco(posi1++)==1){
                if(sala.getidSala()==idSala && sala.getEstado()==true){
                    flag1++;
                }
            }

            while(peli.leerEnDisco(posi2++)==1){
                if(peli.getidPelicula()==idPelicula &&peli.getEstado()==true){
                    flag2++;
                }
            }

            if((flag1+flag2)==0){
                        cout<<"EN LA SALA "<<idSala<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                        cout<<"   LA SALA Y LA PELICULA SE ENCUENTRAN DADAS DE BAJA "<<endl;
                        cout<<"--------------------------------------------------------"<<endl;
                }
            else {if(flag1==0){
                        cout<<"EN LA SALA "<<idSala<<endl;
                        cout<<"------------------------------------"<<endl;
                        cout<<" LA SALA SE ENCUENTRA DADA DE BAJA!"<<endl;
                        cout<<"------------------------------------"<<endl;
                }
                if(flag2==0){
                        cout<<"EN LA SALA "<<idSala<<endl;
                        cout<<"---------------------------------------"<<endl;
                        cout<<" LA PELICULA SE ENCUENTRA DADA DE BAJA"<<endl;
                        cout<<"---------------------------------------"<<endl;
                }
            }

           if((flag2+flag1)==2){
            cout<<"SALA EN LA QUE SE ENCUENTRA DISPONIBLE: SALA "<<idSala<<""<<endl;
            cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
            cout<<"NOMBRE DE LA PELICULA: ";
            cout<<nombrePelicula<<endl;
            while(peli.leerEnDisco(pos2++)==1){
                if(peli.getidPelicula()==idPelicula){
                    while(dire.leerEnDisco(pos1++)==1){
                        if(dire.getidDirector()== peli.getidDirector()){
                            cout<<"DIRECTOR: "<<dire.getnombreDirector()<<endl;
                        }
                    }
                }
            }
            while(sala.leerEnDisco(pos++)==1){
                if(sala.getidSala()==idSala && sala.getEstado()==true){
                    cout<<"TIPO DE PELICULA: "<<sala.getTipo()<<endl;
                    cout<<"PRECIO: $"<<sala.getPrecio()<<endl;
                }
            }
        }
        }

    }


};

void SalasPorPelicula::EliminarDeDisco(){
    int pos=0;
    int idS;
    int xd=0;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID SALA A ELIMINAR O 0 (cero) PARA SALIR: ";
    cin>>idS;
    cout<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    if(idS==0){cout<<"USTED A INGRESADO 0, USTED ESTA SALIENDO"<<endl;
                return;}
    while(leerEnDisco(pos)==1){
        if(getidSala()==idS&& getEstado()==true){
            cout<<"REGISTRO A ELIMINAR: "<<endl<<endl;
            mostrar();
            setEstado(false);
            if(ModificarEnDisco(pos)==1){
                cout<<"-------------------------"<<endl;
                cout<<"   REGISTRO ELIMINADO! "<<endl;
                cout<<"-------------------------"<<endl;
                xd++;
            }
        }
        pos++;
    }
     if(xd==0){
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"  ID DE SALAS X PELICULA ES INVALIDO O SE ENCUENTRA DADO DE BAJA"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;}

}

int SalasPorPelicula::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("salasPorPelicula.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(SalasPorPelicula)*pos,0);
    int escribio=fwrite(this,sizeof(SalasPorPelicula),1,p);
    fclose(p);
    return escribio;
}

int SalasPorPelicula::grabarEnDisco(){
    FILE *p;
    p=fopen("salasPorPelicula.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(SalasPorPelicula),1,p);
    fclose(p);
    return escribio;
}

int SalasPorPelicula::leerEnDisco(int pos){
    FILE *p;
    p=fopen("salasPorPelicula.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(SalasPorPelicula)*pos,0);
    int leyo=fread(this,sizeof(SalasPorPelicula),1,p);
    fclose(p);
    return leyo;
}




#endif // PELICULASSALAS_H_INCLUDED
