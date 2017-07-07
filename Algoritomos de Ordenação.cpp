#include <iostream>
#define tam 9

//Objetivo: Analisar a diferença entre - bubbleSort - quickSort - inserction.

int inteiros[tam] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
int copia[tam] = {1, 12, 5, 26, 7, 14, 3, 7, 2};
int countQuick = 0;
int countBouble = 0;
int countInserction = 0;

void PopularLista() {
	for (int i = tam - 1, j = 0; i >= 0; i--) {
		inteiros[j] = i;
		j++;
	}
}

void Resetar() {
	for (int i = 0; i <= tam; i++) {
		copia[i] = inteiros[i];
	}
}

void bubbleSort(int arr[]) {
	int aux;
	int trocas = 0;

	for (int i = 0; i < tam; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (arr[i] > arr[j]) {
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				countBouble++;

				for (int i = 1; i <= tam; i++) {
					std::cout << arr[i] << " ";
				}
				std::cout << std::endl;
			}			
		}		
	}	
}


void quickSort(int arr[], int left, int right) {

	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);


	for (int i = 1; i <= tam; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	countQuick++;
}


void inserction(int arr[]) {	

	for (int i = 1; i < tam; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			int aux = arr[j];
			arr[j] = arr[j - 1];
			countInserction++;
			arr[j - 1] = aux;
			j--;

			for (int i = 1; i <= tam; i++) {
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
	}
}

int main() {	

	for (int i = 0; i < tam; i++) {
		std::cout << inteiros[i] << " ";
	}

	std::cout << std::endl;

	

	bubbleSort(copia);
	std::cout << std::endl << "Trocas Bouble: " << countBouble << std::endl << std::endl;

	Resetar();

	quickSort(copia, 0, tam);
	std::cout << std::endl  << "Trocas Quick: " << countQuick << std::endl << std::endl;
	
	Resetar();

	inserction(copia);
	std::cout << std::endl << "Trocas Inserction: " << countInserction << std::endl << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < tam; i++)
		std::cout << inteiros[i] << " ";	

	std::cout << std::endl;

	system("pause");
	return 0;
}