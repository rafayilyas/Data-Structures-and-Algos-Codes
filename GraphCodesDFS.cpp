// #include <iostream>
// using namespace std;

// #define MAX_VERTICES 5
// #define MAX_SIZE 10

// class Graph
// {
// private:
//     struct Node
//     {
//         int vertex;
//         int weight;
//         Node *next;
//     };

//     Node *adjacencyList[MAX_VERTICES];

//     void dfsHelper(int currentVertex, bool visited[])
//     {
//         visited[currentVertex] = true;
//         cout << currentVertex << " ";

//         Node *current = adjacencyList[currentVertex];
//         while (current != NULL)
//         {
//             int neighborVertex = current->vertex;
//             if (!visited[neighborVertex])
//             {
//                 dfsHelper(neighborVertex, visited);
//             }
//             current = current->next;
//         }
//     }

// public:
//     Graph()
//     {
//         for (int i = 0; i < MAX_VERTICES; i++)
//         {
//             adjacencyList[i] = NULL;
//         }
//     }

//     void addEdge(int source, int destination, int weight)
//     {
//         Node *newNode = new Node;
//         newNode->vertex = destination;
//         newNode->weight = weight;
//         newNode->next = adjacencyList[source];
//         adjacencyList[source] = newNode;
//     }

//     void printGraph()
//     {
//         for (int i = 0; i < MAX_VERTICES; i++)
//         {
//             cout << "Adjacency list for vertex " << i << ": " << endl;
//             Node *current = adjacencyList[i];
//             while (current != NULL)
//             {
//                 cout << "(" << current->vertex << ", " << current->weight << ")" << endl;
//                 current = current->next;
//             }
//         }
//     }

//     void dfsTraversal(int startIndex)
//     {
//         bool visited[MAX_VERTICES] = {false};
//         dfsHelper(startIndex, visited);
//         cout << endl;
//     }
// };

// int main()
// {
//     Graph graph;

//     graph.addEdge(0, 1, 4);
//     graph.addEdge(0, 2, 1);
//     graph.addEdge(1, 3, 1);
//     graph.addEdge(2, 1, 2);
//     graph.addEdge(2, 3, 5);
//     graph.addEdge(3, 4, 3);

//     graph.printGraph();

//     cout << "DFS Traversal: ";
//     graph.dfsTraversal(0);

//     return 0;
// }



#include <iostream>
using namespace std;

#define MAX_VERTICES 5
#define MAX_STACK_SIZE 10

class Graph
{
private:
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph()
    {
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            for (int j = 0; j < MAX_VERTICES; j++)
            {
                adjacencyMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int source, int destination, int weight)
    {
        adjacencyMatrix[source][destination] = weight;
        adjacencyMatrix[destination][source] = weight;
    }

    void printGraph()
    {
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            cout << "Vertex " << i << " connections: ";
            for (int j = 0; j < MAX_VERTICES; j++)
            {
                if (adjacencyMatrix[i][j] != 0)
                {
                    cout << j << "(" << adjacencyMatrix[i][j] << ") ";
                }
            }
            cout << endl;
        }
    }

    void dfsTraversal(int startVertex)
    {
        bool visited[MAX_VERTICES] = {false};
        int stack[MAX_STACK_SIZE];
        int top = -1;

        stack[++top] = startVertex;

        while (top >= 0)
        {
            int currentVertex = stack[top--];

            if (!visited[currentVertex])
            {
                visited[currentVertex] = true;
                cout << currentVertex << " ";
            }

            for (int i = MAX_VERTICES - 1; i >= 0; i--) // Reverse to maintain correct order
            {
                if (adjacencyMatrix[currentVertex][i] != 0 && !visited[i])
                {
                    stack[++top] = i;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph graph;

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 1);
    graph.addEdge(0, 3, 1);
    graph.addEdge(0, 4, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 4, 1);

    graph.printGraph();

    cout << "DFS Traversal: ";
    graph.dfsTraversal(0);

    return 0;
}
