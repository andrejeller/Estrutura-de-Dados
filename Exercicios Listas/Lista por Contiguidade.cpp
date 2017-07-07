#include <iostream>
#include <string>
#define tam 10

//Lista por Contiguidade
int menu();
void listar();
void incluir();
void excluir();
void consultar();
void organizar();
void inicializar();

struct competidor {
	int ID;
	std::string name;
	int Score;
};

competidor players[tam];
int pos = 0; // arrumar quano apagado valor

int main() {


	int tela = 0;
	inicializar();

	while (tela != 4)
	{
		organizar();

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
	for (int i = 0; i< tam; i++) {
		players[i].ID = 0;
		players[i].name = "no name";
		players[i].Score = 0;
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
	int score;
	std::string nome;

	std::cout << "Nome:";
	std::cin >> nome;
	std::cout << "Score:";
	std::cin >> score;

	players[pos].ID = pos;
	players[pos].name = nome;
	players[pos].Score = score;

	pos++;

	system("pause");
	system("cls");
}

//função para excluir um player
void excluir() {
	// Apagar 1 item, apagar tudo
	int posicao;
	std::cout << "Excluir player na posicao: ";
	std::cin >> posicao;

	players[posicao].ID = 0;
	players[posicao].name = "no name";
	players[posicao].Score = 0;

	std::cout << "Player " << posicao << " apagado ccom sucesso !" << std::endl;
	system("pause");

	pos--;
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
		std::cout << "ID: " << players[posicao].ID << std::endl
			<< "Nome: " << players[posicao].name << std::endl
			<< "Score: " << players[posicao].Score << std::endl;
	}
	else if (opcao == 2) {
		listar();
	}

	else std::cout << "Opcao Invalida X_x" << std::endl;

	system("pause");
	system("cls");
}


//função para listar todos os player
void listar() {
	system("cls");

	std::cout << "|   POS   |    ID    |    NOME    |    SCORE    |" << std::endl;
	for (int i = 0; i < tam; i++) {
		std::cout << "     " << i << "         " << players[i].ID << "        " << players[i].name << "          " << players[i].Score << std::endl;
	}

	std::cout << std::endl;
}


//função para organizar sem deixar espaço em branco...
void organizar() {

	for (int i = 0; i <tam; i++) {
		int j = i + 1;

		if (j > tam) j = i;

		if (players[i].name == "no name") {
			//copia
			players[i].ID = players[j].ID;
			players[i].name = players[j].name;
			players[i].Score = players[j].Score;
			//apaga
			players[j].ID = 0;
			players[j].name = "no name";
			players[j].Score = 0;
		}
	}
}