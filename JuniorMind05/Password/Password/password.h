<<<<<<< HEAD
#include <string>
#include "generator.h"
=======
#ifndef PASSWORD_H
#define PASSWORD_H
#include <string>
<<<<<<< HEAD
#include <algorithm>
#include <ctime>
#include "generator.h"
=======
#include <random>

class Generator {
	std::uniform_int_distribution<int> dis;
	std::mt19937 gen;
public:
	Generator(int lower = 33, int upper = 126)
		: gen(std::random_device()()), dis(lower, upper) {}

	int operator()() {
		return dis(gen);
	}
};
>>>>>>> ed8bb73f06027da45cd1e20eafb7ff2ac429c66f
>>>>>>> a43f23bcbab71ce1fbdf359ba26d5ee9466d1b2e

struct PasswordOptions
{
	int passLenght;
	int uppercase;
	int numbers;
	int symbols;
	bool excludeAmbiguius;
	bool excludeSimilar;

	struct StringSets
	{
		std::string ambiguous = "{}[]()/\\'`~,;:.<>\"";
		std::string symbols = "!@#$%^&*-_+=|?";
		std::string numbers = "1234567890";
		std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
		std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		std::string similar = "iIl10oO";
	}strSets;

	std::string GetAllowed()
	{
		std::string allowed = strSets.lowercase;
		if (!excludeAmbiguius) allowed += strSets.ambiguous;
		if (!excludeSimilar) allowed += strSets.similar;
		return allowed;
	}

	std::string GetRestricted()
	{
		std::string restricted = "";
		if (excludeAmbiguius) restricted += strSets.ambiguous;
		if (excludeSimilar) restricted += strSets.similar;
		return restricted;
	}

	bool CheckChar(std::string str, char toCheck)
	{
		for each(char c in str)
		{
			if (toCheck == c) return true;
		}
		return false;
	}

	std::string GetUpperCases()
	{
		Generator rndNo;
		std::string str = "";
		int i = 0;
		while (i < uppercase)
		{
			char nextChar = char(rndNo());
			if (CheckChar(strSets.uppercase, nextChar) && !CheckChar(GetRestricted(), nextChar))
			{
				str += nextChar;
				i++;
			}
		}
		return str;
	}

	std::string GetNumbers()
	{
		Generator rndNo;
		std::string str = "";
		int i = 0;
		while (i < numbers)
		{
			char nextChar = char(rndNo());
			if (CheckChar(strSets.numbers, nextChar) && !CheckChar(GetRestricted(), nextChar))
			{
				str += nextChar;
				i++;
			}
		}
		return str;
	}

	std::string GetSymbols()
	{
		Generator rndNo;
		std::string str = "";
		int i = 0;
		while (i < symbols)
		{
			char nextChar = char(rndNo());
			if (CheckChar(strSets.symbols, nextChar) && !CheckChar(GetRestricted(), nextChar))
			{
				str += nextChar;
				i++;
			}
		}
		return str;
	}

	std::string shufflecards(std::string str)
	{
		srand(time(NULL));
		random_shuffle(str.begin(), str.end());
		return str;
	}

	std::string GeneratePassword()
	{
		Generator rndNo;
		std::string password = GetUpperCases() + GetNumbers() + GetSymbols();

		while (password.size() < passLenght)
		{
			char nextChar = char(rndNo());
			if (CheckChar(GetAllowed(), nextChar) && !CheckChar(GetRestricted(), nextChar)) { password += nextChar; }
		}
		return shufflecards(password);
	}

<<<<<<< HEAD
};
=======
};

#endif
>>>>>>> ed8bb73f06027da45cd1e20eafb7ff2ac429c66f
