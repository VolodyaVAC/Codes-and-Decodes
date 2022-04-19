#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

void etf(string s); // функция enter to file
void zeroAndOne(string str); // шифровка нулями и еденицами
void shifrAtabash(string st); // шифр Атабаш
void matrixShifr(string sp); // Матричная шифровка

int main() {

    string str;

    getline(cin, str); //Ввод текста из консоли

    etf(str); // Запись строки в файл

    //zeroAndOne(str); // использование шифра нулями и еденицами

    //shifrAtabash(str); // использование шифра Атабаша

    matrixShifr(str);

    return 0;
}

void etf (string s)  {
    ofstream f;
    f.open("C:/Users/Mazafacker/CLionProjects/untitled1/enter_file.txt", ofstream::app);
    if (!f.is_open()) {
        cout << "Error of opening file!!!";
        exit(1);
    }
    f << s << endl;
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

void matrixShifr(string sp) {
    string key1, key2;
    int n, len, k = 0;
    char ch, chn;


    len = sp.size(); //длинна строки

    if ((sqrt(len) - (int)sqrt(len)) > 0.001){
        n = sqrt(len) + 1;
    } else n = sqrt(len);
    cout << "Enter two keys with lenght " << n << " : " << endl;
    cin >> key1 >> key2;
    char list[n+1][n+1];


    for (int i = 1; i <= n; i++){ // заполниение матрицы строкой
        for(int j = 1; j <= n; j++){
            list[i][j] = sp[k];
            k++;
        }
    }
    for (int i = 1; i <=n; i ++) list[0][i] = key1[i-1]; // заполнение 1ой строки ключом
    for (int i = 1; i <=n; i ++) list[i][0] = key2[i-1]; // заполнение 1ого столбца ключом
    list[0][0] = NULL;

    // доделать сортировку, вывод
}






