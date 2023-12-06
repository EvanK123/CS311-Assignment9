#include "graph.h"

/*
 * Construct a Graph with the given number of vertices.
 * @param nV The number of vertices in the graph.
 */
Graph::Graph(int nC)
{
    numCities = nC; 
    adjList.resize(nC);
}

/*
 * Graph destructor.
 */
Graph::~Graph()
{
    // Nothing specific to do in the destructor
}

/*
 * Add a city to the graph.
 * @param v The city to be added.
 */
void Graph::addCity(City c)
{
    cities.push_back(c);
    numCities++;
    adjList.push_back(vector<Road>());
}

/*
 * Add a directed edge v1->v2 to the graph.
 * @param v1 The source vertex.
 * @param v2 The destination vertex.
 * @param weight The weight of the edge.
 */
void Graph::addRoad(int fromCity, int toCity, int distance)
{
    Road road(fromCity, toCity, distance);
    adjList[fromCity].push_back(road);
}


/*
 * Get the number of outgoing roads from a city.
 * @param v The road to check.
 * @return The number of outgoing roads from the city.
 */
int Graph::outDegree(int c)
{
    return adjList[c].size();
}

/*
 * Print the graph.
 */
void Graph::printGraph()
{
    cout << "Graph:" << endl;
    for (int i = 0; i < numCities; i++)
    {
        cout << "City " << i << ": ";
        for (auto road : adjList[i])
        {
            cout << road.toCity << " ";
        }
        cout << endl;
    }
    cout << endl;
}