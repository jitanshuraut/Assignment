# Breadth First Search or BFS for a Graph
The breadth-first search (BFS) algorithm is used to search a tree or graph data structure for a node that meets a set of criteria. It starts at the tree’s root or graph and searches/visits all nodes at the current depth level before moving on to the nodes at the next depth level. Breadth-first search can be used to solve many problems in graph theory.

## Algorithm of breadth-first search
Step 1: Consider the graph you want to navigate.

Step 2: Select any vertex in your graph, Say v1, from which you want to traverse the graph.

Step 3:Examine any two data structure for traversing the graph.

             Visited array(size of the graph)

             Queue data structure

Step 4:Starting from the vertex, you will add to the visited array, and afterward, you will v1’s adjacent vertices to the queue data structure.

Step 5:Now,using the FIFO concept, you must remove the element from the queue , put it into the visited array, and then return to the queue to add the adjacent vertices of the removed element.

Step 6:Repeat step 5 until the queue is not empty and no vertex is left to be visited.

## Pseudocode
```
Breadth_First_Search( Graph, X ) // Here, Graph is the graph that we already have and X is the source node

Let Q be the queue
Q.enqueue( X ) // Inserting source node X into the queue
Mark X node as visited.

While ( Q is not empty )
Y = Q.dequeue( ) // Removing the front node from the queue

Process all the neighbors of Y, For all the neighbors Z of Y
If Z is not visited, Q. enqueue( Z ) // Stores Z in Q
Mark Z as visited
```
```
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
	int V; // No. of vertices
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
	Graph* g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g->adj[i][j] = false;
		}
	}

	return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
	g->adj[v][w] = true; // Add w to v’s list.
}

// prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
	// Mark all the vertices as not visited
	bool visited[MAX_VERTICES];
	for (int i = 0; i < g->V; i++) {
		visited[i] = false;
	}

	// Create a queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) {
		// Dequeue a vertex from queue and print it
		s = queue[front++];
		printf("%d ", s);

		// Get all adjacent vertices of the dequeued
		// vertex s. If a adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int adjacent = 0; adjacent < g->V;
			adjacent++) {
			if (g->adj[s][adjacent] && !visited[adjacent]) {
				visited[adjacent] = true;
				queue[rear++] = adjacent;
			}
		}
	}
}

// Driver program to test methods of graph struct
int main()
{
	// Create a graph given in the above diagram
	Graph* g = Graph_create(4);
	Graph_addEdge(g, 0, 1);
	Graph_addEdge(g, 0, 2);
	Graph_addEdge(g, 1, 2);
	Graph_addEdge(g, 2, 0);
	Graph_addEdge(g, 2, 3);
	Graph_addEdge(g, 3, 3);

	printf("Following is Breadth First Traversal "
		"(starting from vertex 2) \n");
	Graph_BFS(g, 2);

	Graph_destroy(g);

	return 0;
}

```
## Complexity of BFS algorithm
Time complexity of BFS depends upon the data structure used to represent the graph. The time complexity of BFS algorithm is O(V+E), since in the worst case, BFS algorithm explores every node and edge. In a graph, the number of vertices is O(V), whereas the number of edges is O(E).

The space complexity of BFS can be expressed as O(V), where V is the number of vertices.

## Advantages of Breadth First Search
🌟 BFS will never get trapped exploring the useful path forever.
🌟 If there is a solution, BFS definitely find it out.
🌟 If there is more than one solution then BFS can find the minimal one that requires less number 
    of steps. If there is a solution then BFS is guaranteed to find it.
🌟 Low storage requirement: linear with depth.
🌟 Easily programmed.

##  Disadvantages of Breadth First Search:
The main drawback of BFS is its memory requirement. Since each level of the tree must be saved in order to generate the next level and the amount of memory is proportional to the number of nodes stored the space complexity of BFS is O(bd ), where b is the branching factor(the number of children at each node, the outdegree) and d is the depth. As a result, BFS is severely space-bound in practice so will exhaust the memory available on typical computers in a matter of minutes.

