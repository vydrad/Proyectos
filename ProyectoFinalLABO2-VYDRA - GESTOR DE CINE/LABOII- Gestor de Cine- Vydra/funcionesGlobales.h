#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include "peliculas.h"
#include "rlutil.h"


///void ShowTime(const char* text, int posx, int posy, bool selected);

void ShowTime(const char* text, int posx, int posy, bool selected){
    if (selected){
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::locate(posx-2,posy);
        std::cout<<(char)175<<" "<<text<<" "<<(char)174<<std::endl;
    }
    else{
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::locate(posx-2,posy);
        std::cout<<"  "<<text<<"    "<<std::endl;
    }
    rlutil::setBackgroundColor(rlutil::BLACK);
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


int validacionSalafalsa(int id);
int validacionpeliculafalsa(int id);
int validaciondirectorfalso(int id);
int validacionSalaporpeliculafalso(int id);
int validacionVentafalsa(int id);


void DardealtaVentas(){
    ventas obj;
    int pos=0, pos1=0;
    int idS;
    int aux=0;

    cout<<"-----------------------------------------------"<<endl;
    cout<<"LAS VENTAS QUE SE PUEDEN RECUPERAR SON:"<<endl;
    while(obj.leerEnDisco(pos1++)==1){
        if(obj.getEstado()==false){
            obj.mostrarfalse();
            aux++;
        }
   }
      if(aux==0){cout<<"-----------------------------------------------"<<endl;
                cout<<"      NO HAY VENTAS QUE ESTEN ELIMINADAS "<<endl;
                cout<<"-----------------------------------------------"<<endl;
    }
    else{

    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE VENTA ELIMINADO PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
    cin>>idS;
    if(idS==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return;
    }

    while(validacionVentafalsa(idS)==0){
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"  EL ID DE VENTA PINGRESADO ES INVALIDO O 'NO' SE ENCUENTRA DADO DE BAJA"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"POR FAVOR INTRODUZCA EL ID DE VENTA ELIMINADO NUEVAMENTE PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
        cin>>idS;
        if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
            return;
        }
    }


        while(obj.leerEnDisco(pos)==1){
            if(obj.getNventa()==idS && obj.getEstado()==false){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"EL ID DE VENTA RECUPERADO TIENE LOS SIGUIENTES DATOS:"<<endl;
                obj.mostrarfalse();
                obj.setEstado(true);
                if(obj.ModificarEnDisco(pos)==1){
                cout<<"-----------------------"<<endl;
                cout<<"  REGISTRO RECUPERADO! "<<endl;
                cout<<"-----------------------"<<endl;

            }
        }
        pos++;
        }
    }
 return;



}

void DardealtaSalasporpelicula(){
    SalasPorPelicula obj;
    int pos=0, pos1=0;
    int idS;
    int aux=0;

    cout<<"-----------------------------------------------"<<endl;
    cout<<"LAS SALAS POR PELICULAS QUE SE PUEDEN RECUPERAR SON:"<<endl;
    while(obj.leerEnDisco(pos1++)==1){
        if(obj.getEstado()==false){
            obj.mostrarfalse();
            aux++;
        }
   }
    if(aux==0){ cout<<"-------------------------------------------------------"<<endl;
                cout<<"      NO HAY SALAS POR PELICULA QUE ESTEN ELIMINADAS "<<endl;
                cout<<"-------------------------------------------------------"<<endl;
    }
    else{

    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID SALA POR PELICULA ELIMINADO PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
    cin>>idS;
    if(idS==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return;
    }

    while(validacionSalaporpeliculafalso(idS)==0){
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"   ID DE SALA POR PELICULA INGRESADO ES INVALIDO O 'NO' SE ENCUENTRA DADO DE BAJA"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"POR FAVOR INTRODUZCA EL ID SALA POR PELICULA ELIMINADO NUEVAMENTE PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
        cin>>idS;
        if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
            return;
        }
    }


        while(obj.leerEnDisco(pos)==1){
            if(obj.getidSala()==idS && obj.getEstado()==false){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"EL ID DE SALA POR PELICULA RECUPERADO TIENE LOS SIGUIENTES DATOS:"<<endl;
                obj.mostrarfalse();
                obj.setEstado(true);
                if(obj.ModificarEnDisco(pos)==1){
                cout<<"-----------------------"<<endl;
                cout<<"  REGISTRO RECUPERADO! "<<endl;
                cout<<"-----------------------"<<endl;

            }
        }
        pos++;
        }
    }
 return;



}


