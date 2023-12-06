//CS311 graph.h
#pragma once
#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

/**
 * @brief City class
 * 
 */
struct City {
public:
    int id;
    string cityCode;
    string cityName;
    int population;
    int elevation;

    City(int id = 0, string cityCode = "", string cityName = "", int population = 0, int elevation = 0) {
        this->id = id;
        this->cityCode = cityCode;
        this->cityName = cityName;
        this->population = population;
        this->elevation = elevation;
    }
};

/**
 * @brief Road class
 * 
 */
struct Road {
    int fromCity;  // fromCity ID - reference City
    int toCity;    // toCity ID - reference City
    int distance;   

    Road(int fromCity = 0, int toCity = 0, int distance = 0) {
        this->fromCity = fromCity;
        this->toCity = toCity;
        this->distance = distance;
    }
};

/**
 * @brief Graph class
 *
 */
class Graph
{
public:
    int numCities;            // No. of vertices
    vector<City> cities; // The list of vertices
    vector<vector<Road>> adjList; // The adjacency list
    unordered_map<string, City> citymap;    
    

    // Default constructor. Create an empty graph
    Graph() {
        numCities = 0;
    }

    // Constructor. Create a graph with n vertices
    Graph(int nC);

    // Destructor
    ~Graph();

    /** 
     * @brief get the number of road in the graph
    */
    int getNumCities() {
        return numCities;
    };

    /**
     * @brief Add a new vertex to the graph
     * @param v The vertex to be added
     */
    void addCity(City v);

    /**
     * @brief Add a directed edge to the graph
     *
     * @param c1 The index of the city where the road starts
     * @param c2 The index of the city where the road ends
     * @param weight The weight of the edge
     */
    void addRoad(int c1, int c2, int distance);


    /**
     * @brief the number of outgoing roads from a city
     * @param c The index of the city
     * @return The number of outgoing roads from the city
     */
    int outDegree(int c);

   
    /**
      * @brief Print the graph
      */
    void printGraph();
};
