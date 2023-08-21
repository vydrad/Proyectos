#ifndef DIRECTORES_H_INCLUDED
#define DIRECTORES_H_INCLUDED

class director{
private:
    int idDirector;
    char nombreDirector[30], Nacionalidad[20];
    Fecha FechaNacimiento;
    bool estado;
public:
    void setidDirector (int idD){idDirector=idD;}
    void setnombreDirector (const char *Nd){strcpy(nombreDirector,Nd);}
    void setNacionalidad (const char *N){strcpy(Nacionalidad,N);}
    void setFechaNacimiento(Fecha F){FechaNacimiento=F;}
    void setEstado(bool e){estado=e;}

    int getidDirector (){return idDirector;}
    const char *getnombreDirector (){return nombreDirector;}
    const char *getNacionalidad (){return Nacionalidad;}
    Fecha getFechaNacimiento (){return FechaNacimiento;}
    bool getEstado(){return estado;}

    void EliminarDeDisco();
    int ModificarEnDisco(int pos);
    void mostrarDeDisco();
    int grabarEnDisco();
    int leerEnDisco(int);


    void cargar(){
        estado=true;
        fflush(stdin);
        idDirector=autonumericoIDdirectores()+1;
        cout<<"ID DE DIRECTOR: "<<idDirector<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"INGRESAR EL NOMBRE DEL DIRECTOR: ";
        cargarCadena(nombreDirector,29);
        cout<<"-----------------------------------------------"<<endl;
        cout<<"INGRESE LA NACIONALIDAD DEL DIRECTOR: ";
        cargarCadena(Nacionalidad,19);
        cout<<"----------------------------------------------"<<endl;
        cout<<"FECHA DE NACIMIENTO DEL DIRECTOR: "<<endl;
        FechaNacimiento.Cargar3();

    }

    void mostrar(){
        if(estado==true){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"ID: ";
            cout<<idDirector<<endl;
            cout<<"NOMBRE DEL DIRECTOR: ";
            cout<<nombreDirector<<endl;
            cout<<"NACIONALIDAD: ";
            cout<<Nacionalidad<<endl;
            cout<<"FECHA DE NACIMIENTO: ";
            FechaNacimiento.Mostrar();
            cout<<"-------------------------------------------------";
        }
        cout<< endl;
    }

    void mostrarfalse(){
        if(estado==false){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"ID: ";
            cout<<idDirector<<endl;
            cout<<"NOMBRE DEL DIRECTOR: ";
            cout<<nombreDirector<<endl;
            cout<<"NACIONALIDAD: ";
            cout<<Nacionalidad<<endl;
            cout<<"FECHA DE NACIMIENTO: ";
            FechaNacimiento.Mostrar();
            cout<<"-------------------------------------------------";
        }
        cout<< endl;
    }


};

void director::EliminarDeDisco(){
    int pos=0;
    int idD;
    int xd=0;
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE DIRECTOR A ELIMINAR O 0 (cero) PARA SALIR: ";
    cin>>idD;

    if(idD==0){
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- "<<endl;
            cout<<"--- USTED A INGRESADO 0, USTED ESTA SALIENDO ---"<<endl;
            cout<<"--- --- --- --- --- --- --- --- --- --- --- --- "<<endl;}
    else{
    while(leerEnDisco(pos)==1){
        if(getidDirector()==idD && getEstado()==true){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"EL ID DE DIRECTOR TIENE LOS SIGUIENTES DATOS"<<endl;
            mostrar();
            setEstado(false);
            if(ModificarEnDisco(pos)==1){
                cout<<"---------------------"<<endl;
                cout<<"REGISTRO ELIMINADO! "<<endl;
                cout<<"---------------------"<<endl;
               xd++;
            }
        }
        pos++;
    }

        if(xd==0){
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"ID DE DIRECTOR ES INVALIDO O SE ENCUENTRA DADO DE BAJA"<<endl;
    cout<<"--------------------------------------------------------"<<endl;}


    }
}

int director::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("director.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(director)*pos,0);
    int escribio=fwrite(this,sizeof(director),1,p);
    fclose(p);
    return escribio;
}

int director::grabarEnDisco(){
    FILE *p;
    p=fopen("director.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(director),1,p);
    fclose(p);
    return escribio;
}

int director::leerEnDisco(int pos){
    FILE *p;
    p=fopen("director.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(director)*pos,0);
    int leyo=fread(this,sizeof(director),1,p);
    fclose(p);
    return leyo;
}




#endif // DIRECTORES_H_INCLUDED