void DardealtaDirector(){
    director obj;
    int pos=0, pos1=0;
    int idS;
    int aux=0;

    cout<<"-----------------------------------------------"<<endl;
    cout<<"LOS DIRECTORES QUE SE PUEDEN RECUPERAR SON:"<<endl;
    while(obj.leerEnDisco(pos1++)==1){
        if(obj.getEstado()==false){
            obj.mostrarfalse();
            aux++;
        }

   }
   if(aux==0){  cout<<"-----------------------------------------------"<<endl;
                cout<<"      NO HAY DIRECTORES QUE ESTEN ELIMINADOS "<<endl;
                cout<<"-----------------------------------------------"<<endl;
    }
    else{
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE DIRECTOR ELIMINADO PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
    cin>>idS;
    if(idS==0){
            cout<<"---------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return;
    }

    while(validaciondirectorfalso(idS)==0){
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"   ID DE DIRECTOR INGRESADO ES INVALIDO O 'NO' SE ENCUENTRA DADO DE BAJA"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"POR FAVOR INTRODUZCA EL ID DE DIRECTOR ELIMINADO NUEVAMENTE PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
        cin>>idS;
        if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
            return;
        }
    }


        while(obj.leerEnDisco(pos)==1){
            if(obj.getidDirector()==idS && obj.getEstado()==false){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"EL ID DE DIRECTOR RECUPERADO TIENE LOS SIGUIENTES DATOS:"<<endl;
                obj.mostrarfalse();
                obj.setEstado(true);
                if(obj.ModificarEnDisco(pos)==1){
                cout<<"-----------------------"<<endl;
                cout<<"  REGISTRO RECUPERADO! "<<endl;
                cout<<"-----------------------"<<endl;

            }
        }
        pos++;
        }


    }
 return;

   }





void DardealtaPelicula(){
    pelicula obj;
    int pos=0, pos1=0;
    int idS;
    int aux=0;

    cout<<"-----------------------------------------------"<<endl;
    cout<<"LAS PELICULAS QUE SE PUEDEN RECUPERAR SON:"<<endl;
    while(obj.leerEnDisco(pos1++)==1){
        if(obj.getEstado()==false){
            obj.mostrarfalse();
            aux++;
        }
   }

    if(aux==0){ cout<<"-----------------------------------------------"<<endl;
                cout<<"     NO HAY PELICULAS QUE ESTEN ELIMINADAS "<<endl;
                cout<<"-----------------------------------------------"<<endl;
    }
    else{

    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE PELICULA ELIMINADO PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
    cin>>idS;
    if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
            return;
    }

    while(validacionpeliculafalsa(idS)==0){
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"   ID DE PELICULA INGRESADO ES INVALIDO O 'NO' SE ENCUENTRA DADO DE BAJA"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"POR FAVOR INTRODUZCA EL ID DE PELICULA ELIMINADO NUEVAMENTE PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
        cin>>idS;
        if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
            return;
        }
    }


        while(obj.leerEnDisco(pos)==1){
            if(obj.getidPelicula()==idS && obj.getEstado()==false){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"EL ID DE PELICULA RECUPERADO TIENE LOS SIGUIENTES DATOS:"<<endl;
                obj.mostrarfalse();
                obj.setEstado(true);
                if(obj.ModificarEnDisco(pos)==1){
                cout<<"-----------------------"<<endl;
                cout<<"  REGISTRO RECUPERADO! "<<endl;
                cout<<"-----------------------"<<endl;

            }
        }
        pos++;
        }
    }
 return;

   }



