#include <iostream>
#include <string>

using namespace std;

int main(){
	string Texto, TextoInv, Palavra, PalavraInv;
	std::cout << "Digite algo: ";
	getline(std::cin, Texto);
	Texto.push_back(' ');

	for (int i = 0, j = 0; i < Texto.size(); i++) {
		Palavra.push_back(Texto.at(i));

		if (Texto.at(i) == ' ') {
			for (int h = i; h >= j; h--)
				TextoInv.push_back(Texto.at(h));

			j = i + 1;

			for (int h = 0; h < PalavraInv.size(); h++)
				TextoInv.push_back(PalavraInv.at(h));

			Palavra.clear();
			PalavraInv.clear();
		}
	}
	std::cout << "Texto Invertido:";
	for (int i = 0; i < TextoInv.size(); i++)
		std::cout << TextoInv.at(i);
	

	std::cout << std::endl;
	system("pause");
	return 0;
}