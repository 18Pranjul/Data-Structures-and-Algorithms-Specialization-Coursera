#include <bits/stdc++.h> 
using namespace std; 
struct Edge { 
	int src, dest, weight; 
}; 
struct Graph { 
	int V, E; 
	struct Edge* edge; 
}; 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[graph->E]; 
	return graph; 
} 
int main() 
{ 
	int V,E,i,j,k;
	cin>>V>>E;
	struct Graph* graph = createGraph(V, E); 
    for(i=0;i<E;i++) 
    {
        cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight;
        graph->edge[i].src--;
        graph->edge[i].dest--;
    }
	bool visited[V+5]; 
	memset(visited, 0, sizeof(visited)); 
	int dist[V+5],f=0; 
	for (int k = 0; k < V; k++) 
	{ 
		if (visited[k] == false) 
		{ 
			for (int i = 0; i < V; i++) dist[i] = INT_MAX; 
	        dist[k] = 0; 
	        for (int i = 1; i <= V - 1; i++) 
	        { 
		        for (int j = 0; j < E; j++) 
		        { 
			        int u = graph->edge[j].src; 
			        int v = graph->edge[j].dest; 
			        int weight = graph->edge[j].weight; 
			        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				     dist[v] = dist[u] + weight; 
		        } 
	        } 
	        for (int i = 0; i < E; i++) 
	        { 
		        int u = graph->edge[i].src; 
		        int v = graph->edge[i].dest; 
		        int weight = graph->edge[i].weight; 
		        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
	            {
	                f=1;
	                goto end;
	            }
	        }
			for (int i = 0; i < V; i++) if (dist[i] != INT_MAX)	visited[i]=true;
		} 
	} 
    end:;
    cout<<f;
	return 0; 
} 
