//
// Created by Mazafacker on 01.05.2022.
//


#include "includes.h"

class DE_CODE_ATABASH{
public:
    static void deCodeAtabash(){
        string sh, res; // результат кодировки
        char ch;
        char val, n, t;
        cin >> sh;

        for (int i = 0; i < sh.size(); i++) { // обработка строки посимвольно
            ch = sh[i];
            n = ch;
            if ((n <= 'Z') and (n >= 'A')){
                val = 'Z' - n; //разница между номером символа и началом алфавита
                t = 'A' + val;
                res.push_back(t);
            } else{
                if(((n <= 'z') and (n >= 'a'))){
                    val = 'z' - n; //разница между номером символа и началом алфавита
                    t = 'a' + val;
                    res.push_back(t);
                } else {
                    char t = sh[i];
                    res.push_back(t);
                }
            }
        }
        etf(res);
    }
};

