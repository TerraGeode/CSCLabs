#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

ofstream fout;

int main() {
    string file, names[] = {"Tartaglia", "Zhongli", "Niguang", "Mei", "Kiana", "Jean"};
    int i, length;

    cout << "file name: ";
    cin >> file;

    cout << "file length: ";
    cin >> length;

    fout.open(file);

    for (i = 0; i < length; i++){
        if (i == rand() % length) {
            fout << "You, " << names[rand() % 6] << endl;
        } else {
            fout << names[rand() % 6] << " " << names[rand() % 6] << endl;
        }
    }

    fout.close();

    return 0;
}