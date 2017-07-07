#include <iostream>
#include <string>
#define tam 3

int menu();
void listar();
void incluir();
void consultar();
void organizar();
void inicializar();

struct registro {
	int carga;
	char status;
	int	temperatura;
	int coordenada_x;
	int coordenada_y;
};

registro informacoes[tam];
int inicio = 0; // arrumar quano apagado valor
int fim = 1;
int quantidade = 0;

int main() {

	int tela = 0;
	inicializar();

	while (tela != 4)
	{
		if (fim > tam) fim = 0; // checar rotação
		if (inicio > tam) inicio = 0;
		if (quantidade > tam) quantidade = tam;

		if (tela == 0) {
			tela = menu();
			std::cout << inicio << "  " << fim  << " " << quantidade << std::endl;
		}
		else if (tela == 1) {
			incluir();
			tela = 0;
		}
		else if (tela == 2) {
			consultar();
			tela = 0;
		}
		else if (tela == 5) {
			listar();
			tela = 0;
		}
		else {
			std::cout << "Opcao Invalida x_X" << std::endl << std::endl;
			system("pause");
			tela = 0;
		}

	}

	std::cout << "###########################" << std::endl;
	std::cout << "##### VOCE ESTA SAINDO#####" << std::endl;
	std::cout << "###########################" << std::endl << std::endl;
	system("pause");
	return 0;
}


/*
###########
###########
###########
###########
###########
*/

//// Inicializar tudo zerado
void inicializar() {
	for (int i = 0; i< tam; i++) {
		informacoes[i].carga = 0;
		informacoes[i].status = 'I'; // I - inativo  // A - Ativo
		informacoes[i].temperatura = 0;
		informacoes[i].coordenada_x = 0;
		informacoes[i].coordenada_y = 0;
	}
}

//Painel com as opçoes
int menu() {
	std::cout << "O que voce quer fazer ?" << std::endl;
	std::cout << "[1] - Incluir" << std::endl;
	std::cout << "[2] - Consultar" << std::endl;
	std::cout << "[4] - Sair" << std::endl;
	int numero;
	std::cout << "Opcao: ";
	std::cin >> numero;

	system("cls");
	return numero;
}

//funçao para incluir um novo Registro
void incluir() {
	bool filaCheia = false;
	
	///// Incluir, Substituir...
	if (quantidade >= tam) {
		filaCheia = true;		
		std::cout << "FILA CHEIA: " << std::endl;
	}

	if (!filaCheia) {
		std::cout << "Carga: ";
		std::cin >> informacoes[fim].carga;

		std::cout << "Status: ";
		std::cin >> informacoes[fim].status;

		std::cout << "Temperatura: ";
		std::cin >> informacoes[fim].temperatura;

		std::cout << "Coordenada X: ";
		std::cin >> informacoes[fim].coordenada_x;

		std::cout << "Coordenada Y: ";
		std::cin >> informacoes[fim].coordenada_y;

		fim++;
		quantidade ++;
	}
	
	system("pause");
	system("cls");
}

//função para consultar um Registro
void consultar() {
	std::cout << "Consulta padrao ativada" << std::endl << std::endl;


	std::cout
		<< "Carga: " << informacoes[inicio].carga << std::endl
		<< "Status: " << informacoes[inicio].status << std::endl
		<< "Temperatura: " << informacoes[inicio].temperatura << std::endl
		<< "Coordenada X: " << informacoes[inicio].coordenada_x << std::endl
		<< "Coordenada Y: " << informacoes[inicio].coordenada_y << std::endl << std::endl;

	informacoes[inicio].carga = 0;
	informacoes[inicio].status = 'I';
	informacoes[inicio].temperatura = 0;
	informacoes[inicio].coordenada_x = 0;
	informacoes[inicio].coordenada_y = 0;

	std::cout << "Informacoes na posicao " << inicio << " apagadas com sucesso" << std::endl;

	inicio++;
	quantidade--;

	system("pause");
	system("cls");
}


//função para listar todos os Registros
void listar() {
	system("cls");

	std::cout << "|   CARGA   |    STATUS    |    TEMPERATURA    |    COORDENADA    |" << std::endl;
	for (int i = 0; i < tam; i++) {
		std::cout
			<< "      " << informacoes[i].carga
			<< "            " << informacoes[i].status
			<< "                " << informacoes[i].temperatura
			<< "                 " << informacoes[i].coordenada_x
			<< ", " << informacoes[i].coordenada_y << std::endl;
	}

	std::cout << std::endl;
	system("pause");
	system("cls");
	std::cout << std::endl;
}

void organizar() {

	for (int i = 0; i <tam; i++) {
		int j = i + 1;

		if (j > tam) j = i;

		if (informacoes[i].status == 'I') {
			//copia
			informacoes[i].carga = informacoes[j].carga;
			informacoes[i].status = informacoes[j].status;
			informacoes[i].temperatura = informacoes[j].temperatura;
			informacoes[i].coordenada_x = informacoes[j].coordenada_x;
			informacoes[i].coordenada_y = informacoes[j].coordenada_y;
			//apaga
			informacoes[j].carga = 0;
			informacoes[j].status = 'I';
			informacoes[j].temperatura = 0;
			informacoes[j].coordenada_x = 0;
			informacoes[j].coordenada_y = 0;
		}
	}
}