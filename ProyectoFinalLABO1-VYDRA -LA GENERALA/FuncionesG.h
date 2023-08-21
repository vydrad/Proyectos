#ifndef FUNCIONESG_H_INCLUDED
#define FUNCIONESG_H_INCLUDED
#include "rlutil.h"
using namespace std;
/// DAVID THOMAS VYDRA

void twoplayers(char puntajemaximo[],int& puntajemax);
void oneplayer(char puntajemaximo[],int& puntajemax);

void ShowTime(const char* text, int posx, int posy, bool seleccionado);
void CargarVectorjugador(int vecpuntosj1[],int tam);

void ponerCero (int vec[], int tam);
void cargarAleatorio(int vec[], int tam, int limite);
void mostrarVector(int vec[], int tam);

void cargarAleatorioen0(int vec[], int tam, int limite);

void Cuantos(int vec1[],int x,int qwe);

void GuardarNumerosRepetidos(int vecvalores[],int vecj1[],int vecrep[],int limite);
bool generala(int vecpuntosj1[],int vecrep[],int limite);
bool poker(int vecpuntosj1[],int vecrep[],int limite);
bool full(int vecpuntosj1[],int vecrep[],int limite);
bool escalera(int vecpuntosj1[],int vecrep[],int limite);
bool generala2(int vecpuntosj1[],int vecrep[],int limite);

void AsignarPdisponible(int vecpuntosj1[],int vecrep[],bool esca, bool ful,bool po, bool gene);

void mostrarVectorTabla1(int vec[], int tam);

int sumarVectorjugadores(int vec[], int tam );///sumador de NO-1

