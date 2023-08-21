#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#include <ctime>
class pelicula{
private:
    int idPelicula,idDirector, duracion, precio, idioma;
    char nombrePelicula[30], genero[20];

    director direc;
    Salas salaNum;
    bool estado;
public:
    void setidPelicula (int idP){idPelicula=idP;}
    void setidDirector (int idD){idDirector=idD;}
    void setIdioma (int I){idioma=I;}
    void setDuracion (int d){duracion=d;}
    void setPrecio (int p){precio=p;}

    void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
    void setGenero (const char *g){strcpy(genero,g);}
    void setEstado(bool e){estado=e;}

    int getidPelicula (){return idPelicula;}
    int getidDirector (){return idDirector;}
    int getIdioma(){return idioma;}
    int getDuracion (){return duracion;}
    int getPrecio (){return precio;}
    const char *getNombrePelicula (){return nombrePelicula;}
    const char *getGenero (){return genero;}
    bool getEstado(){return estado;}

    int ModificarEnDisco(int pos);
    void EliminarDeDisco();
    int grabarEnDisco();
    int leerEnDisco(int);
    bool cargarPeliculas();

    void cargar(){
        estado=true;
        fflush(stdin);
        idPelicula=autonumericoIDPeliculas()+1;

        cout<<"ID DE PELICULA: "<<idPelicula<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"INGRESE EL NOMBRE DE LA PELICULA: ";
        cargarCadena(nombrePelicula,29);
        cout<<"-------------------------------------------"<<endl;
        cout <<"INGRESE EL GENERO: ";
        cargarCadena(genero,19);
        cout<<"-------------------------------------------"<<endl;
        cout<<"INGRESE EL IDIOMA [ (1=Castellano) , (2=Subtitulado) ] :"<<endl;
        cin>>idioma;
        while ((idioma<=0) || (idioma>=3)){
            cout<<"-------------------------------------------------------------------------------"<<endl;
            cout<<"EL NUMERO DE IDIOMA ESTA FUERA DEL RANGO (1 A 2), INGRESE UN NUMERO NUEVAMENTE"<<endl;
            cout<<"INGRESE EL IDIOMA [ (1=Castellano) , (2=Subtitulado) ] : "<<endl;
            cin>>idioma;
        }

        fflush(stdin);
        cout<<"-------------------------------------------"<<endl;
        cout<<"INGRESE LA DURACION [minutos]: ";
        cin>>duracion;
            while(duracion>240 || duracion<1){
                if(duracion>240){
                cout<<"--------------------------------------------"<<endl;
                cout <<" LA MAXIMA DURACION ES DE 240 MIN (4 HORAS)"<< endl;
                cout<<"--------------------------------------------"<<endl;
                }
                else if(duracion<=0){
                    cout<<"------------------------------------------------------"<<endl;
                    cout <<"NO SE PUEDE ASIGNAR UNA DURACION DE PELICULA MENOR O IGUAL A 0"<< endl;
                    cout<<"-------------------------------------------------------"<<endl;}
                    cout<<"INGRESE EL PRECIO DE LA SALA NUEVAMENTE: " ;
                    cin>>duracion;
            }

        cout<<"-------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DEL DIRECTOR: ";
        cin>>idDirector;
        while(validacionDir(idDirector)==0){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"ESTE DIRECTOR NO SE ENCUENTRA EN LOS REGISTROS"<<endl;
            system("pause");
            system("cls");
            cout<<"-------------------------------------------"<<endl;
            cout<<"INGRESE EL ID DEL DIRECTOR: "<<endl;
            cin>>idDirector;
        }


        director direc;
        int pos3=0;
        while(direc.leerEnDisco(pos3++)==1){
            if(idDirector==direc.getidDirector()){
                cout<<"DIRECTOR: " << direc.getnombreDirector()<<endl;
            }

        }

    }


