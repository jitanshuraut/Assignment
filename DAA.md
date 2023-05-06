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

## Algorithm for Topological Sorting:
Approach:

Create a stack to store the nodes.
Initialize visited array of size N to keep the record of visited nodes.
Run a loop from 0 till N
if the node is not marked True in visited array
Call the recursive function for topological sort and perform the following steps.
Mark the current node as True in the visited array.
Run a loop on all the nodes which has a directed edge to the current node
if the node is not marked True in the visited array:
Recursively call the topological sort function on the node
Push the current node in the stack.
Print all the elements in the stack.

```
// A C++ program to print topological
// sorting of a DAG
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	// No. of vertices'
	int V;

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[],
							stack<int>& Stack);

public:
	// Constructor
	Graph(int V);

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of
	// the complete graph
	void topologicalSort();
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

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
								stack<int>& Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack
	// which stores result
	Stack.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function
	// to store Topological
	// Sort starting from all
	// vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
	
	delete [] visited;
}

// Driver Code
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given "
			"graph \n";

	// Function Call
	g.topologicalSort();

	return 0;
}
```



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

## Complexity

Still O(n2)
```
◦ Different types of trees (heaps, red-black trees) allow both of the following in O(log n) time
◦ Find and delete minimum
◦ Insert or update a value
◦ With such a tree
◦ Finding minimum visit time vertex takes O(log n)
◦ With adjacency list, updating visit times takes O(log n) each, total O(m) edges
◦ Overall O(n log n + m log n) = O((n+m) log n)
```

```
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
	int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

// A utility function used to print the solution
void printArr(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

// The main function that finds shortest distances from src
// to all other vertices using Bellman-Ford algorithm. The
// function also detects negative weight cycle
void BellmanFord(struct Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	// Step 1: Initialize distances from src to all other
	// vertices as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times. A simple
	// shortest path from src to any other vertex can have
	// at-most |V| - 1 edges
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX
				&& dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles. The above
	// step guarantees shortest distances if graph doesn't
	// contain negative weight cycle. If we get a shorter
	// path, then there is a cycle.
	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX
			&& dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return; // If negative cycle is detected, simply
					// return
		}
	}

	printArr(dist, V);

	return;
}

// Driver's code
int main()
{
	/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1 (or A-B in above figure)
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = -1;

	// add edge 0-2 (or A-C in above figure)
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 4;

	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 3;

	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;
	graph->edge[3].weight = 2;

	// add edge 1-4 (or B-E in above figure)
	graph->edge[4].src = 1;
	graph->edge[4].dest = 4;
	graph->edge[4].weight = 2;

	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 3;
	graph->edge[5].dest = 2;
	graph->edge[5].weight = 5;

	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 3;
	graph->edge[6].dest = 1;
	graph->edge[6].weight = 1;

	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 4;
	graph->edge[7].dest = 3;
	graph->edge[7].weight = -3;
	
	// Function call
	BellmanFord(graph, 0);

	return 0;
}
```

