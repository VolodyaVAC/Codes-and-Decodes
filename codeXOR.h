//
// Created by Mazafacker on 01.05.2022.
//

#ifndef UNTITLED1_CODEXOR_H
#define UNTITLED1_CODEXOR_H
#include "includes.h"

using namespace std;
class codeXOR{
public:
    static void codeXor(string sx){
        bool s, k;
        string key;
        vector <int> res;
        char ch, c, h;
        int n;

        cout << sx.size() << endl; // ввод ключа
        do{
            cin >> key;
        }while (key.size() != sx.size());

        for (int i = 0; i < sx.size(); i++){

            c = sx[i]; h = key[i];
            ch = h ^ c;
            n = (int)ch;
            res.push_back(n);
        }

        etfv(res);
    }
};

#endif //UNTITLED1_CODEXOR_H
