#include "Header.h"

int main() {
    int n, num1, num2, num_obj1, num_obj2;
    char symbol;
    cin >> n;
    cin.unsetf(ios::dec); // Отключение флага вывода/вывода
    cin.setf(ios::hex); // Установить флаг ввода/вывода
    vector<Hex> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> num1 >> num2;
        mas[i] = Hex(num1, num2);
    }
    while (cin.get() != EOF) {
        cin >> num_obj1 >> symbol >> num_obj2;
        if (symbol == '&') {
            mas[num_obj1 - 1] &= mas[num_obj2-1];
        }
        else if (symbol == '|') {
            mas[num_obj1 - 1] |= mas[num_obj2 - 1];
        }
    }
    cout.unsetf(ios::dec);
    cout.setf(ios::hex | ios::uppercase);
    cout.fill('0');
    cout.width(2);
    cout << mas[num_obj1 - 1].getId();
}