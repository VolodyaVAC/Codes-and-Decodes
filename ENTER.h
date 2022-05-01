//
// Created by Mazafacker on 01.05.2022.
//

#ifndef UNTITLED1_ENTER_H
#define UNTITLED1_ENTER_H
#include "includes.h"

using namespace std;
class ENTER {
public:
    static void etf (string s)  {
        ofstream f;
        f.open("C:/Users/Mazafacker/CLionProjects/untitled1/enter_file.txt", ofstream::app);
        if (!f.is_open()) {
            cout << "Error of opening file in eof!!!";
            exit(1);
        }
        f << s << endl;
        f.close();
    }

    static void etfv(vector <int> t){
        ofstream f;
        f.open("C:/Users/Mazafacker/CLionProjects/untitled1/enter_file.txt", ofstream::app);
        if (!f.is_open()) {
            cout << "Error of opening file in eof!!!";
            exit(1);
        }
        for (int i = 0; i < t.size(); i++){
            f << t[i] << ' ';
        } f << endl;
        f.close();
    }
};


#endif //UNTITLED1_ENTER_H
