#include <iostream>
#include <string>
#include <limits>


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

//Добавление трубы

void AddPipe(Pipe& p) {
    cout << "Enter the name of the pipe: ";
    getline(cin, p.name);

    cout << "Enter the length of the pipe (positive value): ";
    while(!(cin >> p.length) || p.length <=0) {
        cout << "Invalid value. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    cout << "Enter the diameter of the pipe: ";
    while(!(cin >> p.diameter) || p.diameter <=0) {
        cout << "Invalid value. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    p.inrepair = false;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Вывод информации о трубек

void ViewPipe(Pipe p) {
    cout << "Information about the pipe:";
    cout << "Name: " << p.name << endl;
    cout << "Length: " << p.length << endl;
    cout << "Diameter: " << p.diameter << endl;
    cout << "Status: " << (p.inrepair ? "In repairing" : "Running") << endl;

}


// Статус трубы

void EditStatusPipe(Pipe& p) {
    if (p.name.empty()) {
        cout << "Pipe was not found.";
        return;
    }

    cout << "The current status of the pipe:" << (p.inrepair ? "In repairing" : "Running") << endl;
    cout << "Enter a new status ( 1 - In repairing, 0 - Running)";
    int status;
    while (!(cin >> status) || (status != 0 && status != 1)) {
        cout << "Invalid value. Enter 1 or 0 ( 1 - In repairing, 0 - Running): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    p.inrepair = status;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}



void AddStation(Station& s) {
    cout << "Enter the name of the station (Positive value): ";
    getline(cin, s.name);

    cout << "Enter the number of workshops (Positive value): ";

    while(!(cin >> s.workshops) || s.workshops <=0) {
        cout << "Invalid value. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the number of Active workshops: ";

    while(!(cin >> s.activeworkshops) || s.activeworkshops <=0 || s.activeworkshops > s.workshops) {
        cout << "Invalid value. Enter a number from 0 to " << s.workshops << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the efficiency of workshop: ";

    while(!(cin >> s.station_efficiency) || s.station_efficiency <= 0) {
        cout << "Invalid value. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


// Вывод информации о станции
void ViewStation(Station s) {
    cout << "Information about the station:";
    cout << "Name: " << s.name << endl;
    cout << "Number of workshops: " << s.workshops << endl;
    cout << "Number of Active workshops: " << s.activeworkshops << endl;
    cout << "Efficiency: " << s.station_efficiency << endl;

}


// Статус станции

void EditStatusStation(Station& s) {
    if (s.name.empty()) {
        cout << "Pipe was not found.";
        return;
    }

    cout << "The current number of Active workshops:" << s.activeworkshops << endl;
    cout << "Select an action: " << endl;
    cout << "1. Start the workshop" << endl;
    cout << "2. Stop the workshop" << endl;
    cout << "Enter the number (1 or 2): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Incorrect choice. Enter '1' to start or '2' to stop the workshop: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    if (choice == 1){
        if (s.activeworkshops < s.workshops) {
            s.activeworkshops++;
            cout << "The workshop is running. The current number of active workshops: " << s.activeworkshops << "/" << s.workshops << endl;
        } else {
            cout << "It is impossible to start a new workshop. All workshops are already working. The current number of active workshops: " << s.activeworkshops << "/" << s.workshops << endl;
        }
    } else if (choice == 2){
        if (s.activeworkshops > 0) {
            s.activeworkshops--;
            cout << "The workshop is stopped. The current number of active workshops: " << s.activeworkshops << "/" << s.workshops << endl;
        } else {
            cout << "All workshops have already been stopped. The current number of active workshops: " << s.activeworkshops << "/" << s.workshops << endl;
        }
    }

     cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');







    int status;
    while (!(cin >> status) || (status != 0 && status != 1)) {
        cout << "Invalid value. Enter 1 or 0 ( 1 - In repairing, 0 - Running): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    p.inrepair = status;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}