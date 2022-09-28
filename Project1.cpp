// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <stdlib.h>



using namespace std;
// Creating graph object as an adjacency list of strings representing names, and all adjacent nodes.
// Also keeping track of which names of nodes have been visited
// Adding blueprints for the add edge function and dfs functions

class Graph {
public:
	map<string, bool> visited;
	map<string, list<string> > adj;

	void addEdge(string v, string w);
	void DFS(string v, string goal);
};
// adding edge takes the name of node and it's neighbor, links them in adjecncy list

void Graph::addEdge(string name, string neighborsName)
{
	adj[name].push_back(neighborsName); // Add w to v’s list.
}

// recursively travels down the neighbors of unvisited nodes, aborts when goal is found
void Graph::DFS(string curNode, string goal){

	visited[curNode] = true;
	// prints the name of the current node to the console
	cout << curNode << " - ";
	// aborts when goal is found
	if(curNode==goal){
		std::cout << "goalFound" << '\n';
		std::abort();
	}
	// iterates through adjacency list and recursively calls DFS on unvisited neighbordds
	list<string>::iterator i;
	for (i = adj[curNode].begin(); i != adj[curNode].end(); ++i)
		if (!visited[*i]){
			DFS(*i,goal);
		}
	}


int main()
{
	// constructing directed graph from figure 1
	Graph f1;

	f1.addEdge("S","A");
	f1.addEdge("S","B");
	f1.addEdge("S","C");
	f1.addEdge("A","D");
	f1.addEdge("A","E");
	f1.addEdge("A","G");
	f1.addEdge("B","G");
	f1.addEdge("C","G");

	// Constructing undirected map of Romania
	Graph f2;
	f2.addEdge("Arad","Sibiu");
	f2.addEdge("Arad","Zerind");
	f2.addEdge("Arad","Timisoara");
	f2.addEdge("Sibiu","Arad");
	f2.addEdge("Sibiu","Fagaras");
	f2.addEdge("Sibiu","Oradeu");
	f2.addEdge("Sibiu","Riminicu Vilcea");
	f2.addEdge("Zerind","Arad");
	f2.addEdge("Zerind","Oradea");
	f2.addEdge("Timisoara","Arad");
	f2.addEdge("Timisoara","Lugoj");
	f2.addEdge("Fagaras","Bucharest");
	f2.addEdge("Sibiu","Bucharest");
	f2.addEdge("Lugoj","Timisoara");
	f2.addEdge("Lugoj","Mehadia");
	f2.addEdge("Mehadia","Lugoj");
	f2.addEdge("Mehadia","Drobeta");
	f2.addEdge("Drobeta","Craiova");
	f2.addEdge("Drobeta","Mehadia");
	f2.addEdge("Craiova","Drobeta");
	f2.addEdge("Craiova","Pitesti");
	f2.addEdge("Craiova","Riminicu Vilcea");
	f2.addEdge("Riminicu Vilcea","Pitesti");
	f2.addEdge("Riminicu Vilcea","Craiova");
	f2.addEdge("Riminicu Vilcea","Sibiu");
	f2.addEdge("Pitesti","Riminicu Vilcea");
	f2.addEdge("Pitesti","Craiova");
	f2.addEdge("Pitesti","Bucharest");
	f2.addEdge("Oradea","Zerind");
	f2.addEdge("Oradea","Sibiu");
	f2.addEdge("Bucharest","Giurgiu");
	f2.addEdge("Bucharest","Fagaras");
	f2.addEdge("Bucharest","Urziceni");
	f2.addEdge("Giurgiu","Bucharest");
	f2.addEdge("Urziceni","Bucharest");
	f2.addEdge("Urziceni","Hirsova");
	f2.addEdge("Urziceni","Vashui");
	f2.addEdge("Hirsova","Eforie");
	f2.addEdge("Hirsova","Urziceni");
	f2.addEdge("Eforie","Hirsova");
	f2.addEdge("Vashui","Urziceni");
	f2.addEdge("Vashui","Iasi");
	f2.addEdge("Iasi","Vashui");
	f2.addEdge("Iasi","Neamt");
	f2.addEdge("Neamt","Iasi");



	// std::cout << "Running DFS for figure 1" << '\n';
	// f1.DFS("S","G");

	std::cout << "Running DFS for Romania map" << '\n';

	f2.DFS("Arad","Bucharest");

	return 0;
}
