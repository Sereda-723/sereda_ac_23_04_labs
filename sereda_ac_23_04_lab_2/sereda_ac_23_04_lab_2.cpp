#include <iostream>
#include <string>



using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "Helllo wo!" << endl;

    char x;
    cin >> x;
    
    cout << "Привет‚ "s << x << endl;
    cout << "йцукенгшщзхъэждлорпавыфячсмитьбю "s << x << endl;
    return 0;

}