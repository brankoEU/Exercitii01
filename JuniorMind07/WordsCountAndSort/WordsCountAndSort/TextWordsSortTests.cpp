#include "stdafx.h"
#include "CppUnitTest.h"
#include <numeric>
#include <iterator>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			inline wstring ToString(const vector<int>& t) { return accumulate(t.begin(), t.end(), wstring(L""), [](wstring result, int item) -> wstring { return result + L" " + to_wstring(item); }); }
		}
	}
}

namespace WordsCountAndSort
{		
	TEST_CLASS(WordsTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual({3,2,1}, PrintResult("mama tata mama mama tata sac"));
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual({ 6,6,6,3,3,3,2,2,1,1,1,1,1,1 }, PrintResult("Nory was a Catholic because her mother was a Catholic and Nory’s mother was a Catholic because her father was a Catholic and her father was a Catholic because his mother was a Catholic or had been"));
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
				if (!Contain(words, split[i]))
				{
					words.push_back({ split[i] ,static_cast<int>(count(split.begin(), split.end(), split[i])) });
					if ((words.size() > 1) && (words[words.size()-1].counter > words[words.size() - 2].counter))
						InsertionSort(words, words.size());
					    //ShellSort(words, words.size());
				}
			}
			return words;
		}

		void InsertionSort(vector<Text> &vec, int n)
		{
			int i, j;
			for (i = 1; i < n; i++)
			{
				Text key = vec[i];
				j = i - 1;
				while (j >= 0 && vec[j].counter < key.counter)
				{
					vec[j + 1] = vec[j];
					j = j - 1;
				}
				vec[j + 1] = key;
			}
		}

		void ShellSort(vector<Text> &vec, int n)
		{
			for (int gap = n / 2; gap > 0; gap /= 2)
			{
				for (int i = gap; i < n; i += 1)
				{
					Text temp = vec[i];
					int j;
					for (j = i; j >= gap && vec[j - gap].counter < temp.counter; j -= gap)
						vec[j] = vec[j - gap];

					vec[j] = temp;
				}
			}
		}

		vector<int> PrintResult(string text)
		{
			vector<int> result;
			vector<Text> words = StoreAndCount(text);
			for (int i = 0; i < words.size(); i++)
				result.emplace_back(words[i].counter);
			return result;
		}

	};
}