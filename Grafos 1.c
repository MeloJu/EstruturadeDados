#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int destino;
    int custo;
    struct lista *prox;
}lista;







void inicializar(lista **g, int n)
{
    int i;
   
    for(i = 0; i<=n; i++)
    {
        g[i] = NULL;        
    }

}


lista *inserirlista(lista *l, int d, int c)
{
    lista *no = (lista *)malloc(sizeof(lista));
    no->destino = d;
    no->custo = c;
    no->prox = l;
    return no;
}


void InserirAresta(lista **g, int origem, int destino, int custo)
{
    g[origem] = inserirlista(g[origem], destino, custo); 

}

void ImprimirLista(lista *l)
{
    if(l != NULL)
    {
        printf(" -(%d %d)", l->destino, l->custo);
        ImprimirLista(l->prox);
    }


}


void ImprimirGrafo(lista **g, int n)
{
    
    printf("Grafo: ");
    for(int i = 1; i<=n; i++)
    {
        printf("\nt%d\n", i);
        ImprimirLista(g[i]);

    }
}


lista  *removerlista(lista *novo, int numero)
{
    lista *aux2;
    lista *aux = novo;
    
    if(aux == NULL)
        return novo;
    
    if(aux->destino == numero)
      {
          aux2 = aux->prox;
          free(aux);
          aux = aux2;
          return aux;
      }  

     if(novo == NULL)
        return NULL;
    
    novo->prox  =  removerlista(novo->prox, numero);

    return novo;
}   


void removeraresta(lista **g, int n, int origem, int destino, int custo)
{
    
        g[origem] = removerlista(g[origem], destino);
        printf("Removido\n");
      
}

int Saida(lista *l, int cont)
{
    if(l != NULL)
    {
        return Saida(l->prox, cont++);
    }

    else 
        return cont;
}

int Entrada(lista *l, int cont, int origem)
{

    if(l != NULL)
    {
        if(l->destino == origem)
        return Entrada(l->prox, cont++, origem);
    }

    else 
        return cont;
}


void entrada_saida(lista **g, int n, int origem)
{
    lista *l;
    int entrada = 0;
    int saida = 0;
    for(int i = 1; i<=n; i++)
    {


        if(g[i] == origem)
        {
            l = g[i];
            saida = Saida(l, 0);
            printf("O grau de saida eh %d", saida);  
        }

        entrada = Entrada(g[i], 0, origem);
        entrada += entrada;
    }

    printf("O grau de entrada eh %d", entrada);  

}

int verifica(lista **g, int n)
{
	
	int cont = 0;
	
    for(int i = 1; i <= n; i++) 
    {
		lista *l = g[i];
		while(l != NULL) 
        {     
			cont++; 
			l = l->prox;
		}
	}
	
    int total = n * (n-1);
	
	if(cont == total) 
    {
		return 1;
	} 
    
    else 
    {
		return 0;
	}
}
	
void DestroiLista(*lista g)
{

    lista* a = g;
    while (a != NULL)
    {
        lista* j = a->prox; 
        free(a); 
        a = j; 
    }
}



lista *libera(lista **g, int n)
{
    for(int i = 1; i<=n; i++)
    {
        DestroiLista(g[i]);
    }

}



int main()
{
    int n = 0;
    int op = 0;
    int origem = 0;
    int destino = 0;
    int custo = 0;
    printf("Digite o numero de nos do grafo\n");
    scanf("%d", &n);
    lista **g;
    
    g = (lista**)malloc((n+1)*sizeof(lista*));
    
    inicializar(g, n);
   
    printf("Menu:\n\n");
   
    while(op != 6)
    {
        printf("Digite uma opcao:\n");
        printf("1 - Inserir uma aresta no grafo\n");
        printf("2 - Remover uma aresta do grafo\n");
        printf("3 - Imprimir grafo\n");
        printf("4 - Imprimir os graus de entrada e saida de um vertice\n");
        printf("5 - Verificar se um grafo eh completo\n");
        printf("6 - Para sair\n");
        scanf("%d", &op);
         switch(op)
        {
            case 1:
                    printf("Digite a origem\n");
                    scanf("%d", &origem);
                    printf("Digite o destino\n");
                    scanf("%d", &destino);
                    printf("Digite o custo\n");
                    scanf("%d", &custo);
                    InserirAresta(g, origem, destino, custo);
                    break;
            
            case 2:
                    printf("Digite a origem\n");
                    scanf("%d", &origem);
                    printf("Digite o destino\n");
                    scanf("%d", &destino);
                    printf("Digite o custo\n");
                    scanf("%d", &custo);
                    removeraresta(g, n, origem, destino, custo);
                    break;
            case 3:
                    ImprimirGrafo(g, n);
                    break;

            case 4:
                    printf("Digite o vertice\n");
                    scanf("%d", &origem);
                    entrada_saida(g, n, origem);
                    break;

            case 5:
                    origem = verifica(g, n);
                    if(origem == 0)
                        printf("Não é completo\n");
                    else
                        printf("É completo\n");

                    break;
        
        }
}
    libera(g, n);
    return 0;

}