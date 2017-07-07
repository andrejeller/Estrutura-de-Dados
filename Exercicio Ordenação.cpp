#include <iostream>
#include <algorithm>
#include <vector>
//using std::vector;
using namespace std;

class Pessoa {
	string nome;
	int idade;
public:
	Pessoa(string no, int id)
	{
		idade = id;
		nome = no;
	}
	string getNome()
	{
		return nome;
	}
	int getIdade()
	{
		return idade;
	}
};

bool ordena_por_nome(Pessoa A, Pessoa B)
{
	if (A.getNome() > B.getNome())
		return true;
	return false;
}

int main() {

	vector <Pessoa> listaNomes;
	vector <Pessoa>::iterator ptr;

	listaNomes.push_back(Pessoa("Joao", 25));
	listaNomes.push_back(Pessoa("Maria", 32));
	listaNomes.push_back(Pessoa("Carla", 4));
	listaNomes.push_back(Pessoa("Abel", 30));

	sort(listaNomes.begin(), listaNomes.end(), ordena_por_nome);

	// percorrendo a lista com um ITERATOR
	for (ptr = listaNomes.begin(); ptr != listaNomes.end(); ptr++)
	{
		std::cout << "Nome: " << ptr->getNome();
		std::cout << " - Idade: " << ptr->getIdade() << std::endl;
	}
	system("pause");

}