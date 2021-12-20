#include "header.h"

using namespace std;

int StrToInt(string in)
{
    stringstream ss;
    int num;
    ss << in;
    ss >> num;
    ss.clear();
    return(num);
}

string IntToStr(int in)
{
    stringstream ss;
    string obj;
    ss << in;
    ss >> obj;
    ss.clear();
    return(obj);
}

vector<int> ReadWordsToNums(string line, char separator)
{
    vector<int> words;
    string word = "";
    for (char x : line)
    {
        if (x != separator) {
            word = word + x;
        } else {
            words.push_back(StrToInt(word));
            word = "";
        }
    }
    words.push_back(StrToInt(word));
    return (words);
}

Parameters ReadInstance (string file_path)
{
    ifstream inFile;
    inFile.open(file_path);
    string line;
    int step = 1;

    Parameters parameters;

    if (!inFile)
    {
        cerr << "Archivo de instanciacion no encontrado.";
        exit(1);
    }

    vector<vector<int>> options;
    vector<int> class_demand;
    while (getline(inFile, line, '\n'))
    {
        if ((line[0] != '#')&&(line != ""))
        {
            if (step == 1) {
                vector<int> first = ReadWordsToNums(line, ' ');
                parameters.SetNumCars(first[0]);
                parameters.SetNumOptions(first[1]);
                parameters.SetNumClasses(first[2]);
                step++;
            } else if (step == 2) {
                parameters.SetP(ReadWordsToNums(line, ' '));
                step++;
            } else if (step == 3) {
                parameters.SetQ(ReadWordsToNums(line, ' '));
                step++;
            } else {
                vector<int> translated = ReadWordsToNums(line, ' ');
                translated.erase(translated.begin());
                class_demand.push_back(translated[0]);
                translated.erase(translated.begin());
                options.push_back(translated);
            }
        }
    }
    parameters.SetOptions(options);
    parameters.SetClassDemand(class_demand);
    return (parameters);
}

void PrintSolution(Solution solution)
{
    cout << "Solucion inicial:\n";
    int init = 1;
    vector<int> arr = solution.GetSolution();
    for (int option : arr)
    {
        if (init == 1) {cout << IntToStr(option); init = 0;}
        else {cout << ", " + IntToStr(option);}
    }
    cout << '\n';
}

int ObjFunction(Parameters instance, vector<int> solution)
{
    int p;
    int q;
    int car;
    int opt_sum;
    int sub_sum;
    int obj_sum = 0;
    int total = instance.GetNumCars();
    // Por cada opcion:
    for (int option = 0; option < instance.GetNumOptions(); option++)
    {
        opt_sum = 0;
        p = instance.GetP(option);
        q = instance.GetQ(option);
        // en cada subarreglo:
        for (int sub = 0; sub <= total - q; sub++)
        {
            sub_sum = 0;
            for (int index = 0; index < q; index++)
            {
                car = solution[index + sub];
                sub_sum += instance.GetOptions(car)[option];
            }
            sub_sum -= p;
            opt_sum += (sub_sum + std::abs(sub_sum))/2;
        }
        obj_sum += opt_sum;
    }
    return (obj_sum);
}

vector<int> GetRandomRange(Parameters instance)
{
    vector<int> range;
    for (int index = 0; index < instance.GetNumCars(); index++)
    {
        range.push_back(index);
    }
    random_device rd; 
    auto rng = default_random_engine { rd() };
    shuffle(range.begin(), range.end(), rng);
    return (range);
}

Solution HC(Parameters instance, Solution solution, int iteration)
{
    cout << "Iteracion: " + IntToStr(iteration) + "\n";
    cout << "Obj: " + IntToStr(solution.GetObj()) + "\n";
    int targ_cap;
    int swap_a;
    int swap_b;
    int new_obj;
    vector<int> new_array;
    vector<int> rand_base = GetRandomRange(instance);
    Solution new_solution = Solution();
    for (int attempt = 0; attempt < instance.GetNumCars(); attempt++)
    {
        targ_cap = instance.GetNumCars() - attempt;
        for (int target = 1; target < targ_cap; target++)
        {
            swap_a = rand_base[attempt];
            swap_b = rand_base[attempt + target];
            new_array = solution.GetSolution();
            new_array[attempt] = swap_b;
            new_array[attempt + target] = swap_a;
            new_obj = ObjFunction(instance, new_array);
            cout << IntToStr(new_obj) + "-> ";
            if (new_obj < solution.GetObj())
            {
                cout << '\n';
                new_solution.SetObj(new_obj);
                new_solution.SetSolution(new_array);
                return (HC(instance, new_solution, iteration+1));
            }
        }
    }
    return (solution);
}

vector<int> GetInitial(Parameters instance)
{
    vector<int> solution;
    for (int car_class = 0; car_class < instance.GetNumClasses(); car_class++)
    {
        for (int demand = 0; demand < instance.GetClassDemand(car_class); demand++)
        {
            solution.push_back(car_class + 1);
        }
    }
    random_device rd; 
    auto rng = default_random_engine { rd() };
    shuffle(solution.begin(), solution.end(), rng);
    return (solution);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "No se pudieron interpretar los argumentos ingresados.";
        exit(1);
    }
    Parameters instance = ReadInstance(argv[1]);
    cout << "Instancia correctamente cargada.\n";
    Solution init_solution = Solution();
    init_solution.SetSolution(GetInitial(instance));
    init_solution.SetObj(ObjFunction(instance, init_solution.GetSolution()));
    cout << "Solucion inicial:\n";
    PrintSolution(init_solution);
    HC(instance, init_solution, 1);

}