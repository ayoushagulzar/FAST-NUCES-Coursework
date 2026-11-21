// A university wants to assign one of three available colors to four connected departments in a graph.
// Any two directly connected departments must have different colors. Write a backtracking program to
// assign colors to all vertices, or report that no valid coloring exists.
// Use the following undirected graph:
//   ● Vertices: A, B, C, D
//   ● Edges: A–B, A–C, B–C, B–D, C–D
//   ● Available colors: Red, Green, Blue

#include <iostream>
using namespace std;

const int V = 4;
const int COLORS = 3;

char colorNames[COLORS][10] = {"Red", "Green", "Blue"};

// Adjacency matrix
int graph[V][V] = {
    {0, 1, 1, 0},  // A
    {1, 0, 1, 1},  // B
    {1, 1, 0, 1},  // C
    {0, 1, 1, 0}   // D
};

int color[V];

// Checking if a color can be assigned to a vertex
bool isSafe(int vertex, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoring(int vertex) {

    // base case: all vertices have been colored
    if (vertex == V) {
        return true;
    }

    // try all three colors
    for (int c = 0; c < COLORS; c++) {

        if (isSafe(vertex, c)) {

            color[vertex] = c;

            // move to the next vertex
            if (graphColoring(vertex + 1)) {
                return true;
            }

            // backtrack
            color[vertex] = -1;
        }
    }

    return false;
}

int main() {

    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    if (graphColoring(0)) {

        cout << "Valid Coloring Exists:\n";

        for (int i = 0; i < V; i++) {
            cout << char('A' + i) << " = "
                 << colorNames[color[i]] << endl;
        }

    } else {
        cout << "No valid coloring exists.";
    }

    return 0;
}