## Enhancements to BFS
• If BFS(i) sets visited[j] == 1, we know that i and j are connected
• How do we identify a path from i to j
• When we mark visited[k] = 1, remember the neighbour from which we marked it
◦ If exploring edge (j,k) visits k, set parent[k] = j

• BFS can record how long the path is to each vertex
• Instead of binary array visited[], keep integer array level []
• level[j] = -1 initially
• level[j] = p means j is reached in p steps from i


# Depth First Search or DFS for a Graph
Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. 

So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.

## Follow the below steps to solve the problem:

🌟 Create a recursive function that takes the index of the node and a visited array.
🌟 Mark the current node as visited and print the node.
🌟 Traverse all the adjacent and unmarked nodes and call the recursive function with the index of 
   the adjacent node.


# code
```
// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

// Driver's code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	// Function call
	g.DFS(2);

	return 0;
}

// improved by Vishnudev C

```
## Complexity of Depth-first search algorithm
The time complexity of the DFS algorithm is O(V+E), where V is the number of vertices and E is the number of edges in the graph.

The space complexity of the DFS algorithm is O(V)

## Advantages of Depth First Search:
Memory requirement is only linear with respect to the search graph. This is in contrast with breadth-first search which requires more space. The reason is that the algorithm only needs to store a stack of nodes on the path from the root to the current node.

The time complexity of a depth-first Search to depth d and branching factor b (the number of children at each node, the outdegree) is O(bd) since it generates the same set of nodes as breadth-first search, but simply in a different order. Thus practically depth-first search is time-limited rather than space-limited.

If depth-first search finds solution without exploring much in a path then the time and space it takes will be very less.

DFS requires less memory since only the nodes on the current path are stored. By chance DFS may find a solution without examining much of the search space at all.

## Disadvantages of Depth First Search:
The disadvantage of Depth-First Search is that there is a possibility that it may down the left-most path forever. Even a finite graph can generate an infinite tre One solution to this problem is to impose a cutoff depth on the search. Although ideal cutoff is the solution depth d and this value is rarely known in advance of actually solving the problem. If the chosen cutoff depth is less than d, the algorithm will fail to find a solution, whereas if the cutoff depth is greater than d, a large price is paid in execution time, and the first solution found may not be an optimal one.

Depth-First Search is not guaranteed to find the solution.

And there is no guarantee to find a minimal solution, if more than one solution

## Applications of Depth First Search
```
Detecting cycle in a graph 
Path Finding 
Topological Sorting
To test if a graph is bipartite 
```
## Applications of Breadth First Traversal
```
Shortest Path and Minimum Spanning Tree for unweighted graph
Minimum Spanning Tree for weighted graphs
Peer to Peer Networks
....
```
## DAG
In computer science and mathematics, DAG stands for "Directed Acyclic Graph". 

A DAG is a directed graph that has no cycles, which means that there is no way to start at any node and follow a sequence of directed edges that will eventually loop back to that node. Instead, the edges in a DAG go in a single direction, forming a tree-like structure. Each edge in a DAG has a direction, indicating that one node is the parent or predecessor, and the other node is the child or successor.

DAGs are commonly used in computer science to represent dependencies between tasks or data. For example, in a software build system, a DAG can be used to represent the dependencies between source code files, so that the build system can determine the correct order in which to compile them. DAGs are also used in data processing pipelines, where each node represents a step in the processing, and the edges indicate the data flow between the steps.
## Topological Ordering
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

