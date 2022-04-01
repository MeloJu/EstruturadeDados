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



void libera (Lista *lista)
{
    Lista* p = lista;
    while (p != NULL)
    {
        Lista* t = p->prox; 
        free(p); 
        p = t; 
    }
}



void imprime(Lista *l)
{
    Lista *p = l;
    if(p!=NULL)
    {
        printf("%d ", p->n);
        imprime(p->prox);
    }
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

     if(novo == NULL)
        return NULL;
    
    

    printf("Estou no valor: %d\n", novo->n);
       
    novo->prox  =  delete(novo->prox, numero);

    return novo;

}   


int fazersoma(Lista *novo, int soma)
{
   

}





int main()
{
    int menu = 0; 
    int numero = 0;
    int soma = 0;
    Lista *novo = CriaLista();
    


    while(menu != 5)
    {
        printf("1 - Inserir numero na lista\n2 - Deletar numero da lista\n3 - Somar todos os numeros da lista\n");
        printf("4 - Contar o numero de ocorrencias do numero na lista\n5- Encerrar o programa\n");
        scanf("%d", &menu);
        printf("\n");
        if(menu == 1)
        {
            printf("Digite o numero que deseja inserir\n");
            scanf("%d", &numero);
            novo = insere(novo, numero);
        }

        if(menu == 2)
        {
            printf("Digite o numero que deseja deletar\n");
            scanf("%d", &numero);
            novo = delete(novo, numero);
        }

        if(menu == 3)
        {
            soma = fazersoma(novo, soma);
            printf("O resultado da soma eh: %d\n", soma);


        }

         if(menu == 4)
        {
            //fazer uma funcao de procura na lista


        }


        if(menu == 6)
        {
            
            imprime(novo);

        }

        printf("\n");
    }






}