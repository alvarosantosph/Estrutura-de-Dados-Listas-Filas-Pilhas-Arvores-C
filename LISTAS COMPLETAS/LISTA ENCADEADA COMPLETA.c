/***************************************************************************

O c�digo completo de uma Lista Encadeada (ligada) com as seguintes fun��es:

Inserir um n� na primeira posi��o
Insere um n� na ultima posi��o
Imprimir os valores de todos os n�s
Remover todos os n�s da Lista
Remover todos os n�s com determinado valor
Remover o primeiro n� da Lista
Remover o ultimo n� da Lista
Remover o n� de uma posi��o dada
Inserir um n� com determinado valor em determinada posi��o
Verificar se a lista est� ordenada
Retornar o numero de n�s que s�o multiplos de determinado valor
Remover todos os n�s pares 

***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
 
enum boolean
{
    true = 1, false = 0
};
typedef enum boolean bool;
 
 
typedef struct Node{
    int info;
    struct Node *proximo;
}No;
 
No *primeiro = NULL;
 
void inserirPrimeiro(int valor);//Insere um n� na primeira posi��o
 
void inserirUltimo(int valor);//Insere um n� na ultina posi��o
 
void imprimir();//Imprime os valores de todos os n�s
 
void limpar();//Remove todos os n�s da Lista
 
void removerValor(int valor);//Remove todos os n�s com info = valor
 
void removerPrimeiro();//Remove o primeiro n� da Lista
 
void removerUltimo();//Remove o ultimo n� da Lista
 
void removerPosicao(int i);//Remove o n� da posi��o i
 
int tamanho();//Retona o numeros de n�s da Lista
 
void inserirPosicao(int i, int valor);//Insere um n� com info = valor na posi��o i
 
bool estaOrdenada();//Retorna se a lista est� em ordem crescente
 
int multiplos(int valor);//Retorna o numero de n�s que s�o multiplos de valor
 
int removerPares();//Remove todos os n�s pares, e retorna o n�mero de n�s excluidos
 
int main()
{
    //ALGUNS TESTES J� FEITOS.
    inserirPrimeiro(60);
    inserirPrimeiro(50);
    inserirPrimeiro(40);
    inserirPrimeiro(30);
    inserirPrimeiro(20);
    inserirPrimeiro(10);
    removerPares();
    imprimir();
    int x = 3;
    printf("Sao %d multiplos de %d.", multiplos(x), x);
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    removerPosicao(3);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    inserirPosicao(3,99);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    inserirUltimo(22);
    printf("\n");
    imprimir();
    if (estaOrdenada())
        printf("Esta ordenada");
    else
        printf("Nao esta ordenada");
    return 0;
}
 
void inserirPrimeiro(int valor)
{
    No *no = (No*) malloc (sizeof(No));
    no->info = valor;
    no->proximo = primeiro;
    primeiro = no;
}
 
void imprimir()//Imprime os valores de todos os n�s
{
    if (primeiro == NULL)
    {
        printf("A lista esta vazia!");
        return;
    }
    No *no = primeiro;
    while (no != NULL)
    {
        printf("%d ", no->info);
        no = no->proximo;
    }
}
 
void limpar()//Remove todos os n�s da Lista
{
    No *no = primeiro, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->proximo;
        free (aux);
    }
    primeiro = NULL;
}
 
void removerValor(int valor)//Remove todos os n�s com info = valor
{
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo, *anterior = NULL;
        while (aux != NULL)
        {
            if (no == primeiro)
            {
                if (no->info == valor)
                {
                    primeiro = aux;
                    free(no);
                    no = primeiro;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
            else
            {
                if (no->info == valor)
                {
                    anterior->proximo = aux;
                    free(no);
                    no = aux;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
        }
        //condi��o para o �ltimo n�
        if (no->info == valor)
        {
            if (tamanho > 1)
            {
                anterior->proximo = NULL;
                free(no);
            }
            else
            {
                free(no);
                primeiro = NULL;
            }
        }
    }
}
 
void removerPrimeiro()//Remove o primeiro n� da Lista
{
    if (primeiro != NULL)
    {
        No *no = primeiro;
        primeiro = no->proximo;
        free(no);
    }
}
 
void removerUltimo()//Remove o ultimo n� da Lista
{
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo;
        while(aux->proximo != NULL)
        {
            no = no->proximo;
            aux = aux->proximo;
        }
        free(aux);
        no->proximo = NULL;
    }
}
 
void removerPosicao(int i)//Remove o n� da posi��o i
{
    if (i < 0)
        return;
    if ((primeiro != NULL) && (tamanho() >= i))
    {
        No *no = primeiro, *aux, *anterior;
        int cont = 0;//para contagem da posi��o a partir de 0
        while (cont < i)
        {
            anterior = no;
            no = no->proximo;
            cont++;
        }
        aux = no->proximo;
        free(no);
        anterior->proximo = aux;
    }
}
 
int tamanho()//Retona o numeros de n�s da Lista
{
    int cont = 0;
    No *no = primeiro;
    while (no != NULL)
    {
        no = no->proximo;
        cont++;
    }
    return cont;
}
 
void inserirPosicao(int i, int valor)//Insere um n� com info = valor na posi��o i
{
    if (i < 0)
        return;
    if (i == 0)
    {
        inserirPrimeiro(valor);
        return;
    }
    if (tamanho() >= i)
    {
        No *no = primeiro, *aux, *novo;
        novo = (No*) malloc (sizeof(No));
        novo->info = valor;
        int cont = 0;//para contagem da posi��o a partir de 0
        while (cont < i-1)//i-1 para parar uma posi��o antes de i, para fazer a inser��o na posi��o certa
        {
            no = no->proximo;
            cont++;
        }
        aux = no->proximo;
        no->proximo = novo;
        novo->proximo = aux;
    }
}
 
void inserirUltimo(int valor)//Insere um n� na ultina posi��o
{
    if (primeiro == NULL)
    {
        inserirPrimeiro(valor);
        return;
    }
    No *no = primeiro, *novo;
    while (no->proximo != NULL)
    {
        no = no->proximo;
    }
    novo = (No*) malloc (sizeof(No));
    novo->info = valor;
    novo->proximo = NULL;
    no->proximo = novo;
}
 
bool estaOrdenada()//Retorna se a lista est� em ordem crescente
{
    if (primeiro != NULL)
    {
        No *no = primeiro;
        while (no->proximo != NULL)
        {
            if (no->info > no->proximo->info)
                return false;
            no = no->proximo;
        }
    }
    return true;
}
 
int multiplos(int valor)//Retorna o numero de n�s que s�o multiplos de valor
{
    int cont = 0;
    if (primeiro != NULL)
    {
        No *no = primeiro;
        while (no != NULL)
        {
            if ((no->info % valor) == 0)
                cont++;
            no = no->proximo;
        }
    }
    return cont;
}
 
int removerPares()//Remove todos os n�s pares, e retorna o n�mero de n�s excluidos
{
    int cont = 0;
    if (primeiro != NULL)
    {
        No *no = primeiro, *aux = no->proximo, *anterior;
        while (aux != NULL)
        {
            if (no == primeiro)
            {
                if ((no->info % 2) == 0)
                {
                    primeiro = aux;
                    free(no);
                    no = primeiro;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
            else
            {
                if ((no->info % 2) == 0)
                {
                    anterior->proximo = aux;
                    free(no);
                    no = aux;
                    aux = aux->proximo;
                }
                else
                {
                    anterior = no;
                    no = no->proximo;
                    aux = aux->proximo;
                }
            }
        }
        //condi��o para o �ltimo n�
        if ((no->info % 2) == 0)
        {
            if (tamanho() > 1)
            {
                anterior->proximo = NULL;
                free(no);
            }
            else
            {
                free(no);
                primeiro = NULL;
            }
        }
    }
    return cont;
}