void DardealtaSala(){
    Salas obj;
    int pos=0, pos1=0;
    int idS;
    int aux=0;

    cout<<"-----------------------------------------------"<<endl;
    cout<<"LAS SALAS QUE SE PUEDEN RECUPERAR SON:"<<endl;
    while(obj.leerEnDisco(pos1++)==1){
        if(obj.getEstado()==false){
            obj.mostrarfalse();
            aux++;
        }
   }

    if(aux==0){ cout<<"-----------------------------------------------"<<endl;
                cout<<"      NO HAY SALAS QUE ESTEN ELIMINADAS "<<endl;
                cout<<"-----------------------------------------------"<<endl;
    }
    else{

    cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"INTRODUZCA EL ID DE SALA ELIMINADO PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
    cin>>idS;
    if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"-----------------------------------------"<<endl;
            return;
    }



    while(validacionSalafalsa(idS)==0){
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"   ID DE SALA INGRESADO ES INVALIDO O 'NO' SE ENCUENTRA DADO DE BAJA"<<endl;
        cout<<"-----------------------------------------------------------------------"<<endl;
        cout<<"POR FAVOR INTRODUZCA EL ID DE SALA ELIMINADO NUEVAMENTE PARA VOLVER A RECUPERARLO O 0 (cero) PARA SALIR: ";
        cin>>idS;
        if(idS==0){
            cout<<"-----------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            return;
        }
    }

        while(obj.leerEnDisco(pos)==1){
            if(obj.getidSala()==idS && obj.getEstado()==false){
                cout<<"-----------------------------------------------"<<endl;
                cout<<"EL ID DE SALA RECUPERADO TIENE LOS SIGUIENTES DATOS:"<<endl;
                obj.mostrarfalse();
                obj.setEstado(true);
                if(obj.ModificarEnDisco(pos)==1){
                cout<<"-----------------------"<<endl;
                cout<<"  REGISTRO RECUPERADO! "<<endl;
                cout<<"-----------------------"<<endl;

            }
        }
        pos++;
        }

        }
   return;
}







///PELICULAS
void mostrarpeliculasporID(){
        pelicula obj;
        int pos=0;
        int Idbuscar, aux=0;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE PELICULA A BUSCAR O 0 (cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
        cin>>Idbuscar;

        if(Idbuscar==0){
            cout<<"------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO "<<endl;
            cout<<"------------------------------------------"<<endl;
            return;
        }
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                if(obj.getidPelicula()==Idbuscar){
                    obj.mostrar();
                    aux++;
                }
            }
            else if(obj.getidPelicula()==Idbuscar){
                    cout<<"-------------------------------"<<endl;
                    cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
                    cout<<"-------------------------------"<<endl;
                    aux++;
                }
        }


        if(aux==0){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"NO HUBO COINCIDENCIAS CON EL NRO DE ID DE DIRECTOR INGRESADO"<<endl;
            cout<<"------------------------------------------------------------"<<endl;
        }
    }

void mostrarPeliculas(){
        pelicula obj;
        FILE *p;
        p=fopen("pelicula.dat","rb");
        if (p==NULL) return;
        while(fread(&obj,sizeof (pelicula),1,p)==1){
            obj.mostrar();
        }
        fclose(p);
    }
///BACKUP
int LeerDeDiscobkpPELI(int pos){
    FILE *A;
    pelicula obj;
    A=fopen("backup/pelicula.bkp","rb");
    if(A==NULL){
        cout<<"ERROR DE LECTURA!";
        return-1;
    }
    fseek(A,sizeof(pelicula)*pos,0);
    int leyo=fread(&obj,sizeof(pelicula),1,A);
    fclose(A);
    return leyo;
}

