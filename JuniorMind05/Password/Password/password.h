#pragma once
#include <string>
#include <algorithm>
#include "generator.h"

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
		std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
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

	std::string GetChars(int opt, char min, char max)
	{
		Generator rndNo;
		std::string str = "";
		int i = 0;
		while (i < opt)
		{
			char nextChar = char(rndNo());
			if ((nextChar >= min && nextChar <= max) && !CheckChar(GetRestricted(), nextChar))
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

	std::string ShufflePassword(std::string str)
	{
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(str.begin(), str.end(), g);
		return str;
	}

	std::string GeneratePassword()
	{
		Generator rndNo;
		std::string password = GetChars(uppercase, 'A', 'Z') + GetChars(numbers, '0', '9') + GetSymbols();

		while (password.size() < passLenght)
		{
			char nextChar = char(rndNo());
			if (CheckChar(GetAllowed(), nextChar) && !CheckChar(GetRestricted(), nextChar)) { password += nextChar; }
		}
		return ShufflePassword(password);
	}
};
