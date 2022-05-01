//
// Created by Mazafacker on 01.05.2022.
//

#ifndef UNTITLED1_DE_MATRIX_CODE_H
#define UNTITLED1_DE_MATRIX_CODE_H
#include "includes.h"


class DE_MATRIX_CODE {
public:
    stutic void matrixDeCode(){
        string key1, key2, res, key1r, key2r, sf;

        cin >> sf >> key1 >> key2;

        key1r = key1; key2r = key2;

        for (int i = 0; i < key1.size(); i++){
            for (int j = 0; j < key1.size(); j++){
                if (key1r[j] > key1r[j+1]){
                    swap(key1r[j], key1r[j+1]);
                }
            }
        }

        for (int i = 0; i < key2.size(); i++){
            for (int j = 0; j < key2.size(); j++){
                if (key2r[j] > key2r[j+1]){
                    swap(key2r[j], key2r[j+1]);
                }
            }
        }

        int n, len, k = 0;

        len = sf.size(); //длинна строки

        if ((sqrt(len) - (int)sqrt(len)) > 0.001){
            n = sqrt(len) + 1;
        } else n = sqrt(len);
        char list[n+1][n+1];

        for (int i = 1; i <= n; i++){ // заполниение матрицы строкой
            for(int j = 1; j <= n; j++){
                list[i][j] = sf[k];
                k++;
            }
        }
        for (int i = 1; i <=n; i ++) list[0][i] = key1r[i-1]; // заполнение 1ой строки ключом
        for (int i = 1; i <=n; i ++) list[i][0] = key2r[i-1]; // заполнение 1ого столбца ключом
        for (int i = 0; i <= n; i++){ // заполнение NULL'ов пробелами
            for (int j = 0; j <= n; j++){
                (list[i][j] == NULL) ? list[i][j] = ' ' : list[i][j] = list[i][j];
            }
        }

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n; j++){
                cout << list[i][j]<< '-';
            }
            cout << endl;
        }
    }//закончить матричную декодировку и найти ошибку в кодировке
};


#endif //UNTITLED1_DE_MATRIX_CODE_H
