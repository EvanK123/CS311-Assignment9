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

bool Graph::shortRoute(string fromCityCode, string toCityCode, int &shortestDistance, vector<string> &shortestRoute) 
{
    // Convert city codes to IDs
    int sourceId = citymap[fromCityCode].id;
    int destinationId = citymap[toCityCode].id;

    // Data structures for Dijkstra's algorithm
    vector<int> dist(numCities, numeric_limits<int>::max()); // Distance from source to each city
    vector<int> prev(numCities, -1); // Previous city in the shortest path
    set<pair<int, int>> queue; // Min-priority queue (distance, cityId)

    // Initialize source city
    dist[sourceId] = 0;
    queue.insert({0, sourceId});

    while (!queue.empty()) {
        int currentCity = queue.begin()->second;
        queue.erase(queue.begin());

        // Iterate through adjacent cities (roads)
        for (const Road &road : adjList[currentCity]) {
            int neighbor = road.toCity;
            int roadDistance = road.distance;

            // Check if a shorter path is found
            if (dist[neighbor] > dist[currentCity] + roadDistance) {
                // Remove the old distance if it's in the queue
                if (dist[neighbor] != numeric_limits<int>::max()) {
                    queue.erase(queue.find({dist[neighbor], neighbor}));
                }
                // Update distance and predecessor
                dist[neighbor] = dist[currentCity] + roadDistance;
                prev[neighbor] = currentCity;
                queue.insert({dist[neighbor], neighbor});
            }
        }
    }

    // Check if there's a path to destination
    if (dist[destinationId] == numeric_limits<int>::max()) {
        return false;
    }

    // Construct the shortest path
    shortestDistance = dist[destinationId];
    int temp = destinationId;
    while (temp != -1) {
        shortestRoute.insert(shortestRoute.begin(), cities[temp].cityCode);
        temp = prev[temp];
    }

    return true;
}