// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[],int size, bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < size; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int size)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < size; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int** graph, int size , int src)
{
    int dist[size]; // The output array.  dist[i] will hold the
                 // shortest
    // distance from src to i

    bool sptSet[size]; // sptSet[i] will be true if vertex i is
                    // included in shortest
    // path tree or shortest distance from src to i is
    // finalized

    // Initialize all distances as INFINITE and stpSet[] as
    // false
    for (int i = 0; i < size; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < size - 1; count++) {
        // Pick the minimum distance vertex from the set of
        // vertices not yet processed. u is always equal to
        // src in the first iteration.
        int u = minDistance(dist, size , sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < size; v++)

            // Update dist[v] only if is not in sptSet,
            // there is an edge from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist, size);
}

// driver's code


int main()
{
    int** graph;
    char* line = NULL;
    int counter = 0;
    char num;
    int size;
    int line_size = 0;
    printf("How many verticies do you want?\n");
    scanf("%d", &size);
    if (size > 1000)
    {
        printf("too much verticies, needed under 1000\n");
        return 1;
    }
        
    getchar();  // Consume the newline character after the integer input

    // Allocate memory for the graph
    graph = (int**)malloc(size * sizeof(int*));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(size * sizeof(int));
        if (graph[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated memory before returning
            for (int j = 0; j < i; j++) {
                free(graph[j]);
            }
            free(graph);
            return 1;
        }
    }

    for (int i = 0; i < size; i++)
    {       
        // scan line
        while(scanf("%c",&num) == 1)
        {   
            if (num == '\n')
            {
                break;
            }
            
            if (!isdigit(num) && num != 32)
            {
                if(num == 45)   // 45 is '-'
                    printf("you used a minus number\n");
                else
                    printf("you put a letter, error \n");
                return 1;
            }

            // Reallocate memory to hold one more character
            char* temp = realloc(line, (counter+1) * sizeof(char));
            if (temp == NULL) {
                // Handle memory allocation failure
                free(line); // Free any already allocated memory
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            line = temp;

            // Add the character to the string
            line[counter] = num;
            counter++;
        }
        
        // Make a copy of the original line
        char* line_copy = strdup(line);
        if (line_copy == NULL) {
            // Handle memory allocation failure
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        // Split the line into tokens to find the size
        char* token = strtok(line_copy, " ");
        while (token != NULL) {
            // Move to the next token
            token = strtok(NULL, " ");  
            line_size++;
        }

        if (line_size < size)
        {
            printf("too few values in the line, error\n");
            return 1;
        }
        else if (line_size > size)
        {
            printf("too many values in the line, error\n");
            return 1;
        }

        // Split the line into tokens based on space delimiter
        token = strtok(line, " ");
        int rows = 0;
        while (token != NULL) {        

            int number = atoi(token);
            // Convert token to integer and store in graph
            graph[i][rows] = number;

            // Move to the next token
            token = strtok(NULL, " ");
            rows++;
        }
        free(line);     // reset line
        counter = 0;
        line = NULL;
        line_size = 0;
    }
    
    printf("\nyour graph is: \n");
    // Print the graph for verification
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", graph[i][j]);
        }          
        printf("\n");
    }
    printf("\n");

    // Function call
    dijkstra(graph,size,0);

    // Free memory allocated for graph
    for (int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}