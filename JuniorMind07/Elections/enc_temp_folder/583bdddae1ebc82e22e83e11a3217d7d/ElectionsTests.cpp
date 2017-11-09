#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Elections
{	
	class Candidate
	{
	private:
		std::string name;
		int votes;
	public:
		Candidate(std::string name, int votes)
		{
			this->name = name;
			this->votes = votes;
		}
		std::string GetName()
		{
			return this->name;
		}
		int GetVotes()
		{
			return this->votes;
		}
		int AddVotes(Candidate other)
		{
			return this->votes += other.votes;
		}
	};


	enum class SortType { byVotes, byNames };

	class PollingStation
	{
	private:
		std::string stationName;
		std::vector<Candidate> candidates;

	void shellSort(SortType sort)
	{
		for (int gap = candidates.size() / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < candidates.size(); i += 1)
			{
				Candidate temp = candidates[i];
				int j;
				for (j = i; j >= gap && CompareBy(sort, candidates[j - gap], temp); j -= gap)
					candidates[j] = candidates[j - gap];
				candidates[j] = temp;
			}
		}
	}

	bool CompareBy(SortType sort, Candidate cand1, Candidate cand2)
	{
		if (sort == SortType::byVotes)
			return cand1.GetVotes() < cand2.GetVotes();
		return cand1.GetName() > cand2.GetName();
	}

	void AddVotes(PollingStation station)
	{
		for each (Candidate cd in candidates)
			for each (Candidate other in station.candidates)
			{
				if(cd.GetName().compare(other.GetName()) == 0)
					cd.AddVotes(other);
			}
	}

	public:
		PollingStation(std::string stationName, std::vector<Candidate> candidates)
		{
			this->stationName = stationName;
			this->candidates = candidates;
		}

		std::vector<Candidate> GetCandidates()
		{
			return this->candidates;
		}

		void Sort(SortType sort)
		{
			shellSort(sort);
		}
			
		void AddVotes(std::vector<PollingStation> stations)
		{
			for each (PollingStation st in stations)
			{
				AddVotes(st);
			}
		}

	};

	TEST_CLASS(ElectionsSortTests)
	{
	public:
		
		TEST_METHOD(SortByNameORVotes)
		{
			PollingStation st1 = { "station1",{ { "PSD",43 },{ "PNL",31 },{ "PC",27 } } };
			PollingStation st2 = { "station2",{ { "PNL",62 },{ "PC",51 },{ "PSD",46 } } };
			st1.Sort(SortType::byNames);
			st2.Sort(SortType::byVotes);
			Assert::AreEqual("PC", st1.GetCandidates()[0].GetName().c_str());
			Assert::AreEqual("PNL", st2.GetCandidates()[0].GetName().c_str());
		}

		TEST_METHOD(FillStations)
		{
			std::vector<PollingStation> st = StationsFill();

			Assert::AreEqual("PSD", st[0].GetCandidates()[0].GetName().c_str());
			Assert::AreEqual("PNL", st[1].GetCandidates()[0].GetName().c_str());
			Assert::AreEqual("PC", st[2].GetCandidates()[0].GetName().c_str());
		}

		TEST_METHOD(AddVotesTest)
		{
			std::vector<PollingStation> st = StationsFill();
			PollingStation central = { "Centralized", { { "PSD",0 },{ "PNL",0 },{ "PC",0 } } };
			central.AddVotes(st);
			
			//PSD = 108; PNL = 115; PC = 112;
			//Assert::AreEqual("PNL", st[0].GetCandidates()[0].GetName().c_str());
			Assert::AreEqual(1, central.GetCandidates()[0].GetVotes());
		}


		
		std::vector<PollingStation> StationsFill()
		{
			PollingStation st1 = { "station1", { { "PSD",43 },{ "PNL",31 },{ "PC",27 } } };
			PollingStation st2 = { "station2", { { "PNL",62 },{ "PC",51 },{ "PSD",46 } } };
			PollingStation st3 = { "station3", { { "PC",34 },{ "PNL",22 },{ "PSD",19 } } };
			std::vector<PollingStation> stations;
			stations.push_back(st1);
			stations.push_back(st2);
			stations.push_back(st3);
			return stations;
		}


	};
}