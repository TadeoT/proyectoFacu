BD/**
* @file BD.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase BD
*
* Este archivo define la clase BD, las constantes que se usan en los
* argumentos de sus metodos, y un puntero para acceder a una instancia de la
* clase, para que todos los que incluyan esta cabecera hagan referencia al
* mismo objeto.
**/
#ifndef BD_H
#define BD_H

#include <vector>
#include "Clientes.h"
#include "Productos.h"
#include "Ventas.h"

/// @brief constante para indicar que fall� una b�squeda
#define NO_SE_ENCUENTRA -1

/// @brief enumeraci�n para los posibles criterios de ordenamiento
/// es para pasar como argumento al m�todo, queda m�s legible que un n�mero
enum CriterioOrden { ORDEN_APELLIDO_Y_NOMBRE, ORDEN_TELEFONO, ORDEN_DIRECCION, ORDEN_EMAIL };

/**
* @brief Clase contenedora que administra la lista de Clientes,Productos y Ventas
*
* Contiene la lista total de Clientes, Productos, Ventas y los metodos para buscar, ordenar,
* modificar, y leer y guardar en los archivos binarios. Es la clase que engloba
* todo el problema. Deberia haber una sola instancia y que todos trabajen
* sobre la misma.
* Notar que los datos estan siempre en memoria, y luego de modificarlos se debe
* llamar al metodo Guardar para que los cambios se reflejen en los archivos.
**/
class BD {
private:

	/// @brief Nombre del archivo de donde se leen y donde se escriben los datos
	std::string nombre_archivo;

	/// @brief Contenedor STL para los datos
	std::vector<Clientes> arregloClientes;
	std::vector<Productos> arregloProductos;
	std::vector<Ventas> arregloVentas;

public:

	/// @brief Crea el objeto y carga los datos desde un archivo
	BD(std::string archivo);

	/// @brief Guarda los datos en el archivo
	bool Guardar();

	/// @brief Devuelve la cantidad de registros
	int CantidadDatos();

	/// @brief Agrega un registro
	void AgregarCliente(const Cliente &p);

	/// @brief Devuelve un registro para ver o modificar
	Cliente &operator[](int i);
	/// @brief Devuelve un registro para ver o modificar
	Cliente &VerCliente(int i);


	/// @brief Quita una Cliente de la base de datos
	void EliminarCliente(int i);

	/// @brief Ordena el vector
	void Ordenar(CriterioOrden criterio);

	// funciones para busquedas
	/// @brief Buscar un Cliente por nombre
	int BuscarNombre(std::string parte_nombre, int pos_desde);
	/// @brief Buscar un Cliente por apellido
	int BuscarApellido(std::string parte_apellido, int pos_desde);
	/// @brief Buscar un Cliente por apellido y nombre
	int BuscarApellidoYNombre(std::string parte_apellido, int pos_desde);
	/// @brief Buscar un Cliente por direccion
	int BuscarDireccion(std::string parte_direccion, int pos_desde);
	/// @brief Buscar un Cliente por telefono
	int BuscarTelefono(std::string parte_telefono, int pos_desde);
	/// @brief Buscar un Cliente por email
	int BuscarEmail(std::string parte_correo, int pos_desde);
	/// @brief Buscar un Cliente por ciudad
	int BuscarCiudad(std::string parte_ciudad, int pos_desde);
	/// @brief Buscar un Cliente por fecha de nacimiento
	int BuscarNacimiento(int dia, int mes, int anio, int pos_desde);

};

#endif
