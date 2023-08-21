#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED


class datos{
    private:
        float recaudacionTotalCine=0;
        float recaudacionporpelicula=0;
        char nombrePelicula[30];
        char nombreDirector[30];
        char tipoSala[3];
        float recaudacionSalas;
        int idSala;

        ventas reg;
        pelicula aux;
        director obj;
        Salas sal;

    public:
        void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
        void setRecaudacionporpelicula(float rt){recaudacionporpelicula=rt;}
        void setRecaudacionTotalCine(float rtc){recaudacionTotalCine=rtc;}
        void setNombreDirector (const char *Nd){strcpy(nombreDirector,Nd);}
        void setTipoSala(const char *ts){strcpy(tipoSala,ts);}
        void setRecaudacionSalas(float s){recaudacionSalas=s;}
        void setIdSala(int idS){idSala=idS;}

        float getrecaudacionporpelicula(){return recaudacionporpelicula;}
        float getRecaudacionTotalCine(){return recaudacionTotalCine;}
        const char *getnombreDirector (){return nombreDirector;}
        float getRecaudacionSalas(){return recaudacionSalas;}
        int setIdSala(){return idSala;}

        void Mostrar(){
        cout<<nombrePelicula<<endl;
        cout<<recaudacionporpelicula<<endl;
        }
        void MostrarDirector(){
        cout<<nombreDirector<<endl;
        cout<<recaudacionporpelicula<<endl;
        }
        void MostrarSalas(){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"EL TIPO DE SALA CON MAYOR RECAUDACION ES LA: " <<tipoSala<<endl;
        cout<<"CON UNA RECAUDACION DE: "<<recaudacionSalas<<endl;
        cout<<"-------------------------------------------------"<<endl;
        }
        void MostrarSala(){
        cout<<"-------------------------------------------------"<<endl;
        cout<<"LA SALA CON MAYOR RECAUDACION ES LA SALA: " <<idSala<<endl;
        cout<<"CON UNA RECAUDACION DE: "<<recaudacionSalas<<endl;
        cout<<"-------------------------------------------------"<<endl;
        }

//////////////////////////////////////PUNTO 1//////////////////////////////////////////////
///PELICULAS VENTAS
    float recpeli(int id){
        int pos=0;
        float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidPelicula()==id && aux.getEstado()==true ){
                canttotal+=calcularRecaudacion(aux.getidPelicula());
            }
        }
        return canttotal; ///DEVUELVE LA CANTIDAD TOTAL DE LA RECAUDACION
    }

    void recaudacionpeliculas(){
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getEstado()==true){
                cout<<"-----------------------------------------------------"<<endl;
                cout<<aux.getNombrePelicula()<<" RECAUDO UN TOTAL DE "<<recpeli(aux.getidPelicula())<<" PESOS"<<endl<<endl;
                cout<<"-----------------------------------------------------"<<endl;
            }
        }
    }

//////////////////////////////////////PUNTO 2//////////////////////////////////////////////
///DIRECTOR-::- PELICULAS-hubo- VENTAS
    float calcularRecaudacion (int id){
        float sumaRecaudacion=0;
        int pos=0;
        ///LEER VENTAS
        while (reg.leerEnDisco(pos++)){
            if(reg.getidPelicula()==id && reg.getEstado()==true){ ///SOLO LEE LAS VENTAS EN TRUE
                sumaRecaudacion+=reg.getTotal();
            }
        }
        return(float)sumaRecaudacion;
    }

    float recdir(int id){
        int pos=0;
        float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id && aux.getEstado()==true){
                canttotal+=calcularRecaudacion(aux.getidPelicula());
            }
        }
        return canttotal;
    }

    void recaudaciondirector(){
        int pos=0;
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"EL DIRECTOR "<<obj.getnombreDirector()<<" RECAUDO UN TOTAL DE "<<recdir(obj.getidDirector())<<" PESOS"<<endl<<endl;
                cout<<"-----------------------------------------------------"<<endl;
            }
        }
    }

