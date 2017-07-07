#include <iostream>
#include <time.h>

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

	/*if (numBusca == vec[min])
		return min;
	if (numBusca == vec[max])
		return max;
	if (numBusca == vec[meio])
		return meio;
	else {*/
		while (min <=max) {
			cont++;
			meio = (min + max) / 2;
			if (numBusca == vec[meio])
				return cont;
			if (numBusca < vec[meio])
				max = meio - 1;
			else
				min = meio + 1;
			
			/*meio = (max - min) / 2;
			if (vec[meio] == numBusca)
				return meio;
			if (vec[meio] > numBusca)
				max = meio - 1;
			else
				min = meio + 1;*/
		}
		return -1;
	//}
}
int main() {
	srand(time(NULL));
	int vetor[1000];
	int num = 15;

	int resp;

	for (int i = 0; i<1000; i++) {
		vetor[i] = i;
	}

	resp = buscaBin(vetor, 1000, num);
	std::cout << resp;

	system("pause");
	return 0;
}