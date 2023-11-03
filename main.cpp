#include <iostream>

bool CompareSymbol(char first, char second) {
	char capitalENcountOfSymbols[] = { 'O','A','I','E','H','C','B','K','P','X','T','M' };
	char capitalUAcountOfSymbols[] = { 'О','А','І','Е','Н','С','В','К','Р','Х','Т','М' };
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
	std::cout << "Я програма яка вміє порівнювати символи" << std::endl;
	std::cout << "Введіть перший символ: ";
	std::cin >> firstSymbol;
	std::cout << "Введіть другий символ: ";
	std::cin >> secondSymbol;
	SpecificSymbols first(firstSymbol), second(secondSymbol);
	std::cout << "Виберіть один з варіантів" << std::endl;
	std::cout << "Введіть 1 якщо бажаєте порівняти символи на рівність" << std::endl;
	std::cout << "Введіть 2 якщо бажаєте порівняти символи на НЕрівність" << std::endl;
	do {
		std::cout << "Ваш вибір: ";
		std::cin >> userChoose;
		if (userChoose == 1) {
			std::cout << (first == second ? "символи однакові" : "символи різні") << std::endl;
			break;
		}
		else if (userChoose == 2) {
			std::cout << (first != second ? "символи різні" : "символи однакові") << std::endl;
			break;
		}
		std::cout << "Такий варіант непередбачений, повторіть вибір" << std::endl;
	} while (userChoose != 1 || userChoose != 2);
	return 0;
}