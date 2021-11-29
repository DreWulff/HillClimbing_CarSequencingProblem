#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <algorithm>
#include <random>


using namespace std;

class Parameters
{
    public:
    Parameters();
    // Metodos para definir parametros
    void SetNumCars(int);
    void SetNumOptions(int);
    void SetNumClasses(int);
    void SetP(vector<int>);
    void SetQ(vector<int>);
    void SetClassDemand(vector<int>);
    void SetOptions(vector<vector<int>>);
    // Metodos para obtener parametros
    int GetNumCars();
    int GetNumOptions();
    int GetNumClasses();
    int GetP(int);
    int GetQ(int);
    int GetClassDemand(int);
    vector<int> GetOptions(int);

    private:
    int num_cars;
    int num_options;
    int num_classes;
    vector<int> p;
    vector<int> q;
    vector<int> class_demand;
    vector<vector<int>> options;
};