/* 
Alunos:  Juan Melo e Matheus Citeli
Exercicio: implemente as seguintes funções
1 - Somar todos os elementos da lista
2 - Contar o numero de ocorrencias por um elemento x na lista
3 - Remover um elemento x da lista - pode supor que o elemento exista na lista
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista
{
    int n;
    struct Lista *prox;
}Lista;

Lista *CriaLista()
{
    return NULL;
}

Lista *CriaElemento(int numero)
{
    Lista *resp = (Lista *)malloc(sizeof(Lista));
    resp->n = numero;
    resp->prox = NULL;
    return resp;
}

Lista *insere(Lista *lista, int numero)
{
    Lista *novo = CriaElemento(numero);
    novo->prox = lista;
    lista = novo;
    return lista;
}

void imprime(Lista *l)
{
    if(l != NULL)
    {
        printf("|%d| ", l->n);
        imprime(l->prox);    
    }
    printf("\n");
}

Lista  *delete(Lista *novo, int numero)
{
    Lista *aux2;
    Lista *aux = novo;
    
    if(aux == NULL)
        return novo;
    
    if(aux->n == numero)
      {
          aux2 = aux->prox;
          free(novo);
          aux = aux2;
          return aux;
      }  
    
    novo->prox  =  delete(novo->prox, numero);
    return novo;
}   

void DestroiLista(Lista **novo)
{
    if(*novo != NULL)
        DestroiLista(&(*novo)->prox);

    free(*novo);
    *novo = NULL;
}

int fazersoma(Lista *novo, int soma)
{
    if(novo == NULL)
        return soma;
    else
        return fazersoma(novo->prox, novo->n + soma);
}

int contar(Lista *novo, int numero, int cont)
{
    if(novo == NULL)
        return cont;
    else if(novo->n==numero)
        cont++;
        
    return contar(novo->prox, numero, cont);
}

int main()
{
    int menu = 0; 
    int numero = 0;
    int soma = 0;
    Lista *novo = CriaLista();

    while(menu != 7)
    {
        printf("1 - Inserir numero na lista\n2 - Deletar numero da lista\n3 - Somar todos os numeros da lista\n");
        printf("4 - Contar o numero de ocorrencias do numero na lista\n5 - Imprimir a lista\n6 - Para destruir a lista\n7-Para encerrar o programa\n");
        scanf("%d", &menu);
        printf("\n");
       
        if(menu == 1)
        {
            printf("Digite o numero que deseja inserir\n");
            scanf("%d", &numero);
            novo = insere(novo, numero);
            system("cls");
        }

        if(menu == 2)
        {
            printf("Digite o numero que deseja deletar\n");
            scanf("%d", &numero);
            novo = delete(novo, numero);
            system("cls");
        }

        if(menu == 3)
        {
            numero = fazersoma(novo, soma);
            printf("O resultado da soma eh: %d\n", numero);
        }

        if(menu == 4)
        {
            printf("Digite o numero que deseja procurar\n");
            scanf("%d", &numero);
            numero = contar(novo, numero, 0);
            printf("Se repetiu %d vez(es)\n", numero);
        }

        if(menu == 5)
            imprime(novo);
        
        if(menu == 6)
        {
            DestroiLista(&novo);
            system("cls");
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
