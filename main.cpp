#include "includes.h"

int main() {

    string str, *p;

    getline(cin, str); //Ввод текста из консоли

    ENTER::etf(str); // Запись строки в файл

    //CODE_ATABASH::codeAtabash(str);

    //MATRIX_CODE::matrixCode(str);

    CODE_XOR::codeXor(str);

    DE_CODE_XOR::deCodeXOR();

    return 0;
}