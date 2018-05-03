#ifndef PathSearch_H
#define PathSearch_H

#include<vector>
#include<map>
#include<list>
class Node
{
private:
	int locate = 0;
	int cost = 1000;
	int PreNodeLocate = 1000;
public:
	int getCost() const
	{
		return cost;
	}

	int getPreNodeLocate() const
	{
		return PreNodeLocate;
	}

	int getLocate() const
	{
		return locate;
	}

	bool operator < (const Node &a) const
	{
		return cost> a.getCost();
	}

	void ModifiCost(int newcost)
	{
		cost = newcost;
	}

	void ModifiPreLocate(int newPre)
	{
		PreNodeLocate = newPre;
	}

	void ModifiLocate(int newLO)
	{
		locate = newLO;
	}

};
using namespace std;
bool GraghRead(const char* address, vector<vector<int>> &GraghInfo, int &StartPoint, int &EndPoint, int &allNum, vector<int> &PointPass, vector<vector<int>> &PathPass, vector<int> &PointSelect, vector<vector<int>> &PointDelete);
void ArcsDelete(vector<vector<int>> &PointDelete, vector<vector<int>> &GraghInfo);
void Dijkstra1(vector<vector<int>> &GraghInfo, int Num, int allNum, vector<int> &PathNode, int StartPoint, int EndPoint, vector<int> &PathCost, vector<vector<int>> &Pathmatrix);
void Dijkstra2(vector<vector<int>> &GraghInfo, int Num, int allNum, vector<int> &PointSelect, vector<int> &PathNode, int StartPoint, vector<int> &PathCost, vector<vector<int>> &Pathmatrix);
void PairCostCaculate(vector<vector<int>> &GraghInfo, int allNum, int StartPoint, int EndPoint, map<pair<int, int>, int> &Cost, map<pair<int, int>, vector<int>> &Path);
void OneToOtherCost(vector<vector<int>> &GraghInfo, int allNum, int StartPoint, vector<int> &PointSelect, map<pair<int, int>, int> &PathCost, map<pair<int, int>, vector<int>> &PathMartix);
void auxiliaryGraghBuild(vector<vector<int>> &GraghInfo, int allNum, int StartPoint, int EndPoint, vector<int> &PointSelect, map<pair<int, int>, int> &PairCost, map<pair<int, int>, vector<int>> &PairPath);

#endif