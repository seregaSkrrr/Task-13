#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int countLinesInFile(const string& filename) {
    ifstream file(filename);

    int count = 0;
    string line;
    while (getline(file, line)) {
        ++count;
    }

    return count;
}

void copyFile(const string& source, const string& destination) {
    ifstream src(source, ios::binary);
    ofstream dest(destination, ios::binary);

    dest << src.rdbuf();
    cout <<"Выполнено!";
}

void sortFile(const string& filename) {
    ifstream inputFile(filename);

    vector<int> numbers;
    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = 0; j < numbers.size() - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }

    ofstream outputFile(filename);

    for (const auto& num : numbers) {
        outputFile << num << " ";
    }
    outputFile.close();
}

void analyzeFile(const string& fileName) {
    ifstream file(fileName);

    string line;
    while (getline(file, line)) {
        int line_count = 1;
        istringstream iss(line);
        string word;
        int wordCount = 0;
        while (iss >> word) {
            ++wordCount;
        }
        cout << "Строка " << line_count << " содержит " << wordCount << " слов." << endl;
        line_count++;
    }
}

void combineFiles(const vector<string>& fileNames, const string& outputFileName) {
    ofstream outputFile(outputFileName);

    for (const auto& fileName : fileNames) {
        ifstream inputFile(fileName);
        
        string line;
        while (getline(inputFile, line)) {
            outputFile << line << endl;
        }
    }
}

void searchInFile(const string& fileName, const string& searchString) {
    ifstream file(fileName);

    string line;
    int lineNumber = 0, counter = 0;
    while (getline(file, line)) {
        ++lineNumber;
        if (line.find(searchString) != string::npos) {
            counter++;
            cout << "Line " << lineNumber << " contains \"" << searchString << "\"" << endl;
        }
    }

    if (lineNumber > 0 && counter ==0) {
        cout << "\"" << searchString << "\" not found in the file" << endl;
    }
}

void replaceTextInFile(const string& fileName, const string& from, const string& to) {
    ifstream inputFile(fileName);

    string tempFileName = fileName + ".tmp";
    ofstream outputFile(tempFileName);

    string line;
    while (getline(inputFile, line)) {
        string::size_type pos = 0;
        while ((pos = line.find(from, pos)) != string::npos) {
            line.replace(pos, from.length(), to);
            pos += to.length();
        }
        outputFile << line << endl;
    }
    

    inputFile.close();
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "");

    //Task 1
    //string filename;
    //cout << "Имя файла: ";
    //cin >> filename;
    //int count = countLinesInFile(filename);
    //cout << "Количество строк в вашем файле: " << count << endl;

    //Task 2
    //string source, destination;
    //cout << "Откуда закидываем: ";
    //cin >> source;
    //cout << "Куда закидываем: ";
    //cin >> destination;
    //copyFile(source, destination);

    //Task 3
    //string filename;
    //cout << "Имя файла: ";
    //cin >> filename;
    //sortFile(filename);

    //Task 4
    //string filename;
    //cout << "Имя файла: ";
    //cin >> filename;
    //analyzeFile(filename);

    //Task 5
    //vector<string> fileNames = { "1.txt", "2.txt"};
    //combineFiles(fileNames, "3.txt");

    //Task 6
    //string filename, str;
    //cout << "Имя файла: ";
    //cin >> filename;
    //cout << "Что ищем: ";
    //cin >> str;
    //searchInFile(filename, str);

    //Task 7
    string filename, from, to;
    cout << "Имя файла: ";
    cin >> filename;
    cout << "Что меняем: ";
    cin >> from;
    cout << "На что меняем :";
    cin >> to;
    replaceTextInFile(filename, from, to);
    cout << "Честно говоря я не знаю как перезаписать в этот же файл без потери всех файлов, поэтому посмотрите у себя в файлах проекта новый файл с таким же названием, но на конце .tmp там он изменённый <3" << endl;

    return 0;
}