Note: Topological Sorting for a graph is not possible if the graph is not a DAG.
![Topological-Sorting-1](https://user-images.githubusercontent.com/96559286/236356247-b8327811-eae5-4bd2-ac29-e90a09bb6e14.png)

# Detect Cycle in a Directed Graph
## DFS
To find cycle in a directed graph we can use the Depth First Traversal (DFS) technique. It is based on the idea that there is a cycle in a graph only if there is a back edge [i.e., a node points to one of its ancestors] present in the graph.

To detect a back edge, we need to keep track of the nodes visited till now and the nodes that are in the current recursion stack [i.e., the current path that we are visiting]. If during recursion, we reach a node that is already in the recursion stack, there is a cycle present in the graph.

```
// A C++ Program to detect cycle in a graph
#include <bits/stdc++.h>
using namespace std;

class Graph {
	// No. of vertices
	int V;

	// Pointer to an array containing adjacency lists
	list<int>* adj;

	// Used by isCyclic()
	bool isCyclicUtil(int v, bool visited[], bool* rs);

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

// DFS function to find if a cycle exists
bool Graph::isCyclicUtil(int v, bool visited[],
						bool* recStack)
{
	if (visited[v] == false) {
		// Mark the current node as visited
		// and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this
		// vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i) {
			if (!visited[*i]
				&& isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])
				return true;
		}
	}

	// Remove the vertex from recursion stack
	recStack[v] = false;
	return false;
}

// Returns true if the graph contains a cycle, else false
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited
	// and not part of recursion stack
	bool* visited = new bool[V];
	bool* recStack = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function
	// to detect cycle in different DFS trees
	for (int i = 0; i < V; i++)
		if (!visited[i]
			&& isCyclicUtil(i, visited, recStack))
			return true;

	return false;
}

// Driver code
int main()
{
	// Create a graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	// Function call
	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";
	return 0;
}
```
## BFS
The idea is to simply use Kahn’s algorithm for Topological Sorting

Steps involved in detecting cycle in a directed graph using BFS.
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the graph and initialize the count of visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then. 

```
// A C++ program to check if there is a cycle in
// directed graph using BFS.
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency list
	list<int>* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v);

	// Returns true if there is a cycle in the graph
	// else false.
	bool isCycle();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

// This function returns true if there is a cycle
// in directed graph, else returns false.
bool Graph::isCycle()
{
	// Create a vector to store indegrees of all
	// vertices. Initialize all indegrees as 0.
	vector<int> in_degree(V, 0);

	// Traverse adjacency lists to fill indegrees of
	// vertices. This step takes O(V+E) time
	for (int u = 0; u < V; u++) {
		for (auto v : adj[u])
			in_degree[v]++;
	}

	// Create an queue and enqueue all vertices with
	// indegree 0
	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	// Initialize count of visited vertices
	// 1 For src Node
	int cnt = 1;

	// Create a vector to store result (A topological
	// ordering of the vertices)
	vector<int> top_order;

	// One by one dequeue vertices from queue and enqueue
	// adjacents if indegree of adjacent becomes 0
	while (!q.empty()) {

		// Extract front of queue (or perform dequeue)
		// and add it to topological order
		int u = q.front();
		q.pop();
		top_order.push_back(u);

		// Iterate through all its neighbouring nodes
		// of dequeued node u and decrease their in-degree
		// by 1
		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

			// If in-degree becomes zero, add it to queue
			if (--in_degree[*itr] == 0)
			{
			q.push(*itr);
			//while we are pushing elements to the queue we will incrementing the cnt
			cnt++;
			}

		
	}

	// Check if there was a cycle
	if (cnt != V)
		return true;
	else
		return false;
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	if (g.isCycle())
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
```

# Detect cycle in an undirected graph
Use DFS from every unvisited node. Depth First Traversal can be used to detect a cycle in a Graph. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is indirectly joining a node to itself (self-loop) or one of its ancestors in the tree produced by DFS. 

To find the back edge to any of its ancestors keep a visited array and if there is a back edge to any visited node then there is a loop and return true.

```
// A C++ Program to detect
// cycle in an undirected graph
#include <iostream>
#include <limits.h>
#include <list>
using namespace std;

// Class for an undirected graph
class Graph {

	// No. of vertices
	int V;

	// Pointer to an array
	// containing adjacency lists
	list<int>* adj;
	bool isCyclicUtil(int v, bool visited[], int parent);

public:
	// Constructor
	Graph(int V);

	// To add an edge to graph
	void addEdge(int v, int w);

	// Returns true if there is a cycle
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{

	// Add w to v’s list.
	adj[v].push_back(w);

	// Add v to w’s list.
	adj[w].push_back(v);
}

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{

	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {

		// If an adjacent vertex is not visited,
		// then recur for that adjacent
		if (!visited[*i]) {
			if (isCyclicUtil(*i, visited, v))
				return true;
		}

		// If an adjacent vertex is visited and
		// is not parent of current vertex,
		// then there exists a cycle in the graph.
		else if (*i != parent)
			return true;
	}
	return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{

	// Mark all the vertices as not
	// visited and not part of recursion
	// stack
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper
	// function to detect cycle in different
	// DFS trees
	for (int u = 0; u < V; u++) {

		// Don't recur for u if
		// it is already visited
		if (!visited[u])
			if (isCyclicUtil(u, visited, -1))
				return true;
	}
	return false;
}

// Driver program to test above functions
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic() ? cout << "Graph contains cycle\n"
				: cout << "Graph doesn't contain cycle\n";

	return 0;
}
```
## BFS
In this article, the BFS based solution is discussed. We do a BFS traversal of the given graph. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not a parent of v, then there is a cycle in the graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle.

```
// C++ program to detect cycle
// in an undirected graph
// using BFS.
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isCyclicConnected(vector<int> adj[], int s,
						int V, vector<bool>& visited)
{
	// Set parent vertex for every vertex as -1.
	vector<int> parent(V, -1);

	// Create a queue for BFS
	queue<int> q;

	// Mark the current node as
	// visited and enqueue it
	visited[s] = true;
	q.push(s);

	while (!q.empty()) {

		// Dequeue a vertex from queue and print it
		int u = q.front();
		q.pop();

		// Get all adjacent vertices of the dequeued
		// vertex u. If a adjacent has not been visited,
		// then mark it visited and enqueue it. We also
		// mark parent so that parent is not considered
		// for cycle.
		for (auto v : adj[u]) {
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
				parent[v] = u;
			}
			else if (parent[u] != v)
				return true;
		}
	}
	return false;
}

bool isCyclicDisconnected(vector<int> adj[], int V)
{
	// Mark all the vertices as not visited
	vector<bool> visited(V, false);

	for (int i = 0; i < V; i++)
		if (!visited[i] && isCyclicConntected(adj, i,
										V, visited))
			return true;
	return false;
}

// Driver program to test methods of graph class
int main()
{
	int V = 4;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	addEdge(adj, 2, 3);

	if (isCyclicDisconntected(adj, V))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
```
# How to find Shortest Paths from Source to all Vertices using Dijkstra’s Algorithm
Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. 

Like Prim’s MST, generate a SPT (shortest path tree) with a given source as a root. Maintain two sets, one set contains vertices included in the shortest-path tree, other set includes vertices not yet included in the shortest-path tree. At every step of the algorithm, find a vertex that is in the other set (set not yet included) and has a minimum distance from the source.


To understand the Dijkstra’s Algorithm lets take a graph and find the shortest path from source to all nodes.
Consider below graph and src = 0



Step 1:

The set sptSet is initially empty and distances assigned to vertices are {0, INF, INF, INF, INF, INF, INF, INF} where INF indicates infinite. 
Now pick the vertex with a minimum distance value. The vertex 0 is picked, include it in sptSet. So sptSet becomes {0}. After including 0 to sptSet, update distance values of its adjacent vertices. 
Adjacent vertices of 0 are 1 and 7. The distance values of 1 and 7 are updated as 4 and 8. 
The following subgraph shows vertices and their distance values, only the vertices with finite distance values are shown. The vertices included in SPT are shown in green colour.




Step 2:

Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). The vertex 1 is picked and added to sptSet. 
So sptSet now becomes {0, 1}. Update the distance values of adjacent vertices of 1. 
The distance value of vertex 2 becomes 12.


Step 3: 

Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). Vertex 7 is picked. So sptSet now becomes {0, 1, 7}. 
Update the distance values of adjacent vertices of 7. The distance value of vertex 6 and 8 becomes finite (15 and 9 respectively). 


Step 4:

Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). Vertex 6 is picked. So sptSet now becomes {0, 1, 7, 6}. 
Update the distance values of adjacent vertices of 6. The distance value of vertex 5 and 8 are updated.
 


We repeat the above steps until sptSet includes all vertices of the given graph. Finally, we get the following Shortest Path Tree (SPT).
 
```
// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}
```