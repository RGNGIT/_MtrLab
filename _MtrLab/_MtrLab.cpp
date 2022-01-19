#include <iostream>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "Введите размер матрицы:\n";
    cin >> n;
    // Инициализация матрицы
    int ** Mtr = new int * [n];
    for (int i = 0; i < n; i++) {
        Mtr[i] = new int[n];
    }
    // Забиваем данными
    cout << "Введите элементы:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> Mtr[i][j];
        }
    }
    bool check = true;
    int sum = 0;
    cout << "Суммы строк без отрицательных элементов:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Mtr[i][j] < 0) {
                check = false;
                break;
            }
            else {
                sum += Mtr[i][j];
            }
        }
        if (check) {
            cout << "Сумма " << (i + 1) << "-й строки: " << sum << endl;
        }
        sum = 0;
        check = true;
    }
    vector<int> sumVec;
    int sumToAdd = 0;
    cout << "Минимум среди сумм диагоналей:\n";
    for (int k = n, ii; k > 0; k--) {
        for (int i = k - 1; i < k; i++) {
            ii = i;
            for (int j = 0; j < n - i; j++) {
                sumToAdd += Mtr[ii][j];
                cout << Mtr[ii][j] << " ";
                ii++;
            }
            cout << "Сумма: " << sumToAdd << endl;
            sumVec.push_back(sumToAdd);
            sumToAdd = 0;
        }
    }
    sumToAdd = 0;
    for (int k = n, ii; k > 1; k--) {
        for (int i = k - 1; i < k; i++) {
            ii = i;
            for (int j = 0; j < n - i; j++) {
                sumToAdd += Mtr[j][ii];
                cout << Mtr[j][ii] << " ";
                ii++;
            }
            cout << "Сумма: " << sumToAdd << endl;
            sumVec.push_back(sumToAdd);
            sumToAdd = 0;
        }
    }
    int min = sumVec[0];
    for (int i = 1; i < sumVec.size(); i++) {
        if (sumVec[i - 1] < min) {
            min = sumVec[i - 1];
        }
    }
    cout << "Минимальная сумма среди диагоналей: " << min;
}