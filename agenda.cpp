#include <stdio.h>

const int TAM = 5;

int main()
{
    int v[TAM];

    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &v[i]);
    }
    int qtd = 0;
    int contador =0;
    for ( int i = 0; i < TAM; i++)
    {
        qtd = 0;
        contador = 1;
        for(int j = 0; j < TAM; j++)
            {
                if (v[j] == v[i])
                qtd++;

            if (qtd > 1)
                contador++;
            }
            printf("%d  %d\n", v[i], contador);

    }


}

