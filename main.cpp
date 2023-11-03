#include <iostream>

bool CompareSymbol(char first, char second) {
	char capitalENcountOfSymbols[] = { 'O','A','I','E','H','C','B','K','P','X','T','M' };
	char capitalUAcountOfSymbols[] = { '�','�','�','�','�','�','�','�','�','�','�','�' };
	for (int i = 0; i < 12; i++)
	{
		if (first == capitalENcountOfSymbols[i] || first == capitalUAcountOfSymbols[i]) {
			if (second == capitalUAcountOfSymbols[i] || second == capitalENcountOfSymbols[i]) {
				return true;
				break;
			}
		}
	}
	return false;
}

class SpecificSymbols {
public:
	char symbol;
	SpecificSymbols(char first) {
		symbol = first;
	}
	bool operator==(SpecificSymbols& _argument) {
		if (symbol != _argument.symbol)
			return CompareSymbol(symbol, _argument.symbol);
		return true;
	}
	bool operator!=(SpecificSymbols& _argument) {
		if (symbol != _argument.symbol)
			return !CompareSymbol(symbol, _argument.symbol);
		return false;
	}
};

int main() {
	system("chcp 1251>nul");
	char firstSymbol;
	char secondSymbol;
	int userChoose{ 0 };
	std::cout << "� �������� ��� �쳺 ���������� �������" << std::endl;
	std::cout << "������ ������ ������: ";
	std::cin >> firstSymbol;
	std::cout << "������ ������ ������: ";
	std::cin >> secondSymbol;
	SpecificSymbols first(firstSymbol), second(secondSymbol);
	std::cout << "������� ���� � �������" << std::endl;
	std::cout << "������ 1 ���� ������ �������� ������� �� ������" << std::endl;
	std::cout << "������ 2 ���� ������ �������� ������� �� ��������" << std::endl;
	do {
		std::cout << "��� ����: ";
		std::cin >> userChoose;
		if (userChoose == 1) {
			std::cout << (first == second ? "������� �������" : "������� ���") << std::endl;
			break;
		}
		else if (userChoose == 2) {
			std::cout << (first != second ? "������� ���" : "������� �������") << std::endl;
			break;
		}
		std::cout << "����� ������ ��������������, �������� ����" << std::endl;
	} while (userChoose != 1 || userChoose != 2);
	return 0;
}