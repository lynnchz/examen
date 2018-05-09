#include "ABM.h"

char menu(void)
{
    char opcion;

    printf(" 1) Agregar producto\n");
    printf(" 2) Borrar producto\n");
    printf(" 3) Modificar Producto\n");
    printf(" 4) Listar\n");
    printf(" 5) Ordenar\n");
    printf(" 6) Salir\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}

void inicializar(eProducto pro[],int tam)
{
    int i;
    for(i=0 ; i<tam ; i++)
    {
        pro[i].isEmpty=VACIO;
    }
}
int buscaLibre(eProducto pro[],int tam)
{
    int indice=-1;
    int i;

    for( i=0 ; i<tam ; i++)
    {
        if(pro[i].isEmpty==VACIO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
int BuscarPro(eProducto pro[], int tam, int codigoDP)
{
    int E=-1;
    int i;

    for( i=0 ; i<tam ; i++)
    {
        if(pro[i].codigoDP==codigoDP && pro[i].isEmpty==LLENO)
        {
            E=i;
            break;
        }
    }

    return E;
}
void mostrarPro2(eProducto pro[],int E)
{
    printf("\n%d\t\t%s\t\t%.2f\t\t%.2f\n", pro[E].codigoDP, pro[E].descripcion, pro[E].importe, pro[E].cantidad);
}
void AgregarProducto(eProducto pro[],int tam)
{
    int indice, E, error=0, codigoDP;
    char aux[50];
    int i;
    int cont=0;
    system("cls");
    indice=buscaLibre(pro,tam);
    if(indice==-1)
    {
        printf("\nNo hay espacio en agenda, borre algun producto primero\n");
        system("pause");
    }
    else
    {
        printf("\t\t\tAgregar producto\n");
        //codigoDP
        printf("\nIngrese Codigo de producto: ");
        fflush(stdin);
        scanf("%s",aux);
        for(i=0 ; i<strlen(aux) ; i++)
        {
            if(!isdigit(aux[i]))
            {
                error=1;
                while(error==1)
                {
                    printf("\nIngrese Codigo de producto correctamente: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    i=-1;
                    error=0;
                }
            }
        }
        codigoDP=atoi(aux);
        E=BuscarPro(pro,tam,codigoDP);
        printf("\n");
        if(E!=-1)
        {
            printf("El siguiente empleado ya ha sido agregado previamente\n");
            printf("|Codigo de producto    |descripcion                        |importe|cantidad\n");
            mostrarPro2(pro,E);
        }
        else
        {
            pro[indice].isEmpty=LLENO;
            pro[indice].codigoDP=codigoDP;
            //descripcion
            printf("Ingrese descripcion: ");
            fflush(stdin);
            scanf("%[^\n]",pro[indice].descripcion);
            strlwr(pro[indice].descripcion);
            for(i=0 ; pro[indice].descripcion[i]!='\0' ; i++)
            {
                if(i==0)
                {
                    pro[indice].descripcion[i]=toupper(pro[indice].descripcion[i]);
                }
                if(pro[indice].descripcion[i]==' ')
                {
                    pro[indice].descripcion[i+1]=toupper(pro[indice].descripcion[i+1]);
                }
            }
            //importe
            printf("\nIngrese Importe: ");
            fflush(stdin);
            scanf("%f",&pro[indice].importe);
            while(pro[indice].importe<0)
            {
                printf("\nIngrese un importe correcto: ");
                fflush(stdin);
                scanf("%f",&pro[indice].importe);
            }
            //cantidad
            printf("\nIngrese cantidad: ");
            fflush(stdin);
            scanf("%s",aux);
            error=0;
            cont++;
            for(i=0; i<strlen(aux) ; i++)
            {
                if(!isdigit(aux[i]))
                {
                    error=1;
                    while(error==1)
                    {
                        printf("\nIngrese cantidad correctamente: ");
                        fflush(stdin);
                        scanf("%s",aux);
                        i=-1;
                        error=0;
                    }
                }
            }
            pro[E].cantidad=atof(aux);
            pro[indice].cantidad=atof(aux);

        }
    }
}
void BorrarProducto(eProducto pro[],int tam)
{
    int E, error=0, codigoDP;
    char aux[15], confirma;
    int i;

    system("cls");
    printf("\t\t\tEliminar producto\n");
    printf("\nIngrese Codigo de producto: ");
    fflush(stdin);
    scanf("%s",aux);
    for(i=0 ; i<strlen(aux) ; i++)
    {
        if(!isdigit(aux[i]))
        {
            error=1;
            while(error==1)
            {
                printf("\nIngrese Codigo de producto correctamente: ");
                fflush(stdin);
                scanf("%s",aux);
                i=-1;
                error=0;
            }
        }
    }
    codigoDP=atoi(aux);
    E=BuscarPro(pro,tam,codigoDP);
    if(E==-1)
    {
        printf("\nEl Codigo de producto %d no corresponde a ningun producto registrado\n",codigoDP);
    }
    else
    {

        printf("Seguro que desea eliminar el porducto s/n? \n");
        fflush(stdin);
        scanf("%c",&confirma);
        confirma=tolower(confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRespuesta invalida, desea eliminar el producto?\n");
            fflush(stdin);
            scanf("%c",&confirma);
        }
        if(confirma=='s')
        {
            pro[E].isEmpty=VACIO;
            printf("\n\nEl producto se ha eliminado exitosamente\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n");
        }
    }
}
char menuModif(void)
{
    char opcion;

    system("cls");
    printf("Seleccione que desea modificar\n\n");
    printf(" 1 - descripcion\n");
    printf(" 2 - importe\n");
    printf(" 3 - cantidad\n");
    printf(" 4 - Salir\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
void modiPro(eProducto pro[],int tam)
{
    int E, error=0, seguir=1, codigoDP;
    char aux[80], confirma, opcion;
    int i;

    system("cls");
    printf("\t\t\tModificacion de Datos\n");
    printf("\nIngrese Codigo de producto: ");
    fflush(stdin);
    scanf("%s",aux);
    for(i=0 ; i<strlen(aux) ; i++)
    {
        if(!isdigit(aux[i]))
        {
            error=1;
            while(error==1)
            {
                printf("\nIngrese Codigo de producto correctamente: ");
                fflush(stdin);
                scanf("%s",aux);
                i=-1;
                error=0;
            }
        }
    }
    codigoDP=atoi(aux);
    E=BuscarPro(pro,tam,codigoDP);
    if(E==-1)
    {
        printf("\nEl Codigo de producto %d no corresponde a ningun empleado registrado\n",codigoDP);
    }
    else
    {
        printf("\n");
        printf("Confirma la modificacion? s/n \n");
        fflush(stdin);
        scanf("%c",&confirma);
        confirma=tolower(confirma);
        while(confirma!='s' && confirma!='n')
        {
            printf("\nRespuesta invalida, confirma la modificacion?\n");
            fflush(stdin);
            scanf("%c",&confirma);
        }
        if(confirma=='s')
        {
            do
            {
                opcion=menuModif();
                while(opcion<49 || opcion>55 || !isdigit(opcion))
                {
                    system("cls");
                    printf("Ingrese correctamente una de las siguientes opciones\n\n");
                    opcion=menuModif();
                }
                switch(opcion)
                {

                case '1':
                {
                    system("cls");
                    printf("\nIngrese nuevo descripcion: ");
                    fflush(stdin);
                    scanf("%[^\n]",aux);
                    strlwr(aux);
                    printf("\n");
                    for(i=0 ; aux[i]!='\0' ; i++)
                    {
                        if(i==0)
                        {
                            aux[i]=toupper(aux[i]);
                        }
                        if(aux[i]==' ')
                        {
                            aux[i+1]=toupper(aux[i+1]);
                        }
                    }
                    strcpy(pro[E].descripcion,aux);
                    printf("\nModificacion exitosa!\n\n\n");
                    system("pause");
                    break;
                }
                case '2':
                {
                    system("cls");
                    printf("\t\t\tImporte\n");
                    printf("\nIngrese nuevo importe: ");
                    fflush(stdin);
                    scanf("%c",aux);
                    printf("\n");

                    while(aux[0]<0)
                    {
                        printf("\nIngrese importe correctamente: ");
                        fflush(stdin);
                        scanf("%c",aux);

                        pro[E].importe=aux[0];
                        printf("\nModificacion exitosa!\n\n\n");
                        system("pause");
                        break;

                    }
                }
                case '3':
                {
                    system("cls");
                    printf("\t\t\tCantidad\n");
                    printf("\nIngrese nuevo cantidad: ");
                    fflush(stdin);
                    scanf("%s",aux);
                    error=0;
                    printf("\n");
                    for(i=0 ; i<strlen(aux) ; i++)
                    {
                        if(!isdigit(aux[i]))
                        {
                            error=1;
                            while(error==1)
                            {
                                printf("\nIngrese cantidad correctamente: ");
                                fflush(stdin);
                                scanf("%s",aux);
                                i=-1;
                                error=0;
                            }
                        }
                    }
                    pro[E].cantidad=atof(aux);
                    printf("\nModificacion exitosa!\n\n\n");
                    system("pause");
                    break;
                }
                case '4':
                {
                    seguir=0;
                    break;
                }
                }
            }
            while(seguir==1);
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n\n");
        }
    }
}
void listraPro(eProducto pro[],int tam)
{
    int encuentra=1, vacio=1;
    int i;

    system("cls");
    printf("\t\t\tListar productos\n");
    for( i=0 ; i<tam ; i++)
    {
        if(pro[i].isEmpty==LLENO)
        {
            if(encuentra==1)
            {

                printf("Codigo de producto    descripcion      importe  \tcantidad        |\n");
                encuentra=0;
                vacio=0;
            }
            mostrarPro2(pro,i);
        }
    }
    if(vacio==1)
    {
        printf("\nLa agenda esta vacia, no hay nada que listar\n");
    }
}
void ordernarPro(eProducto pro[],int tam)
{
    int vacio=1;
    int i;
    eProducto aux;
    system("cls");
    printf("\n\t\t\tOrdenar productos\n");

    for( i=0 ; i<tam-1 ; i++)
    {
        int j;
        for(j=i+1 ; j<tam ; j++)
        {
            if(pro[i].importe<pro[j].importe && pro[i].isEmpty==LLENO && pro[j].isEmpty==LLENO)
            {
                vacio=0;
                aux=pro[i];
                pro[i]=pro[j];
                pro[j]=aux;
            }
            else if(pro[i].importe==pro[j].importe && pro[i].isEmpty==LLENO && pro[j].isEmpty==LLENO)
            {
                if(strcmp(pro[i].descripcion,pro[j].descripcion)>0)
                {
                    vacio=0;
                    aux=pro[i];
                    pro[i]=pro[j];
                    pro[j]=aux;
                }
            }
        }
    }
    if(vacio==0)
    {
        printf("\n\n\t\t\t***Ordenamiento exitoso!***\n\n\n");
    }
    else
    {
        printf("\nNo hay ningun dato en el sistema\n\n\n");
    }
}
void HardcodeProveedor(eProveedor lista[])
{
    eProveedor nuevaL;

    strcpy(nuevaL.descripcion,"Todo x 2 peso ");
    nuevaL.codigoDProveedor=0;
    lista[0]=nuevaL;

    strcpy(nuevaL.descripcion,"YPF");
    nuevaL.codigoDProveedor=1;
    lista[1]=nuevaL;

    strcpy(nuevaL.descripcion,"Jumbo");
    nuevaL.codigoDProveedor=2;
    lista[2]=nuevaL;

    strcpy(nuevaL.descripcion,"Coto");
    nuevaL.codigoDProveedor=3;
    lista[3]=nuevaL;

    strcpy(nuevaL.descripcion,"ChangoMas");
    nuevaL.codigoDProveedor=4;
    lista[4]=nuevaL;
}

/*void mostrarProveedor(eProveedor lista[])
{

printf("%d\t%s\n", lista[] nuevaL.descripcion);

}

void mostrarProveedores()
{
    int i;
    for (i=0; i<tam; i++)
    {
        mostrarProveedor(lista(i));
    }

}*/
