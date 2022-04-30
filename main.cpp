#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<vector>
using namespace std;

void etf(string s); // функция enter to file
void codeAtabash(string st); // шифр Атабаш (сделана)
void deCodeAtabash(); // Дешифратор шифра Атабаша (сделано)
void matrixCode(string sp); // Матричная шифровка (вроде сделана)
void matrixDeCode(); //Матричная Дешифровка
void codeXOR(string sx);
void deCodeXOR();

int main() {

    string str, *p;

    getline(cin, str); //Ввод текста из консоли

    etf(str); // Запись строки в файл

    //codeAtabash(str);

    //matrixCode(str);

    codeXOR(str);

    //eff();

    return 0;
}

void etf (string s)  {
    ofstream f;
    f.open("C:/Users/Mazafacker/CLionProjects/untitled1/enter_file.txt", ofstream::app);
    if (!f.is_open()) {
        cout << "Error of opening file in eof!!!";
        exit(1);
    }
    f << s << endl;
    f.close();
}

void codeAtabash(string st){
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

    etf(res);
}

void deCodeAtabash(){
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

void matrixDeCode(){
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
} //закончить матричную декодировку и найти ошибку в кодировке

void codeXOR(string sx){
    bool s, k;
    string key;
    vector <int> res;
    int n;
    cout << sx.size() << endl; // ввод ключа
    do{
        cin >> key;
    }while (key.size() != sx.size());

    for (int i = 0; i < sx.size(); i++){
        char ch, c, h;
        c = sx[i]; h = key[i];
        ch = c ^ h;
        n = (int)ch;
        res.push_back(n);
    }

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
}

void deCodeXOR(){
    vector <int> res;
    int n;
    string sg;

    for (int i = 0; i < n; i++){
        cin >> n;
        res.push_back(n);
    }


}



