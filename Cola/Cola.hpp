/**
 * \file Cola.hpp
 * \brief Implementación de una cola genérica.
 * \author Ana Laura Chenoweth Galaz, Georgina Salcido Valenzuela
 * \date 17/03/2024
 */


#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

/** \class Cola
 *
 * Permite utilizar <b> colas de datos genéricos. </b> y ofrece un conjunto de operaciones básicas: agregar, eliminar, obtener el tamano de la cola,
 * obtener el valor del fondo, obtener el valor del frente, imprimir, vaciar, etc.
 **/

template <typename T>
class Cola
{
public:
    /** \brief Constructor de la clase Cola.
     *
     */
    Cola();

    /** \brief Destructor de la clase Cola.
     *
     */
    ~Cola();

    /** \brief Constructor de copias de la clase Pila.
     *
     * \param &c Cola a la cual se le construye la copia.
     *
     */
    Cola(const Cola<T> &c);

    /** \brief Sobrecarga del operador de asignación
     *
     * \param &c Cola asignada en una nueva cola.
     * \return Cola& Cola a la cuál se le asignó la cola.
     *
     */
    Cola<T> &operator=(const Cola &c);

    /** \brief Método para agregar un elemento a la cola.
     *
     * \param valor T elemento a agregar
     * \return void
     *
     */
    void Agregar(T valor);

    /** \brief Método para eliminar un elemento de la cola.
     *
     * \return void
     *
     */
    void Eliminar();

    /** \brief Método que regresa el tama�o de la cola
     *
     * \return int Tamano de la cola.
     *
     */
    int ObtenerTam() const;

    /** \brief Método que regresa el ultimo elemento de la cola.
     *
     * \return T Valor del último elemento.
     *
     */
    T ObtenerFondo() const;

    /** \brief Método que regresa el primer elemento de la cola.
     *
     * \return T Valor del primer elemento.
     *
     */
    T ObtenerFrente() const;

    /** \brief Método que retorna si la cola está v&iacute;cia.
     *
     * \return bool
     *
     */
    bool EstaVacia() const;

    /** \brief Método para vaciar la cola.
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief Método que imprime todo el contenido de la cola.
     *
     * \return void
     *
     */
    void Imprimir() const;

    /** \brief Método que imprime el contenido de la cola a excepcion del primer elemento.
     *
     * \return void
     *
     */
    void ImprimirSinFrente() const;


private:

    /** \brief Atributo Tama�o de la cola.
     *
     */
    int tam;

    /** \brief Atributo Elemento de la cola.
     *
     */
    struct Elemento
    {
        T valor;
        Elemento *siguiente;
        Elemento(T val, Elemento *sig) : valor(val), siguiente(sig) {} // Constructor for Elemento
    };
    Elemento *fondo;
};

#include "Cola.tpp"

#endif // COLA_HPP_INCLUDED
