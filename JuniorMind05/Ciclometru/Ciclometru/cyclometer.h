#ifndef CYCLOMETER_H
#define CYCLOMETER_H

using namespace std;

struct Cyclometer
{
	string name;
	double diameter;
	vector<double> records;
	Cyclometer(string name, double diameter, vector<double> records)
	{
		this->name = name;
		this->diameter = diameter;
		this->records = records;
	}

	double Circumference()
	{
		return diameter * 3.14;
	}

	double GetTotalDistance()
	{
		double distance = 0;
		for (int i = 0; i < records.size(); i++)
		{
			distance += Circumference()*records[i];
		}
		return distance;
	}

	int GetMaxRotationPos()
	{
		double maxRotations = records[0];
		int position;
		for (int i = 1; i < records.size(); i++)
		{
			if (records[i] > maxRotations)
			{
				maxRotations = records[i];
				position = i + 1;
			}
		}
		return position;
	}

	double GetAverageSpeed()
	{
		return GetTotalDistance() / records.size();
	}

	double GetMaxRoatations()
	{
		return records[GetMaxRotationPos() - 1];
	}

	double SpeedPerSecond()
	{
		return Circumference() * GetMaxRoatations();
	}

};

#endif