#include <stdio.h>
#include <stdlib.h>

void ImprimirC(int *vet, int pos, int n, int* vAux){
	int aux=0;
	if(pos==n){
		for(int i=0; i<=n;i++)
			aux+=vet[i];
		if(aux%2==0){
			for(int i=0; i<n;i++)
				printf("%d ", vet[i]);
			printf("\n");
		}
	}
	else{
		for(int i=0;i<=3;i++)
		{
			vet[pos]=vAux[i];
			ImprimirC(vet,pos+1,n,vAux);
		}
	}
}

int main(){
	int n;
	printf("Valor de n para as combinacoes:\n");
	scanf("%d",&n);
	int* vet = (int*)malloc(sizeof(int)*n);
	int* vetAux = (int*) malloc(sizeof(int)*4);
	vetAux[0] = 15;
	vetAux[1] = 31;
	vetAux[2] = 55;
	vetAux[3] = 44;
	ImprimirC(vet,0,n,vetAux);
}
