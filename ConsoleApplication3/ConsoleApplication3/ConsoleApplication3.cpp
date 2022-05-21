#include <iostream>
#include <string>
#include <cmath>
#include<time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите разрешённые символы: ";
    string allowed = string();
    cin >> allowed;
    cout << "Введите пароль: ";
    string password = string();
    cin >> password;
    int num = pow(allowed.size(), password.size());
    string code = string(password.size(), allowed[0]);
    int i = -1;
    int start = clock();
    while (code != password) {
        i = i + 1;
        for (int n = 1; n < code.size() + 1; n++) {
            int k = pow(allowed.size(), n);
            code = code.replace(code.size() - n, 1, 1, allowed[i % k / pow(allowed.size(), (n - 1))]);
        }
        cout << i << ", " << code << "\n";
    }
    int end = clock();
    cout << (end - start)/((double) CLOCKS_PER_SEC);
}
