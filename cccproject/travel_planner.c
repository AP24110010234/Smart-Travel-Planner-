#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6 // Number of locations

// Function to find the location with the minimum distance value, from
// the set of locations not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Function to print shortest path from source to destination using parent array
void printPath(int parent[], int j, const char* location_names[]) {
    if (parent[j] == -1) {
        printf("%s", location_names[j]);
        return;
    }
    printPath(parent, parent[j], location_names);
    printf(" -> %s", location_names[j]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using an adjacency matrix
void dijkstra(int graph[V][V], int src, int dest, const char* location_names[]) {
    int dist[V];     // The output array. dist[i] will hold the shortest distance from src to i
    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in shortest path tree
    int parent[V];   // Array to store shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    parent[src] = -1;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);
        if(u == -1) break;

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Optional optimization: Stop when we reach the destination
        if (u == dest) break;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array and path
    if (dist[dest] == INT_MAX) {
        printf("No path exists between %s and %s\n", location_names[src], location_names[dest]);
    } else {
        printf("Shortest Path: ");
        printPath(parent, dest, location_names);
        printf("\nMinimum Distance: %d units\n", dist[dest]);
    }
}

int main() {
    // Array of location names for user-friendly output
    const char* location_names[] = {
        "New York", 
        "Boston", 
        "Philadelphia", 
        "Washington DC", 
        "Baltimore", 
        "Richmond"
    };
    
    // Graph representation using an Adjacency Matrix
    // 0 represents no direct path between those nodes
    int graph[V][V] = {
        // NY(0) BOS(1) PHI(2) WDC(3) BAL(4) RIC(5)
/*NY 0*/{ 0,     5,     2,     0,     0,     0 },
/*BOS 1*/{ 5,     0,     1,     3,     0,     0 },
/*PHI 2*/{ 2,     1,     0,     8,     4,     0 },
/*WDC 3*/{ 0,     3,     8,     0,     2,     6 },
/*BAL 4*/{ 0,     0,     4,     2,     0,     3 },
/*RIC 5*/{ 0,     0,     0,     6,     3,     0 }
    };

    printf("=== Smart Travel Planner (C Version) ===\n");
    printf("Available Locations:\n");
    for (int i = 0; i < V; i++) {
        printf(" %d: %s\n", i, location_names[i]);
    }

    int src, dest;
    printf("\nEnter source location index (0-5): ");
    if(scanf("%d", &src) != 1 || src < 0 || src >= V) {
        printf("Invalid source. Please enter a valid index between 0 and 5.\n");
        return 1;
    }

    printf("Enter destination location index (0-5): ");
    if(scanf("%d", &dest) != 1 || dest < 0 || dest >= V) {
        printf("Invalid destination. Please enter a valid index between 0 and 5.\n");
        return 1;
    }

    printf("\nCalculating shortest path...\n");
    dijkstra(graph, src, dest, location_names);

    return 0;
}
