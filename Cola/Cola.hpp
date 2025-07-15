/**
 * \file Cola.hpp
 * \brief Implementaci&oacute;n de una cola gen&eacute;rica.
 * \author Ana Laura Chenoweth Galaz, Georgina Salcido Valenzuela
 * \date 17/03/2024
 */


#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED

/** \class Cola
 *
 * Permite utilizar <b> colas de datos gen&eacute;ricos. </b> y ofrece un conjunto de operaciones b&aacute;sicas: agregar, eliminar, obtener el tamano de la cola,
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

    /** \brief Sobrecarga del operador de asignaci&oacute;n
     *
     * \param &c Cola asignada en una nueva cola.
     * \return Cola& Cola a la cu&aacute;l se le asign&oacute; la cola.
     *
     */
    Cola<T> &operator=(const Cola &c);

    /** \brief M&eacute;todo para agregar un elemento a la cola.
     *
     * \param valor T elemento a agregar
     * \return void
     *
     */
    void Agregar(T valor);

    /** \brief M&eacute;todo para eliminar un elemento de la cola.
     *
     * \return void
     *
     */
    void Eliminar();

    /** \brief M&eacute;todo que regresa el tama�o de la cola
     *
     * \return int Tamano de la cola.
     *
     */
    int ObtenerTam() const;

    /** \brief M&eacute;todo que regresa el ultimo elemento de la cola.
     *
     * \return T Valor del &uacute;ltimo elemento.
     *
     */
    T ObtenerFondo() const;

    /** \brief M&eacute;todo que regresa el primer elemento de la cola.
     *
     * \return T Valor del primer elemento.
     *
     */
    T ObtenerFrente() const;

    /** \brief M&eacute;todo que retorna si la cola est&aacute; v&iacute;cia.
     *
     * \return bool
     *
     */
    bool EstaVacia() const;

    /** \brief M&eacute;todo para vaciar la cola.
     *
     * \return void
     *
     */
    void Vaciar();

    /** \brief M&eacute;todo que imprime todo el contenido de la cola.
     *
     * \return void
     *
     */
    void Imprimir() const;

    /** \brief M&eacute;todo que imprime el contenido de la cola a excepcion del primer elemento.
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
