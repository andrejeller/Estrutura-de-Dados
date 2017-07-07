#include <iostream>
#include <string>
#include <vector>
#include <stack>

std::stack<char> operadores;
std::stack<float> numeros;
float resultado = 0;



int main(){

	std::string equacao;
	std::cout << "Digite a equacao: ";
	std::getline(std::cin, equacao);

	for (int i = 0; i < equacao.size(); i++){
		if (equacao[i] >= 48 && equacao[i] <= 57)
			numeros.push(equacao[i] - 48);

		else if (equacao[i] == '+' || equacao[i] == '-' || equacao[i] == '*' || equacao[i] == '/')
			operadores.push(equacao[i]);

		else if (equacao[i] == ')'){

			float valor = numeros.top();
			numeros.pop();
			
			resultado = numeros.top();
			numeros.pop();

			switch (operadores.top()){
				case '/':
					resultado = resultado / valor;
					break;
				case '*':
					resultado = valor * resultado;
					break;
				case '+':
					resultado += valor;
					break;
				case '-':
					resultado -= valor;
					break;
			}
			operadores.pop();
			numeros.push(resultado);
		}
	}

	std::cout << "Resultado: " << resultado << std::endl;
	system("pause");
	return 0;
}