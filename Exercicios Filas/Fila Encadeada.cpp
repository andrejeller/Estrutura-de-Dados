#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#define tam 10


using namespace std;

int menu();
void listar();
void incluir();
void excluir();
void consultar();

struct registro {
	int carga;
	char status;
	int	temperatura;
	int coordenada_x;
	int coordenada_y;
};

vector<registro> informacoes;

int main() {

	int tela = 0;
	
	while (tela != 4)
	{
		if (tela == 0) {
			tela = menu();
		}
		else if (tela == 1) {
			incluir();
			tela = 0;
		}
		else if (tela == 2) {
			excluir();
			tela = 0;
		}
		else if (tela == 3) {
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


//Painel com as opçoes - Menu
int menu() {
	std::cout << "O que voce quer fazer ?" << std::endl;
	std::cout << "[1] - Incluir" << std::endl;
	std::cout << "[2] - Excluir" << std::endl;
	std::cout << "[3] - Consultar" << std::endl;
	std::cout << "[4] - Sair" << std::endl;
	int numero;
	std::cout << "Opcao: ";
	std::cin >> numero;

	system("cls");
	return numero;
}

//funçao para incluir um novo elemento no final da fila
void incluir() {	
	registro inclusao;
	
	std::cout << "Carga: ";
	std::cin >> inclusao.carga;

	std::cout << "Status: ";
	std::cin >> inclusao.status;

	std::cout << "Temperatura: ";
	std::cin >> inclusao.temperatura;

	std::cout << "Coordenada X: ";
	std::cin >> inclusao.coordenada_x;

	std::cout << "Coordenada Y: ";
	std::cin >> inclusao.coordenada_y;

	informacoes.push_back(inclusao);
	
	system("pause");
	system("cls");
}

//função para excluir um elemento da fila
void excluir() {
	// Apagar 1 item, apagar tudo
	int posicao;
	std::cout << "Excluir player na posicao: ";
	std::cin >> posicao;

	if (!informacoes.empty() && 0 < posicao < informacoes.size()){
		informacoes.erase(informacoes.begin() + posicao);
		std::cout << "Registro " << posicao << " apagado ccom sucesso !" << std::endl;
	}
	else
		std::cout << "Registro " << posicao << " nao existe" << std::endl;

	system("pause");
	system("cls");
}

//função para consultar o primeiro elemento da fila
//apenas é possivel consultar o primeiro elemento da fila, pois este em si é seu conceito
// e, ao ser consultado este regiistro é apagado e passado ao próximo da fila.
void consultar() {
	std::cout << "Consulta padrao ativada" << std::endl << std::endl;
	registro* consulta;
	consulta = &informacoes.at(0);
	std::cout
		<< "Carga: " << consulta->carga << std::endl
		<< "Status: " << consulta->status << std::endl
		<< "Temperatura: " << consulta->temperatura << std::endl
		<< "Coordenada X: " << consulta->coordenada_x << std::endl
		<< "Coordenada Y: " << consulta->coordenada_y << std::endl << std::endl;


	std::cout << "Informacoes no inicio da fila apagadas com sucesso" << std::endl;

	informacoes.erase(informacoes.begin());

	system("pause");
	system("cls");
}


//função para listar toda a fila
void listar() {
	system("cls");

	std::cout << "|   CARGA   |    STATUS    |    TEMPERATURA    |    COORDENADA    |" << std::endl;
	for (int i = 0; i < informacoes.size(); i++) {
		std::cout
			<< "      " << informacoes.at(i).carga
			<< "            " << informacoes.at(i).status
			<< "                " << informacoes.at(i).temperatura
			<< "                 " << informacoes.at(i).coordenada_x
			<< ", " << informacoes.at(i).coordenada_y << std::endl;
	}

	std::cout << std::endl;
	system("pause");
	system("cls");
	std::cout << std::endl;
}