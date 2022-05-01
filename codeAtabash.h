//
// Created by Mazafacker on 01.05.2022.
//

#ifndef UNTITLED1_CODEATABASH_H
#define UNTITLED1_CODEATABASH_H
#include "includes.h"

class codeAtabash {
public:
    void codeAtabach(string st){
        string res; // результат кодировки
        char ch;
        char val, n, t;

        for (int i = 0; i < st.size(); i++) { // обработка строки посимвольно
            ch = st[i];
            n = ch;
            if ((n <= 'Z') and (n >= 'A')){
                val = n - 'A'; //разница между номером символа и началом алфавита
                t = 'Z' - val;
                res.push_back(t);
            } else{
                if(((n <= 'z') and (n >= 'a'))){
                    val = n - 'a'; //разница между номером символа и началом алфавита
                    t = 'z' - val;
                    res.push_back(t);
                } else {
                    char t = st[i];
                    res.push_back(t);
                }
            }
        }
        etf(res);
    }
};


#endif //UNTITLED1_CODEATABASH_H
