#include<fstream>
#include"PathSearch.h"
#include<iostream>
#include<vector>
#include<algorithm>

bool GraghRead(const char* address, vector<vector<int>> &GraghInfo, int &StartPoint, int &EndPoint, int &allNum, vector<int> &PointPass, vector<vector<int>> &PathPass, vector<int> &PointSelect, vector<vector<int>> &PointDelete)
{
	int Row = 0;
	int Col = 0;
	int Value = 0;
	int Edege = 0;
	int PointPassSize = 0;
	int PathPassSize = 0;
	int PointDeleteSize = 0;
	int first = 0;
	int second = 0;
	int PointNumber;
	ifstream is(address);
	if (is)
	{
		is >> allNum>>StartPoint>>EndPoint>>Edege>>PointPassSize>>PathPassSize>>PointDeleteSize>>PointNumber;
		GraghInfo.resize(allNum);
		for (auto &a : GraghInfo)
		{
			a.assign(allNum, 1000);
		}
		int edegeSize = 0;
		while (edegeSize != Edege)
		{
			is >> Row >> Col >> Value;
			++edegeSize;
			int a = 0;
			for (int i = 0; i < allNum; ++i)
			{
				for (int j = 0; j < allNum; ++j)
				{
					if (i == j)
					{
						GraghInfo[i][j] = 0;
					}
					if (Row == i&&Col == j)
					{
						GraghInfo[i][j] = Value;
						GraghInfo[j][i] = Value;
						int a = 1;
						break;
					}
				}
				if ( a == 1)
					break;
			}
		}
		

		for (int i = 0; i < PointPassSize; ++i)
		{
			is >> first;
			PointPass.push_back(first);
		}

		PathPass.resize(PathPassSize);
		for (int i = 0; i < PathPassSize; ++i)
		{
			is >> first >> second;
			PathPass[i].push_back(first);
			PathPass[i].push_back(second);

		}
		
		PointDelete.resize(PointDeleteSize);
		for (int i = 0; i < PointDeleteSize; ++i)
		{
			is >> first >> second;
			PointDelete[i].push_back(first);
			PointDelete[i].push_back(second);
		}

		for (auto a : PointPass)
		{
			PointSelect.push_back(a);
		}
		for (auto a : PathPass)
		{
			PointSelect.push_back(a[0]);
			PointSelect.push_back(a[1]);
		}
		sort(PointSelect.begin(), PointSelect.end());
		is.close();
	}
	else
	{
		cerr << "file open fail" << endl;
		return false;
	}
	return true;
}

void ArcsDelete(vector<vector<int>> &PointDelete, vector<vector<int>> &GraghInfo)
{
	for (auto a : PointDelete)
	{
		GraghInfo[a[0]][a[1]] = 1000;
		GraghInfo[a[1]][a[0]] = 1000;
	}
}