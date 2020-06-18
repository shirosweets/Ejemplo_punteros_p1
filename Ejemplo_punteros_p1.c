#include <stdio.h>
#include <stdlib.h> // para el assert

struct _punto { // P4
    int x;
    int y;
};

typedef struct _punto *punto_t; // Sinónimo P4

struct persona{ // P4 EJEMPLO
    char inicial;
    int edad;
};

// Call by address
void mitad(int *y){ // Utilizo un puntero para así modificar a donde apunta *y
    *y = *y/2;
}

// Otra forma de resolverlo es: Call by value
int mitad2(int a){ // Utilizo una función que devuelve un entero
    return a/2;
}

void modificar(int *q5){ // P5 se crea otro frame en STACK y apunta al mismo bloque de memoria que p5
    q5[1]=2;
    return; // Al finalizar se elimina el puntero *q5
}

int main(){
    printf(" ********* Inicio programa *********\n");

    printf("\n Parte 1: - Link: https://youtu.be/ocuEnhhj1h0");

    printf("\n\n");
    int x1 = 4;
    int x2 = 3;

    printf(" x1=%d\n", x1);
    printf(" x2=%d\n", x2);

    char c1 = 'a';
    char c2 = 'z';

    printf(" c1=%c\n", c1);
    printf(" c2=%c\n", c2);
    //float f1 = 3.4;

    x1 = x2*2; // Nada nuevo hasta acá

    printf(" El valor de x1 es: %d\n", x1);

    // Se lee de derecha a izquierda el puntero  <--
    int *p = &x1; // p es un puntero a un entero = & a donde apunta (x1)
    int *q = &x2; // q es un puntero a un entero = & a donde apunta (x2)
    char *r = &c2; // r es un puntero a un char = & a donde apunta (c2)

    // Asignacion que modifica el lugar a donde apunta p (modifico la flecha, no el contenido)
    p = q; // p apunta al mismo lugar donde apunta q, ambos punteros apuntan al mismo valor (x2)
    
    // x1=6, x2=3, p-->x2, q-->x2, r-->c2, c1='a', c2='z'
    // *Modico a donde apunta la flecha (modifico el contenido de la flecha)
    *p = 9; // (x2)
    // x1=6, x2=9, p-->x2, q-->x2, r-->c2, c1='a', c2='z'
    q = &x1; // q ahora apunta a x1
    // x1=6, x2=9, p-->x2, q-->x1, r-->c2, c1='a', c2='z'
    *q = *p+1; // la celda apuntada por q (x1) voy a guardar el valor de *q(x1) = *p(x2=9)+1
    // x1=10, x2=9, p-->x2, q-->x1, r-->c2, c1='a', c2='z'
    r = &c1; // Modifico a donde apunta r
    //printf("El valor de r es: %p\n", r);
    // x1=10, x2=9, p-->x2, q-->x1, r-->c1, c1='a', c2='z'
    *r = c2; // Modifico la celda apuntada por r
    //printf("El valor de r es: %p\n", r);
    // x1=10, x2=9, p-->x2, q-->x1, r-->c1, c1='z', c2='z' 

    //int *p;  Declaración de un puntero de tipo entero
    //(&) Operador de referencia ("crear una flecha")
    //(*) Operador de dereferenciación ("seguir la flecha")

    printf("\n PARTE 2: Pasaje de referencias - Link: https://youtu.be/nPykvR-wh5k");

    int x = 4;
    mitad(&x);
    printf("\n\n Call by address: %d\n", x);
    
    mitad2(x);
    printf(" Call by value: %d\n", x);


    printf("\n PARTE 3: Arreglos - Link: https://youtu.be/xqWlvg--DvY");

    printf("\n\n");

    int a[4]={1, 3, 8, 6};
    int *p1 = NULL;
    p1 = a; // la a se converte en un puntero al primer elemento del arreglo
    // El puntero p apunta a la primera celda del arreglo
    // p-->a[0], a[0]=1
    *p1 = 5; // Se modifica el a[0]
    // a[4]={5, 3, 8, 6}, a[0]=5
    *(p1+1) = 0; // Modifico el elemento de la celda a[0]+1, es decir a[1]=0, me desplazo una celda más
    // a[4]={5, 0, 8, 6}, p1[0]=5, p1[1]=0
    *(p1+3) = 7;
    // a[4]={5, 0, 8, 7}, a[0]=5, p1[1]=0, p1[3]=7
    p1[2]=3; // Yo puedo usar tranquilamente a p1 como si fuera el arreglo por p1=a
    // a[4]={5, 0, 3, 7}, a[0]=5, p1[1]=0, p1[2]=3, p1[3]=7
    p1 = p1+1;// Puedo cambiar de lugar el puntero, apuntando al segundo, olvidándome del primero
    // a[4]={5, 0, 3, 7}, a[0]=5, p1[1]=0, p1[2]=3, p1[3]=7
    p1[1]=2; // Accedo a la primera celda
    // a[4]={5, 0, 2, 7}, a[0]=5, p1[1]=0, p1[2]=3, p1[3]=7, p1[1]=2

    // Los punteros siempre quedan en el primer lugar del arreglo al menos que los modifiquemos de lugar

    printf("\n Parte 4: Estructuras - Link: https://youtu.be/iuSzA7I56Mw");;
    printf("\n\n");

    /*struct _punto r2;
    // Con el operador . podemos acceder a los campos de la estructura
    r2.x = 0; // En el campo x de la estructura r guardame 0
    r2.y = 1; // En el campo y de la estructura r guardame 1
    // Empezamos con punteros
    struct _punto *p2 = NULL; // p2 es un puntero a una estructura _punto
    p2 = &r; // Apunto a la dirección de r, p2 apunta a todo r2
    // No es valido .p2 porque p2 es un puntero NO es una estructura
    // Si es válido
    (*p2).x = 2; // En la estructura apuntada por p2 accedo al campo x
    // (*p2).x = 2 es equivalente a p2->x = 2
    p2->y = 3; // Solo tiene sentido si p2 es un puntero a una estructura, sino no tiene sentido */
    

    // *struct _punto r; lo cambio por punto_t p2 = NULL;
    struct _punto r2;
    r2.x=0;
    r2.y=1;
    printf(" r2.x=%d\n", r2.x);
    printf(" r2.y=%d\n", r2.y);

    punto_t p2 = NULL;
    p2=&r2;
    (*p2).x=2;
    p2->y=3;

    printf("\n r2.x es: %d\n", r2.x);
    printf(" r2.y es: %d\n", r2.y);

    // <<Checkpoint>>
    // -Punteros y estructuras: 
    // El operador "->" sirve para acceder al campo de una estructura a partir de un puntero
    // (*p).x es equivalente a p->x
    // -Sinónimos de tipos:
    // typedef es útil para hacer sinónimos de tipos
    // Ejemplos: 
    // typedef int entero;
    // typedef char caracter;
    // typedef int *puntero_a_entero;

    // entero x=0;
    // puntero_a_entero p=&x;

    // EJEMPLO

    printf("\n EJEMPLO 2\n");
    struct persona per1;
    per1.inicial = 'v';
    per1.edad = 19;

    printf("\n La edad de valentina es %d\n", per1.edad);

    struct persona *q4 = &per1;
    q4->edad = q4->edad+1; // q4 está apuntando al campo edad y le estoy modificando el campo de esa celda por a edad que ya tenía+1

    printf("\n La edad de valentina es %d\n", per1.edad);

    printf("\n PARTE 5: Manejo dinámico de memoria - Link: https://youtu.be/-hAzKSd09nE");

    printf("\n\n");

    int *p5 = NULL; // Se crea en el STACK
    p5=calloc(2, sizeof(int)); // Reservo usando calloc, 2 celdas contiguas en el HEAP y que ambas tienen 
    // el tamaño de un arreglo y las inicializa con el valor 0 y me devuelve un puntero que apunta a la
    // primera posición del bloque continuo, creando así un arreglo de 2 espacios en el HEAP
    // {0,0}
    p5[1]=2;
    // {0, 2}
    free(p5); // Libero la memoria del HEAP, pero el puntero sigue apuntado al lugar donde apuntaba
    // Llego a un puntero colgante o dangling pointer (que genera una violación de segmento)
    // y debo cambiar por una constante nula 
    p5 = NULL;

    // IMPORTANTE: no tiene sentido llamar a free si no usé calloc

    // EJEMPLO 2 P5 (continúa...)

    p5=calloc(2, sizeof(int)); // Mismo de antes
    //assert(p5!=NULL);
    modificar(p5);
    free(p5); // Libero del HEAP
    p5=NULL; // Ya no queda nada en la memoria

    // ¿Qué pasa si no libero la memoria? --> https://youtu.be/-hAzKSd09nE?t=1034

    printf("\n PARTE 6: Implementación del TAD Counter - Link: https://youtu.be/3HiHZPDHY2c");

    printf("\n\n");

    

    printf("\n ********* Fin programa *********\n");
    return (0);
}