void oneplayer(char puntajemaximo[],int& puntajemax){

system("cls");

int i;
int rondas, Crondas=0, Ctiros=0, Ctirostot=0;
const int limite=6;
int vectorj1 [5];
int vectorvalores [6]= {1,2,3,4,5,6};
int vectorep [6];
int vectorpuntosj1 [10];
char jugador1[30];


    CargarVectorjugador(vectorpuntosj1,10);
    rlutil::showcursor();

    rlutil::locate(4,3);
    cout<<"---------------------*****BIENVENIDO--A--LA*****-----------------------"<<endl;
    rlutil::locate(4,4);
    cout<<"--------------------------****GENERALA****-----------------------------"<<endl;
    rlutil::locate(4,5);
    cout<<"---------------------------------***-----------------------------------"<<endl;
    rlutil::locate(4,6);
    cout<<"------------------------1-JUGADOR/SOLITARIO----------------------------"<<endl;
    rlutil::locate(4,8);
    cout<<"-----------------------------------------------------------------------"<<endl;
    rlutil::locate(4,9);
    cout<<"-------------------JUGADOR 1 INGRESE SU NOMBRE ABAJO:------------------"<<endl;
    rlutil::locate(4,10);
    cout<<"-----------------------------------------------------------------------"<<endl;
    rlutil::locate(4,11);
    cin.getline(jugador1,30,'\n');
    rlutil::locate(4,12);
    cout<<"-----------------------------------------------------------------------"<<endl;
    rlutil::locate(4,13);
    cout<<"----------------¿CUANTAS RONDAS QUIERE JUGAR? (10-MAX)-----------------"<<endl;
    rlutil::locate(4,14);
    cout<<"-----------------------------------------------------------------------"<<endl;
    rlutil::locate(4,15);
    cin >> rondas ;
    rlutil::locate(4,16);
    cout<< "----------------------------------------------------------------------"<<endl;
    system ("cls");

    for (i=1;i<=rondas;i++){

        Crondas+=1;
        Ctiros=0;

        rlutil::locate(4,2);
        cout<<"--------------------------------------------------"<<endl;
        rlutil::locate(4,3);
        cout<<"---------------RONDA: "<<Crondas<<"--------------------------"<<endl;
        rlutil::locate(4,4);
        cout<<"-------------LANZAMIENTOS:"<<Ctirostot <<"----------------------"<<endl;
        rlutil::locate(4,5);
        cout<<"------------PUNTAJE ACUMULADO:"<<sumarVectorjugadores(vectorpuntosj1,10) <<"------------------"<<endl;
        rlutil::locate(4,6);
        cout<<"--------------------------------------------------"<<endl;

        system("pause");
        system ("cls");

        Ctiros+=1;
        Ctirostot+=1;

        int y=0,qw=1;


        while (qw!=0){

            rlutil::hidecursor();

            rlutil::locate(2,6+y);
            std::cout<<(char)175<<std::endl;

            rlutil::locate(4,2);
            cout<< "----------NOMBRE: "<< jugador1 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj1,10) <<"----- "<<endl;
            rlutil::locate(4,3);
            cout << "----------RONDA NUMERO #"<<Crondas<<"-------"<<"TIRO #"<<Ctiros<<"-------------------"<<endl;
            rlutil::locate(4,4);
            cout << "----------COMENZAR TIRO DE DADOS ?  SI / NO --------------" <<endl;
            rlutil::locate(4,5);
            cout<< "----------------------------------------------------------"<<endl;
            ShowTime(" SI ",4,6,y==0 );
            ShowTime(" NO ",4,7,y==1 );


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
                        if(y>1){
                        y=1;}
                            break;

                case 1:   ///ENTER

                    switch (y){

                        case 0:  ///CASO SI
                            rlutil::locate(4,8);
                            cout<<"--------------------------------------"<<endl;
                            rlutil::locate(4,9);
                            cout <<"---"<<jugador1<<" TUS DADOS SON:"<<endl;
                            rlutil::locate(4,10);
                            cout<<"--------------------------------------"<<endl;

                            ponerCero(vectorj1, 5);
                            cargarAleatorio(vectorj1, 5, 6);
                            mostrarVector(vectorj1, 5);

                            int a;

                            for (a=1;a<=2;a++){ ///el for de los tiros
                                int u=0,qwe=1;

                                while (qwe!=0){

                                    rlutil::locate(2,19+u);
                                    std::cout<<(char)175<<std::endl;
                                    rlutil::locate(4,16);
                                    cout<<"---------------------------------------------------------------------------------------------"<<endl;
                                    rlutil::locate(4,17);
                                    cout<<"------------------------------------QUIERE VOLVER A TIRAR?-----------------------------------"<<endl;
                                    rlutil::locate(4,18);
                                    cout<<"---------------------------------------------------------------------------------------------"<<endl;
                                    ShowTime(" SI ",4,19,u==0 );
                                    ShowTime(" NO ",4,20,u==1 );



                                    switch(rlutil::getkey()){

                                        case 14: ///UP
                                            rlutil::locate(2,19+u);
                                            std::cout<<"  "<<std::endl;
                                            u--;
                                            if(u<0){
                                            u=0;}
                                                break;
                                        case 15: ///DOWN
                                            rlutil::locate(2,19+u);
                                            std::cout<<"  "<<std::endl;
                                            u++;
                                            if(u>1){
                                            u=1;}
                                                break;
                                        case 1:   ///ENTER

                                            switch (u){

                                                case 0:  ///CASO SI
                                                    Ctirostot+=1;
                                                    Ctiros+=1;
                                                    system("cls");

                                                    rlutil::locate(4,2);
                                                    cout<< "---------------------------------------------------------------------------------------"<<endl;
                                                    rlutil::locate(4,3);
                                                    cout<< "----------NOMBRE: "<< jugador1 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj1,10) <<"--------------- "<<endl;
                                                    rlutil::locate(4,4);
                                                    cout << "-------RONDA NUMERO #"<<Crondas << "------" << "TIRO #" << Ctiros <<"----------------"<<endl;
                                                    rlutil::locate(4,5);
                                                    cout<< "--------------------------------------------"<<endl;
                                                    rlutil::locate(4,6);
                                                    cout<< "la mano anterior era:"<<endl;

                                                    mostrarVector(vectorj1,5);
                                                    Cuantos(vectorj1,5,qwe);/// NUEVA FUNCION  Rlutil
                                                    cargarAleatorioen0(vectorj1,5,6);

                                                    system("cls");

                                                    rlutil::locate(4,2);
                                                    cout<< "---------------------------------------------------------------------------------------"<<endl;
                                                    rlutil::locate(4,3);
                                                    cout<< "----------NOMBRE: "<< jugador1 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj1,10) <<"--------------- "<<endl;
                                                    rlutil::locate(4,4);
                                                    cout << "-------RONDA NUMERO #"<<Crondas << "------" << "TIRO #" << Ctiros <<"----------------"<<endl;
                                                    rlutil::locate(4,5);
                                                    cout<< "--------------------------------------------"<<endl;
                                                    rlutil::locate(4,6);
                                                    cout<< "LA NUEVA MANO AHORA ES:"<<endl;

                                                    mostrarVector(vectorj1,5);

                                                    if (Ctiros==3){
                                                    qwe=0;
                                                    qw=0;
                                                    a=2;
                                                    }

                                                    break;

                                                case 1:///CASO NO

                                                    qwe=0;
                                                    qw=0;
                                                    a=2;

                                                    break;
                                            } /// switch U
                                    } /// Switchgetkey  VOLVER A TIRAR comenzar tiro = U

                                }///WHILE qwe

                            } ///EL FOR DE LOS TIROS

                        case 1:
                            qw=0;
                            a=2;
                                break;
                    }///Switch Y

            } ///Switchgetkey COMENZAR A TIRAR = Y

        }/// WHILE qw

        system("pause");
        system ("cls");

        rlutil::locate(4,2);
        cout <<"-----------------***TABLA DE POSIBLES PUNTAJES***--------------------"<<endl;
        rlutil::locate(4,3);
        cout <<"-------------------- ELIJA UNO DE LOS PUNTAJES ----------------------"<<endl;
        rlutil::locate(4,4);
        cout <<"----------SI INGRESA UN VALOR NO VISIBLE, PERDERA SUS PUNTOS---------"<<endl;

        GuardarNumerosRepetidos(vectorvalores,vectorj1,vectorep,limite);
        bool gen=false; bool pok=false; bool ful=false;bool esc=false;
        esc=escalera(vectorpuntosj1,vectorep,limite);
        ful=full(vectorpuntosj1,vectorep,limite);
        pok=poker(vectorpuntosj1,vectorep,limite);
        gen=generala(vectorpuntosj1,vectorep,limite);

      ///  cout<<" generala:"<<gen<<" poker:"<<pok<<" full:"<<ful<<" esc:"<<esc<<endl;
        AsignarPdisponible(vectorpuntosj1,vectorep,esc,ful,pok,gen);

         ponerCero(vectorep,6);



    }///FOR DE LAS RONDAS

    int Puntajefinal;
    Puntajefinal=sumarVectorjugadores(vectorpuntosj1,10);


    if (Puntajefinal>puntajemax){

        puntajemax=Puntajefinal;
        strcpy(puntajemaximo,jugador1); /// Funcion de la libreria STRING

        rlutil::locate(4,2);
        cout<<"-------------------------------------------------------------"<<endl;
        rlutil::locate(4,3);
        cout<<"----------------------*FINAL DEL JUEGO* ---------------------"<<endl;
        rlutil::locate(4,4);
        cout<<"---*FELICIDADES!! HA ROTO EL RECORD ACTUAL DE 1 JUGADOR!!*---"<<endl;
        rlutil::locate(4,5);
        cout<<"----NOMBRE: "<< puntajemaximo<<" ---PUNTAJE MAXIMO "<<puntajemax<<" --------"<<endl;
        rlutil::locate(4,6);
        cout<<" --------*ESPERO QUE VUELVAS A INTENTARLO PRONTO :D*---------"<<endl;
        rlutil::locate(4,7);
        cout<<"-----------------------****FIN****---------------------------"<<endl;}

    else {

        rlutil::locate(4,2);
        cout<<"----------------------------------------------------------------------"<<endl;
        rlutil::locate(4,3);
        cout<<"--------------------*FINAL DEL JUEGO* -----------------------"<<endl;
        rlutil::locate(4,4);
        cout<<"--MUCHAS GRACIAS POR JUGAR:"<< jugador1<<" TU PUNTAJE TOTAL FUE DE:"<<Puntajefinal<<"  -----------"<<endl;
        rlutil::locate(4,5);
        cout<<"--ESPERO QUE VUELVAS A INTENTARLO PRONTO Y TE SUPERES :D "<<endl;
        rlutil::locate(4,6);
        cout<<"---------------------------****FIN****----------------------------------"<<endl;}


    system ("pause");
    system("cls");
    cin.ignore();

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}/// DE LA FUNCION




