
#include "graph.h"

int main(int argc, char * argv[])
{

   if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <from_city_code> <to_city_code>" << endl;
        return 1;
    }

    string fromCityCode = argv[1];
    string toCityCode = argv[2];

    // open both files
    ifstream cityFile("city.txt");
    ifstream roadFile("road.txt");

    if (!cityFile.is_open() || !roadFile.is_open()) {
        cerr << "Error opening input files." << endl;
        return 1;
    }

    Graph graph;

    unordered_map<string, City> citymap;
   
    //CityCode, CityID, CityName, CityPopulation, CityElevation

    // no clue if this works i'm kinda lazy to test atm
    // Read city data
    while (!cityFile.eof()) {
        City city;
        // Every city is identified by a number, code, name, population, and elevation
        cityFile >> city.id >> city.cityCode >> city.cityName >> city.population >> city.elevation;
        // EX:           0              AN          ANAHEIM           1273000              310
        citymap[city.cityCode] = city;
        graph.addCity(city); 
        //cout << city.id << " " << city.cityCode << " " << city.cityName << " " << city.population << " " << city.elevation << endl;
    }

    

    int tempfromCity = 0, temptoCity = 0, tempdistance = 0;
    // Read road data
    while (!roadFile.eof()) {
        // tempfromCity = 0, temptoCity = 0, tempdistance = 0; this actually causes errors dont do this 
        // Every road is identified by the cities (city #) it connects and the distance 
        roadFile >> tempfromCity >> temptoCity >> tempdistance;
        //EX:              0              18            36
        //                 AN             VV            Distance of 36km (or miles idk bro) from Anaheim to Victorville)

        graph.addRoad(tempfromCity, temptoCity, tempdistance);
        // if you wanted to add bidirectional roads, switching toCity and fromCity would technically do that
        //cout << tempfromCity << " " << temptoCity << " " << tempdistance << endl; //just using this for debug purposes
    }


    // close both files
    cityFile.close();
    roadFile.close();

    // debug testing
    //graph.printGraph();
    

    if(citymap.find(fromCityCode) == citymap.end())
    {
        cout << "Invalid city code: " << fromCityCode << endl;
        return 1;
    }


    if(citymap.find(toCityCode) == citymap.end())
    {
        cout << "Invalid city code: " << toCityCode << endl;
        return 1;
    }

    cout << "Author: x, xx and xxx" << endl;
    cout << "Date: 11/27/2023" << endl;
    cout << "Course: CS311 (Data structures and Algorithms)" << endl;
    cout << "Description: Program to find the shortest route between cities" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "From City: " << citymap[fromCityCode].cityName << ", Population " << citymap[fromCityCode].population << ", Elevation " << citymap[fromCityCode].elevation << endl;
    cout << "To City: " << citymap[toCityCode].cityName << ", Population " << citymap[toCityCode].population << ", Elevation " << citymap[toCityCode].elevation << endl;

    /* TODO: ShortestRoute Implementation */
}