bool backuppelicula(){
    int pos=0;
    FILE *b;
    pelicula obj;
    b=fopen("backup/pelicula.bkp","wb");
    //b=fopen("datosiniciales/peliculaInicio.bkp","wb");
    if(b==NULL){
        return false;
    }
    while(obj.leerEnDisco(pos)==1){
        fwrite(&obj,sizeof(pelicula),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){
        return false;
    }
    return true;
}

bool recupelicula(){
    int pos=0;
    pelicula obj;
    FILE *br;
    br=fopen("pelicula.dat","wb");
    if(br==NULL){
        return false;
    }
    while(LeerDeDiscobkpPELI(pos)==1){
        fwrite(&obj,sizeof(pelicula),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){
        return false;
    }
    return true;
}



///VENTAS
void mostrarventasporID(){
        ventas obj;
        int pos=0;
        int Idbuscar, aux=0;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE LA VENTA A BUSCAR O 0 (cero) PARA SALIR AL MENU ANTERIOR :"<<endl;
        cin>>Idbuscar;
        if(Idbuscar==0){
            cout<<"------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO "<<endl;
            cout<<"------------------------------------------"<<endl;
            return;
        }
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                if(obj.getNventa()==Idbuscar){
                    obj.mostrar();
                    aux++;
                }
            }
            else if(obj.getNventa()==Idbuscar){
                    cout<<"-------------------------------"<<endl;
                    cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
                    cout<<"-------------------------------"<<endl;
                    aux++;
                }
        }


        if(aux==0){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"NO HUBO COINCIDENCIAS CON EL NRO DE ID DE DIRECTOR INGRESADO"<<endl;
            cout<<"------------------------------------------------------------"<<endl;
        }
    }




    void mostrarVentas(){
        FILE *p;
        ventas obj;
        p=fopen("ventas.dat","rb");
        if (p==NULL) return;
        while(fread(&obj,sizeof (ventas),1,p)==1){
            obj.mostrar();
        }
        fclose(p);
    }
///BACKUP
int LeerDeDiscobkpVentas(int pos){
    FILE *A;
    ventas obj;
    A=fopen("backup/ventas.bkp","rb");
    if(A==NULL){
        cout<<"ERROR DE LECTURA!";
        return-1;
    }
    fseek(A,sizeof(ventas)*pos,0);
    int leyo=fread(&obj,sizeof(ventas),1,A);
    fclose(A);
    return leyo;
}