```
// Floyd-Warshall Algorithm in C++

#include <iostream>
using namespace std;

// defining the number of vertices
#define nV 4

#define INF 999

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) {
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
  floydWarshall(graph);
}
```
```
// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int dist[][V])
{

	int i, j, k;

	/* Add all vertices one by one to
	the set of intermediate vertices.
	---> Before start of an iteration,
	we have shortest distances between all
	pairs of vertices such that the
	shortest distances consider only the
	vertices in set {0, 1, 2, .. k-1} as
	intermediate vertices.
	----> After the end of an iteration,
	vertex no. k is added to the set of
	intermediate vertices and the set becomes {0, 1, 2, ..
	k} */
	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++) {
				// If vertex k is on the shortest path from
				// i to j, then update the value of
				// dist[i][j]
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

// Driver's code
int main()
{
	/* Let us create the following weighted graph
			10
	(0)------->(3)
		|	 /|\
	5 |	 |
		|	 | 1
	\|/	 |
	(1)------->(2)
			3	 */
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ INF, 0, 3, INF },
						{ INF, INF, 0, 1 },
						{ INF, INF, INF, 0 } };

	// Function call
	floydWarshall(graph);
	return 0;
}

// This code is contributed by Mythri J L

```
```
#include <stdio.h>    
#include <limits.h>    
#define vertices 5  /*Define the number of vertices in the graph*/  
/* create minimum_key() method for finding the vertex that has minimum key-value and that is not added in MST yet */   
int minimum_key(int k[], int mst[])    
{  
    int minimum  = INT_MAX, min,i;    
      
    /*iterate over all vertices to find the vertex with minimum key-value*/  
    for (i = 0; i < vertices; i++)  
        if (mst[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    
    return min;    
}    
/* create prim() method for constructing and printing the MST.  
The g[vertices][vertices] is an adjacency matrix that defines the graph for MST.*/  
void prim(int g[vertices][vertices])    
{    
    /* create array of size equal to total number of vertices for storing the MST*/  
    int parent[vertices];    
    /* create k[vertices] array for selecting an edge having minimum weight*/  
    int k[vertices];       
    int mst[vertices];      
    int i, count,edge,v; /*Here 'v' is the vertex*/  
    for (i = 0; i < vertices; i++)  
    {  
        k[i] = INT_MAX;  
        mst[i] = 0;    
    }  
    k[0] = 0; /*It select as first vertex*/  
    parent[0] = -1;   /* set first value of parent[] array to -1 to make it root of MST*/  
    for (count = 0; count < vertices-1; count++)    
    {    
        /*select the vertex having minimum key and that is not added in the MST yet from the set of vertices*/  
        edge = minimum_key(k, mst);    
        mst[edge] = 1;    
        for (v = 0; v < vertices; v++)    
        {  
            if (g[edge][v] && mst[v] == 0 && g[edge][v] <  k[v])    
            {  
                parent[v]  = edge, k[v] = g[edge][v];    
            }  
        }  
     }    
     /*Print the constructed Minimum spanning tree*/  
     printf("\n Edge \t  Weight\n");  
     for (i = 1; i < vertices; i++)    
     printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);    
      
}    
int main()    
{    
    int g[vertices][vertices] = {{0, 0, 3, 0, 0},    
                                {0, 0, 10, 4, 0},    
                                {3, 10, 0, 2, 6},    
                                {0, 4, 2, 0, 1},    
                                {0, 0, 6, 1, 0},    
                                };   
    prim(g);    
    return 0;  
}  

```
```
int result[1000] = {0};
int fact(int n) {
   if (n >= 0) {
      result[0] = 1;
      for (int i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}
```
```
// A memoization solution for Rod cutting problem
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n
and price[] as prices of different pieces */
int cutRod(int price[], int index, int n,
		vector<vector<int> >& dp)
{
	// base case
	if (index == 0) {
		return n * price[0];
	}
	if (dp[index][n] != -1)
		return dp[index][n];
	// At any index we have 2 options either
	// cut the rod of this length or not cut
	// it
	int notCut = cutRod(price, index - 1, n,dp);
	int cut = INT_MIN;
	int rod_length = index + 1;

	if (rod_length <= n)
		cut = price[index]
			+ cutRod(price, index, n - rod_length,dp);

	return dp[index][n]=max(notCut, cut);
	
}
/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	vector<vector<int> > dp(size,
							vector<int>(size + 1, -1));
	cout << "Maximum Obtainable Value is "
		<< cutRod(arr, size - 1, size, dp);
	getchar();
	return 0;
}

// This code is contributed by Sanskar
```
```
/* Dynamic Programming solution to
find length of the
longest common substring */
#include <iostream>
#include <string.h>
using namespace std;

/* Returns length of longest
common substring of X[0..m-1]
and Y[0..n-1] */
int LCSubStr(char* X, char* Y, int m, int n)
{
	// Create a table to store
	// lengths of longest
	// common suffixes of substrings.
	// Note that LCSuff[i][j] contains
	// length of longest common suffix
	// of X[0..i-1] and Y[0..j-1].

	int LCSuff[m + 1][n + 1];
	int result = 0; // To store length of the
					// longest common substring

	/* Following steps build LCSuff[m+1][n+1] in
		bottom up fashion. */
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// The first row and first column
			// entries have no logical meaning,
			// they are used only for simplicity
			// of program
			if (i == 0 || j == 0)
				LCSuff[i][j] = 0;

			else if (X[i - 1] == Y[j - 1]) {
				LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
				result = max(result, LCSuff[i][j]);
			}
			else
				LCSuff[i][j] = 0;
		}
	}
	return result;
}

// Driver code
int main()
{
	char X[] = "OldSite:GeeksforGeeks.org";
	char Y[] = "NewSite:GeeksQuiz.com";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of Longest Common Substring is "
		<< LCSubStr(X, Y, m, n);
	return 0;
}
```
```
/* A Top-Down DP implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char* X, char* Y, int m, int n,
		vector<vector<int> >& dp)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
						lcs(X, Y, m - 1, n, dp));
}

/* Driver code */
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
	cout << "Length of LCS is " << lcs(X, Y, m, n, dp);

	return 0;
}
```
```
// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int** dp)
{
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {

		// Store the value of function call
		// stack in table before return
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		// Store value in a table before return
		dp[i][W] = max(val[i]
						+ knapSackRec(W - wt[i], wt, val,
										i - 1, dp),
					knapSackRec(W, wt, val, i - 1, dp));

		// Return value of table after storing
		return dp[i][W];
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	// double pointer to declare the
	// table dynamically
	int** dp;
	dp = new int*[n];

	// loop to create the table dynamically
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];

	// loop to initially filled the
	// table with -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}

// Driver Code
int main()
{
	int profit[] = { 60, 100, 120 };
	int weight[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(profit) / sizeof(profit[0]);
	cout << knapSack(W, weight, profit, n);
	return 0;
}
```
```
#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int v, int n,
			vector<vector<int> >& dp)
{
	if (v == 0)
		return dp[n][v] = 1;
	if (n == 0)
		return 0;
	if (dp[n][v] != -1)
		return dp[n][v];
	if (a[n - 1] <= v) {
		// Either Pick this coin or not
		return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
						+ coinchange(a, v, n - 1, dp);
	}
	else // We have no option but to leave this coin
		return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int32_t main()
{
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		int n, v;
		n = 3, v = 4;
		vector<int> a = { 1, 2, 3 };
		vector<vector<int> > dp(n + 1,
								vector<int>(v + 1, -1));
		int res = coinchange(a, v, n, dp);
		cout << res << endl;
	}
}
// This Code is Contributed by
// Harshit Agrawal NITT
```


