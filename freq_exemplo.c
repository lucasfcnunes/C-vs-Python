#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 200 + 1
#define EOS '\0'

#define OK 0

#define DEBUG 1

//Define o struct
struct ficha_palavra
{
    char palavra[MAX_LENGTH];
    short unsigned quantidade;
};

int main(int argc, const char *argv[])
{

    //Recebe a frase digitada e salva no vetor frase
    char frase[MAX_LENGTH];
    // printf("%i", argc);
    if (argc == 2)
    {
        strncpy(frase, argv[1], MAX_LENGTH);
    }
    else
    {
        printf("Digite a frase: ");
        gets(frase);
    }

    //Declaração de variaveis
    int vazio, qPalavras, tamanho, f;
    char primeiroElemento, ultimoElemento;

    //Contagem de CONJUNTOS de caracteres vazios para contagem de palavras e verificacao do tamanho
    vazio = 0;    //Conjunto de caracteres vazios
    tamanho = -1; //Quantidade de caracteres existentes na frase digitada
    for (int i = 0; frase[i] != EOS; i++)
    {
        if (i == 0)
        {
            primeiroElemento = frase[i];
            if (primeiroElemento == ' ')
            {
                vazio--;
            }
        }
        else
        {
            if (frase[i] == ' ' && frase[i - 1] != ' ')
            {
                vazio++;
            }
        }
        ultimoElemento = frase[i];
        tamanho++;
    }

    if (ultimoElemento == ' ')
    {
        vazio--;
    }
    qPalavras = vazio + 1;                    //Quantidade de palavras
    char palavras[qPalavras - 1][MAX_LENGTH]; //Vetor palavras com tamanho apropriado

    //Separa as palavras em um vetor
    int contador = 0;
    for (int k, j = 0; j <= tamanho; j++)
    {
        k = 0;
        if (frase[j] != ' ' && (frase[j - 1] == ' ' || j == 0))
        { //identifica se frase[j] é o inicio de uma palavra
            f = j;
            while (frase[f] != ' ' && f <= tamanho)
            {
                palavras[contador][k] = frase[f];
                k++;
                f++;
            }
            palavras[contador][k] = EOS;
            contador++;
        }
    }

    //Coloca as palavras diferentes na ficha
    struct ficha_palavra ficha[qPalavras]; //Cria um struct do tipo ficha com tamanho maximo igual a quantidade de palavras(incluindo as repetidas)
    int qPalavrasDif = 0;
    for (int i = 0, repete; i < qPalavras - 1; i++)
    {
        repete = 0;
        for (int k = i + 1; k < qPalavras; k++)
        {
            if (strcmp(palavras[i], palavras[k]) == 0)
            {
                repete = 1;
                break;
            }
        }
        if (repete == 0)
        {
            strcpy(ficha[qPalavrasDif].palavra, palavras[i]);
            qPalavrasDif++;
        }
    }
    strcpy(ficha[qPalavrasDif].palavra, palavras[qPalavras - 1]);
    qPalavrasDif++; //Quantidade de palavras diferentes

    //Salva no struct a quantidade de vezes que cada palavra aparece
    for (int i = 0, a; i < qPalavrasDif; i++)
    {
        a = 0;
        for (int j = 0; j < qPalavras; j++)
        {
            if (strcmp(ficha[i].palavra, palavras[j]) == 0)
            {
                a++;
            }
        }
        ficha[i].quantidade = a;
    }

    //Coloca na tela o conteudo do struct
    for (int i = 0; i < qPalavrasDif; i++)
    {
        printf("\n%s - %d\n", ficha[i].palavra, ficha[i].quantidade);
    }
    return OK;
}