void twoplayers(char puntajemaximo[],int &puntajemax){

system("cls");


int i,a;
int rondas, Crondas=0, Ctiros=0, Ctirostot=0,Ctirostot2=0;
const int  limite =6;
int vectorj1 [5], vectorj2 [5];
int vectorvalores [6]= {1,2,3,4,5,6};
int vectorep [6];
int vectorpuntosj1 [10];
int vectorpuntosj2 [10];
char jugador1[30];
char jugador2[30];
///int vectorj3 [5]= {1,1,1,1,1 };
bool genserv1, genserv2;
    CargarVectorjugador(vectorpuntosj1,10);
    CargarVectorjugador(vectorpuntosj2,10);

    rlutil::showcursor();
    rlutil::locate(4,3);
    cout<<"-------------------*******--------XD-------*******-----------------------"<<endl;
    rlutil::locate(4,4);
    cout<<"---------------------*****BIENVENIDO--A--LA*****-------------------------"<<endl;
    rlutil::locate(4,5);
    cout<<"--------------------------****GENERALA****-------------------------------"<<endl;
    rlutil::locate(4,6);
    cout<<"---------------------------------***-------------------------------------"<<endl;
    rlutil::locate(4,7);
    cout<<"----------------------------2-JUGADORES/RAS------------------------------"<<endl;
    rlutil::locate(4,8);
    cout<<"-------------------------------------------------------------------------"<<endl;
    rlutil::locate(4,9);
    cout << "JUGADOR 1 INGRESE SU NOMBRE:"<<endl;
    rlutil::locate(4,10);
    cin.getline(jugador1,30,'\n');
     rlutil::locate(4,11);
    cout<<"-------------------------------------------------------------------"<<endl;
    rlutil::locate(4,12);
    cout << "JUGADOR 2 INGRESE SU NOMBRE:"<<endl;
    rlutil::locate(4,13);
    cin.getline(jugador2,30,'\n');
    rlutil::locate(4,14);
    cout<< "------------------------------------------------------------------"<<endl;
    rlutil::locate(4,15);
    cout << "¿CUANTAS RONDAS QUIEREN JUGAR? (10-MAX)"<<endl;
    rlutil::locate(4,16);
    cin >> rondas ;



    int rondasdobles;
    rondasdobles=rondas*2;


    system ("cls");
    for (i=1;i<=rondasdobles;i++){

            Crondas+=1;
            Ctiros=0;

            if (i%2!=0){
                     rlutil::locate(4,2);
                    cout<<"------------------------------------------------------"<<endl;
                     rlutil::locate(4,3);
                    cout<<"---------------RONDA: "<<Crondas<<"-------------------------------"<<endl;
                     rlutil::locate(4,4);
                    cout<<"-----------PROXIMO TURNO:"<<jugador1<<"----------------"<<endl;
                     rlutil::locate(4,5);
                    cout<<"-------------LANZAMIENTOS:"<< Ctirostot <<"----------------------------"<<endl;
                     rlutil::locate(4,6);
                    cout<<"---------PUNTAJE - JUGADOR 1 "<<jugador1<<":"<<sumarVectorjugadores(vectorpuntosj1,10)<<" PUNTOS ---------------------"<<endl;
                     rlutil::locate(4,7);
                    cout<<"---------PUNTAJE - JUGADOR 2 "<<jugador2<<":"<<sumarVectorjugadores(vectorpuntosj2,10)<<" PUNTOS ---------------------"<<endl;
                     rlutil::locate(4,8);
                    cout<<"------------------------------------------------------"<<endl;

        system("pause");
        system ("cls") ;

            Ctiros+=1;
            Ctirostot+=1;

            int y=0;
            int qw=1;
            rlutil::hidecursor();
        while (qw!=0){

            rlutil::hidecursor();

            rlutil::locate(2,6+y);
            std::cout<<(char)175<<std::endl;

            rlutil::locate(4,2);
            cout<< "----------NOMBRE: "<< jugador1 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj1,10) <<"----- "<<endl;
            rlutil::locate(4,3);
            cout << "----------RONDA NUMERO #"<<Crondas<<"-------"<<"TIRO #"<<Ctiros<<"-------------------"<<endl;
            rlutil::locate(4,4);
            cout << "----------COMENZAR TIRO DE DADOS ?  SI / NO --------------" <<endl;
            rlutil::locate(4,5);
            cout<< "----------------------------------------------------------"<<endl;
            ShowTime(" SI ",4,6,y==0 );
            ShowTime(" NO ",4,7,y==1 );


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
                        if(y>1){
                        y=1;}
                            break;

                case 1:   ///ENTER

                    switch (y){

                        case 0:  ///CASO SI
                            rlutil::locate(4,8);
                            cout<<"--------------------------------------"<<endl;
                            rlutil::locate(4,9);
                            cout <<"---"<<jugador1<<" TUS DADOS SON:"<<endl;
                            rlutil::locate(4,10);
                            cout<<"--------------------------------------"<<endl;

                            ponerCero(vectorj1, 5);
                            cargarAleatorio(vectorj1, 5, 6);
                            mostrarVector(vectorj1, 5);





                            for (a=1;a<=2;a++){ ///el for de los tiros
                                int u=0,qwe=1;



                            GuardarNumerosRepetidos(vectorvalores,vectorj1,vectorep,limite);
                            genserv1=false;
                            genserv1=generala2(vectorpuntosj1,vectorep,6);

                            ponerCero(vectorep,6);
                            if(genserv1==true){
                                vectorpuntosj1[9]=100;
                                system("pause");
                                system("cls");
                                rlutil::locate(4,2);
                                cout <<"-------------------------------------------------------------------"<<endl;
                                rlutil::locate(4,3);
                                cout <<"--------------FELICIDADES HA SACADO GENERALA SERVIDA---------------"<<endl;
                                rlutil::locate(4,4);
                                cout <<"-SI TU CONTRINCANTE NO SACA GENERALA SERVIDA, GANARAS DIRECTAMENTE-"<<endl;
                                rlutil::locate(4,5);
                                cout <<"-------------------------------------------------------------------"<<endl;

                               system("pause");

                                qwe=0;
                                qw=0;
                                a=2;
                            }


                                while (qwe!=0){

                                    rlutil::locate(2,19+u);
                                    std::cout<<(char)175<<std::endl;
                                    rlutil::locate(4,16);
                                    cout<<"---------------------------------------------------------------------------------------------"<<endl;
                                    rlutil::locate(4,17);
                                    cout<<"--------QUIERE VOLVER A TIRAR?---->  SI  <--|-->  NO  <---QUEDARSE CON LO OBTENIDO?----------"<<endl;
                                    rlutil::locate(4,18);
                                    cout<<"---------------------------------------------------------------------------------------------"<<endl;
                                    ShowTime(" SI ",4,19,u==0 );
                                    ShowTime(" NO ",4,20,u==1 );



                                    switch(rlutil::getkey()){

                                        case 14: ///UP
                                            rlutil::locate(2,19+u);
                                            std::cout<<"  "<<std::endl;
                                            u--;
                                            if(u<0){
                                            u=0;}
                                                break;
                                        case 15: ///DOWN
                                            rlutil::locate(2,19+u);
                                            std::cout<<"  "<<std::endl;
                                            u++;
                                            if(u>1){
                                            u=1;}
                                                break;
                                        case 1:   ///ENTER

                                            switch (u){

                                                case 0:  ///CASO SI
                                                    Ctirostot+=1;
                                                    Ctiros+=1;
                                                    system("cls");

                                                    rlutil::locate(4,2);
                                                    cout<< "---------------------------------------------------------------------------------------"<<endl;
                                                    rlutil::locate(4,3);
                                                    cout<< "----------NOMBRE: "<< jugador1 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj1,10) <<"--------------- "<<endl;
                                                    rlutil::locate(4,4);
                                                    cout << "-------RONDA NUMERO #"<<Crondas << "------" << "TIRO #" << Ctiros <<"----------------"<<endl;
                                                    rlutil::locate(4,5);
                                                    cout<< "--------------------------------------------"<<endl;
                                                    rlutil::locate(4,6);
                                                    cout<< "la mano anterior era:"<<endl;

                                                    mostrarVector(vectorj1,5);
                                                    Cuantos(vectorj1,5,qwe);/// NUEVA FUNCION  Rlutil
                                                    cargarAleatorioen0(vectorj1,5,6);

                                                    system("cls");

                                                    rlutil::locate(4,2);
                                                    cout<< "---------------------------------------------------------------------------------------"<<endl;
                                                    rlutil::locate(4,3);
                                                    cout<< "----------NOMBRE: "<< jugador1 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj1,10) <<"--------------- "<<endl;
                                                    rlutil::locate(4,4);
                                                    cout << "-------RONDA NUMERO #"<<Crondas << "------" << "TIRO #" << Ctiros <<"----------------"<<endl;
                                                    rlutil::locate(4,5);
                                                    cout<< "--------------------------------------------"<<endl;
                                                    rlutil::locate(4,6);
                                                    cout<< "LA NUEVA MANO AHORA ES:"<<endl;

                                                    mostrarVector(vectorj1,5);

                                                    if (Ctiros==3){
                                                    qwe=0;
                                                    qw=0;
                                                    a=2;
                                                    }

                                                    break;

                                                case 1:///CASO NO

                                                    qwe=0;
                                                    qw=0;
                                                    a=2;

                                                    break;
                                            } /// switch U
                                    } /// Switchgetkey  VOLVER A TIRAR comenzar tiro = U

                                }///WHILE qwe

                            } ///EL FOR DE LOS TIROS

                        case 1:
                            qw=0;
                            a=2;
                                break;
                    }///Switch Y

            } ///Switchgetkey COMENZAR A TIRAR = Y

        }/// WHILE qw



        if (genserv1==false){
        system("pause");
        system ("cls");

        rlutil::locate(4,2);
        cout <<"-----------------***TABLA DE POSIBLES PUNTAJES***--------------------"<<endl;
        rlutil::locate(4,3);
        cout <<"-------------------- ELIJA UNO DE LOS PUNTAJES ----------------------"<<endl;
        rlutil::locate(4,4);
        cout <<"----------SI INGRESA UN VALOR NO VISIBLE, PERDERA SUS PUNTOS---------"<<endl;

        GuardarNumerosRepetidos(vectorvalores,vectorj1,vectorep,limite);
        bool gen=false; bool pok=false; bool ful=false;bool esc=false;
        esc=escalera(vectorpuntosj1,vectorep,limite);
        ful=full(vectorpuntosj1,vectorep,limite);
        pok=poker(vectorpuntosj1,vectorep,limite);
        gen=generala(vectorpuntosj1,vectorep,limite);

      ///  cout<<" generala:"<<gen<<" poker:"<<pok<<" full:"<<ful<<" esc:"<<esc<<endl;
        AsignarPdisponible(vectorpuntosj1,vectorep,esc,ful,pok,gen);}/// genserv

        ponerCero(vectorep,6);




                Crondas-=1;
}

                else {
                    system("cls");
                     rlutil::locate(4,2);
                    cout<<"------------------------------------------------------"<<endl;
                     rlutil::locate(4,3);
                    cout<<"---------------RONDA: "<<Crondas<<"-------------------------------"<<endl;
                     rlutil::locate(4,4);
                    cout<<"-----------PROXIMO TURNO:"<<jugador2<<"----------------"<<endl;
                     rlutil::locate(4,5);
                    cout<<"-------------LANZAMIENTOS:"<< Ctirostot2 <<"----------------------------"<<endl;
                     rlutil::locate(4,6);
                    cout<<"---------PUNTAJE - JUGADOR 1 "<<jugador1<<":"<<sumarVectorjugadores(vectorpuntosj1,10)<<" PUNTOS ---------------------"<<endl;
                     rlutil::locate(4,7);
                    cout<<"---------PUNTAJE - JUGADOR 2 "<<jugador2<<":"<<sumarVectorjugadores(vectorpuntosj2,10)<<" PUNTOS ---------------------"<<endl;
                     rlutil::locate(4,8);
                    cout<<"------------------------------------------------------"<<endl;

        system("pause");
        system ("cls");
            Ctiros+=1;
            Ctirostot2+=1;
         int y=0;
            int qw=1;

               while (qw!=0){




            rlutil::hidecursor();

            rlutil::locate(2,6+y);
            std::cout<<(char)175<<std::endl;

            rlutil::locate(4,2);
            cout<< "----------NOMBRE: "<< jugador2 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj2,10) <<"----- "<<endl;
            rlutil::locate(4,3);
            cout << "----------RONDA NUMERO #"<<Crondas<<"-------"<<"TIRO #"<<Ctiros<<"-------------------"<<endl;
            rlutil::locate(4,4);
            cout << "----------COMENZAR TIRO DE DADOS ?  SI / NO --------------" <<endl;
            rlutil::locate(4,5);
            cout<< "----------------------------------------------------------"<<endl;
            ShowTime(" SI ",4,6,y==0 );
            ShowTime(" NO ",4,7,y==1 );


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
                        if(y>1){
                        y=1;}
                            break;

                case 1:   ///ENTER

                    switch (y){

                        case 0:  ///CASO SI
                            rlutil::locate(4,8);
                            cout<<"--------------------------------------"<<endl;
                            rlutil::locate(4,9);
                            cout <<"---"<<jugador2<<" TUS DADOS SON:"<<endl;
                            rlutil::locate(4,10);
                            cout<<"--------------------------------------"<<endl;


                            ponerCero(vectorj2, 5);
                            cargarAleatorio(vectorj2, 5, 6);
                            mostrarVector(vectorj2, 5);



                            for (a=1;a<=2;a++){ ///el for de los tiros
                                int u=0,qwe=1;

                            while (qwe!=0){

                            GuardarNumerosRepetidos(vectorvalores,vectorj2,vectorep,limite);
                            genserv2=false;
                            genserv2=generala2(vectorpuntosj1,vectorep,6);

                            ponerCero(vectorep,6);

                            if(genserv1==true){
                            ///system("pause");
                           /// system("cls");
                                if(genserv2==true){


                                rlutil::locate(4,16);
                                cout <<"---------------------------------------"<<endl;
                                rlutil::locate(4,17);
                                cout <<"--------------FELICIDADES--------------"<<endl;
                                rlutil::locate(4,18);
                                cout <<"------HA SACADO GENERALA SERVIDA-------"<<endl;
                                rlutil::locate(4,19);
                                cout <<"---------------------------------------"<<endl;
                                vectorpuntosj2[9]=100;


                                }
                                else {
                                rlutil::locate(4,16);
                                cout <<"----------------------------------------"<<endl;
                                rlutil::locate(4,17);
                                cout <<" NO HAS PODIDO SACAR GENERALA SERVIDA :("<<endl;
                                rlutil::locate(4,18);
                                cout <<"----------------------------------------"<<endl;
                                }

                                system("pause");
                                i=rondas*2;
                                qwe=0;
                                qw=0;
                                a=2;
                            }

                        else {

                                    rlutil::locate(2,19+u);
                                    std::cout<<(char)175<<std::endl;
                                    rlutil::locate(4,16);
                                    cout<<"---------------------------------------------------------------------------------------------"<<endl;
                                    rlutil::locate(4,17);
                                    cout<<"---------------------------------QUIERE VOLVER A TIRAR?--------------------------------------"<<endl;
                                    rlutil::locate(4,18);
                                    cout<<"---------------------------------------------------------------------------------------------"<<endl;
                                    ShowTime(" SI ",4,19,u==0 );
                                    ShowTime(" NO ",4,20,u==1 );



                                    switch(rlutil::getkey()){

                                        case 14: ///UP
                                            rlutil::locate(2,19+u);
                                            std::cout<<"  "<<std::endl;
                                            u--;
                                            if(u<0){
                                            u=0;}
                                                break;
                                        case 15: ///DOWN
                                            rlutil::locate(2,19+u);
                                            std::cout<<"  "<<std::endl;
                                            u++;
                                            if(u>1){
                                            u=1;}
                                                break;
                                        case 1:   ///ENTER

                                            switch (u){

                                                case 0:  ///CASO SI
                                                    Ctirostot2+=1;
                                                    Ctiros+=1;
                                                    system("cls");

                                                    rlutil::locate(4,2);
                                                    cout<< "---------------------------------------------------------------------------------------"<<endl;
                                                    rlutil::locate(4,3);
                                                    cout<< "----------NOMBRE: "<< jugador2 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj2,10) <<"--------------- "<<endl;
                                                    rlutil::locate(4,4);
                                                    cout << "-------RONDA NUMERO #"<<Crondas << "------" << "TIRO #" << Ctiros <<"----------------"<<endl;
                                                    rlutil::locate(4,5);
                                                    cout<< "--------------------------------------------"<<endl;
                                                    rlutil::locate(4,6);
                                                    cout<< "la mano anterior era:"<<endl;

                                                    mostrarVector(vectorj2,5);
                                                    Cuantos(vectorj2,5,qwe);/// NUEVA FUNCION  Rlutil
                                                    cargarAleatorioen0(vectorj2,5,6);

                                                    system("cls");

                                                    rlutil::locate(4,2);
                                                    cout<< "---------------------------------------------------------------------------------------"<<endl;
                                                    rlutil::locate(4,3);
                                                    cout<< "----------NOMBRE: "<< jugador2 <<"   ------PUNTOS:"<< sumarVectorjugadores(vectorpuntosj2,10) <<"--------------- "<<endl;
                                                    rlutil::locate(4,4);
                                                    cout << "-------RONDA NUMERO #"<<Crondas << "------" << "TIRO #" << Ctiros <<"----------------"<<endl;
                                                    rlutil::locate(4,5);
                                                    cout<< "--------------------------------------------"<<endl;
                                                    rlutil::locate(4,6);
                                                    cout<< "LA NUEVA MANO AHORA ES:"<<endl;

                                                    mostrarVector(vectorj2,5);

                                                    if (Ctiros==3){
                                                    qwe=0;
                                                    qw=0;
                                                    a=2;
                                                    }

                                                    break;

                                                case 1:///CASO NO

                                                    qwe=0;
                                                    qw=0;
                                                    a=2;

                                                    break;
                                        } /// switch U

                                    } /// Switchgetkey  VOLVER A TIRAR comenzar tiro = U

                                }///ELSE DE GENSERV1 PARA GENSERV2

                            } ///WHILE QWE


                                }/// FOR DE LOS TIROS
                        case 1:
                            qw=0;
                            a=2;
                                break;



                    }///Switch Y

            } ///Switchgetkey COMENZAR A TIRAR = Y

        }/// WHILE qw




        if(genserv1==false&&genserv2==false){
        system("pause");
        system ("cls");

        rlutil::locate(4,2);
        cout <<"-----------------***TABLA DE POSIBLES PUNTAJES***--------------------"<<endl;
        rlutil::locate(4,3);
        cout <<"-------------------- ELIJA UNO DE LOS PUNTAJES ----------------------"<<endl;
        rlutil::locate(4,4);
        cout <<"----------SI INGRESA UN VALOR NO VISIBLE, PERDERA SUS PUNTOS---------"<<endl;

        GuardarNumerosRepetidos(vectorvalores,vectorj2,vectorep,limite);
        bool gen=false; bool pok=false; bool ful=false;bool esc=false;
        esc=escalera(vectorpuntosj2,vectorep,limite);
        ful=full(vectorpuntosj2,vectorep,limite);
        pok=poker(vectorpuntosj2,vectorep,limite);
        gen=generala(vectorpuntosj2,vectorep,limite);

      ///  cout<<" generala:"<<gen<<" poker:"<<pok<<" full:"<<ful<<" esc:"<<esc<<endl;
        AsignarPdisponible(vectorpuntosj2,vectorep,esc,ful,pok,gen);}




        ponerCero(vectorep,6);
} /// Else del jugador 2






} /// FOR DE LA RONDAS DOBLES



    system("cls");

