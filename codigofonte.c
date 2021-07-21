
#include <stdio.h>

#include <math.h>

#include <stdlib.h>



float funcF(int a , int b , int c , float x)

{

    float F;

    F = (a*pow(x , 3))+ b*x+c;

    return(F);

}

float funcG(int a , int b , int c , float x)

{

    float G;

    G = (((a*-1)*pow(x , 3))+(c*-1))/b;

    return(G);

}

float funcI(int a,int b,int c, float x , float erro , int i)

{

    float Xi , f;

    Xi=funcG(a , b , c , x);

    f=funcF(a , b , c , Xi);

    if(f<0)

    {

        f=f*-1;

    }

    i=i+1;

    if(f>erro)

    {

        return funcI(a , b , c , Xi , erro , i);

    }

    printf("quantidade de iterações : %d\n ", i);

    return Xi;

}

int main()

{

    int a , b, c , cont=0;

    float erro;

    printf("digite a:");

    scanf("%d", &a);

    printf("digite b:");

    scanf("%d", &b);

    printf("digite c:");

    scanf("%d", &c);

    float x,y ;

    do{

        printf("defina um intervalo [a , b]\n") ;

        scanf("%f%f" , &x , &y);

        printf("\nintervalo : [%0.1f , %0.1f]\n" , x , y);

        if(funcF(a , b , c , x)< 0 && funcF(a , b , c , y)>0 || funcF(a , b , c , x)> 0 && funcF(a , b , c , y)<0 )

        {

            cont=2;

        }

        if(cont<2)

        {

            printf("%d\n" , cont);

            printf("intervalo não funciona pois F(a)>0 e F(b)<0");

            cont=0;

        }

    }while(cont!=2);



    //aproximação inicial

    printf("defina o erro:");

    scanf("%f" , &erro);

    float inicial;

    printf("defina a aproximação inical entre o intervalo [%0.1f , %0.1f]\n", x , y);

    scanf("%f" , &inicial);

    int i=0;

    printf("raiz aproximada X=%f " , funcI( a, b, c, inicial , erro , i));





    return 0;

}

