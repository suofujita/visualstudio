#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class graph {
private:
	int V;
	vector<vector<int>> adjList;
public:
	graph(int n) {
		V = n;
		adjList.resize(n);
	};
	void addEdge(int, int, bool);
	void printAdjList();
    void BFS(int);
    void DFS(int);
};
void graph::addEdge(int u, int v, bool isDirected = true) {
	if (u >= 0 && u < V && v >= 0 && v < V) {
		adjList[u].push_back(v);
        if(!isDirected) {
            adjList[v].push_back(u);
        }
	}
    else {
        cout << "Invalid" << endl;
    } 
}
void graph::printAdjList() {
	for (int i=0;i<V;i++) {
        cout << i << " ";
		for (int j : adjList[i])
			cout << j << " ";
		cout << endl;
	}
}

void graph::BFS(int v) {
    vector<int> visited(V, 0);
    visited[v] = 1;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for(int i: adjList[curr]){  // i là giá trị addList[curr][index]
            if(visited[i]==0) {
                visited[i]=1;
                q.push(i);
            }
        }
    }
}
int main() {
    graph g(6);
    g.addEdge(0, 1, false);
    g.addEdge(0, 2, false);
    g.addEdge(1, 2, false);
    g.addEdge(1, 4, false);
    g.addEdge(1, 5, false);
    g.addEdge(2, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 5, false);
    
    g.printAdjList();
    g.BFS(0);
    return 0;
}