if (genserv1==true||genserv2==true){
    ///system("cls");
    if (genserv1 ==true){
    rlutil::locate(4,2);
    cout << "------------------------------****----------------------------------"<<endl;
    rlutil::locate(4,3);
    cout << "-----------------------*FIN DEL JUEGO 2P*---------------------------"<<endl;
    rlutil::locate(4,4);
    cout << "*FELICIDADES "<<jugador1<<" HAS GANADO DEBIDO A GENERALA SERVIDA!*"<<endl;
    rlutil::locate(4,5);
    cout << "------------------------------****----------------------------------"<<endl;

    vectorpuntosj1[9]=100;
    puntajemax=100;
    strcpy(puntajemaximo,jugador1);}

    else {
    rlutil::locate(4,2);
    cout << "------------------------------****----------------------------------"<<endl;
    rlutil::locate(4,3);
    cout << "------------------------*FIN DEL JUEGO 2P*--------------------------"<<endl;
    rlutil::locate(4,4);
    cout << "*FELICIDADES "<<jugador2<<" HAS GANADO DEBIDO A GENERALA SERVIDA!*"<<endl;
    rlutil::locate(4,5);
    cout << "------------------------------****----------------------------------"<<endl;
    vectorpuntosj2[9]=100;
    strcpy(puntajemaximo,jugador2);
    puntajemax=100;}

    system("pause");

}


