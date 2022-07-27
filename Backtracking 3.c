#include <stdio.h>
#include <stdlib.h>

void ImprimirC(int *vet, int pos, int n, int cent, int* vAux){
	if(pos == n){
		int soma = 0;
		for(int i = 0; i < n; i++){
			soma += (vet[i] * vAux[i]);
		}
		if(soma == cent){
            for(int i = 0; i < n; i++){
                printf("%d moedas de %d centS; ",vet[i],vAux[i]);
            }
            printf("\n");
		}
	}else{
            for(int i = 0; i <= cent; i++){
                vet[pos] = i;
                ImprimirC(vet, pos+1, n, cent, vAux);
            }
        }
}

int main(){
	int n;
	printf("Digite a quantidade de cents para a combinacao ocorrerr:\n");
	scanf("%d",&n);
	int* vet = (int*)malloc(sizeof(int)*5);
	int* vAux = (int*) malloc(sizeof(int)*5);
	vAux[0] = 1;
	vAux[1] = 5;
	vAux[2] = 10;
	vAux[3] = 25;
	vAux[4] = 50;
	ImprimirC(vet,0,5,n,vAux);
}