bool backupventa(){
    int pos=0;
    FILE *b;
    ventas obj;
    b=fopen("backup/ventas.bkp","wb");
    //b=fopen("datosiniciales/ventasInicio.bkp","wb");
    if(b==NULL){
        return false;
    }
    while(obj.leerEnDisco(pos)==1){
        fwrite(&obj,sizeof(ventas),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){
        return false;
    }
    return true;
}

bool recuventa(){
    int pos=0;
    ventas obj;
    FILE *br;
    br=fopen("ventas.dat","wb");
    if(br==NULL){
        return false;
    }
    while(LeerDeDiscobkpVentas(pos)==1){
        fwrite(&obj,sizeof(ventas),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){
        return false;
    }
    return true;

}

/// SALAS X PELICULAS
void mostrarsalasporpeliculasporID(){
        SalasPorPelicula obj;
        int pos=0;
        int Idbuscar, aux=0;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE SALA POR PELICULA A BUSCAR o 0 PARA SALIR AL MENU ANTERIOR: "<<endl;
        cin>>Idbuscar;
        if(Idbuscar==0){
            cout<<"------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO "<<endl;
            cout<<"------------------------------------------"<<endl;
            return;
        }
        else{

            while(obj.leerEnDisco(pos++)==1){
                    if(obj.getidSala()==Idbuscar && obj.getEstado()==1){
                        obj.mostrar();
                        cout<<"-----------------------------------"<<endl;
                        aux++;
                    }

            }

        if(aux==0){
            cout<<"-----------------------------------------------------------------------"<<endl;
            cout<<"NO HUBO COINCIDENCIAS CON EL NRO DE ID DE SALA POR PELICULA INGRESADO"<<endl;
            cout<<"-----------------------------------------------------------------------"<<endl;
        }
        }

    }

    void mostrarSalasPorPelicula(){
        FILE *p;
        SalasPorPelicula obj;
        p=fopen("salasPorPelicula.dat","rb");
        if (p==NULL) return;

        while(fread(&obj,sizeof (SalasPorPelicula),1,p)==1){
            obj.mostrar();
        }
        fclose(p);
    }
///BACKUP
int LeerDeDiscobkpSALAXPELI(int pos){
    FILE *A;
    SalasPorPelicula obj;
    A=fopen("backup/salasPorPelicula.bkp","rb");
    if(A==NULL)
    {   cout<<"------------------"<<endl;
        cout<<"ERROR DE LECTURA!"<<endl;
        cout<<"------------------"<<endl;
        return-1;
    }
    fseek(A,sizeof(SalasPorPelicula)*pos,0);
    int leyo=fread(&obj,sizeof(SalasPorPelicula),1,A);
    fclose(A);
    return leyo;
}

bool backupSalaXpeli(){
    int pos=0;
    SalasPorPelicula obj;
    FILE *b;
    b=fopen("backup/salasPorPelicula.bkp","wb");
    //b=fopen("datosiniciales/SalasPorPeliculaInicio.bkp","wb");
    if(b==NULL){
        return false;
    }
    while(obj.leerEnDisco(pos)==1){
        fwrite(&obj,sizeof(SalasPorPelicula),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){
        return false;
    }
    return true;
}

bool recuSalaXpeli(){
    int pos=0;
    FILE *br;
    SalasPorPelicula obj;
    br=fopen("salasPorPelicula.dat","wb");
    if(br==NULL){
        return false;
    }
    while(LeerDeDiscobkpSALAXPELI(pos)==1){
        fwrite(&obj,sizeof(SalasPorPelicula),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){
        return false;
    }
    return true;
}


///SALAS

void mostrarsalasporID(){
        Salas obj;
        int pos=0;
        int Idbuscar, aux=0;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE SALA A BUSCAR O 0 (cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
        cin>>Idbuscar;

        if(Idbuscar==0){
            cout<<"------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO "<<endl;
            cout<<"------------------------------------------"<<endl;
            return;
        }
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                if(obj.getidSala()==Idbuscar){
                    obj.mostrar();
                    aux++;
                }
            }
            else if(obj.getidSala()==Idbuscar){
                    cout<<"-------------------------------"<<endl;
                    cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
                    cout<<"-------------------------------"<<endl;
                    aux++;
                }
        }

        if(aux==0){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"NO HUBO COINCIDENCIAS CON EL NRO DE ID DE SALA INGRESADO"<<endl;
            cout<<"------------------------------------------------------------"<<endl;
        }
    }



void mostrarDeDiscoSALA(){
    int pos=0;
    Salas obj;
    while(obj.leerEnDisco(pos++)==1){
        obj.mostrar();
    }
}

///BACKUP
int LeerDeDiscobkpSALA(int pos){
    FILE *A;
    Salas obj;
    A=fopen("backup/sala.bkp","rb");
    if(A==NULL){
        cout<<"ERROR DE LECTURA!";
        return-1;
    }
    fseek(A,sizeof(Salas)*pos,0);
    int leyo=fread(&obj,sizeof(Salas),1,A);
    fclose(A);
    return leyo;
}

bool backupsala(){
    int pos=0;
    FILE *b;
    Salas obj;
    b=fopen("backup/sala.bkp","wb");
    if(b==NULL){
        return false;
    }
    while(obj.leerEnDisco(pos)==1){
        fwrite(&obj,sizeof(Salas),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){
        return false;
    }
    return true;
}

bool recusala(){
    int pos=0;
    FILE *br;
    Salas obj;
    br=fopen("salas.dat","wb");
    if(br==NULL){
        return false;
    }
    while(LeerDeDiscobkpSALA(pos)==1){
        fwrite(&obj,sizeof(Salas),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){
        return false;
    }
    return true;
}


///DIRECTORES
void mostrardirectoresporID(){
        director obj;
        int pos=0;
        int Idbuscar, aux=0;
        cout<<"------------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DE DIRECTOR A BUSCAR O 0 (cero) PARA SALIR AL MENU ANTERIOR: "<<endl;
        cin>>Idbuscar;
        if(Idbuscar==0){
            cout<<"------------------------------------------"<<endl;
            cout<<"USTED HA INGRESADO 0, USTED ESTA SALIENDO "<<endl;
            cout<<"------------------------------------------"<<endl;
            return;
        }
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                if(obj.getidDirector()==Idbuscar){
                    obj.mostrar();
                    aux++;
                }
            }
            else if(obj.getidDirector()==Idbuscar){
                    cout<<"-------------------------------"<<endl;
                    cout<<"EL REGISTRO ESTA DADO DE BAJA"<<endl;
                    cout<<"-------------------------------"<<endl;
                    aux++;
                }
        }


        if(aux==0){
            cout<<"------------------------------------------------------------"<<endl;
            cout<<"NO HUBO COINCIDENCIAS CON EL NRO DE ID DE DIRECTOR INGRESADO"<<endl;
            cout<<"------------------------------------------------------------"<<endl;
        }
    }


void mostrardirectores(){
        FILE *p;
        director obj;
        p=fopen("director.dat","rb");
        if (p==NULL) return;
        while(fread(&obj,sizeof (director),1,p)==1){
            obj.mostrar();
        }
        fclose(p);
    }
///BACKUP
int LeerDeDiscobkpDIR(int pos){
    FILE *A;
    director obj;
    A=fopen("backup/director.bkp","rb");
    if(A==NULL){
        cout<<"ERROR DE LECTURA!";
        return-1;
    }
    fseek(A,sizeof(director)*pos,0);
    int leyo=fread(&obj,sizeof(director),1,A);
    fclose(A);
    return leyo;
}

bool backupdirector(){
    int pos=0;
    FILE *b;
    director obj;
    b=fopen("backup/director.bkp","wb");
    //b=fopen("datosiniciales/directoresInicio.bkp","wb");
    if(b==NULL){
        return false;}
    while(obj.leerEnDisco(pos)==1){
        fwrite(&obj,sizeof(director),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){
        return false;}
    return true;
}

bool recudirector(){
    int pos=0;
    FILE *br;
    director obj;
    br=fopen("director.dat","wb");
    if(br==NULL){
        return false;
    }
    while(LeerDeDiscobkpDIR(pos)==1){
        fwrite(&obj,sizeof(director),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){
        return false;
    }
    return true;

}


int validacionIDpelicula(int id){
    pelicula reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidPelicula()==id && reg.getEstado()==true){
            return 1;
        }
    }
    return 0;
}
int validacionIDventa(int id){
    ventas reg;
    int pos=0;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getNventa()==id && reg.getEstado()==true){
            return 1;
        }
    }
    return 0;
}

int validacionDir(int id){
    director aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidDirector()==id&&aux.getEstado()==true){
           /// cout<<"DIRECTOR:"<<aux.getnombreDirector();
            return 1;
        }
    }
    return 0;
}

