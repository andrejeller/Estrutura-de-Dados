#include <iostream>
#define tamTabela 100
#define tamChaves 1000

int main() {

	int lista[tamTabela];
	//Inicializa tudo com Zero 0 
	for (int i = 0; i < tamTabela; i++) {
		lista[i] = 0;
	}

	//a toda colisão adiciona 1 no local dela
	for (int i = 0; i < tamChaves; i++) {
		int h = i % tamTabela;
		lista[h] ++;
	}

	//imprime a quantidade de colisoes
	for (int i = 0; i < tamTabela; i++) {
		std::cout << lista[i] << std::endl;
	}
	
	//para transformar em .txt
	FILE *fp;
	fopen_s(&fp, "tabelaHash.txt", "w+");
	for (int i = tamTabela - 1; i > -1; i--)
	{
		fprintf(fp, "%d %d \n", i, lista[i]);
	}


	system("pause");
	return 0;
}