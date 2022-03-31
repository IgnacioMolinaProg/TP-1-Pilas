#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
void cargarPila(Pila *p);
void ejercicio_1();
void ejercicio_2();
void ejercicio_3();
void ejercicio_4();
void ejercicio_5();
void ejercicio_6();
void ejercicio_7();
void ejercicio_8();
void ejercicio_9();
void ejercicio_10();

int main()
{
    int ejercicio;
    do
    {
        system("cls");
        printf("\t\t\t\tTrabajo Practico N%c1: Pilas\n",167);
        printf("\n1.Cargar desde el teclado una pila DADA con 5 elementos. Pasar los tres primeros elementos ");
        printf("\n  que se encuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.\n");
        printf("\n2.Cargar desde el teclado la pila ORIGEN e inicializar en vacio la pila DESTINO. Pasar todos los\n");
        printf("  elementos de la pila ORIGEN a la pila DESTINO.\n");
        printf("\n3.Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos a valor 8.\n");
        printf("\n4.Cargar desde el teclado la pila ORIGEN e inicializar en vacio la pila DESTINO. Pasar los elementos de\n");
        printf("  la pila ORIGEN a la pila DESTINO, pero dejandolos en el mismo orden.\n");
        printf("\n5.Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos\n");
        printf("  cargados originalmente en ella, pero en orden inverso.\n");
        printf("\n6.Pasar el primer elemento (tope) de la pila DADA a su ultima posicion (base), dejando los restantes\n");
        printf("  elementos en el mismo orden.\n");
        printf("\n7.Pasar el ultimo elemento (base) de la pila DADA a su primera posicion (tope), dejando los restantes\n");
        printf("  elementos en el mismo orden.\n");
        printf("\n8.Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.\n");
        printf("\n9.Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado\n");
        printf("\n10.Comparar las pilas A y B, evaluando si son completamente iguales (en cantidad de elementos,\n");
        printf("   valores que contienen y posición de los mismos). Mostrar por pantalla el resultado.\n");
        printf("\n0.Salir.\n");
        printf("\nQue ejercicio desea realizar? [ ]\b\b");
        scanf("%i",&ejercicio);
        switch(ejercicio)
        {
        case 1:
            system("cls");
            ejercicio_1();
            system("pause");
            break;
        case 2:
            system("cls");
            ejercicio_2();
            system("pause");
            break;
        case 3:
            system("cls");
            ejercicio_3();
            system("pause");
            break;
        case 4:
            system("cls");
            ejercicio_4();
            system("pause");
            break;
        case 5:
            system("cls");
            ejercicio_5();
            system("pause");
            break;
        case 6:
            system("cls");
            ejercicio_6();
            system("pause");
            break;
        case 7:
            system("cls");
            ejercicio_7();
            system("pause");
            break;
        case 8:
            system("cls");
            ejercicio_8();
            system("pause");
            break;
        case 9:
            system("cls");
            ejercicio_9();
            system("pause");
            break;
        case 10:
            system("cls");
            ejercicio_10();
            system("pause");
            break;
        case 0:
            break;
        }

    }while(ejercicio!=0);
    return 0;
}
void cargarPila(Pila *p)
{
    char control;
    do
    {
        printf("\n");
        leer(&(*p));
        printf("Desea ingresar otro valor? S/N [ ]\b\b");
        fflush(stdin);
        scanf("%c",&control);
    }while(control=='s'||control=='S');
}
void ejercicio_1()
{
    int i;
    Pila DADA;
    Pila AUX1;
    Pila AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);
    printf("Cargue la Pila DADA con 5 elementos:\n");
    for(i=0;i<5;i++)
        leer(&DADA);
    printf("\nPila DADA cargada:");
    mostrar(&DADA);
    for(i=0;i<5;i++)//pasar los ultimos 3 numeros a las pila AUX1 y los otros 2 a la pila AUX2
    {
        if(i<3)
            apilar(&AUX1,desapilar(&DADA));
        else
            apilar(&AUX2,desapilar(&DADA));

    }
    printf("Pila AUX1");
    mostrar(&AUX1);
    printf("Pila AUX2");
    mostrar(&AUX2);

}
void ejercicio_2()
{
    Pila ORIGEN;
    Pila DESTINO;
    inicpila(&ORIGEN);
    inicpila(&DESTINO);
    cargarPila(&ORIGEN);
    printf("\nPila ORIGEN:");
    mostrar(&ORIGEN);
    while(!pilavacia(&ORIGEN))
        apilar(&DESTINO,desapilar(&ORIGEN));
    printf("\nPila DESTINO:");
    mostrar(&DESTINO);
}
void ejercicio_3()
{
    Pila DADA;
    Pila DISTINTOS;
    Pila AUX;
    inicpila(&DADA);
    inicpila(&DISTINTOS);
    inicpila(&AUX);
    cargarPila(&DADA);
    while(!pilavacia(&DADA))
    {
        if(tope(&DADA)==8)
                apilar(&AUX,desapilar(&DADA));
        else
            apilar(&DISTINTOS,desapilar(&DADA));
    }
    while(!pilavacia(&AUX))
        apilar(&DADA,desapilar(&AUX));
    printf("\nPila DADA: ");
    mostrar(&DADA);
    printf("\nPila DISTINTOS: ");
    mostrar(&DISTINTOS);
}
void ejercicio_4()
{
    Pila ORIGEN,DESTINO,AUX;
    inicpila(&ORIGEN);
    inicpila(&DESTINO);
    inicpila(&AUX);
    cargarPila(&ORIGEN);
    printf("Pila ORIGEN:");
    mostrar(&ORIGEN);
    while(!pilavacia(&ORIGEN))
        apilar(&AUX,desapilar(&ORIGEN));
    while(!pilavacia(&AUX))
        apilar(&DESTINO,desapilar(&AUX));
    printf("PIla DESTINO:");
    mostrar(&DESTINO);
}
void ejercicio_5()
{
    Pila DADA,AUX1,AUX2;
    inicpila(&DADA);
    inicpila(&AUX1);
    inicpila(&AUX2);
    cargarPila(&DADA);
    mostrar(&DADA);
    while(!pilavacia(&DADA))
        apilar(&AUX1,desapilar(&DADA));
    while(!pilavacia(&AUX1))
        apilar(&AUX2,desapilar(&AUX1));
    while(!pilavacia(&AUX2))
        apilar(&DADA,desapilar(&AUX2));
    printf("Pila DADA invertida:");
    mostrar(&DADA);
}
void ejercicio_6()
{
    Pila DADA,AUX;
    int topeDada;
    inicpila(&DADA);
    inicpila(&AUX);
    cargarPila(&DADA);
    mostrar(&DADA);
    topeDada=desapilar(&DADA);
    while(!pilavacia(&DADA))
        apilar(&AUX,desapilar(&DADA));
    apilar(&DADA,topeDada);
    while(!pilavacia(&AUX))
        apilar(&DADA,desapilar(&AUX));
    printf("Pila DADA con el tope en la base:");
    mostrar(&DADA);
}
void ejercicio_7()
{
    Pila DADA,AUX;
    int BaseDada;
    inicpila(&DADA);
    inicpila(&AUX);
    cargarPila(&DADA);
    mostrar(&DADA);
    while(!pilavacia(&DADA))
        apilar(&AUX,desapilar(&DADA));
    BaseDada=desapilar(&AUX);
    while(!pilavacia(&AUX))
        apilar(&DADA,desapilar(&AUX));
    apilar(&DADA,BaseDada);
    printf("Pila DADA con la base en el tope:");
    mostrar(&DADA);
}
void ejercicio_8()
{
    Pila MAZO,JUGADOR_1,JUGADOR_2;
    inicpila(&MAZO);
    inicpila(&JUGADOR_1);
    inicpila(&JUGADOR_2);
    cargarPila(&MAZO);
    printf("MAZO:");
    mostrar(&MAZO);
    while(!pilavacia(&MAZO))
    {
        apilar(&JUGADOR_1,desapilar(&MAZO));
        if(!pilavacia(&MAZO))
            apilar(&JUGADOR_2,desapilar(&MAZO));
    }
    printf("JUGADOR 1:");
    mostrar(&JUGADOR_1);
    printf("JUGADOR 2:");
    mostrar(&JUGADOR_2);
}
void ejercicio_9()
{
    Pila pilaA,pilaB,auxA,auxB;
    char masGrande;
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxA);
    inicpila(&auxB);
    printf("Cargue la pila A:");
    cargarPila(&pilaA);
    printf("\nCargue pila B:");
    cargarPila(&pilaB);
    printf("\nPila A:");
    mostrar(&pilaA);
    printf("Pila B");
    mostrar(&pilaB);
    while(!pilavacia(&pilaA)&&!pilavacia(&pilaB))
    {
        apilar(&auxA,desapilar(&pilaA));
        apilar(&auxB,desapilar(&pilaB));
    }
    if(pilavacia(&pilaA)&&pilavacia(&pilaB))
        printf("\nLas dos pilas son del mismo tamanio.\t");
    else
    {
        if(!pilavacia(&pilaA))
            masGrande='A';
        if(!pilavacia(&pilaB))
            masGrande='B';
        printf("La pila mas grande es la %c.\t",masGrande);
    }
    while(!pilavacia(&auxA))
        apilar(&pilaA,desapilar(&auxA));
    while(!pilavacia(&auxB))
        apilar(&pilaB,desapilar(&auxB));
}
void ejercicio_10()
{
     Pila pilaA,pilaB,auxA,auxB;
    char sonIguales='s';
    inicpila(&pilaA);
    inicpila(&pilaB);
    inicpila(&auxA);
    inicpila(&auxB);
    printf("Cargue la pila A:");
    cargarPila(&pilaA);
    printf("\nCargue pila B:");
    cargarPila(&pilaB);
    printf("\nPila A:");
    mostrar(&pilaA);
    printf("Pila B");
    mostrar(&pilaB);
    while(!pilavacia(&pilaA)&&!pilavacia(&pilaB)&&sonIguales=='s')//se corta cuando en una de las dos pilas quedo vacia
    {
        if(tope(&pilaA)==tope(&pilaB))
        {
            apilar(&auxA,desapilar(&pilaA));
            apilar(&auxB,desapilar(&pilaB));
        }
        else
            sonIguales='n';
    }
    if(!pilavacia(&pilaA)||!pilavacia(&pilaB))//si una de las pila quedo con un elemento
        sonIguales='n';
    if(sonIguales=='s')
        printf("\n\nLas dos pilas son identicas.\n");
    else
        printf("\n\nLas dos pilas son distintas.\n");
    while(!pilavacia(&auxA))
        apilar(&pilaA,desapilar(&auxA));
    while(!pilavacia(&auxB))
        apilar(&pilaB,desapilar(&auxB));
}
