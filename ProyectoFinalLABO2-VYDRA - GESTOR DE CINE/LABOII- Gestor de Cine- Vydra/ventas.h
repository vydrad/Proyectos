#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas{
private:
    int Nventa, CantEntradas,idPelicula,idSala, Pago,butacastotal=0,butacasvendidas=0,butacassala=0;
    float Total;
    pelicula obj;
    Salas aux;
    SalasPorPelicula reg;
    Fecha fechaVenta;
    bool estado;

public:
    void setidPelicula (int id){idPelicula=id;}
    void setidSala(int ids){idSala=ids;}
    void setNventa (int Nv){Nventa=Nv;}
    void setCantEntradas (int CantE){CantEntradas=CantE;}
    void setPago (int P){Pago=P;}
    void setFechaVenta(Fecha F){fechaVenta=F;}
    void setEstado(bool e){estado=e;}
    void setTotal(float t){Total=t;}

    int getidPelicula(){return idPelicula;}
    int getidSala(){return idSala;}
    int getNventa (){return Nventa;}
    int getCantEntradas (){return CantEntradas;}
    int getPago (){return Pago;}
    Fecha getFecha (){return fechaVenta;}

    bool getEstado(){return estado;}
    float getTotal(){return Total;}

    void EliminarDeDisco();
    int ModificarEnDisco(int pos);
    int grabarEnDisco();
    int leerEnDisco(int);


    bool cargarVentas(){
        FILE *p;
        bool escribio;
        ventas reg;
        p=fopen("ventas.dat","ab");
        if (p==NULL) return false;
        cargar();
        escribio=fwrite(this,sizeof reg, 1,p);
        fclose(p);
        return escribio;
    }

    void mostrarVentas(){
        FILE *p;
        p=fopen("ventas.dat","rb");
        if (p==NULL) return;
        while(fread(this,sizeof (ventas),1,p)==1){
            mostrar();
        }
        fclose(p);
    }


    void cargar(){

        Fecha Actual;
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);

        Actual.setAnio(1900+tmPtr->tm_year);
        Actual.setMes(tmPtr->tm_mon+1);
        Actual.setDia(tmPtr->tm_mday);

        estado=true;
        int pos1=0;

        Nventa=autonumericoIDVentas()+1;
        cout<<"-------------------------------"<<endl;
        cout<<"NUMERO DE VENTA : "<<Nventa<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"INGRESE EL ID DE LA PELICULA: ";
        cin>>idPelicula;
        while(validacionIDpelicula(idPelicula)==0){///VERIFICA QUE EL ID PELICULA EXISTA
            cout<<"------------------------------------------------"<<endl;
            cout <<"EL ID INGRESADO NO EXISTE O ESTA DADO DE BAJA! "<< endl;
            cout<<"------------------------------------------------"<<endl;
            cout<<"INGRESE EL ID DE LA PELICULA NUEVAMENTE : ";
            cin>>idPelicula;
        }

        while(validacionPeliculaEnSalas(idPelicula)==0){/// VERIFICA QUE LA PELICULA EXISTA EN ALGUNA SALA
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"--- ERROR ! EL ID DE PELICULA NO SE ENCUENTRA EN CARTELERA ---"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;
           cout<<"INGRESE EL ID DE LA PELICULA NUEVAMENTE : ";
            cin>>idPelicula;
        }

        cout<<"-----------------------------------------------------"<<endl;
        cout<<"ELIJA LA SALA EN DONDE VERA LA PELICULA DENTRO DE LAS DISPONIBLES: ";
        cin>>idSala;
        cout<<"-----------------------------------------------------"<<endl;
        while(validacionSalasPorPelicula2(idSala,idPelicula)==0){///VERIFICA QUE COINCIDA LA SALA Y LA PELICULA QUE EXISTAN

            cout<<"INGRESE EL ID DE SALA NUEVAMENTE: " ;
            cin>>idSala;
            cout<<"-----------------------------------------------------"<<endl;
        }

        butacassala=cantButacasSala(idSala);
        butacasvendidas=calcularVentas(idSala);
        butacastotal=butacassala-butacasvendidas;

        cout<<"CANTIDAD DE BUTACAS DISPONIBLES: "<<butacastotal<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        if(butacastotal<=0){
            cout<<"LA SALA YA SE ENCUENTRA COMPLETA"<<endl;
            cout<<"USTED ESTA SALIENDO, VUELVA A INGRESAR A ESTE MENU"<<endl;
            system("pause");
            system("cls");
            return cargar(); /// cargar();
        }

        cout<<"INGRESE CANTIDAD DE ENTRADAS: ";
        cin>>CantEntradas;
        while(CantEntradas>10 || CantEntradas<1){
                if(CantEntradas>10){
            cout<<"----------------------------------------"<<endl;
            cout <<" SE PUEDEN COMPRAR HASTA 10 ENTRADAS! "<< endl;
            cout<<"----------------------------------------"<<endl;
                }
                else if(CantEntradas<1){
            cout<<"----------------------------------------------------"<<endl;
            cout <<" LA MENOR CANTIDAD PERMITIDA DE ENTRADAS ES 1  -.-'' "<< endl;
            cout<<"----------------------------------------------------"<<endl;}
            cout<<"INGRESE LA CANTIDAD DE ENTRADAS NUEVAMENTE: " ;
            cin>>CantEntradas;
        }

        while(CantEntradas>butacastotal){
            cout<<"----------------------------------------------------"<<endl;
            cout<<"NO HAY SUFICIENTES BUTACAS!"<< endl;
            cout<<"CANTIDAD DE BUTACAS DISPONIBLES:"<<butacastotal<<endl;
            cout<<"INGRESE LA CANTIDAD DE ENTRADAS NUEVAMENTE: " <<endl;
            cin>>CantEntradas;
        }
        cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]: ";
        cin >>Pago;
        while ((Pago<=0) || (Pago>=4)){
            cout<<"EL NUMERO DE METODO DE PAGO INGRESADO ESTA FUERA DEL RANGO (1 A 3)"<<endl;
            cout<<"INGRESE METODO DE PAGO NUEVAMENTE [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]: "<<endl;
            cin>>Pago;

        }

        int importe;
        while (aux.leerEnDisco(pos1++)==1){
            if(aux.getidSala()==idSala){
                importe=aux.getPrecio();
            }
        }

        Total=validacionPrecio(importe,Pago);
        Total=Total*CantEntradas;
        cout<<"EL TOTAL ES DE : $" <<Total<<endl;
        fechaVenta.setAnio(Actual.getAnio());
        fechaVenta.setMes(Actual.getMes());
        fechaVenta.setDia(Actual.getDia());
        cout<<"LA FECHA DE VENTA ES: ";
        fechaVenta.Mostrar();

    }

    void mostrar(){
        Salas sala;
        int pos=0;
        if(estado==true){
            cout<<"-------------------------------------------------";
            cout<<endl;
            cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
            cout<<"ID DE LA PELICULA: ";
            cout<<idPelicula<<endl;
            cout<<"ID DE LA SALA: ";
            cout<<idSala<<endl;
            while(sala.leerEnDisco(pos++)==1){
                if(sala.getidSala()==idSala){
                    cout<<"TIPO DE SALA: "<<sala.getTipo()<<endl;
                }
            }
            cout<<"FECHA DE VENTA:";
            fechaVenta.Mostrar();
            cout<<"CANTIDAD DE ENTRADAS: ";
            cout<<CantEntradas<<endl;
            if(Pago==1){
                     cout<<"METODO DE PAGO "<<Pago<<" = EFECTIVO"<<endl;
            }
            if(Pago==2){
                     cout<<"METODO DE PAGO "<<Pago<<" = CREDITO"<<endl;
            }
            if(Pago==3){
                     cout<<"METODO DE PAGO "<<Pago<<" = DEBITO"<<endl;
            }
            cout<<"IMPORTE: ";
            cout<< Total<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }

    }

    void mostrarfalse(){
        Salas sala;
        int pos=0;
        if(estado==false){
            cout<<"-------------------------------------------------";
            cout<<endl;
            cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
            cout<<"ID DE LA PELICULA: ";
            cout<<idPelicula<<endl;
            cout<<"ID DE LA SALA: ";
            cout<<idSala<<endl;
            while(sala.leerEnDisco(pos++)==1){
                if(sala.getidSala()==idSala){
                    cout<<"TIPO DE SALA: "<<sala.getTipo()<<endl;
                }
            }
            cout<<"FECHA DE VENTA:";
            fechaVenta.Mostrar();
            cout<<"CANTIDAD DE ENTRADAS: ";
            cout<<CantEntradas<<endl;
            if(Pago==1){
                     cout<<"METODO DE PAGO "<<Pago<<" = EFECTIVO"<<endl;
            }
            if(Pago==2){
                     cout<<"METODO DE PAGO "<<Pago<<" = CREDITO"<<endl;
            }
            if(Pago==3){
                     cout<<"METODO DE PAGO "<<Pago<<" = DEBITO"<<endl;
            }
            cout<<"IMPORTE: ";
            cout<< Total<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }

    }


};

