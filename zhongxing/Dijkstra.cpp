#include"PathSearch.h"
#include<vector>
#include<algorithm>
#include<queue>

void Dijkstra1(vector<vector<int>> &GraghInfo, int Num, int allNum, vector<int> &PathNode, int StartPoint, int EndPoint, vector<int> &PathCost, vector<vector<int>> &Pathmatrix)
{
	vector<bool> label(allNum, false);
	vector<Node> Nodes(Num);
	Node startNode;
	startNode.ModifiLocate(StartPoint);
	label[StartPoint] = false;
	startNode.ModifiCost(0);
	priority_queue<Node> NodeQueue;
	NodeQueue.push(startNode);
	for (int i = 0; i < Num; ++i)
	{
		Nodes[i].ModifiLocate(PathNode[i]);
	}
	while (!NodeQueue.empty())
	{
		Node NodeNow = NodeQueue.top();
		NodeQueue.pop();
		if (label[NodeNow.getLocate()])
			continue;
		label[NodeNow.getLocate()] = true;
		PathCost[NodeNow.getLocate()] = NodeNow.getCost();
		if (NodeNow.getLocate() == EndPoint)
			break;
		for (int i = 0; i < Num; ++i)
		{
			if (!label[Nodes[i].getLocate()] && (NodeNow.getCost() + GraghInfo[NodeNow.getLocate()][Nodes[i].getLocate()]) < Nodes[i].getCost())
			{
				Nodes[i].ModifiCost(NodeNow.getCost() + GraghInfo[NodeNow.getLocate()][Nodes[i].getLocate()]);
				Pathmatrix[Nodes[i].getLocate()] = Pathmatrix[NodeNow.getLocate()];
				Pathmatrix[Nodes[i].getLocate()].push_back(NodeNow.getLocate());
				NodeQueue.push(Nodes[i]);
			}
		}
	}
}

void Dijkstra2(vector<vector<int>> &GraghInfo, int Num, int allNum, vector<int> &PointSelect, vector<int> &PathNode, int StartPoint, vector<int> &PathCost, vector<vector<int>> &Pathmatrix)
{
	int SelectNum = 0;
	vector<bool> label(allNum, false);
	vector<Node> Nodes(Num);
	Node startNode;
	startNode.ModifiLocate(StartPoint);
	label[StartPoint] = false;
	startNode.ModifiCost(0);
	priority_queue<Node> NodeQueue;
	NodeQueue.push(startNode);
	for (int i = 0; i < Num; ++i)
	{
		Nodes[i].ModifiLocate(PathNode[i]);
	}
	while (!NodeQueue.empty())
	{
		Node NodeNow = NodeQueue.top();
		NodeQueue.pop();
		if (label[NodeNow.getLocate()])
			continue;
		label[NodeNow.getLocate()] = true;
		PathCost[NodeNow.getLocate()] = NodeNow.getCost();
		if (find(PointSelect.begin(), PointSelect.end(), NodeNow.getLocate()) != PointSelect.end())
			++SelectNum;
		if (SelectNum == PointSelect.size())
			break;
		for (int i = 0; i < Num; ++i)
		{
			if (!label[Nodes[i].getLocate()] && (NodeNow.getCost() + GraghInfo[NodeNow.getLocate()][Nodes[i].getLocate()]) < Nodes[i].getCost())
			{
				Nodes[i].ModifiCost(NodeNow.getCost() + GraghInfo[NodeNow.getLocate()][Nodes[i].getLocate()]);
				Pathmatrix[Nodes[i].getLocate()] = Pathmatrix[NodeNow.getLocate()];
				Pathmatrix[Nodes[i].getLocate()].push_back(NodeNow.getLocate());
				NodeQueue.push(Nodes[i]);
			}
		}
	}
}