//////////////////////////////////PUNTO 3//////////////////////////////////////
    ///PELICULAS VENTAS
    int recauxpelicula(int ID){
        ventas reg;
        int pos=0;
        int acumImporte=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==ID && reg.getEstado()==true){
                acumImporte+=reg.getTotal();
            }
        }
        return acumImporte;
    }

    int contarpeliculas(){
        int pos=0;
        int tam=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getEstado()==true){
                tam+=1;
            }
        }
        return tam;
    }

    int contarpeliculas2(){
        int pos=0;
        int tam=0;
        while(aux.leerEnDisco(pos++)==1){
                tam+=1;
            }
        return tam;
    }


    void peliculamayorVentas(){
        int max=0,posmax=0,auxi1=0;
        datos *vDinamico;
        int cantpeliculas=contarpeliculas();
        int cantpeliculatotal=contarpeliculas2();
        vDinamico=new datos[cantpeliculas];
        if(vDinamico==NULL)return;

        for(int i=0; i<cantpeliculatotal; i++){
            aux.leerEnDisco(i);
            if(aux.getEstado()){
            vDinamico[auxi1].setNombrePelicula(aux.getNombrePelicula());/// SET NOMBRE PELICULA
            vDinamico[auxi1].setRecaudacionporpelicula(recauxpelicula(aux.getidPelicula()));
            auxi1++;

            }
        }
        max=vDinamico[0].getrecaudacionporpelicula(); ///GET RECAUDACION POR PELICULA
        for(int i=0; i<cantpeliculas; i++){
            if(vDinamico[i].getrecaudacionporpelicula()>max ){
                max=vDinamico[i].getrecaudacionporpelicula();
                posmax=i;
            }
        }
        cout<<"---------------------------------------------"<<endl;
        cout<<"PELICULA CON MAYOR RECAUDACION"<<endl;
        cout<<"---------------------------------------------"<<endl;

        for(int i=0; i<cantpeliculas; i++){
            if(posmax==i){
                vDinamico[posmax].Mostrar();
            }
        }
        delete vDinamico;
        cout<<"---------------------------------------------"<<endl;
    }
//////////////////////////////////////PUNTO 4//////////////////////////////////////////////
    ///DIRECTOR PELICULAS VENTAS
    int contardirectores(){
        int pos=0;
        int tam=0;
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
                tam+=1;
            }
        }
        return tam;
    }
        int contardirectores2(){
        int pos=0;
        int tam=0;
        while(obj.leerEnDisco(pos++)==1){
                tam+=1;
            }
        return tam;
    }


    /*
    float calcularRecaudacion (int id){
        float sumaRecaudacion=0;
        int pos=0;
        ///LEER VENTAS
        while (reg.leerEnDisco(pos++)){
            if(reg.getidPelicula()==id && reg.getEstado()==true){ ///SOLO LEE LAS VENTAS EN TRUE
                sumaRecaudacion+=reg.getTotal();
            }
        }
        return(float)sumaRecaudacion;
    }

        float recdir(int id){
        int pos=0;
        float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id && aux.getEstado()==true){
                canttotal+=calcularRecaudacion(aux.getidPelicula());
            }
        }
        return canttotal;
    }
    */

    void directormayorVentas(){
        int max=0,posmax=0, auxi=0;
        datos *vDinamico;
        int cantdirectores=contardirectores();
        int cantdiretotal=contardirectores2();
        vDinamico=new datos[cantdirectores];
        if(vDinamico==NULL)return;

        for(int i=0; i<cantdiretotal; i++){
            obj.leerEnDisco(i);
            vDinamico[auxi].setNombreDirector(obj.getnombreDirector());/// SET NOMBRE DIRECTOR
            vDinamico[auxi].setRecaudacionporpelicula(recdir(obj.getidDirector()));/// SET RECAUDACION POR PELICULA
            auxi++;
            }
        max=vDinamico[0].getrecaudacionporpelicula();
        for(int i=0; i<cantdirectores; i++){
            if(vDinamico[i].getrecaudacionporpelicula()>max){
                max=vDinamico[i].getrecaudacionporpelicula();/// GET RECAUDACION POR PELICULA
                posmax=i;
            }
        }
        cout<<"---------------------------------------------"<<endl;
        cout<<"DIRECTOR CON MAYOR RECAUDACION"<<endl;
        cout<<"---------------------------------------------"<<endl;

        for(int i=0; i<cantdirectores; i++){
            if(posmax==i){
                vDinamico[posmax].MostrarDirector();
            }
        }

        delete vDinamico;
        cout<<"---------------------------------------------"<<endl;
    }