int validacionSala(int id){
Salas aux;
int pos=0;
while(aux.leerEnDisco(pos++)==1){
    if(aux.getidSala()==id && aux.getEstado()==true){
        return 1;
    }

}
return 0;
}


int validacionSalafalsa(int id){
    Salas aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidSala()==id && aux.getEstado()==false){
            return 1;
        }
    }
    return 0;
}


int validacionVentafalsa(int id){
    ventas aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getNventa()==id && aux.getEstado()==false){
            return 1;
        }
    }
    return 0;
}



int validacionSalaporpeliculafalso(int id){
    SalasPorPelicula aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidSala()==id && aux.getEstado()==false ){
            return 1;
        }
    }
    return 0;
}


int validacionpeliculafalsa(int id){
    pelicula aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidPelicula()==id && aux.getEstado()==false){
            return 1;
        }
    }
    return 0;
}
int validaciondirectorfalso(int id){
    director aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidDirector()==id && aux.getEstado()==false){
            return 1;
        }
    }
    return 0;
}

int validacionModificarPeliculasPorSala(int id){
    SalasPorPelicula aux;
    int pos=0, pos2=0;
    Salas reg;
    bool auxi=false;
    while(reg.leerEnDisco(pos2++)==1){
            if(id==reg.getidSala() && reg.getEstado()==true){
                auxi=true;

            }

        }

    while(aux.leerEnDisco(pos++)==1){
        if(id==aux.getidSala()&& aux.getEstado()==true){
            auxi=false;
        }
    }

    if(auxi){
        return 1;
    }
    else{
    return 0;}
}

