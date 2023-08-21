#ifndef PROTOFUNCIONES_H_INCLUDED
#define PROTOFUNCIONES_H_INCLUDED

///PROTOTIPOS
void cargarCadena(char *pal, int tam);
int validacionIDpelicula(int id);
int validacionIDventa(int id);
int validacionDir(int id);
int validacionSala(int id);
int validacionPrecio(int precio, int pago);
int validacionSalaPelicula(int id, int idp);
int validacionModificarPeliculasPorSala(int id);
int validacionSalasPorPelicula(int id);
int validacionSalasPorPelicula2(int id, int idp);
int validacionPeliculaEnSalas(int id);

int autonumericoIDdirectores();
int autonumericoIDPeliculas();
int autonumericoIDSalas();
int autonumericoIDVentas();

int calcularPlazas(int id,int dia, int mes, int anio);
int cantButacasSala(int id);
int calcularVentas(int id);
int DatosInicio();
///FIN PROTOTIPOS

#endif // PROTOFUNCIONES_H_INCLUDED
