#include "stdafx.h"
#include "CppUnitTest.h"
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace WordsCountAndSort
{		
	TEST_CLASS(WordsTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Assert::AreEqual("", StoreAndCount("mama tata mama mama tata sac").c_str());
		}

		struct Text
		{
			string word;
			int counter;
			Text(string word, int counter)
			{
				this->word = word;
				this->counter = counter;
			}
		};

		vector<string> SplitString(string text)
		{
			istringstream iss(text);
			vector<string> split ((istream_iterator<string>(iss)), istream_iterator<string>());
			return split;
		}

		bool Contain(vector<Text> words, string toCheck)
		{
			for (int i = 0; i < words.size(); i++)
			{
				if (toCheck == words[i].word) return true;
			}
			return false;
		}

		vector<Text> StoreAndCount(string text)
		{
			vector<Text> words;
			vector<string> split = SplitString(text);
			for (int i = 0; i < split.size(); i++)
			{
				if (!Contain(words,split[i]))
					words.push_back({ split[i] , count(split.begin(), split.end(), split[i]) });
			}
			return words;
		}

	};
}