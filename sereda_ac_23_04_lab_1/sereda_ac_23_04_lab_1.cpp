#include <iostream>
#include <string>


using namespace std;


// Структура Pipe, которая задает свойства трубы - Название, длина, диаметр трубы и статус.

struct Pipe {
    string name;
    float length = 0.0;
    float diameter = 0.0;
    bool inrepair = false;
};

// Структура Station, задающая свойства компрессорной станции - Название, кол-во цехов, кол-во активных цехов и эффективность.

struct Station {
    string name;
    int workshops = 0;
    int activeworkshops = 0;
    float station_efficiency = 0.0;
};

void AddPip(Pipe& p) {
    cout << "Enter the name of the pipe (Positive value): ";
    getline(cin, p.name);

    cout << "Enter the length of the pipe: ";

    while(!(cin >> p.length) || p.length <=0) {
        cout << "Invalid value. Enter a positive number";
    }

}