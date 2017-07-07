#include <iostream>
#include <time.h>
#include <vector>
#define tam 100
int vetor[tam];


int buscaSeq(int vec[], int tamanho, int numBusca) {
	for (int i = 0; i<tamanho; i++) {
		if (vec[i] == numBusca) {
			return i;
		}
	}
	return -1;
}

int buscaBin(int vec[], int tamanho, int numBusca) {
	int min = 0;
	int max = tamanho - 1;
	int meio = (max - min) / 2;
	int cont = 0;
	
	while (min <= max) {
		cont++;
		meio = (min + max) / 2;
		if (numBusca == vec[meio])
			return cont;
		if (numBusca < vec[meio])
			max = meio - 1;
		else
			min = meio + 1;

	}
	return -1;
	
}

int buscaHash(int vec[], int tamanho, int numBusca) {
	int cont = 0;
	for (int i = numBusca; i < tamanho; i ++) {
			if (vec[i] == i) {
				break;
				cont++;
			}
	}
	return cont;

}

void ordenar(int vec[]) {
	int aux = 0;

	for (int i = 0; i < tam; i++)
	{
		for (int j = 0; j < tam; j++)
		{
			if (vec[i] < vec[j])
			{
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

int main() {
	srand(time(NULL));
	
	
	int num;
	int bin, seq, hash;

	for (int i = 0; i<tam; i++) {
		//vetor[i] = 0+rand()%100; // para numeros aleatorios
		vetor[i] = i; //para numeros nao aleatorios
	}

	ordenar(vetor);
	
	//para imprimir no cp
	for (int i = 0; i < tam; i++) {
		num = i;
		bin = buscaBin(vetor, tam, num);
		seq = buscaSeq(vetor, tam, num);
		hash = buscaHash(vetor, tam, num);
		std::cout << "Buscando Numero " << i << " Seq " << seq << " Bin " << bin << " Hash "<< hash <<  std::endl;
	}
	
	//para transformar em .txt
	FILE *fp;
	fopen_s(&fp, "buscaAleatoria.txt", "w+");
	for (int i = 99; i > -1; i--)
	{
		num = i;
		bin = buscaBin(vetor, tam, num);
		seq = buscaSeq(vetor, tam, num);
		hash = buscaHash(vetor, tam, num);
		fprintf(fp, "%d %d\n", seq, bin);
	}
	
	system("pause");
	return 0;
}