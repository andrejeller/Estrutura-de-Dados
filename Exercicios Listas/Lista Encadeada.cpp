#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

///Lista Encadeada
using namespace std;

struct competidor {
	int ID;
	std::string name;
	int Score;
};

vector<competidor> players;
int posInc = 0;

int menu();
void listar(vector<competidor> lista);
void incluir();
void excluir();
void consultar();

void inicializar();



int main() {

	int tela = 0;
		
	inicializar(); // inicializando com 10 players "nulos"

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



//// Inicializar tudo zerado
void inicializar() {
	for (int i = 0; i < 10; i++) {
		players.push_back(competidor());
		players.at(i).ID = 0;
		players.at(i).name = "no name";
		players.at(i).Score = 0;
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


//funçao para incluir um novo player
void incluir() {
	///// Incluir, Substituir...
	competidor inclusao;


	std::cout << "Nome:";
	std::cin >> inclusao.nome;
	std::cout << "Score:";
	std::cin >> inclusao.score;
	inclusao.ID = 0;

	players.push_back(inclusao);

	system("pause");
	system("cls");
}

//função para excluir um player
void excluir() {
	// Apagar 1 item, apagar tudo
	int posicao;
	std::cout << "Excluir player na posicao: ";
	std::cin >> posicao;


	players.erase(players.begin() + posicao);


	std::cout << "Player " << posicao << " apagado ccom sucesso !" << std::endl;
	system("pause");

	posInc--;
	system("cls");

}


//função para consultar um player
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
		std::cout << "ID: " << players.at(posicao).ID << std::endl
			<< "Nome: " << players.at(posicao).name << std::endl
			<< "Score: " << players.at(posicao).Score << std::endl;
	}
	else if (opcao == 2) {
		listar(players);
	}

	else std::cout << "Opcao Invalida X_x" << std::endl;

	system("pause");
	system("cls");
}


//função para listar todos os player
void listar(vector<competidor> lista) {
	system("cls");

	std::cout << "|   POS   |    ID    |    NOME    |    SCORE    |" << std::endl;
	for (int i = 0; i < lista.size(); i++) {
		std::cout << "     " << i << "         " << lista.at(i).ID << "        " << lista.at(i).name << "          " << lista.at(i).Score << std::endl;
	}

	std::cout << std::endl;
}