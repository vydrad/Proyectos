#ifndef SUBMENUPELICULASSALA_H_INCLUDED
#define SUBMENUPELICULASSALA_H_INCLUDED

/*void SubMenuPeliculasSalas();
void modificarPeliculasPorSala();*/

void SubMenuPeliculasSalas(){

    bool auxi=false;
    SalasPorPelicula aux;
    rlutil::setBackgroundColor(rlutil::BLACK);
    int  y=0;
    do{
        system("cls");
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor();

        rlutil::locate(4,3);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;
        rlutil::locate(4,4);
        cout<<"--- -- -- --- -- --- ---> SUB-MENU PELICULAS POR SALA <--- --- -- --- -- -- ---"<<endl;
        rlutil::locate(4,5);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- -"<<endl;
        ShowTime(" --- --- --- AGREGAR PELICULAS A UNA SALA                     --- --- --- ",4,6,y==0);
        ShowTime(" --- --- --- MOSTRAR PELICULAS POR SALA                       --- --- --- ",4,7,y==1);
        ShowTime(" --- --- --- MOSTRAR PELICULAS POR SALA POR ID                --- --- --- ",4,8,y==2);
        ShowTime(" --- --- --- MODIFICAR LA SALA DONDE SE ENCUENTRA LA PELICULA --- --- --- ",4,9,y==3);
        ShowTime(" --- --- --- ELIMINAR REGISTRO                                --- --- --- ",4,10,y==4);
        ShowTime(" --- --- --- RECUPERAR PELICULA POR SALA ELIMINADA            --- --- --- ",4,11,y==5);
        ShowTime(" --- --- --- VOLVER AL MENU PRINCIPAL                         --- --- --- ",4,12,y==6);
        rlutil::locate (4,13);
        cout<<"--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---"<<endl;

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
                if(y>6){
                    y=6;
                }
                break;

            case 1: ///ENTER
                system("cls");
                switch(y+1){
                    case 1:

                       auxi=aux.cargar();
                       if (auxi){

                            cout<<"-------------------"<<endl;
                            cout<<"REGISTRO AGREGADO! "<<endl;
                            cout<<"-------------------"<<endl;

                       }
                       else{cout<<"--------------------------------------"<<endl;
                            cout<<" VUELVA A INTENTARLO MAS TARDE "<<endl;
                            cout<<"--------------------------------------"<<endl;
                        }
                        system("pause");
                        break;
                    case 2:
                        mostrarSalasPorPelicula();

                        system("pause");
                        break;
                    case 3:
                        mostrarsalasporpeliculasporID();
                        system("pause");
                        break;
                    case 4:
                        aux.modificarPeliculasPorSala();
                        system("pause");
                        break;
                    case 5:
                        aux.EliminarDeDisco();
                        system("pause");
                        break;
                    case 6:
                        DardealtaSalasporpelicula();
                        system("pause");
                    break;
                    case 7:
                        return ;
                        break;
                    default:
                        cout<<"--------------------------"<<endl;
                        cout<<"OPCION INCORRECTA! "<<endl;
                        cout<<"--------------------------"<<endl;
                        break;
                }
            cout <<endl;
        }
    }while(true);

    return ;
}

#endif // SUBMENUPELICULASSALA_H_INCLUDED
