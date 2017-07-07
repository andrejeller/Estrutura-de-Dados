#include <iostream>
#include <time.h>
#define tam 10
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
	int bin, seq;

	for (int i = 0; i<tam; i++) {
		vetor[i] = 0+rand()%10;
	}

	ordenar(vetor);
	std::cout << "Digite um numero: ";
	std::cin >> num;

	bin = buscaBin(vetor, tam, num);
	seq = buscaSeq(vetor, tam, num);

	std::cout << "Numero de buscas em Sequencia -> " << seq << std::endl
		<< "Numero de buscas em Binarios -> " << bin << std::endl << "Sequencia -> ";

	for (int i = 0; i < tam; i++) {
		std::cout << vetor[i] << "  ";
	}


	system("pause");
	return 0;
}