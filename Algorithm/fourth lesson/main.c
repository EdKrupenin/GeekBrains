#include <stdio.h>
#include <stdlib.h>

/// Функция которая сразу в консоль пишет результат перевода
/// \param number
/// \return
int PrintDecToBin(int number){
    if (number == 1 || number == 0) printf("%d", number);
    else{
        PrintDecToBin(number/2);
        printf("%d", number % 2);
    }
}

/*-------------------------------------------*/

/// Функция для возвидения в степень с помощью цикла
/// \param number число
/// \param pow степень
/// \return ответ
int PowDigits(int number, int pow){
    int ans = number;
    switch (pow) {
        case 0 : return  1;
        case 1 : return  number;
        default:
            while ((pow--) > 1) ans*=number;
    }
    return ans;
}

/*------------------------------------------*/
/// Рекурсивное возведение в степень
/// \param number число
/// \param pow степень
/// \return ответ
int PowDigitsRec(int number, int pow){
    switch (pow) {
        case 0 : return  1;
        case 1 : return  number;
        default: return number * PowDigitsRec(number,(--pow));
    }
}

/*----------------------------------------------*/

/// ВОзведение в степень с учетом четности степени
/// \param number число
/// \param pow степень
/// \return ответ
int PowDigitsPropertyRec(int number, int pow){
    int c;
    switch (pow) {
        case 0 : return  1;
        case 1 : return  number;
        default:
            if (pow % 2 == 0){
                c =  PowDigitsPropertyRec(number,(pow/2));
                return c*c;
            }
            else
                return number*PowDigitsPropertyRec(number,(--pow));
    }
}

/*-----------------------------------------------*/

#define WIDTH 8
#define HEIGHT 8

int board[HEIGHT][WIDTH];

///обнуление и заполнение препядствиями
void annull(){
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (i == j && i != 0 && i != (HEIGHT-1))
            board[i][j] = rand() % 2;
            else
            board[i][j] = 0;
        }
    }
    board[0][1] = 1;
    board[0][4] = 1;
}

///Печать поля в консоли
void printBoard(){
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%3d",board[i][j] );
        }
        printf("\n");
    }
}

/// Функция для поиска ходов с препядствиями
/// \param x - координата
/// \param y - координата
/// \return кол-во ходов
int roots(int x, int y){
    if (board[x][y] == 1) return 0; // проверка на препядствия, т.к. массив глобальный передавать не надо, иначе передал
    // бы с помощью указателя *
    if (x == 0 && y == 0) return 0;
    else if (x == 0) {
            if (roots(x, y - 1)==0  && y!=1) return 0;
            return 1;
        } else if (y == 0) {
            if (roots(x-1, y)==0  && x!=1) return 0;
            return 1;
        }
        return roots(x, y - 1) + roots(x - 1, y);


       /*else{
        * if(x==0 && y==0) return 0; // если к клетке не подойти сверху и слева то пути нет...
        else if(x==0)
            {
                if(roots(x,y-1)==0 && board[x][y-1] == 0 && y==1) return 0;
                return 1;
            } else
                {
                    if (y==0)
                        if(roots(x-1,y)==0 && board[x][y-1] == 0 && x==1) return 0;
                    return 1;
                }*/
    //}
}

void kingChess(){
    annull(); // задаем препядствия с помощью рандома
    printBoard(); // выводим поле что бы было видно что препядтсвия есть
    //рекурсивно вызываю roots
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%5d",roots(i,j) );
        }
        printf("\n");
    }
}
/*--------------------------------------------------------*/

int main(const  int argc, const char** argv) {

    PrintDecToBin(30);
    printf("%d \n", PowDigits(2,5));
    printf("%d \n", PowDigitsRec(2,4));
    printf("%d \n", PowDigitsPropertyRec(2,5));
    kingChess();
    return 0;
}
