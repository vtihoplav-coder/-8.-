#include <limits>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

class Train {
    string destination;
    int number;
    int hour;
    int minute;
public:
    Train() {}

    void input() {
        cout << "Пункт призначення: ";
        getline(cin, destination);
        cout << "Номер поїзда: ";
        cin >> number;
        cout << "Час відправлення (година хвилина): ";
        cin >> hour >> minute;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void print() const {
        cout << left << setw(20) << destination
             << setw(8) << number
             << setw(2) << setfill('0') << hour << ":"
             << setw(2) << minute << setfill(' ') << endl;
    }

    int getNumber() const {
        return number;
    }

    string getDestination() const {
        return destination;
    }

    int getMinutes() const {
        return hour * 60 + minute;
    }
};

int main() {
    const int N = 5;
    vector<Train> trains(N);

    cout << "Введіть дані про " << N << " поїздів:\n";
    for (int i = 0; i < N; ++i) {
        cout << "\nПотяг " << i + 1 << endl;
        trains[i].input();
    }

    sort(trains.begin(), trains.end(), [](const Train &a, const Train &b) {
        return a.getNumber() < b.getNumber();
    });

    cout << "\nПотяги, впорядковані за номером:\n";
    cout << left << setw(20) << "Пункт призначення"
         << setw(8) << "№"
         << "Час" << endl;
    for (int i = 0; i < N; ++i) {
        trains[i].print();
    }

    int searchNum;
    cout << "\nВведіть номер поїзда для пошуку: ";
    cin >> searchNum;

    bool found = false;
    for (int i = 0; i < N; ++i) {
        if (trains[i].getNumber() == searchNum) {
            cout << "Знайдено потяг:\n";
            cout << left << setw(20) << "Пункт призначення"
                 << setw(8) << "№"
                 << "Час" << endl;
            trains[i].print();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Потяг з таким номером не знайдено.\n";
    }

    sort(trains.begin(), trains.end(), [](const Train &a, const Train &b) {
        if (a.getDestination() == b.getDestination()) {
            return a.getMinutes() < b.getMinutes();
        }
        return a.getDestination() < b.getDestination();
    });

    cout << "\nПотяги, впорядковані за пунктом призначення\n(і часом відправлення всередині пункту):\n";
    cout << left << setw(20) << "Пункт призначення"
         << setw(8) << "№"
         << "Час" << endl;
    for (int i = 0; i < N; ++i) {
        trains[i].print();
    }

    return 0;
}
