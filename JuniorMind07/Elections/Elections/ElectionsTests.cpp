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
		int AddVotes(Candidate &other)
		{
			return this->votes += other.votes;
		}
	};


	enum class sort_type { byVotes, byNames };

	class PollingStation
	{
	private:
		std::string stationName;
		std::vector<Candidate> candidates;

	void shellSort(sort_type sort, int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i += 1)
			{
				Candidate temp = candidates[i];
				int j;
				for (j = i; j >= gap && CompareBy(sort, candidates[j - gap], temp); j -= gap)
					candidates[j] = candidates[j - gap];
				candidates[j] = temp;
			}
		}
	}

	bool CompareBy(sort_type sort, Candidate cand1, Candidate cand2)
	{
		if (sort == sort_type::byVotes) 
			return cand1.GetVotes() < cand2.GetVotes();
		return cand1.GetName() > cand2.GetName();
	}

	void AddVotes(PollingStation &station)
	{
		for each (Candidate cd in candidates)
			for each (Candidate other in station.candidates)
			{
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

		void Sort(sort_type sort)
		{
			shellSort(sort, GetCandidates().size());
		}
			
		void AddVotes(std::vector<PollingStation> &stations)
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
			st1.Sort(sort_type::byNames);
			st2.Sort(sort_type::byVotes);
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
			central.Sort(sort_type::byNames);
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