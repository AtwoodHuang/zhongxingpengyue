#include"PathSearch.h"
#include<vector>
#include<algorithm>
#include<map>
#include<utility>

void PairCostCaculate(vector<vector<int>> &GraghInfo, int allNum, int StartPoint, int EndPoint, map<pair<int, int>, int> &Cost, map<pair<int, int>, vector<int>> &Path)
{
	vector<int>PathNode;
	for (int i = 0; i < allNum; ++i)
	{
		if (i != StartPoint)
			PathNode.push_back(i);
	}
	vector<int> PathCost(allNum, 1000);
	vector<vector<int>> Pathmarix(allNum);
	Dijkstra1(GraghInfo, allNum-1, allNum, PathNode, StartPoint, EndPoint, PathCost, Pathmarix);
	Pathmarix[EndPoint].push_back(EndPoint);
	Cost.insert(make_pair(make_pair(StartPoint, EndPoint), PathCost[EndPoint]));
	Path.insert(make_pair(make_pair(StartPoint, EndPoint), Pathmarix[EndPoint]));
	Cost.insert(make_pair(make_pair(EndPoint, StartPoint), PathCost[EndPoint]));
	reverse(Pathmarix[EndPoint].begin(), Pathmarix[EndPoint].end());
	Path.insert(make_pair(make_pair(EndPoint, StartPoint), Pathmarix[EndPoint]));
}

void OneToOtherCost(vector<vector<int>> &GraghInfo, int allNum, int StartPoint, vector<int> &PointSelect, map<pair<int, int>, int> &PathCost, map<pair<int, int>, vector<int>> &PathMartix)
{
	vector<int>PathNode;
	for (int i = 0; i < allNum; ++i)
	{
		if (i != StartPoint)
			PathNode.push_back(i);
	}
	vector<int> DjPathCost(allNum, 1000);
	vector<vector<int>> DjPathMatrix(allNum);
	Dijkstra2(GraghInfo, allNum - 1, allNum, PointSelect, PathNode, StartPoint, DjPathCost, DjPathMatrix);
	for (auto a : PointSelect)
	{
		DjPathMatrix[a].push_back(a);
		PathCost.insert(make_pair(make_pair(StartPoint, a), DjPathCost[a]));
		PathMartix.insert(make_pair(make_pair(StartPoint, a), DjPathMatrix[a]));
		PathCost.insert(make_pair(make_pair(a, StartPoint), DjPathCost[a]));
		reverse(DjPathMatrix[a].begin(), DjPathMatrix[a].end());
		PathMartix.insert(make_pair(make_pair(a, StartPoint), DjPathMatrix[a]));
	}
}

void auxiliaryGraghBuild(vector<vector<int>> &GraghInfo, int allNum, int StartPoint, int EndPoint, vector<int> &PointSelect, map<pair<int, int>, int> &PairCost, map<pair<int, int>, vector<int>> &PairPath)
{
	OneToOtherCost(GraghInfo, allNum, StartPoint, PointSelect, PairCost, PairPath);
	OneToOtherCost(GraghInfo, allNum, EndPoint, PointSelect, PairCost, PairPath);
	for (unsigned int i = 0; i < PointSelect.size(); ++i)
	{
		for (unsigned int j = i + 1; j < PointSelect.size(); ++j)
		{
			PairCostCaculate(GraghInfo, allNum,PointSelect[i],PointSelect[j],PairCost,PairPath);
		}
	}
}

