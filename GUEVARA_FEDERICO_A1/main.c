#include "funciones.h"

int main()
{
    int continuar=1;
    char opcion;
    eProveedor proveedores[50];
    eProducto  productos[50];
    eProducto pro[TAM];
    inicializar(pro,TAM);
    do
    {
        printf("Elija una de las siguientes opciones\n\n");
        opcion=menu();
        while(opcion<49||opcion>54||isdigit(opcion)==0)
        {
            system("cls");
            printf("Ingrese correctamente una de las siguientes opciones\n\n");
            opcion=menu();
        }
        switch(opcion)
        {
            case '1':
            {
                AgregarProducto(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '2':
            {
                BorrarProducto(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                modiPro(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '4':
            {
                listraPro(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '5':
            {
                ordernarPro(pro,TAM);
                system("pause");
                system("cls");
                break;
            }
            case '6':
            {
                continuar=0;
                break;
            }
        }
    }
    while(continuar==1);

    return 0;
}

