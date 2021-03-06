#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

///Biblioteca STL
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
void listar(vector<jogador>* registro);
void incluir(vector<jogador>* registro);
void excluir(vector<jogador>* registro);
void consultar(vector<jogador>* registro);


int main() {

	int tela = 0;

	vector<jogador> registro;


	while (tela != 4) {

		if (tela == 0) {
			tela = menu();
		}
		else if (tela == 1) {
			incluir(&registro);
			tela = 0;
		}
		else if (tela == 2) {
			excluir(&registro);
			tela = 0;
		}
		else if (tela == 3) {
			consultar(&registro);
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


//Painel com as op�oes
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


//fun�ao para incluir um novo player
void incluir(vector<jogador>* registro) {
	///// Incluir, Substituir...
	jogador inclusao;
	qnt++;

	std::cout << "Nome:";
	std::cin >> inclusao.Name;
	std::cout << "Score:";
	std::cin >> inclusao.Score;
	std::cout << "Idade:";
	std::cin >> inclusao.Idade;
	std::cout << "Level:";
	std::cin >> inclusao.Level;
	inclusao.ID = qnt;


	registro->push_back(inclusao);

	system("pause");
	system("cls");
}

//fun��o para excluir um player
void excluir(vector<jogador>* registro) {
	bool excluir = false;
	char yes;

	while (!excluir) {

		// Apagar 1 item, apagar tudo
		int posicao;
		std::cout << "Excluir player na posicao: ";
		std::cin >> posicao;

		if (posicao > registro->size())
			std::cout << "Jogador inexistente, tente novamente." << std::endl;
		else
			std::cout << "Deseja realmente excluir o jogador: " << registro->at(posicao).Name << " ? " << std::endl
			<< "[S] - Para Excluir" << std::endl
			<< "[N] - Para tentar escolher outro jogador" << std::endl
			<< "Opcao: ";

		std::cin >> yes;

		if (yes == 'S') {
			registro->erase(registro->begin() + posicao);
			excluir = true;
		}
		else if (yes == 'N')
			excluir = false;
		else
			std::cout << "x_X Opcao Invalida" << std::endl;


		std::cout << "Player " << posicao << " apagado com sucesso !" << std::endl;
		system("pause");
	}


	qnt--;
	system("cls");

}


//fun��o para consultar um player
void consultar(vector<jogador>* registro) {
	int opcao, posicao;
	std::cout << "Escolha uma opcao" << std::endl << std::endl;
	std::cout << "[1] - Consulta por posicao" << std::endl;
	std::cout << "[2] - Listar players" << std::endl;
	std::cout << "Opcao: ";
	std::cin >> opcao;

	if (opcao == 1) {
		bool consultado = false;

		while (!consultado) {
			std::cout << "Escolha a posicao para consultar: ";
			std::cin >> posicao;

			if (posicao > registro->size())
				std::cout << "Jogador inexistente, tente novamente. ou digite -1 para sair" << std::endl;
			else if (posicao == -1)
				consultado = true;
			else {
				std::cout << "ID: " << registro->at(posicao).ID << std::endl
					<< "Nome: " << registro->at(posicao).Name << std::endl
					<< "Score: " << registro->at(posicao).Score << std::endl
					<< "Idade: " << registro->at(posicao).Idade << std::endl
					<< "Level: " << registro->at(posicao).Level << std::endl;
					consultado = true;
			}
		}
	}
	else if (opcao == 2) {
		listar(registro);
	}

	else std::cout << "Opcao Invalida X_x" << std::endl;

	system("pause");
	system("cls");
}


//fun��o para listar todos os player
void listar(vector<jogador>* registro) {
	system("cls");

	std::cout << "||   ID   ||    NOME    ||    SCORE    ||    IDADE    ||    LEVEL    ||" << std::endl;
	for (int i = 0; i < registro->size(); i++) {
		std::cout << "     " << registro->at(i).ID
			<< "         " << registro->at(i).Name
			<< "        " << registro->at(i).Score
			<< "          " << registro->at(i).Idade
			<< "          " << registro->at(i).Level
			<< std::endl;
	}

	std::cout << std::endl;
}