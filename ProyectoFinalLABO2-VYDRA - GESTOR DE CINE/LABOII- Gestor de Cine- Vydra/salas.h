#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

class Salas
{
private:
    int idSala;
    char tipo[3];
    int plazas;
    float precio;
    bool estado;

public:
    void setidSala(int S){idSala=S;}
    void setTipo(const char *t){strcpy(tipo,t);}
    void setPlazas(int p){plazas=p;}
    void setPrecio(float pr){precio=pr;}
    void setEstado(bool e){estado=e;}

    int getidSala(){return idSala;}
    const char *getTipo(){return tipo;}
    int getPlazas(){return plazas;}
    float getPrecio(){return precio;}
    bool getEstado(){return estado;}

    void EliminarDeDisco();
    int ModificarEnDisco(int pos);
    int grabarEnDisco();
    int leerEnDisco(int);

    bool cargarSalas(){
        FILE *s;
        bool escribio;
        Salas reg;
        s=fopen("salas.dat","ab");
        if (s==NULL) return false;
        cargar();
        escribio=fwrite(this,sizeof reg, 1,s);
        fclose(s);
        return escribio;
    }

    void ValidarTipodeSALA(){
        bool aux =false;
        char auxi[3];

        cout<<"INGRESE EL EL TIPO DE SALA (2D,3D,4D): ";
        cargarCadena(auxi,2);
        cout<<"--------------------------------------------------------"<<endl;


        while(aux == false){
            if(strcmp("4d",auxi)==0 || strcmp("3d",auxi)==0 ||strcmp("2d",auxi)==0||
            strcmp("4D",auxi)==0 ||strcmp("3D",auxi)==0 ||strcmp("2D",auxi)==0){

                setTipo(auxi);

                return;}
            else{
                cout<<"USTED A INGRESADO UNA OPCION INEXISTENTE, VUELVA A DIGITAR EL TIPO DE SALA (2d,3d,4d)"<<endl;
                cargarCadena(auxi,2);
            }
        }
    }

    void cargar(){

        estado=true;
        idSala=autonumericoIDSalas()+1;
        cout<<"ID DE LA SALA: "<<idSala<<endl;
        cout<<"--------------------------------------------------------"<<endl;
       /* cout<<"INGRESE EL EL TIPO DE SALA (2D,3D,4D): ";
        cargarCadena(auxi,2);
        cout<<"--------------------------------------------------------"<<endl;*/

        ValidarTipodeSALA();

        if(strcmp(tipo,"2d")==0 || strcmp(tipo,"2D")==0){
            precio=600;
            plazas=150;
        }
        else if(strcmp(tipo,"3d")==0 || strcmp(tipo,"3D")==0){
            precio=700;
            plazas=150;
            }
            else if(strcmp(tipo,"4d")==0 || strcmp(tipo,"4D")==0){
                precio=1000;
                plazas=100;
                }
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"PRECIO DE LA ENTRADA EN LA SALA DE "<<tipo<< " ES DE: $"<<precio<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"LA CANTIDAD DE BUTACAS DE LA SALA ES DE: ";
        cout<<plazas<<endl;

    }
    void cargarmodificar(int id){

        estado=true;
        cout<<"--------------------------------------------------------"<<endl;

        ValidarTipodeSALA();

        if(strcmp(tipo,"2d")==0 || strcmp(tipo,"2D")==0){
            precio=600;
            plazas=150;
        }
        else if(strcmp(tipo,"3d")==0 || strcmp(tipo,"3D")==0){
            precio=700;
            plazas=150;
            }
            else if(strcmp(tipo,"4d")==0 || strcmp(tipo,"4D")==0){
                precio=1000;
                plazas=100;
                }
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"PRECIO DE LA ENTRADA EN LA SALA DE "<<tipo<< " ES DE: $"<<precio<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"LA CANTIDAD DE BUTACAS DE LA SALA ES DE: ";
        cout<<plazas<<endl;

    }

    void  mostrar(){
        if(estado==true){
            cout<<"-------------------------------------------------";
            cout<<endl;
            cout<<"ID SALA: "<<idSala<<endl;
            cout<<"TIPO DE SALA: "<<tipo<<endl;
            cout<<"PRECIO EN LA SALA: $"<<precio<<endl;
            plazas-=calcularVentas(idSala);
            cout<<"CANTIDAD DE BUTACAS: "<<plazas<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }

    }

        void  mostrarfalse(){
        if(estado==false){
            cout<<"-------------------------------------------------";
            cout<<endl;
            cout<<"ID SALA: "<<idSala<<endl;
            cout<<"TIPO DE SALA: "<<tipo<<endl;
            cout<<"PRECIO EN LA SALA: $"<<precio<<endl;
            plazas-=calcularVentas(idSala);
            cout<<"CANTIDAD DE BUTACAS: "<<plazas<<endl;
            cout<<"-------------------------------------------------"<<endl;
        }

    }


};

void Salas::EliminarDeDisco(){
    int pos=0;
    int idS;
    int xd =0;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE SALA A ELIMINAR O 0 (cero) PARA SALIR: ";
    cin>>idS;
    if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED A INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
                return;}
        else{

    while(leerEnDisco(pos)==1){
        if(getidSala()==idS && getEstado()==true){
            cout<<"----------------------------------------------"<<endl;
            cout<<"EL ID DE SALA TIENE LOS SIGUIENTES DATOS"<<endl;
            mostrar();
            setEstado(false);
            if(ModificarEnDisco(pos)==1){
                cout<<"--------------------------"<<endl;
                cout<<"REGISTRO ELIMINADO! "<<endl;
                cout<<"--------------------------"<<endl;
                xd++;
            }
        }
        pos++;
    }
     if(xd==0){
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"        ID DE SALA ES INVALIDO O SE ENCUENTRA DADO DE BAJA"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;}
        }
}

int Salas::ModificarEnDisco(int pos){
    FILE *s;
    s=fopen("salas.dat","rb+");
    if (s==NULL) return -1;
    fseek(s,sizeof(Salas)*pos,0);
    int escribio=fwrite(this,sizeof(Salas),1,s);
    fclose(s);
    return escribio;
}

int Salas::grabarEnDisco(){
    FILE *s;
    s=fopen("salas.dat","ab");
    if (s==NULL) return -1;
    int escribio=fwrite(this,sizeof(Salas),1,s);
    fclose(s);
    return escribio;
}

int Salas::leerEnDisco(int pos){
    FILE *s;
    s=fopen("salas.dat","rb");
    if (s==NULL) return -1;
    fseek(s,sizeof(Salas)*pos,0);
    int leyo=fread(this,sizeof(Salas),1,s);
    fclose(s);
    return leyo;
}




#endif // SALAS_H_INCLUDED
