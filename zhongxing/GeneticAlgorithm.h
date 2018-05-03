#ifndef GA_H
#define GA_H
#include<vector>
#include <map>
#include <set>
#include <utility> // pair
#include <time.h> // time
#include <stdlib.h> // srand, rand

bool PathCheck(std::vector<int> copy_solution, std::vector<std::vector<int>> PathPass);
// class that represents the graph
class Graph
{
private:
	int V; // number of vertices
	int total_edges; // total of edges
	int initial_vertex; // initial vertex
	int end_vertex;    //  end vertex
	std::map<std::pair<int, int>, int> map_edges; // map of the edges
	std::vector<std::vector<int>> PathPass;
	std::vector<int> PointSelect;
public:
	Graph(int V, int initial_vertex, int end_vertex, std::vector<std::vector<int>> PathPass, std::vector<int> PointSelect,std::map<std::pair<int, int>, int> PairCost); // constructor
	int existsEdge(int src, int dest); // checks if exists a edge
	friend class Genetic; // to access private membres this class
};

typedef std::pair<std::vector<int>, int> my_pair;


// sort vector with pair
struct sort_pred
{
	bool operator()(const my_pair& firstElem, const my_pair& secondElem)
	{
		return firstElem.second < secondElem.second;
	}
};

// class that represents genetic algorithm
class Genetic
{
private:
	Graph* graph; // the graph
	std::vector< my_pair > population; // each element is a pair: vector and total cost
	int size_population; // size of population
	int real_size_population; // real size population
	int generations; // amount of generations
	int mutation_rate; // mutation rate
private:
	void initialPopulation(); // generates the initial population
public:
	Genetic(Graph* graph, int size_population, int generations, int mutation_rate); // constructor
	int isValidSolution(std::vector<int> solution); // checks if a solution is valid
	void crossOver(std::vector<int>& parent1, std::vector<int>& parent2); // makes the crossover
	void insertBinarySearch(std::vector<int>& child, int total_cost); // uses binary search to insert
	void run(std::pair<std::vector<int>, int> &best_solution); // runs genetic algorithm
	bool existsChromosome(const std::vector<int> & v); // checks if exists the chromosome
};

#endif
