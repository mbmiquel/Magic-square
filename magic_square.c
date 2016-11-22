#include <stdio.h>
#define MAX 29

typedef struct
{
    int nfila, ncol;
    int matriz[MAX][MAX];
}tmatriu;

main ()
{
    int f, c, ini, n, constante;

    tmatriu m;

    printf("Introduzca dimension del cuadrado magico: ");
    scanf("%d", &m.nfila);
    m.ncol=m.nfila;

    if (m.nfila<3)
    {
        printf("La dimension minima del cuadrado magico es 3\n");
    }

    else if (m.nfila>29)
    {
        printf("El programa no genera cuadrados magicos con dimension > 29\n");
    }

    else if (m.nfila%2==0)
    {
        printf("La dimension del cuadrado magico debe ser impar y >=3\n");

    }

    else
    {

        for (f=0; f<29; f++)
        {
            for (c=0; c<29;c++)
            {
                m.matriz[f][c]=0;
            }

        }

        ini=(m.ncol-1)/2;

        m.matriz[0][ini]=1;
        f=0;
        c=ini;

        for (n=2;n<=(m.nfila*m.nfila);)
        {
            if (f-1<0 && c+1<=m.ncol-1) //derecha si arriba no
            {
                c++;
                f=m.nfila-1;
                m.matriz[f][c]=n;
                n++;
            }

            else if (c+1>m.ncol-1 && f-1>=0) //arriba si derecha no
            {
                f--;
                c=0;
                m.matriz[f][c]=n;
                n++;
            }


            else if (f-1>=0 && c+1<=m.nfila-1) //arriba si derecha si
            {
                if (m.matriz[f-1][c+1]==0)  //esta vacia
                {
                    f--;
                    c++;
                    m.matriz[f][c]=n;
                    n++;
                }

                else                        //esta llena
                {
                    f++;
                    m.matriz[f][c]=n;
                    n++;
                }

            }

            else if (f-1<0 && c+1>m.ncol-1) //arriba no derecha no
            {
                    f++;
                    m.matriz[f][c]=n;
                    n++;
            }



        }

        constante= (m.nfila*((m.nfila*m.nfila)+1))/2;
        printf("Todas la direcciones (columnas, filas, diagonales principales) suman: %d", constante);

        for (f=0; f<m.nfila; f++)
        {
        printf("\n");
            for (c=0; c<m.nfila;c++)
            {
                printf("%d  ", m.matriz[f][c]);
            }

        }

        printf("\n");


    }


}
