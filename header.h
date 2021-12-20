#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <algorithm>
#include <random>
#include <cstdlib>


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
    int GetP(int); // Parametros c_o
    int GetQ(int); // Parametros l_o
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

class Solution
{
    public:
    Solution();
    // Metodos para definir aspectos
    void SetSolution(vector<int>);
    void SetObj(int);
    // Metodos para obtener aspectos
    vector<int> GetSolution();
    int GetObj();

    private:
    vector<int> solution;
    int obj;
};