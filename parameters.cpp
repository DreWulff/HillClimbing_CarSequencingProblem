#include "header.h"

using namespace std;

Parameters::Parameters(){}

void Parameters::SetNumCars(int num_cars_in)
{
    num_cars = num_cars_in;
}

void Parameters::SetNumClasses(int num_classes_in)
{
    num_classes = num_classes_in;
}

void Parameters::SetNumOptions(int num_options_in)
{
    num_options = num_options_in;
}

void Parameters::SetP(vector<int> p_in)
{
    p = p_in;
}

void Parameters::SetQ(vector<int> q_in)
{
    q = q_in;   
}

void Parameters::SetClassDemand(vector<int> class_demand_in)
{
    class_demand = class_demand_in;
}

void Parameters::SetOptions(vector<vector<int>> options_in)
{
    options = options_in;
}


int Parameters::GetNumCars()
{
    return (num_cars);
}

int Parameters::GetNumClasses()
{
    return (num_classes);
}

int Parameters::GetNumOptions()
{
    return (num_options);
}

int Parameters::GetP(int car_class)
{
    return (p[car_class]);
}

int Parameters::GetQ(int car_class)
{
    return (q[car_class]);
}

int Parameters::GetClassDemand(int car_class)
{
    return (class_demand[car_class]);
}

vector<int> Parameters::GetOptions(int car_class)
{
    return (options[car_class]);
}


Solution::Solution(){}

void Solution::SetSolution(vector<int> solution_in)
{
    solution = solution_in;
}

void Solution::SetObj(int obj_in)
{
    obj = obj_in;
}

vector<int> Solution::GetSolution()
{
    return (solution);
}

int Solution::GetObj()
{
    return (obj);
}