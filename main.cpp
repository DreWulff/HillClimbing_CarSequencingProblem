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

void PrintSolution(vector<int> solution)
{
    cout << "Solucion inicial:\n";
    int init = 1;
    for (int option : solution)
    {
        if (init == 1) {cout << IntToStr(option); init = 0;}
        else {cout << ", " + IntToStr(option);}
    }
    cout << '\n';
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
    PrintSolution(GetInitial(instance));

}