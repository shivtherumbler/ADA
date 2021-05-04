import java.util.*; 
import java.lang.*; 
import java.io.*; 

class ShortestPath { 

	static final int V = 5; 
	int minDistance(int dist[], Boolean Set[]) 
	{ 
		int min = Integer.MAX_VALUE, min_index = -1; 

		for (int v = 0; v < V; v++) 
			if (Set[v] == false && dist[v] <= min) { 
				min = dist[v]; 
				min_index = v; 
			} 

		return min_index; 
	} 

	void printSolution(int dist[]) 
	{ 
		System.out.println("Vertex \t\t Distance from Source"); 
		for (int i = 0; i < V; i++) 
			System.out.println((char)(i+65) + " \t\t " + dist[i]); 
	} 

	void dijkstra(int graph[][], int src) 
	{ 
		int dist[] = new int[V]; 

		Boolean Set[] = new Boolean[V]; 

		for (int i = 0; i < V; i++) { 
			dist[i] = Integer.MAX_VALUE; 
			Set[i] = false; 
		} 

		dist[src] = 0; 

		for (int count = 0; count < V - 1; count++) { 
			 
			int u = minDistance(dist, Set); 

			Set[u] = true; 
 
			for (int v = 0; v < V; v++) 

				if (!Set[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) 
					dist[v] = dist[u] + graph[u][v]; 
		} 

		printSolution(dist); 
	} 
 
	public static void main(String[] args) 
	{ 

		int graph[][] = new int[][] { { 0, 3, 0, 0, 5 }, 
									{ 0, 0, 8, 5, 3 }, 
									{ 0, 0, 0, 0, 0 }, 
									{ 0, 0, 2, 0, 0 }, 
									{ 0, 0, 0, 4, 0 }  }; 
		ShortestPath t = new ShortestPath(); 
		t.dijkstra(graph, 0); 
	} 
} 