int validacionSalaPelicula(int id,int idp){
    SalasPorPelicula aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidPelicula()==idp && aux.getEstado()==true && aux.getidSala()==id){

        return 1;
        }

    }

    return 0;

}


int validacionSalasPorPelicula(int id){
    SalasPorPelicula aux;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidSala()==id&&aux.getEstado()==true){
          ///  aux.mostrar();
            return 1;
        }
    }
    return 0;
}

int validacionSalasPorPelicula2(int id, int idp){
    SalasPorPelicula aux;
    int pos=0,pos1=0, pos2=0, flag1=0,flag2=0;
    Salas auxi1;
    pelicula auxi2;

    while(auxi1.leerEnDisco(pos1++)==1){
        if(auxi1.getidSala()==id && auxi1.getEstado()==false){
        flag1++;
        }

    }

    while(auxi2.leerEnDisco(pos2++)==1){
        if(auxi2.getidPelicula()==idp && auxi2.getEstado()==false){
        flag2++;
        }

    }

    if((flag1+flag2)==0){
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidSala()==id&&aux.getEstado()==true &&aux.getidPelicula()==idp){
            cout<<"SE ENCUENTRA EN LA SALA: "<<aux.getidSala()<<endl;
            return 1;
            }
        }
    }
    else{
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"ERROR! EL NUMERO DE SALA INGRESADO NO COINCIDE CON NINGUNA EN CARTELERA!"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    ///return 0;
    }
    return 0;
}


int validacionPeliculaEnSalas(int id){
    SalasPorPelicula aux;
    int pos=0;
    int val=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidPelicula()==id&&aux.getEstado()==true){
            aux.mostrar();
            val++;
        }
    }
    if(val>0){
    return 1;
    }
    else{
    return 0;
    }
}

int validacionPrecio(int precio, int pago){
    int importe;
    importe=precio;
    if(pago==1){
        importe=importe*0.95;
    }
    else if(pago==2){
        importe=importe*1.20;
        }
        else{
        importe=importe*1.05;
        }
    return importe;
}

int autonumericoIDdirectores(){
    director obj;
    int pos=0;
    int c=0;
    while(obj.leerEnDisco(pos++)==1){
        c++;
    }
    return c;
}

int autonumericoIDPeliculas(){
    pelicula obj;
    int pos=0;
    int c=0;
    while(obj.leerEnDisco(pos++)==1){
        c++;
    }
    return c;
}
int autonumericoIDSalas(){
    Salas obj;
    int pos=0;
    int c=0;
    while(obj.leerEnDisco(pos++)==1){
        c++;
    }
    return c;
}

int autonumericoIDVentas(){
    ventas obj;
    int pos=0;
    int c=0;
    while(obj.leerEnDisco(pos++)==1){
        c++;
    }
    return c;
}

///CLASE VENTAS
int cantButacasSala(int id){
    Salas aux;
    int cantbutacas=0;
    int pos=0;
    while(aux.leerEnDisco(pos++)==1){
        if(aux.getidSala()==id){
            cantbutacas=aux.getPlazas();
            return cantbutacas;
        }
    }
    return 0;
}

