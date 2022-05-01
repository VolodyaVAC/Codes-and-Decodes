//
// Created by Mazafacker on 01.05.2022.
//

#ifndef UNTITLED1_MATRIX_CODE_H
#define UNTITLED1_MATRIX_CODE_H
#include "includes.h"
class MATRIX_CODE{
public:
    static void matrixCode(string sp) {
        string key1, key2, res;
        int n, len, k = 0;

        len = sp.size(); //длинна строки

        if ((sqrt(len) - (int)sqrt(len)) > 0.001){
            n = sqrt(len) + 1;
        } else n = sqrt(len);

        cout << n << endl; // вывод длинны ключа

        do{ // ввод ключей
            cin >> key1 >> key2;
        } while ((key1.size() != n) and (key2.size() != n));
        char list[n+1][n+1];

        for (int i = 1; i <= n; i++){ // заполниение матрицы строкой
            for(int j = 1; j <= n; j++){
                list[i][j] = sp[k];
                k++;
            }
        }
        for (int i = 1; i <=n; i ++) list[0][i] = key1[i-1]; // заполнение 1ой строки ключом
        for (int i = 1; i <=n; i ++) list[i][0] = key2[i-1]; // заполнение 1ого столбца ключом
        for (int i = 0; i <= n; i++){ // заполнение NULL'ов пробелами
            for (int j = 0; j <= n; j++){
                (list[i][j] == NULL) ? list[i][j] = ' ' : list[i][j] = list[i][j];
            }
        }

        int vol;
        for (int i = 1; i <= n; i++){
            if ((list[0][i] >= 'A') and (list[0][i] <= 'Z')){
                vol = list[0][i] - 'A';
                list[0][i] = 'z' - vol;
            }
        }

        for (int i = 0; i <= n; i++) { //пузырьковая сортировка по первой строке
            for (int j = 0; j <= n-1; j++) {
                if (list[0][j] > list[0][j + 1]) {
                    char b;// создали дополнительную переменную
                    b = list[0][j];
                    list[0][j] = list[0][j + 1]; // меняем местами
                    list[0][j + 1] = b; // значения элементов
                    for (int k = 0; k <= n; k++){ // меняем местами столбцы под элементами
                        b = list[k][j];
                        list[k][j] = list[k][j+1];
                        list[k][j+1] = b;
                    }
                }
            }
        }

        for (int i = 0; i <= n; i++) { //пузырьковая сортировка по первому столбцу
            for (int j = 0; j <= n-1; j++) {
                if (list[j][0] > list[j+1][0]) {
                    char b;// создали дополнительную переменную
                    b = list[j][0];
                    list[j][0] = list[j][0]; // меняем местами
                    list[j][0] = b; // значения элементов
                    for (int k = 0; k <= n; k++){ // меняем местами строки рядом с элементами
                        b = list[j][k];
                        list[j][k] = list[j+1][k];
                        list[j+1][k] = b;
                    }
                }
            }
        }

        cout << endl;
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                cout << list[i][j]<< '-';
            }
            cout << endl;
        }

        char t;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                t = list[i][j];
                res.push_back(t);
            }
        }
        cout << res << endl;

        ENTER::etf(res);
    }
};
#endif //UNTITLED1_MATRIX_CODE_H
