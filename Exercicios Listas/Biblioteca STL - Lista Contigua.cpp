#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <Windows.h>

#define tam 10

///Lista Contigua
using namespace std;

struct jogador {
	int ID;
	std::string Name;
	int Level;
	int Score;
	int Idade;
};


int qnt = 0;
int menu();
void inicializar();
void listar();
void incluir();
void excluir();
void organizar();
void consultar();

jogador registro[tam];

int main() {

	int tela = 0;



	inicializar();

	while (tela != 4) {


		if (tela == 0) {
			tela = menu();
		}
		else if (tela == 1) {
			incluir();
			tela = 0;
		}
		else if (tela == 2) {
			excluir();
			organizar();
			tela = 0;
		}
		else if (tela == 3) {
			consultar();
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

//Inicializador 
void inicializar() {
	for (int i = 0; i < tam; i++) {
		registro[i].ID = i;
		registro[i].Name = "no name";
		registro[i].Idade = 0;
		registro[i].Level = 0;
		registro[i].Score = 0;
	}

}

//Painel com as opçoes
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


//funçao para incluir um novo jogador a lista
void incluir() {
	///// Incluir...
	jogador inclusao;

	std::cout << "Nome:";
	std::cin >> registro[qnt].Name;
	std::cout << "Score:";
	std::cin >> registro[qnt].Score;
	std::cout << "Idade:";
	std::cin >> registro[qnt].Idade;
	std::cout << "Level:";
	std::cin >> registro[qnt].Level;

	qnt++;

	system("pause");
	system("cls");
}

//função para excluir um jogador da lista
void excluir() {
	bool excluir = false;
	char yes;

	while (!excluir) {

		// Apagar 1 item, apagar tudo
		int posicao;
		std::cout << "Excluir jogador na posicao: ";
		std::cin >> posicao;

		if (posicao > qnt)
			std::cout << "Jogador inexistente, tente novamente." << std::endl;


		else {
			std::cout << "Deseja realmente excluir o jogador: " << registro[posicao].Name << " ? " << std::endl
				<< "[S] - Para Excluir" << std::endl
				<< "[N] - Para tentar escolher outro jogador" << std::endl
				<< "Opcao: ";

			std::cin >> yes;

			if (yes == 'S' || yes == 's') {
				registro[posicao].Name = "no name";
				registro[posicao].Idade = 0;
				registro[posicao].Level = 0;
				registro[posicao].Score = 0;

				std::cout << "Player " << posicao << " apagado com sucesso !" << std::endl;
				excluir = true;
			}
			else if (yes == 'N' || yes == 'n')
				excluir = false;
			else {
				std::cout << "x_X Opcao Invalida" << std::endl;
				excluir = true;
			}
		}

		excluir = true;

	}


	qnt--;
	system("pause");
	system("cls");

}


//função para consultar um jogador ou todos os jogadores da lista
void consultar() {
	int opcao, posicao;


	std::cout << "Escolha uma opcao" << std::endl << std::endl;
	std::cout << "[1] - Consulta por posicao" << std::endl;
	std::cout << "[2] - Listar players" << std::endl;
	std::cout << "Opcao: ";
	std::cin >> opcao;

	if (opcao == 1) {
		std::cout << "Escolha a posicao para consultar: ";
		std::cin >> posicao;

		if (posicao > tam)
			std::cout << "Jogador inexistente, tente novamente uma posicao entre 0 e" << tam << std::endl;

		else
			std::cout << "ID: " << registro[posicao].ID << std::endl
			<< "Nome: " << registro[posicao].Name << std::endl
			<< "Score: " << registro[posicao].Score << std::endl
			<< "Idade: " << registro[posicao].Idade << std::endl
			<< "Level: " << registro[posicao].Level << std::endl;

	}
	else if (opcao == 2) {
		listar();
	}

	else std::cout << "Opcao Invalida X_x" << std::endl;

	system("pause");
	system("cls");
}


//função para listar todos os jogadores
void listar() {
	system("cls");

	std::cout << "||   ID   ||    NOME    ||    SCORE    ||    IDADE    ||    LEVEL    ||" << std::endl;
	for (int i = 0; i < tam; i++) {
		std::cout << "     " << registro[i].ID
			<< "        " << registro[i].Name
			<< "           " << registro[i].Score
			<< "              " << registro[i].Idade
			<< "              " << registro[i].Level
			<< std::endl;
	}
}


//função para organizar a lista sem deixar espaço em branco... 
//necessaria pois usamos uma Lista Contigua Fixa.
void organizar() {

	for (int i = 0; i < tam - 1; i++) {
		int j = i + 1;

		if (j > tam) j = i;

		if (registro[i].Name == "no name") {
			//copia
			registro[i].Name = registro[j].Name;
			registro[i].Score = registro[j].Score;
			registro[i].Level = registro[j].Level;
			registro[i].Idade = registro[j].Idade;

			//apaga
			registro[j].Name = "no name";
			registro[j].Score = 0;
			registro[i].Level = 0;
			registro[i].Idade = 0;
		}
	}
}