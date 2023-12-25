#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getschedule(string filename) {
    string str;
    string line;
    fstream file(filename);
    if (!file.is_open()) {
        cout << "не удалось открыть файл, проверьте введенные данные";
    }
    while (getline(file, line)) {
        str += line + "\n";
    }

   file.close();

    return str;
}

string getfilename(string WeekDay, string WeekNum) {
    return WeekDay + "_" + WeekNum + ".txt";
}

int main() {
    setlocale(LC_ALL, "Russian");
    string WeekDay;
    string SubgroupNumber;
    string WeekNum;

    cout << "Введите день недели на английском с маленькой буквы (пример: monday)" << endl;
    cin >> WeekDay;

    cout << "Введите номер недели (1,2) если в расписании нет деления на недели(например во вторник) введите 1" << endl;
    cin >> WeekNum;


    string filename = getfilename(WeekDay, WeekNum);
    string schedule = getschedule(filename);
    cout << endl << "============================= Расписание ========================================" << endl;
    cout << schedule;
        
    bool flag;
    cin >> flag;
    return 0;
}