    void mostrarDirectordePelicula(int idPeli){
    director direc;
    pelicula peli;
    int pos=0, pos1=0;
        while(peli.leerEnDisco(pos++)==1){
            if(idPeli == peli.getidPelicula()){

                while(direc.leerEnDisco(pos1++)==1){
                    ///cout<<"DIRECTOR : "<<peli.getidDirector()<<endl;
                    if(peli.getidDirector()==direc.getidDirector()){
                    cout<<"DIRECTOR : "<<direc.getnombreDirector()<<endl;
                    }
                }
            }
        }
    }

        void mostrarfalse(){
        if(estado==false){
            cout<<"-------------------------------------------------";
            cout<<endl;

            cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
            cout<<"NOMBRE DE LA PELICULA: ";
            cout<<nombrePelicula<<endl;
            cout<<"GENERO: ";
            cout<<genero<<endl;

            if(idioma==1){

            cout<<"IDIOMA "<<idioma<<" = CASTELLANO "<<endl;
            }
            if(idioma==2){
              cout<<"IDIOMA "<<idioma<<" = SUBTITULADO "<<endl;
            }

            cout<<"DURACION: ";
            cout<<duracion<<" MINUTOS"<<endl;
            mostrarDirectordePelicula(idPelicula);
            cout<<"-------------------------------------------------";
        }
        cout<<endl;
    }



    void mostrar(){
        if(estado==true){
            cout<<"-------------------------------------------------";
            cout<<endl;
            cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
            cout<<"NOMBRE DE LA PELICULA: ";
            cout<<nombrePelicula<<endl;
            cout<<"GENERO: ";
            cout<<genero<<endl;

            if(idioma==1){

            cout<<"IDIOMA "<<idioma<<" = CASTELLANO "<<endl;
            }
            if(idioma==2){
              cout<<"IDIOMA "<<idioma<<" = SUBTITULADO "<<endl;
            }

            cout<<"DURACION: ";
            cout<<duracion<<" MINUTOS"<<endl;
            mostrarDirectordePelicula(idPelicula);
            cout<<"-------------------------------------------------";
        }
        cout<<endl;
    }
};

void pelicula::EliminarDeDisco(){
    int pos=0;
    int id;
    int xd=0;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE PELICULA A ELIMINAR O 0 (cero) PARA SALIR: ";
    cin>>id;

    if(id==0){
            cout<<"-------------------------------------------"<<endl;
            cout<<"  USTED A INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-------------------------------------------"<<endl;
            return;
    }

    while(leerEnDisco(pos)==1){
        if(getidPelicula()==id && getEstado()==true){
            cout<<"-------------------------------------------------"<<endl;
            cout<<"  EL ID DE PELICULA TIENE LOS SIGUIENTES DATOS  "<<endl;
            cout<<"-------------------------------------------------"<<endl;
            mostrar();
            setEstado(false);
            if(ModificarEnDisco(pos)==1){
                cout<<"----------------------"<<endl;
                cout<<"  REGISTRO ELIMINADO! "<<endl;
                cout<<"----------------------"<<endl;
                xd++;
            }
        }
        pos++;
    }
    if(xd==0){
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"   ID DE PELICULA ES INVALIDO O SE ENCUENTRA DADO DE BAJA"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;}

}

bool pelicula::cargarPeliculas(){
        FILE *p;
        bool escribio;
        pelicula reg;
        p=fopen("pelicula.dat","ab");
        if (p==NULL) return false;
        cargar();
        escribio=fwrite(this,sizeof reg, 1,p);
        fclose(p);
        return escribio;
    }

int pelicula::ModificarEnDisco(int pos){
    FILE *p;
    p=fopen("pelicula.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(pelicula)*pos,0);
    int escribio=fwrite(this,sizeof(pelicula),1,p);
    fclose(p);
    return escribio;
}

int pelicula::grabarEnDisco(){
    FILE *p;
    p=fopen("pelicula.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(pelicula),1,p);
    fclose(p);
    return escribio;
}

int pelicula::leerEnDisco(int pos){
    FILE *p;
    p=fopen("pelicula.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(pelicula)*pos,0);
    int leyo=fread(this,sizeof(pelicula),1,p);
    fclose(p);
    return leyo;
}



#endif // PELICULAS_H_INCLUDED
