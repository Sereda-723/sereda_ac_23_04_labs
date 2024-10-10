#include <iostream>
#include <string>
#include <limits>
#include <fstream>

using namespace std;


// Структура Pipe, которая задает свойства трубы - Название, длина, диаметр трубы и статус.

struct Pipe {
    string name;
    float length = 0.0;
    int diameter = 0;
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
    getline(cin>>ws, p.name);

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

void ViewPipe(const Pipe& p) {//!!
    cout << "Information about the pipe:"<< endl;
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

    cout << "The current status of the pipe: " << (p.inrepair ? "In repairing" : "Running") << endl;
    cout << "Enter a new status ( 1 - In repairing, 0 - Running): ";
    while (!(cin >> p.inrepair) || (p.inrepair != 0 && p.inrepair != 1)) {
        cout << "Invalid value. Enter 1 or 0 ( 1 - In repairing, 0 - Running): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

}


//Добавление Станции

void AddStation(Station& s) {
    cout << "Enter the name of the station (Positive value): ";
    getline(cin>>ws, s.name);

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
void ViewStation(const Station& s) {//!!!
    cout << "Information about the station:"<< endl;
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
}


//Сохранение данных трубы в файл

void SavePipe(const Pipe& p, ofstream& outFile) {
    outFile << "PIPE" << endl;
    outFile << p.name << endl;
    outFile << p.length << endl;
    outFile << p.diameter << endl;
    outFile << p.inrepair << endl;
}

//Сохранение данных станции в файл

void SaveStation(const Station& s, ofstream& outFile) {
    outFile << "STATION" << endl;
    outFile << s.name << endl;
    outFile << s.workshops << endl;
    outFile << s.activeworkshops << endl;
    outFile << s.station_efficiency << endl;
}

// Загрузка трубы из файла
void LoadPipe(Pipe& p, ifstream& inFile) {
    getline(inFile, p.name);
    inFile >> p.length;
    inFile >> p.diameter;
    inFile >> p.inrepair;
}

// загрузка станции из файла
void LoadStation(Station& s, ifstream& inFile) {
    getline(inFile, s.name);
    inFile >> s.workshops;
    inFile >> s.activeworkshops;
    inFile >> s.station_efficiency;
}

// Сохранение
void SaveData(const Pipe& p, const Station& s) {
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        if (!p.name.empty()) {
            SavePipe(p, outFile);
        }
        if (!s.name.empty()) {
            SaveStation(s, outFile);
        }
        outFile.close();
        cout << "The data has been successfully saved to a file." << endl;
    } else {
        cout << "Error, try again." << endl;
    }
}

void LoadData(Pipe& p, Station& s) {
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        string line;
        p = {};
        s = Station();
        while (getline(inFile, line)) {
            if (line == "PIPE") {
                LoadPipe(p, inFile);
            } else if(line == "STATION") {
                LoadStation(s, inFile);
            }


        }

        inFile.close();
        cout << "The data has been uploaded successfully." << endl;
    } else {
        cout << "Error, try again." << endl;
    }
}

int main() {
    Pipe pipe;
    Station station;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a pipe" << endl;
        cout << "2. Add a station" << endl;
        cout << "3. Viewing all objects" << endl;
        cout << "4. Edit the pipe" << endl;
        cout << "5. Edit the station" << endl;
        cout << "6. Save the objects" << endl;
        cout << "7. Load the objects" << endl;
        cout << "0. Exit" << endl;
        cout << "Select an action: " << endl;

        int choice;
        if (!(cin >> choice)) {
            cout << "Incorrect input. Please enter a number from the given options." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }


         switch (choice) {
            case 1:
                AddPipe(pipe);
                break;
            case 2:
                AddStation(station);
                break;
             case 3:
                if (!pipe.name.empty())
                    ViewPipe(pipe);
                else
                    cout << "The pipe was not found" << endl;
                if (!station.name.empty())
                    ViewStation(station);
                else
                    cout << "The station was not found" << endl;
                break;
            case 4:
                EditStatusPipe(pipe);
                break;
            case 5:
                EditStatusStation(station);
                break;
            case 6:
                SaveData(pipe, station);
                break;
            case 7:
                LoadData(pipe, station);
                break;
            case 0:
                cout << "Exit..." << endl;
                return 0;
            default:
                cout << "Incorrect input. Please enter a number from the given options." << endl;
                break;
}
}
}