int calcularVentas(int id){
    ventas obj;
    Salas reg;
    int ventas=0;
    int pos=0;
    int pos2=0;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidSala()==id){
            while(obj.leerEnDisco(pos2++)==1){
                if(obj.getidSala()==id){
                    ventas+=obj.getCantEntradas();
                }
            }
        }
    }
    return ventas;
}

int DatosInicio(){
    director obj;
    FILE *p,*pNuevo;
    p=fopen("datosiniciales/directoresInicio.bkp","rb");
    pNuevo=fopen("director.dat", "wb");
    if(p==NULL){
        cout<<"no abrio directoresInicio.bkp "<<endl;
        return false;
    }
    if(pNuevo==NULL){
        cout<<"no abrio director.dat "<<endl;
        return false;
    }
    while(fread(&obj,sizeof obj,1,p)==1){
        if(obj.getEstado()==true){
            fwrite(&obj, sizeof obj,1, pNuevo);
        }
    }
    fclose(p);
    fclose(pNuevo);

    ///
    Salas reg;
    FILE *q,*pNuevo1;
    q=fopen("datosiniciales/salasInicio.bkp","rb");
    pNuevo1=fopen("salas.dat", "wb");
    if(q==NULL){
        cout<<"no abrio directoresInicio.bkp "<<endl;
        return false;
    }
    if(pNuevo1==NULL){
        cout<<"no abrio salas.dat "<<endl;
        return false;
    }
    while(fread(&reg,sizeof reg,1,q)==1){
        if(reg.getEstado()==true){
            fwrite(&reg, sizeof reg,1, pNuevo1);
        }
    }
    fclose(q);
    fclose(pNuevo1);

    ///

    pelicula lis;
    FILE *w,*pNuevo2;
    w=fopen("datosiniciales/peliculaInicio.bkp","rb");
    pNuevo2=fopen("pelicula.dat", "wb");
    if(w==NULL){
        cout<<"no abrio peliculaInicio.bkp "<<endl;
        return false;
    }
    if(pNuevo2==NULL){
        cout<<"no abrio pelicula.dat "<<endl;
        return false;
    }
    while(fread(&lis,sizeof lis,1,w)==1){
        if(lis.getEstado()==true){
            fwrite(&lis, sizeof lis,1, pNuevo2);
        }
    }
    fclose(w);
    fclose(pNuevo2);
    ///

    SalasPorPelicula aux;
    FILE *p3,*pNuevo3;
    p3=fopen("datosiniciales/SalasPorPeliculaInicio.bkp","rb");
    pNuevo3=fopen("SalasPorPelicula.dat", "wb");
    if(p3==NULL){
        cout<<"no abrio SalasPorPeliculaInicio.bkp "<<endl;
        return false;
    }
    if(pNuevo3==NULL){
        cout<<"no abrio SalasPorPelicula.dat "<<endl;
        return false;
    }
    while(fread(&aux,sizeof aux,1,p3)==1){
        if(aux.getEstado()==true){
            fwrite(&aux, sizeof aux,1, pNuevo3);
        }
    }
    fclose(p3);
    fclose(pNuevo3);

    ///

    ventas ven;
    FILE *p4,*pNuevo4;
    p4=fopen("datosiniciales/ventasInicio.bkp","rb");
    pNuevo4=fopen("ventas.dat", "wb");
    if(p4==NULL){
        cout<<"no abrio ventas.bkp "<<endl;
        return false;
    }
    if(pNuevo4==NULL){
        cout<<"no abrio ventas.dat "<<endl;
        return false;
    }
    while(fread(&ven,sizeof ven,1,p4)==1){
        if(ven.getEstado()==true){
            fwrite(&ven, sizeof ven,1, pNuevo4);
        }
    }
    fclose(p4);
    fclose(pNuevo4);

    return true;
    }



#endif // FUNCIONESGLOBALES_H_INCLUDED
