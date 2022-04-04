#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

#define A 65 // номер A в таблице ASCII
#define Z 90 // номер Z в таблице ASCII
#define AS 97 // номер a в таблице ASCII
#define ZS 122 // номер z в таблице ASCII
#define R 25 // количество символов в латинском алфавите

void etf(string str); // функция enter to file
void zeroAndOne(string str); // шифровка нулями и еденицами
void shifrAtabash(string st); // шифр Атабаш


int main() {
    string str;
    int l;

    getline(cin, str); //Ввод текста из консоли

    etf(str);

    shifrAtabash(str);

    return 0;
}

void etf(string s) {
    ofstream f;
    f.open("C:/Users/Mazafacker/CLionProjects/untitled1/enter_file.txt", ofstream::app);
    if (!f.is_open()) {
        cout << "Error of opening file!!!";
    }
    f << s << "\n";
    f.close();
}

void zeroAndOne(string sz) {
    string strc, l, tr, *e;
    int val, r;

    val = int(sz[0]);
    for(int j = 0; j < 8; j++){
        (val%2) ? l[j] = '1' : l[j] = '0';
    }
    reverse(l.begin(), l.end()); //работа с первым симвалом

    for (int i = 1; i < sz.length(); i++) { //работа с остальными символами
        val = int(sz[i]);
        for(int j = 0; j < 8; j++){
            (val%2) ? l[j] = '1' : l[j] = '0';
        }
        reverse(l.begin(), l.end()); //получение двоичного кода символа

    } // закончить
}

void shifrAtabash(string st){
    string res; // результат кодировки
    int val, n;

    for (int i = 0; i < st.size(); i++) { // обработка строки посимвольно
        n = int(st[i]);
        if ((n <= Z) and (n >= A)){
            val = n - A; //разница между номером символа и началом алфавита
            res[i] = int(Z - n);
        } else if(((n <= ZS) and (n >= AS))){
            val = n - AS; //разница между номером символа и началом алфавита
            res[i] = int(ZS - n);
        } else {
            res[i] = st[i];
        }
    }
    etf(res);
}


