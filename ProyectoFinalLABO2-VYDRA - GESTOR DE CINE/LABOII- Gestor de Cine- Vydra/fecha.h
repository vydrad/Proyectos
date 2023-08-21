#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <ctime>
class Fecha{
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0){
        this->dia=d;
        this->mes=m;
        this->anio=a;
    }


    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

    void Cargar();
    void Mostrar();

       bool VerificaciondeFecha(Fecha Actual){
            if(anio<Actual.getAnio()){
                /// cout<<"Estoy en la de anio"<<endl;
                return true;
                cout<<"----------1----------"<<endl;}
            else if(anio==Actual.getAnio()){
                    if(mes<Actual.getMes()){
                        ///  cout<<"Estoy en la de mes"<<endl;
                        return true;
                        cout<<"----------2----------"<<endl;
                    }

                    else if(mes==Actual.getMes()){
                            if(dia<=Actual.getDia()){
                            /// cout<<"Estoy en la de dia"<<endl;
                            return true;
                            cout<<"-----------3---------"<<endl;
                        }
                    }
                }
            return false;
            }
 void Cargar3(){
            Fecha Actual;
            time_t tiempo;
            struct tm *tmPtr;
            tiempo = time(NULL);
            tmPtr = localtime(&tiempo);
            anio=tmPtr->tm_year+1900;
            mes=tmPtr->tm_mon+1;
            dia=tmPtr->tm_mday;
             Actual.setAnio(anio);
             Actual.setMes(mes);
             Actual.setDia(dia);
            setDia2();
            setMes2();
            setAnio3();

            bool menor=false;
            menor=VerificaciondeFecha(Actual);
            while(menor==false){
                cout<<"------------------------------------------------------------------------------------"<<endl;
                cout<<"HA INGRESADO UNA FECHA EN EL FUTURO, SOLO SE PERMITEN FECHAS DEL PASADO Y ACTUAL"<<endl;
                cout<<"POR FAVOR VUELVA A CARGAR LA FECHA: "<<endl;
                cout<<"------------------------------------------------------------------------------------"<<endl;
                setDia2();
                setMes2();
                setAnio3();
                menor=VerificaciondeFecha(Actual);
            }

        }


        void Cargar2(){
            Fecha Actual;
            time_t tiempo;
            struct tm *tmPtr;
            tiempo = time(NULL);
            tmPtr = localtime(&tiempo);
            anio=tmPtr->tm_year+1900;
            mes=tmPtr->tm_mon+1;
            dia=tmPtr->tm_mday;


             Actual.setAnio(anio);
             Actual.setMes(mes);
             Actual.setDia(dia);


            setDia2();
            setMes2();
            setAnio2();

            bool menor=false;
            menor=VerificaciondeFecha(Actual);
            while(menor==false){
                cout<<"------------------------------------------------------------------------------------"<<endl;
                cout<<"HA INGRESADO UNA FECHA EN EL FUTURO, SOLO SE PERMITEN FECHAS DEL PASADO Y ACTUAL"<<endl;
                cout<<"POR FAVOR VUELVA A CARGAR LA FECHA: "<<endl;
                cout<<"------------------------------------------------------------------------------------"<<endl;
                setDia2();
                setMes2();
                setAnio2();
                menor=VerificaciondeFecha(Actual);
            }

        }
        ///VALIDACION PARA MAYORES DE 18 AÑOS
        void setAnio3(){
        Fecha Actual;
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        Actual.setAnio(1900+tmPtr->tm_year);
            int anio2;
        cout<<"-----------------"<<endl;
        cout<<"INGRESE EL ANIO:"<<endl;
        cin>>anio2;
        while(anio2>(Actual.getAnio()-18) || anio2<1900){
            if(anio2>(Actual.getAnio()-18)){
        cout<<"----------------------------------------------------------------------------------"<<endl;
        cout<<"---     EL DIRECTOR DE LA PELICULA DEBE TENER AL MENOS 18 ANIOS                ---"<<endl;
        cout<<"---     POR FAVOR INGRESE EL NRO DE ANIO 1900 - "<< (Actual.getAnio()-18)<<"                           ---"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
        }
        else if(anio2<1900){
            cout<<"---------------------------------------------------------------"<<endl;
            cout<<"--- POR FAVOR INGRESE UN ANIO ENTRE (1900 - "<<(Actual.getAnio()-18)<<")           ---"<<endl;
            cout<<"---------------------------------------------------------------"<<endl;

        }
        cin>>anio2;

        }
        anio=anio2;
        return;
        }


        void setDia2(){
            int x;
        cout<<"-----------------"<<endl;
        cout<<"INGRESE EL DIA:"<<endl;
        cin>>x;
        while(x>31||x<=0){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"HA INGRESADO UN DIA INVALIDO"<<endl;
        cout<<"POR FAVOR INGRESE EL DIA NUEVAMENTE(1-31)"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cin>>x;
        }
        dia=x;
        }

        void setMes2(){
            int x;
        cout<<"-----------------"<<endl;
        cout<<"INGRESE EL MES:"<<endl;
        cin>>x;
        while(x>12||x<=0){
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"HA INGRESADO UN MES INVALIDO"<<endl;
        cout<<"POR FAVOR INGRESE EL MES NUEVAMENTE(ENTRE 1 Y 12)"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cin>>x;
        }
        mes=x;
        }

        void setAnio2(){
        Fecha Actual;
        time_t tiempo;
        struct tm *tmPtr;
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);
        Actual.setAnio(1900+tmPtr->tm_year);
            int anio2;
        cout<<"-----------------"<<endl;
        cout<<"INGRESE EL ANIO:"<<endl;
        cin>>anio2;
        while(anio2>Actual.getAnio()|| anio2<1900){
        cout<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"--- HA INGRESADO DE ANIO INVALIDO---"<<endl;
        cout<<"--- POR FAVOR INGRESE EL ANIO NUEVAMENTE (1900 - "<<Actual.getAnio()<<") ---"<<endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
        cin>>anio2;
        }
        anio=anio2;

        }



};

void Fecha::Cargar(){
        int d, m, a;
        cout<<"INGRESE EL DIA: ";
        cin>>d;
        cout<<"INGRESE EL MES: ";
        cin>>m;
        cout<<"INGRESE EL ANIO: ";
        cin>>a;
        setDia(d);
        setMes(m);
        setAnio(a);
}

void Fecha::Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;

}


#endif // FECHA_H_INCLUDED