void ventas::EliminarDeDisco(){
    int pos=0;
    int idV;
    int xd=0;
    cout<<"INTRODUZCA EL ID DE VENTA A ELIMINAR O 0 (cero) PARA SALIR: ";
    cin>>idV;
    if(idV==0){
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            return;
    }
    while(leerEnDisco(pos)==1){
        if(getNventa()==idV && getEstado()==true){
            cout<<"EL ID DE VENTA TIENE LOS SIGUIENTES DATOS"<<endl;
            mostrar();
            cout<<endl<<endl;
            setEstado(false);
            if(ModificarEnDisco(pos)==1){
                cout<<"REGISTRO ELIMINADO! ";
                xd++;
            }
        }
        pos++;
    }
    if(xd==0){
    cout<<"ID DE VENTA ES INVALIDO O SE ENCUENTRA DADO DE BAJA"<<endl;}



}

int ventas::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(ventas)*pos,0);
    int escribio=fwrite(this,sizeof(ventas),1,p);
    fclose(p);
    return escribio;
}

int ventas::grabarEnDisco(){
    FILE *p;
    p=fopen("ventas.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(ventas),1,p);
    fclose(p);
    return escribio;
}

int ventas::leerEnDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(ventas)*pos,0);
    int leyo=fread(this,sizeof(ventas),1,p);
    fclose(p);
    return leyo;
}


#endif // VENTAS_H_INCLUDED