else{
int Puntajefinal1,Puntajefinal2,mayorpuntaje;
Puntajefinal1=sumarVectorjugadores(vectorpuntosj1,10);
 Puntajefinal2 =sumarVectorjugadores(vectorpuntosj2,10);


rlutil::locate(4,2);
cout<<"----------------------------------------------------------------------------------------------"<<endl;
rlutil::locate(4,3);
cout<<"------------ PUNTAJE FINAL JUGADOR 1: "<<Puntajefinal1<<" - PUNTAJE FINAL JUGADOR 2: "<<Puntajefinal2<<"-----------"<<endl;

if(Puntajefinal1>Puntajefinal2){
    mayorpuntaje=Puntajefinal1;
    strcpy(puntajemaximo,jugador1);
    rlutil::locate(4,4);
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    rlutil::locate(4,5);
    cout<<"-------------------EL/LA GANADOR ES:"<< jugador1<<"!!!!!!!!-------------------------"<<endl;
    rlutil::locate(4,6);
    cout<<"----------------------*****FELICITACIONES POR HABER GANADO*****-------------------------"<<endl;}

else {mayorpuntaje=Puntajefinal2;
    strcpy(puntajemaximo,jugador2);
    rlutil::locate(4,4);
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    rlutil::locate(4,5);
    cout<<"-------------------EL/LA GANADOR ES:!!!!***"<< jugador2<<"***!!!!---------------------"<<endl;
    rlutil::locate(4,6);
    cout<<"----------------------*****FELICITACIONES POR HABER GANADO*****-------------------------"<<endl;}


if (mayorpuntaje>puntajemax){
    puntajemax=mayorpuntaje;

    rlutil::locate(4,7);
    cout<<"----------------------------------------------------------------------"<<endl;
    rlutil::locate(4,8);
    cout<<"---------------------*****FINAL DEL JUEGO***** -----------------------"<<endl;
    rlutil::locate(4,9);
    cout<<"---*****FELICIDADES!! HA ROTO EL RECORD ACTUAL DE 2 JUGADORES!!*****---"<<endl;
    rlutil::locate(4,10);
    cout<<"- NOMBRE DEL MAESTRO: "<< puntajemaximo<<" - NUEVO PUNTAJE MAXIMO "<<puntajemax<<"  ---------"<<endl;
    rlutil::locate(4,11);
    cout<<"-------ESPERO QUE VUELVAS A INTENTARLO PRONTO Y ROMPAS TU PROPIO RECORD-------"<<endl;
    rlutil::locate(4,12);
    cout<<"------------------------------****FIN****-------------------------------------"<<endl;;}
else {
    rlutil::locate(4,7);
    cout<<"----------------------------------------------------------------------"<<endl;
    rlutil::locate(4,8);
    cout<<"---------------------*****FINAL DEL JUEGO***** -----------------------"<<endl;
    rlutil::locate(4,9);
    cout<<"--MUCHAS GRACIAS POR JUGAR:"<< puntajemaximo <<" TU PUNTAJE TOTAL FUE DE:"<<mayorpuntaje<<"  -----------"<<endl;
    rlutil::locate(4,10);
    cout<<"-------ESPERO QUE VUELVAS A INTENTARLO PRONTO Y ROMPAS EL ACTUAL RECORD-------"<<endl;
    rlutil::locate(4,11);
    cout<<"------------------------------****FIN****-------------------------------------"<<endl;}

system("pause");

}/// FINAL DEL ELSE DE GEN


}



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



