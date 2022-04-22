#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

void etf(string s); // функция enter to file
string eff(); // функция enter from file
void codeZeroAndOne(string str); // шифровка нулями и еденицами
void codeAtabash(string st); // шифр Атабаш (сделана)
void matrixCode(string sp); // Матричная шифровка
void matrixDeCode(string sf); //Матричная Дешифровка

int main() {

    string str;

    getline(cin, str); //Ввод текста из консоли

    etf(str); // Запись строки в файл

    //zeroAndOne(str); // использование шифра нулями и еденицами

    //shifrAtabash(str); // использование шифра Атабаша

    matrixCode(str);

    eff();

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

string eff(){

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

void matrixCode(string sp) {
    string key1, key2, res;
    int n, len, k = 0;


    len = sp.size(); //длинна строки

    if ((sqrt(len) - (int)sqrt(len)) > 0.001){
        n = sqrt(len) + 1;
    } else n = sqrt(len);
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
    cout << res;

    etf(res);
}





