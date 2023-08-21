#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED
#include "funcionesGlobales.h"
#include "rlutil.h"
///void SubmenuConfiguracion();

void SubmenuConfiguracion(){
    director aux;
    pelicula obj;
    ventas reg;

    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;

    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
         cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        rlutil::locate(4,4);
        cout<<"--- --- --- --- --- --- ---> SUB-MENU CONFIGURACION <--- --- --- --- --- --- --"<<endl;
        rlutil::locate(4,5);
         cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        ShowTime(" --- --- --- COPIA DE SEGURIDAD DEL ARCHIVO DE DIRECTORES        --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- COPIA DE SEGURIDAD DEL ARCHIVO SALAS                --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- COPIA DE SEGURIDAD DEL ARCHIVO PELICULAS            --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- COPIA DE SEGURIDAD DEL ARCHIVO SALAS POR PELICULAS  --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- COPIA DE SEGURIDAD DEL ARCHIVO VENTAS               --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- RESTAURAR DATOS DE DIRECTORES                       --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- RESTAURAR DATOS DE SALAS                            --- --- --- ",4,12,y==6);
        ShowTime(" --- --- --- RESTAURAR DATOS DE PELICULAS                        --- --- --- ",4,13,y==7);
        ShowTime(" --- --- --- RESTAURAR DATOS DE SALAS POR PELICULAS              --- --- --- ",4,14,y==8);
        ShowTime(" --- --- --- RESTAURAR DATOS DE VENTAS                           --- --- --- ",4,15,y==9);
        ShowTime(" --- --- --- ESTABLECER DATOS DE INICIO                          --- --- --- ",4,16,y==10);
        ShowTime(" --- --- --- VOLVER AL MENU PRINCIPAL                            --- --- --- ",4,17,y==11);
        rlutil::locate (4,18);
         cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --"<<endl;

        switch(rlutil::getkey()){
            case 14: ///UP
                rlutil::locate(2,6+y);
                std::cout<<"  "<<std::endl;
                y--;
                if(y<0){
                y=0;
                }
                break;

            case 15: ///DOWN
                rlutil::locate(2,6+y);
                std::cout<<"  "<<std::endl;
                y++;
                if(y>11){
                    y=11;
                }
                break;

            case 1: ///ENTER
                system("cls");
                switch(y+1){
                    case 1:
                        if(backupdirector()==true){
                            cout<<"---------------------------------"<<endl;
                            cout<<"   COPIA DE DIRECTOR REALIZADA!";
                            cout<<"---------------------------------"<<endl;
                        }
                        else {  cout<<"---------------------------------------------------------------"<<endl;
                                cout<<" ERROR, NO SE PUDO HACER LA COPIA DEL ARCHIVO DE DIRECTORES"<<endl;
                                cout<<"---------------------------------------------------------------"<<endl;
                        }
                        break;

                    case 2:
                        if(backupsala()==true){
                            cout<<"------------------------------"<<endl;
                            cout<<"COPIA DE SALA REALIZADA!"<<endl;
                            cout<<"------------------------------"<<endl;
                        }
                        else {  cout<<"---------------------------------------------------------------"<<endl;
                                cout<<"      ERROR! NO SE PUDO HACER LA COPIA DEL ARCHIVO DE SALAS"<<endl;}
                                cout<<"---------------------------------------------------------------"<<endl;
                        break;

                    case 3:
                        if(backuppelicula()==true){
                            cout<<"-------------------------------"<<endl;
                            cout<<"COPIA DE PELICULA REALIZADA!"<<endl;
                            cout<<"-------------------------------"<<endl;
                        }
                        else {  cout<<"---------------------------------------------------------------"<<endl;
                                cout<<"  ERROR!, NO SE PUDO HACER LA COPIA DEL ARCHIVO DE PELICULAS"<<endl;
                                cout<<"---------------------------------------------------------------"<<endl;}
                        break;

                    case 4:
                        if(backupSalaXpeli()==true){
                            cout<<"-------------------------------------------------"<<endl;
                            cout<<"    COPIA DE SALAS POR PELICULAS REALIZADA!";
                            cout<<"-------------------------------------------------"<<endl;
                        }
                        else {  cout<<"-------------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA COPIA DEL ARCHIVO DE PELICULAxSALAS"<<endl;
                                cout<<"-------------------------------------------------------------------"<<endl;}
                        break;
                    case 5:
                        if(backupventa()==true){
                            cout<<"-----------------------------"<<endl;
                            cout<<"COPIA DE VENTA REALIZADA!"<<endl;
                            cout<<"-----------------------------"<<endl;
                        }
                        else {  cout<<"------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA COPIA DEL ARCHIVO DE VENTAS"<<endl;
                                cout<<"------------------------------------------------------------"<<endl;}
                        break;
                    case 6:
                        if(recudirector()==true){
                            cout<<"RECUPERACION  DE DIRECTORES REALIZADA!";
                        }
                        else {  cout<<"----------------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA RECUPERACION DEL ARCHIVO DE DIRECTORES"<<endl;
                                cout<<"----------------------------------------------------------------------"<<endl;}
                        break;
                    case 7:
                        if(recusala()==true){
                            cout<<"---------------------------------------"<<endl;
                            cout<<"RECUPERACION DE SALAS  REALIZADA!"<<endl;
                            cout<<"---------------------------------------"<<endl;
                        }
                         else { cout<<"-----------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA RECUPERACION DEL ARCHIVO DE SALAS"<<endl;
                                cout<<"-----------------------------------------------------------------"<<endl;}
                        break;
                    case 8:
                        if(recupelicula()==true){
                            cout<<"---------------------------------------"<<endl;
                            cout<<"RECUPERACION DE PELICULAS REALIZADA!"<<endl;
                            cout<<"---------------------------------------"<<endl;
                        }
                         else {
                                cout<<"---------------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA RECUPERACION DEL ARCHIVO DE PELICULAS"<<endl;
                                cout<<"---------------------------------------------------------------------"<<endl;}
                        break;
                    case 9:
                        if(recuSalaXpeli()==true){
                            cout<<"------------------------------------------------"<<endl;
                            cout<<"RECUPERACION DE SALAS POR PELICULAS REALIZADA!";
                            cout<<"------------------------------------------------"<<endl;
                        }
                         else { cout<<"--------------------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA RECUPERACION DEL ARCHIVO DE PELICULASxSALAS "<<endl;
                                cout<<"--------------------------------------------------------------------------"<<endl;}
                         break;
                    case 10:
                        if(recuventa()==true){
                            cout<<"--------------------------------------"<<endl;
                            cout<<"RECUPERACION DE VENTAS REALIZADA!";
                            cout<<"--------------------------------------"<<endl;
                        }
                         else { cout<<"-----------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO HACER LA RECUPERACION DEL ARCHIVO DE VENTAS"<<endl;
                                cout<<"-----------------------------------------------------------------"<<endl;   }
                        break;
                    case 11:
                        if(DatosInicio()==1){
                            cout<<"-----------------------------------------------------------------"<<endl;
                            cout<<"EXITO! DATOS DE INICIO PARA TODOS LOS ARCHIVOS, REESTABLECIDO!"<<endl;
                            cout<<"-----------------------------------------------------------------"<<endl;
                        }

                        else {  cout<<"-----------------------------------------------------------------"<<endl;
                                cout<<" ERROR! NO SE PUDO REESTABLECER LOS DATOS DE TODOS LOS ARCHIVOS"<<endl;
                                cout<<"-----------------------------------------------------------------"<<endl;}
                        break;
                    case 12:
                        return;
                        break;
                    default:
                        break;
                }

            cout <<endl;
            system("pause");
            system("cls");

        }

    }while(true);

}

#endif // SUBMENUCONFIGURACION_H_INCLUDED
