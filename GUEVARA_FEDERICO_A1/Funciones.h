#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 3
#define VACIO 1
#define LLENO 0

typedef struct
{
    int  codigoDProveedor;
    char descripcion[50];
} eProveedor;

typedef struct
{
    int codigoDP;
    char descripcion[50];
    float importe;
    float cantidad;
    int isEmpty;
}eProducto;


char menu(void);/** \brief llama al menu
 *
 * \param void 0
 * \return char menu
 *
 */
char menuModif(void);/** \brief  modoifca al menu
 *
 * \param void 0
 * \return char menuModif
 *
 */
void init(eProducto[],int);/** \brief inicializa la funcion porducto
 *
 * \param void 0
 * \return char init
 *
 */
int buscaLibre(eProducto[],int); /** \brief Busca un espacio libre
 *
 * \param int
 * \return char
 */
int BuscarPro(eProducto[],int,int);/** \brief busca producto
 *
 * \param int
 * \return int
 *
 */
void mostrarPro2(eProducto[],int);/** \brief
 *
 * \param void 0
 * \return char mostrar
 *
 */
void AgregarProducto(eProducto[],int);/** \brief agrega producto al sistema
 *
 * \param void 0

 * \return char
 *
 */
void BorrarProducto(eProducto[],int);/** \brief da la baja de un producto
 *
 * \param void 0
 * \return char
 *
 */
void modiPro(eProducto[],int);/** \brief modifica un producto
 *
 * \param void 0
 * \return char
 *
 */
void listraPro(eProducto[],int);/** \brief muestra una lista de los productos
 *
 * \param void 0
 * \return char
 *
 */
void ordernarPro (eProducto[],int);/** \brief ordena los productos por impore y descripcion
 *
 * \param void0
 * \return char
 *
 */

void HardcodeProveedor(eProveedor lista[]);/** \brief harcodea proveedoras pra poder cargarlos al producto
 *
 * \param void
 * \return char
 *
 */