void Cuantos(int vec1[],int tam,int qwe){
    bool a=true;
    int y=0, tirar,aux=0,tiros;
    while (a==true){

        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();
        rlutil::locate(2,19+y);

        std::cout<<(char)175<<std::endl;

        rlutil::locate(4,16);
        cout<<"-----------------------------------------------||||-------------------------------------------"<<endl;
        rlutil::locate(4,17);
        cout<<"-----CUANTOS DADOS QUIERE VOLVER A TIRAR? -----||||-----CUALES DADOS QUIERE VOLVER TIRAR?-----"<<endl;
        rlutil::locate(4,18);
        cout<<"-----------------------------------------------||||-------------------------------------------"<<endl;
        ShowTime(" 1 (UNO) ",4,19,y==0 );
        ShowTime(" 2 (DOS) ",4,20,y==1 );
        ShowTime(" 3 (TRES) ",4,21,y==2 );
        ShowTime(" 4 (CUATRO) ",4,22,y==3 );
        ShowTime(" 5 (CINCO) ",4,23,y==4 );


            switch(rlutil::getkey()){

                case 14: ///UP
                    rlutil::locate(4,19+y);
                    std::cout<<"  "<<std::endl;
                    y--;
                    if(y<0){
                    y=0;}
                        break;

                case 15: ///DOWN
                    rlutil::locate(4,19+y);
                    std::cout<<"  "<<std::endl;
                    y++;
                    if(y>4){
                    y=4;}
                        break;
                case 1: ///ENTER
                    tirar=y+1;
                    int j=0;

                    while (tiros!=3){

                        rlutil::hidecursor();



                        ShowTime(" #1 POSICION",60,19,j==0 );
                        ShowTime(" #2 POSICION",60,20,j==1 );
                        ShowTime(" #3 POSICION",60,21,j==2 );
                        ShowTime(" #4 POSICION",60,22,j==3 );
                        ShowTime(" #5 POSICION",60,23,j==4 );


                            switch(rlutil::getkey()){

                                case 14: ///UP
                                    rlutil::locate(40,19+j);
                                    std::cout<<"  "<<std::endl;
                                    j--;
                                    if(j<0){
                                    j=0;}
                                        break;
                                case 15: ///DOWN
                                    rlutil::locate(40,19+j);
                                    std::cout<<"  "<<std::endl;
                                    j++;
                                    if(j>4){
                                    j=4;}
                                    break;
                                case 1: ///ENTER
                                    ///j+1 es el valor del dado que se va a cambiar
                                    rlutil::locate(76,19+j);
                                    cout<< "LA POSICION YA FUE AGREGADA, PROSIGA INDICANDO LA SIGUIENTE"<<endl;
                                    vec1[j]=0;
                                    aux+=1; ///CON aux me ayudo a saber cuando pasó por acá  y cuento cada vez que hace ENTER
                                    if(tirar==aux){ /// luego comparo cuantas veces queria tirar y una vez que La misma veces que eligio un numero, con las que eligio tirar, sale del while
                                    a=false;
                                    tiros=3;
                                    qwe=0;}
                                        break;
                            } ///switchGetKey J
                    }   ///while de los tiros, cuando se elijen la cantidad de dados, se espera seleccionar esa misma cantidad
            }/// switch Getkey Y
    } ///while a true

}






