//
// Created by Mazafacker on 01.05.2022.
//

#ifndef UNTITLED1_DE_CODE_XOR_H
#define UNTITLED1_DE_CODE_XOR_H
#include "includes.h"

class DE_CODE_XOR{
public:
    static void deCodeXOR(){
        vector <int> res;
        int n, l;
        string sg, key;
        char ch, c, h;
        cin >> l;
        for (int i = 0; i < l; i++){
            cin >> n;
            res.push_back(n);
        }
        do{
            cin >> key;
        }while (key.size() != l);
        for (int i = 0; i < l; i++){
            c = key[i];
            h = (char)res[i];
            ch = c ^ h;
            sg.push_back(ch);
        }
        cout << sg;
};

#endif //UNTITLED1_DE_CODE_ATABASH_H