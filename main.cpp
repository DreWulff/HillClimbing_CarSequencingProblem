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
    return (parameters);
}

void PrintInstance(Parameters instance)
{
    cout << "Printing Instance\n";
    cout << "Options:\n";
    for (int option : instance.GetOptions(3))
    {
        cout << IntToStr(option) + '\n';
    }
}

vector<int> GetInitial(Parameters instance)
{
    
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "No se pudieron interpretar los argumentos ingresados.";
        exit(1);
    }
    Parameters instance = ReadInstance(argv[1]);

}