//////////////////////////////////////PUNTO 5//////////////////////////////////////////////
/// SALAS VENTAS
    int salaMas2(int ID){
        ventas reg;
        int pos=0;
        int acumImporte=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidSala()==ID && reg.getEstado()==true){
                acumImporte+=reg.getTotal();
            }
        }
        return acumImporte;
    }

    int contarSalas2(){
        int pos=0;
        int tam=0;
        while(sal.leerEnDisco(pos++)==1){
            if(sal.getEstado()==true){
                tam+=1;
            }
        }
        return tam;
    }

    int contarSalas3(){///total
        int pos=0;
        int tam=0;
        while(sal.leerEnDisco(pos++)==1){

                tam+=1;

        }
        return tam;
    }

    void TiposalaConMasRecaudacion(){
        int maximo=0,posmax=0,auxi=0;
        datos *vDinamico;
        int cantSalas=contarSalas2();
        int cantSalasTOT=contarSalas3();
        vDinamico=new datos[cantSalas];
        if(vDinamico==NULL)return;

        for(int i=0; i<cantSalasTOT; i++){
            sal.leerEnDisco(i);
            if(sal.getEstado()){
            vDinamico[auxi].setTipoSala(sal.getTipo()); ///SET TIPO SALA
            vDinamico[auxi].setRecaudacionSalas(salaMas2(sal.getidSala()));/// SET RECAUDACION SALAS
           auxi++;
           }
        }
        maximo=vDinamico[0].getRecaudacionSalas();
        for(int a=1; a<cantSalas; a++){
            if(vDinamico[a].getRecaudacionSalas()>maximo){
                maximo=vDinamico[a].getRecaudacionSalas(); /// GET RECAUDACION SALAS
                posmax=a;
            }
        }

        for(int b=0; b<cantSalas; b++){
            if(posmax==b){
                vDinamico[posmax].MostrarSalas(); /// MOSTRAR SALAS
            }
        }


        delete vDinamico;
    }

//////////////////////////////////////PUNTO 6//////////////////////////////////////////////
///VENTAS
    void RecaudacionCine(){
    int totalRecaudado=0;
    int pos=0;
    ///LEYENDO LOS REGISTROS DE VENTAS
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getEstado()==true){
            setRecaudacionTotalCine(reg.getTotal()); /// SET RECAUDACION TOTAL CINE
            totalRecaudado+=getRecaudacionTotalCine(); ///GET RECAUDACION TOTAL CINE
        }
    }
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"LA RECAUDACION TOTAL DEL CINE FUE DE: "<<totalRecaudado<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    }


//////////////////////////////////////PUNTO 7//////////////////////////////////////////////

///SALAS VENTAS
    int salaMas(int ID){
        ventas reg;
        int pos=0;
        int acumImporte=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidSala()==ID && reg.getEstado()==true){
                acumImporte+=reg.getTotal();
            }
        }
    return acumImporte;
    }
/*
    int contarSalas(){
        Salas sal;
        int pos=0;
        int tam=0;
        while(sal.leerEnDisco(pos++)==1){
            if(sal.getEstado()==true){
                tam+=1;
            }
        }
        return tam;
    }
*/



    void salaConMasRecaudacion(){
        Salas sal;
        int max=0,posmax=0, auxi=0;
        datos *vDinamico;
        int cantSalas=contarSalas2();
        int cantSalasTot=contarSalas3();
        vDinamico=new datos[cantSalas];
        if(vDinamico==NULL)return;

        for(int i=0; i<cantSalasTot; i++){
            sal.leerEnDisco(i);
            if(sal.getEstado()){
            vDinamico[auxi].setIdSala(sal.getidSala()); /// SET ID SALA
            vDinamico[auxi].setRecaudacionSalas(salaMas(sal.getidSala())); ///  SET  RECAUDACION SALAS
            auxi++;
            }
        }

        max=vDinamico[0].getRecaudacionSalas();
        for(int i=0; i<cantSalas; i++){
            if(vDinamico[i].getRecaudacionSalas()>max){
                max=vDinamico[i].getRecaudacionSalas(); /// GET RECAUDACION SALAS
                posmax=i;
            }
        }

        for(int i=0; i<cantSalas; i++){
            if(posmax==i){
            vDinamico[posmax].MostrarSala();/// MOSTRAR SALA
            }
        }

    delete vDinamico;
    }
