#include<iostream>
#include<stdlib.h>
#include<vector>
#include"PathSearch.h"
#include"GeneticAlgorithm.h"
#include<map>
#include<utility>
#include<time.h>

int main(void)
{
	srand(time(NULL));
	const clock_t begin_time = clock();
	int allNum;
	int StartPoint;
	int EndPoint ;
	vector <vector<int>> PointDelete;
	vector<int> PointPass;
	vector<vector<int>> PathPass;
	vector<int> PointSelect;
	vector<vector<int>> GraghInfo;
	if (!GraghRead("path.txt", GraghInfo,StartPoint,EndPoint,allNum,PointPass,PathPass,PointSelect,PointDelete))
		cout << "the matrix read fail" << endl;
	ArcsDelete(PointDelete, GraghInfo);
	map<pair<int, int>, int> PairCost;
	map<pair<int, int>, vector<int>> PairPath;
	auxiliaryGraghBuild(GraghInfo, allNum, StartPoint, EndPoint, PointSelect, PairCost, PairPath);
	Graph * graph1 = new Graph(PointSelect.size()+2, StartPoint, EndPoint, PathPass, PointSelect, PairCost);
	Genetic genetic(graph1, 10, 2000, 5);
	std::pair<std::vector<int>, int> best_solution;
	genetic.run(best_solution); 
	std::cout <<"the cost is: " <<best_solution.second << std::endl;
	std::cout << "the path is: ";
	int num = 0;
	for (auto a = best_solution.first.begin(); a != best_solution.first.end()-1; ++a)
	{
		for (auto b = PairPath[make_pair(*a, *(a + 1))].begin(); b != PairPath[make_pair(*a, *(a + 1))].end()-1; ++b)
		{
			++num;
			std::cout << *b << " ";
		}
	}
	auto c = *(best_solution.first.end() - 1);
	for (auto j : PairPath[make_pair(c, EndPoint)])
	{
		++num;
		std::cout << j << " ";
	}
	std::cout << std::endl;
	std::cout << "the total points :" << num << std::endl;
	cout << "\nTime for to run the algorithm: " << float(clock() - begin_time) / CLOCKS_PER_SEC << " seconds.";
	std::cout << std::endl;
	system("pause");
}