void ponerCero(int vec[],int tam){
    int i;
    for(i=0;i<tam;i++){
        vec[i]=0;
    }
}

void cargarAleatorio(int vec[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        vec[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int vec[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout << vec[i]<<endl;
    }
}


void cargarAleatorioen0(int vec[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        if (vec[i]==0){
        vec[i]=(rand()%limite)+1;}}
}





bool generala2(int vecpuntosj1[],int vecrep[],int limite){
        int i;
        for (i=0; i<limite;i++){
                if (vecrep[i]==5){
                    if(vecpuntosj1[9]==-1){
                            rlutil::locate(4,16);
                        cout<<"*************************************"<<endl;
                        rlutil::locate(4,17);
                        cout<<" -HA LOGRADO GENERALA SERVIDA, OMG!!!"<<endl;
                        rlutil::locate(4,18);
                        cout<<"*************************************"<<endl;
                        return true;}}
                        }
                        return false;
                    }



void GuardarNumerosRepetidos(int vecvalores[],int vecj1[],int vecrep[],int limite){
        int i,e;
        ponerCero(vecrep,6);
        for (i=0;i<limite;i++){
            for(e=0;e<5;e++)
                if (vecvalores[i]==vecj1[e]){
                    vecrep[i]+=1;
            }
        }
}

///Toda la verificacion de los juegos consta en que comparen los valores de VECREP con lo que se necesita adquirir en cada caso
/// Para finalizar me devuelven el valor booleano 1 o 0 si se cumplio el juego o no.
bool generala(int vecpuntosj1[],int vecrep[],int limite){
        int i;
        for (i=0; i<limite;i++){
                if (vecrep[i]==5){
                    if(vecpuntosj1[9]==-1){
                        rlutil::locate(4,14);
                        cout<<"--*PODEMOS ANOTAR GENERALA! #10 POR 50*--"<<endl;
                        return true;}}
                        }
                        return false;
                    }

bool poker(int vecpuntosj1[],int vecrep[],int limite){
        int i;
        for (i=0; i<limite;i++){
            if (vecrep[i]==4){
            if(vecpuntosj1[8]==-1){
                rlutil::locate(4,13);


                cout<< "---*PODEMOS ANOTAR POKER! #9 POR 40 *---"<<endl;
                    return true;
                }}
        }
                    return false;
                    }

bool full(int vecpuntosj1[],int vecrep[],int limite){
        int i; int fu=0, fa=0; ///Tuve que crear una variable extra para solo me incremente "fu" solo una vez cuando vecrep=2
                                ///porque sino me mostraba full cuando habia 2 pares de dados iguales, Solo en ese caso ya que hay 5 dados maximo
        for (i=0; i<6;i++){

            if (vecrep[i]==3){
                fu+=1;}
            if (vecrep[i]==2){
                fa+=1;
                    if (fa==1){
                        fu+=1;}}
        }

        if (fu==2){
            if(vecpuntosj1[7]==-1){
                rlutil::locate(4,12);
                cout<< "--- *PODEMOS ANOTAR FULL! #8 POR 30 * ---"<<endl;
                return true;}}
        else
                return false;
                    }




bool escalera(int vecpuntosj1[],int vecrep[],int limite){
    int i, Corden=0;

        for (i=0;i<limite;i++){
            if(vecrep[i]==1){
                Corden+=1;}
        }

        if (Corden==5){
            if(vecrep[0]==0||vecrep[5]==0){
            if(vecpuntosj1[6]==-1){
            rlutil::locate(4,11);
            cout <<"--- **PODEMOS ANOTAR ESCALERA! #7 ** ---"<<endl;
            return true;}}
        }
    else
        return false;
            }



void AsignarPdisponible(int vecpuntosj1[],int vecrep[],bool esca,bool ful, bool po, bool gene){
    int valor,y=0;
            int i,o=1;
    while (o!=0){

        int e=5;///
        for (i=0;i<6;i++){
            if (vecrep[i]!=0){
            if (vecpuntosj1[i]==-1){
            valor=vecrep[i]*(i+1); /// LO QUE VALE LA CANTIDAD DE REPETICIONES por el valor del dado(en esa posicion)ej: si hay 2dados con valor2  hace 2*2

            rlutil::locate(4,e+i);
            std::cout <<"-PODEMOS ASIGNAR VALOR EN EL #"<<i+1<<" POR "<< valor<<std::endl;


            }}

        }


        rlutil::locate(4,15);
        cout <<"-MENU PARA TACHARSE UN JUEGO #0"<<endl;
        rlutil::locate(2,5+y);
        cout<<(char)175 <<endl;

        rlutil::locate(45,5+y);
        cout<<(char)174 <<endl;

        switch(rlutil::getkey()){

            case 14: ///UP
                    rlutil::locate(2,5+y);
                    cout<<"  "<<endl;
                    rlutil::locate(45,5+y);
                    cout<<"  " <<endl;
                    y--;
                    if(y<0){
                    y=0;}
                break;

            case 15: ///DOWN
                    rlutil::locate(2,5+y);
                    std::cout<<"  "<<std::endl;
                    rlutil::locate(45,5+y);
                    cout<< "  " <<endl;
                    y++;
                    if(y>10){
                    y=10;}
                break;

            case 1:

                switch (y){

                    default: ///default aqui lo tomamos como todos los valores del 1-6
                            valor= vecrep[y]*(y+1); ///ASI OBTENEMOS EL PUNTAJE
                            if (vecpuntosj1[y]==-1){
                            vecpuntosj1[y]=valor;}
                            o=0;
                        break;

                    case 6:
                            if (esca==true){
                            if (vecpuntosj1[6]==-1){
                            vecpuntosj1[6]=25;
                            rlutil::locate(4,16);
                            cout<< "---------------------------***^***------------------------------"<<endl;
                            rlutil::locate(4,17);
                            cout<< "--------------ENHORABUENA HA ANOTADO ESCALERA!------------------"<<endl;
                            rlutil::locate(4,18);
                            cout<< "---------------------------***^***------------------------------"<<endl;
                            }}
                            o=0;
                        break;

                    case 7:
                            if (ful==true){
                            if (vecpuntosj1[7]==-1){
                            vecpuntosj1[7]=30;
                            rlutil::locate(4,16);
                            cout<< "---------------------------***^***-----------------------------"<<endl;
                            rlutil::locate(4,17);
                            cout<< "----------------ENHORABUENA HA ANOTADO FULL!-------------------"<<endl;
                            rlutil::locate(4,18);
                            cout<< "---------------------------***^***-----------------------------"<<endl;
                            }}
                            o=0;
                        break;

                    case 8:
                            if(po==true){
                            if (vecpuntosj1[8]==-1){
                            vecpuntosj1[8]=40;
                            rlutil::locate(4,16);
                            cout<< "---------------------------***^***------------------------------"<<endl;
                            rlutil::locate(4,17);
                            cout<< "------------------ENHORABUENA HA ANOTADO POKER!-----------------"<<endl;
                            rlutil::locate(4,18);
                            cout<< "---------------------------***^***------------------------------"<<endl;
                            }}
                            o=0;
                        break;

                    case 9:
                            if (gene==true){
                            if (vecpuntosj1[9]==-1){
                            vecpuntosj1[9]=50;
                            rlutil::locate(4,16);
                            cout<< "---------------------------***^***------------------------------"<<endl;
                            rlutil::locate(4,17);
                            cout<< "---------------ENHORABUENA HA ANOTADO GENERALA!-----------------"<<endl;
                            rlutil::locate(4,18);
                            cout<< "---------------------------***^***------------------------------"<<endl;
                            }}
                            o=0;
                        break;

                    case 10:
                            system("cls");
                            int a=0,xdd=1;


                            while (xdd!=0){
                                rlutil::locate(2,2+a);
                        std::cout<<(char)175<<std::endl;
                                rlutil::locate(33,2+a);
                        std::cout<<(char)174<<std::endl;

                                mostrarVectorTabla1(vecpuntosj1, 10);

                                    switch(rlutil::getkey()){

                                        case 14: ///UP
                                            rlutil::locate(2,2+a);
                                            cout<<"  "<<endl;
                                            rlutil::locate(33,2+a);
                                            cout<<"  " <<endl;
                                            a--;
                                            if(a<0){
                                            a=0;}
                                                break;

                                        case 15: ///DOWN
                                            rlutil::locate(2,2+a);
                                            std::cout<<"  "<<std::endl;
                                            rlutil::locate(33,2+a);
                                            cout<<"  " <<endl;
                                            a++;
                                            if(a>9){
                                            a=9;}
                                                break;

                                        case 1:

                                            if (vecpuntosj1[a]==-1){
                                            vecpuntosj1[a]=0;}
                                            xdd=0;
                                            o=0;
                                                break;
                                    } ///SWITCH a

                            }///While de xdd

                }///switch y

        }/// switch del movimiento de y

    }///while de O

    ///mostrarVectorTabla(vecpuntosj1, 10);
    rlutil::locate(4,19);
    cout<< "-----------------------***^***--------------------------"<<endl;
    rlutil::locate(4,20);
    cout<< "----------------PUNTAJE TOTAL ACTUAL:"<< sumarVectorjugadores(vecpuntosj1,10)<<"--------------"<<endl;
    rlutil::locate(4,21);
    cout<< "-----------------------***^***--------------------------"<<endl;

    system("pause");
    system("cls");

}

void mostrarVectorTabla(int vec[], int tam){
    int i;

        cout<<"---------------------***TABLA FINAL DE LA RONDA***---------------------"<<endl;
        for(i=0;i<tam;i++){
        cout <<i+1<<"-"<< vec[i]<<endl;
        }

}

void mostrarVectorTabla1(int vec[], int tam){
    int i,e=2;

        rlutil::locate(4,1);
        cout<<"-----------------***TABLA PARA TACHARSE POSIBLES JUEGOS***-------------------"<<endl;
        for(i=0;i<tam;i++){

            if(vec[i]==-1){
                rlutil::locate(4,e);
                cout <<"--- #"<<i+1<<"-"<<" DISPONIBLE  -------"<<endl;
                e+=1;
            }
            if(vec[i]!=-1){
                rlutil::locate(4,e);
                cout <<"--- #"<<i+1<<"-"<<" NO DISPONIBLE -------"<<endl;
                e+=1;
            }
            rlutil::locate(4,12);
            cout <<"--------------------------------------------------"<<endl;

        }
}



/// CARGANDO EL VECTOR DEL JUGADOR 1
void CargarVectorjugador(int vecpuntosj[],int tam){
int i;
    for(i=0;i<tam;i++){
        vecpuntosj[i]=-1;}
            }





int sumarVectorjugadores(int vec[], int tam ){
    int i, puntaje=0;
    for(i=0;i<tam;i++){
        if (vec[i]!=-1){
            puntaje+=vec[i];/// ESTE ME VA A SUMAR TODOS LOS VALORES QUE NO SEAN -1 Y YA LO PONGO COMO PUNTAJE :D
        }
    }
    return puntaje;
}
///DAVID THOMAS VYDRA


#endif // FUNCIONESG_H_INCLUDED