//////////////////////////////////////PUNTO 8//////////////////////////////////////////////
/// PELICULAS VENTAS
    int IDmenosventas(int ID){
        ventas reg;
        int pos=0;
        int acumImporte=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==ID && reg.getEstado()==true){
                acumImporte+=reg.getTotal();
            }
        }
        return acumImporte;
    }

    int contarpelicula(){
        pelicula aux;
        int pos=0;
        int tam=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getEstado()==true){
                tam+=1;
            }
        }
        return tam;
    }

    int contarpeliculacompleta(){
        pelicula aux;
        int pos=0;
        int tam=0;
        while(aux.leerEnDisco(pos++)==1){
                tam+=1;

        }
        return tam;
    }



    void peliculaMenorVentas(){
    pelicula aux;
    int min=0,posmin=0, auxi1=0;
    datos *vDinamico;
    int cantpeliculas=contarpelicula();
    int cantpelitotal=contarpeliculacompleta();
    vDinamico=new datos[cantpeliculas];
    if(vDinamico==NULL)return;

    for(int i=0; i<cantpelitotal; i++){
        aux.leerEnDisco(i);
        if(aux.getEstado()){
        vDinamico[auxi1].setNombrePelicula(aux.getNombrePelicula()); /// SET NOMBRE PELICULA
        vDinamico[auxi1].setRecaudacionporpelicula(IDmenosventas(aux.getidPelicula()));/// SET RECAUDACION POR PELICULA
        auxi1++;
        }
    }

    for(int i=0; i<cantpeliculas; i++){
        if(i==0){
            min=vDinamico[i].getrecaudacionporpelicula();
        }
        else{
            if(vDinamico[i].getrecaudacionporpelicula()<min){ /// GET RECAUDACION POR PELICULA
                min=vDinamico[i].getrecaudacionporpelicula();
                posmin=i;
            }
        }
    }
    cout<<"---------------------------------------------"<<endl;
    cout<<"PELICULA CON MENOR RECAUDACION"<<endl;
    cout<<"---------------------------------------------"<<endl;

    for(int i=0; i<cantpeliculas; i++){
        if(posmin==i){
            vDinamico[posmin].Mostrar(); /// MOSTRAR
        }
    }
    delete vDinamico;
    cout<<"---------------------------------------------"<<endl;
}
//////////////////////////////////////PUNTO 9//////////////////////////////////////////////
///DIRECTOR  PELICULAS  VENTAS
    int contardirector(){

        int pos=0;
        int tam=0;
        while(obj.leerEnDisco(pos++)==1){
            if(obj.getEstado()==true){
            tam+=1;
            }
        }
    return tam;
    }

    float calcularRecaudac (int id){
        ventas reg;
        float sumaRecaudac=0;
        int pos=0;
        while (reg.leerEnDisco(pos++)){
            if(reg.getidPelicula()==id && reg.getEstado()==true){
                sumaRecaudac+=reg.getTotal();
            }
        }
    return(float)sumaRecaudac;
    }

    float recdire(int id){

        int pos=0;
        float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id && aux.getEstado()==true){
                canttotal+=calcularRecaudac(aux.getidPelicula());
            }
        }
    return canttotal;
    }

    void directorMenorVentas(){
        director obj;
        int min=0,posmin=0,auxi=0;
        datos *vDinamico;
        int cantdirectores=contardirector();
        int cantdiretotal=contardirectores2();
        vDinamico=new datos[cantdirectores];
        if(vDinamico==NULL)return;

        for(int i=0; i<cantdiretotal; i++){
            obj.leerEnDisco(i);
            if(obj.getEstado()){
            vDinamico[auxi].setNombreDirector(obj.getnombreDirector()); /// SET NOMBRE DIRECTOR
            vDinamico[auxi].setRecaudacionporpelicula(recdire(obj.getidDirector()));/// SET RECAUDACION X PELICULA
            auxi++;
            }
        }
        for(int i=0; i<cantdirectores; i++){
            if(i==0){
            min=vDinamico[i].getrecaudacionporpelicula();
            }
            else{
                if(vDinamico[i].getrecaudacionporpelicula()<min){
                    min=vDinamico[i].getrecaudacionporpelicula();/// GET RECAUDACION POR PELICULA
                    posmin=i;
                }
            }
        }
        cout<<"---------------------------------------------"<<endl;
        cout<<"DIRECTOR CON MENOR RECAUDACION"<<endl;
        cout<<"---------------------------------------------"<<endl;

        for(int i=0; i<cantdirectores; i++){
            if(posmin==i){
                vDinamico[posmin].MostrarDirector(); /// MOSTRAR DIRECTOR
            }
        }
        delete vDinamico;
        cout<<"---------------------------------------------"<<endl;
    }

};

#endif // DATOS_H_INCLUDED
