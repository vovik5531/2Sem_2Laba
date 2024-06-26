#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include"Sequence.h"
#include"ArraySequence.h"
#include"ListSequence.h"
#include<string>
#include<iostream>
#include<fstream>
#define arrMenu "Связный массив\n    1. Копировать элементы из массива\n    2. Получить элемент по индексу\n    3. Создать массив заданной длины\n    4. Получить первый элемент массива\n    5. Получить последний элемент массива\n    6. Получить длину массива\n    7. Задать элемент по индексу (Mutable)\n    8. Задать элемент по индексу (Immutable)\n    9. Добавить элемент в конец массива (Mutable)\n    10. Добавить элемент в конец массива (Immutable)\n    11. Добавить элемент в начало массива (Mutable)\n    12. Добавить элемент в начало массива (Immutable)\n    13. Конкатенация двух массивов (Mutable)\n    14. Конкатенация двух массивов (Immutable)\n    15. Вставить элемент в заданную позицию (Mutable)\n    16. Вставить элемент в заданную позицию (Immutable)\n    17. Вывести массив\n    18. Выйти\n"
#define lstMenu "Связный список\n    1. Копировать элементы из списка\n    2. Получить элемент по индексу\n    3. Создать список заданной длины\n    4. Получить первый элемент списка\n    5. Получить последний элемент списка\n    6. Получить длину списка\n    7. Задать элемент по индексу (Mutable)\n    8. Задать элемент по индексу (Immutable)\n    9. Добавить элемент в конец списка (Mutable)\n    10. Добавить элемент в конец списка (Immutable)\n    11. Добавить элемент в начало списка (Mutable)\n    12. Добавить элемент в начало списка (Immutable)\n    13. Конкатенация двух списков (Mutable)\n    14. Конкатенация двух списков (Immutable)\n    15. Вставить элемент в заданную позицию (Mutable)\n    16. Вставить элемент в заданную позицию (Immutable)\n    17. Вывести список\n    18. Выйти\n"
#define tp "Выберите тип данных\n    1. Целые числа\n    2. Вещественные числа\n    3. Строки\n    4. Назад\n"
#define strCrt "Выберите структуру\n    1. Создать динамический массив\n    2. Создать двусвязный список\n    3. Назад\n"
#define MENU "ГЛАВНОЕ МЕНЮ\n    1. Создать структуру\n    2. Запуск тестов\n    3. Выход\n"
using namespace std;

void printFromFile(const string& fileName) {
    ifstream fin(fileName);
    string strh;
    while(!fin.eof()){
        getline(fin, strh);
        cout << strh;
        cout << "\n";
    }
    fin.close();
}

int getUserChoice(int mn, int mx) {
    cout << " >>> ";
    int choice; 
    while(1)
        {
        cin >> choice;
        if (choice < mn || choice > mx) cout << "Unknown command!\n";
        else break;}
    return choice;
}

void menu() {
    std::cout << MENU;
}

void structCreate() {
    cout << strCrt;
}

void typeCreate() {
    cout << tp;
}

void mainLoop() {
    Sequence<int>* intSeq;
    Sequence<double>* doubleSeq;
    Sequence<string>* stringSeq;

    Sequence<int>* intSeqC;
    Sequence<double>* doubleSeqC;
    Sequence<string>* stringSeqC;

    int type, structSeq;

    while(1) {
        menu();
        int userChoice = getUserChoice(1, 3);
        switch (userChoice)
        {
        case 1:
            typeCreate();
            userChoice = getUserChoice(1, 4);
            if (userChoice == 4) break;
            type = userChoice;
            structCreate();
            userChoice = getUserChoice(1, 3);
            if (userChoice == 3) break;
            structSeq = userChoice;
            typeCreate();
            if (type == 1) {
                if (structSeq == 1) {
                    intSeq = new ArraySequence<int>;
                }
                if (structSeq == 2) {
                    intSeq = new ListSequence<int>;
                }
            }
            if (type == 2) {
                if (structSeq == 1) {
                    doubleSeq = new ArraySequence<double>;
                }
                if (structSeq == 2) {
                    doubleSeq = new ListSequence<double>;
                }
            }
            if (type == 2) {
                if (structSeq == 1) {
                    stringSeq = new ArraySequence<string>;
                }
                if (structSeq == 2) {
                    stringSeq = new ListSequence<string>;
                }
            }
            switch (structSeq)
            {
            case 1:
                while(userChoice != 18) {
                    cout << arrMenu;
                    userChoice = getUserChoice(1, 18);
                    switch (userChoice)
                    {
                    case 1:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина массива: ";
                            size_t arr_length; cin >> arr_length;
                            cout << " >>> Введите массив: ";
                            for (size_t i = 0; i != arr_length; ++i) {
                                int tmp;
                                cin >> tmp;
                                intSeq->Append(tmp);
                            }
                            break;
                        case 2:
                            cout << " >>> Длина массива: ";
                            size_t arr_length1; cin >> arr_length1;
                            cout << " >>> Введите массив: ";
                            for (size_t i = 0; i != arr_length1; ++i) {
                                double tmp1;
                                cin >> tmp1;
                                doubleSeq->Append(tmp1);
                            }
                            break;
                        case 3:
                            cout << " >>> Длина массива: ";
                            size_t arr_length2; cin >> arr_length2;
                            cout << " >>> Введите массив: ";
                            stringSeq = new ArraySequence<string>(arr_length2);
                            for (size_t i = 0; i != arr_length2; ++i) {
                                string tmp2;
                                cin >> tmp2;
                                stringSeq->Set(i, tmp2);
                            }
                            break;
                        }
                        break;
                    case 2:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            cout << " >>> " << intSeq->Get(ind - 1);
                            cout << endl;
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            cout << " >>> " << doubleSeq->Get(ind2 - 1);
                            cout << endl;
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind3; cin >> ind3;
                            cout << " >>> " << stringSeq->Get(ind3 - 1);
                            cout << endl;
                            break;
                        }
                        break;
                    case 3:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина массива: ";
                            size_t arr_length; cin >> arr_length;
                            for (size_t i = 0; i != arr_length; ++i) {
                                intSeq->Append(0);
                            }
                            break;
                        case 2:
                            cout << " >>> Длина массива: ";
                            size_t arr_length1; cin >> arr_length1;
                            for (size_t i = 0; i != arr_length1; ++i) {
                                doubleSeq->Append(0);
                            }
                            break;
                        case 3:
                            cout << " >>> Длина массива: ";
                            size_t arr_length2; cin >> arr_length2;
                            for (size_t i = 0; i != arr_length2; ++i) {
                                stringSeq->Append("");
                            }
                            break;
                        }
                        break;
                    case 5:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> " << intSeq->GetLast();
                            break;
                        case 2:
                            cout << " >>> " << doubleSeq->GetLast();
                            break;
                        case 3:
                            cout << " >>> " << stringSeq->GetLast();
                            break;
                        }
                        break;
                    case 4:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> " << intSeq->GetFirst();
                            break;
                        case 2:
                            cout << " >>> " << doubleSeq->GetFirst();
                            break;
                        case 3:
                            cout << " >>> " << stringSeq->GetFirst();
                            break;
                        }
                        break;
                    case 6:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> " << intSeq->GetLength();
                            break;
                        case 2:
                            cout << " >>> " << doubleSeq->GetLength();
                            break;
                        case 3:
                            cout << " >>> " << stringSeq->GetLength();
                            break;
                        }
                        break;
                    case 7:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Set(ind, tmp);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Set(ind1, tmp1);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Set(ind2, tmpss);
                            break;
                        }
                        break;
                    case 8:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Set(ind, tmp);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            doubleSeq->Set(ind, tmp);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Set(ind2, tmpss);
                            break;
                        }
                        break;
                    case 9:
                        switch (type)
                        {
                        case 1:
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Append(tmp);
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Append(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Append(tmpss);
                            break;
                        }
                        break;
                    case 10:
                        switch (type)
                        {
                        case 1:
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Append(tmp);
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Append(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Append(tmpss);
                            break;
                        }
                        break;
                    case 12:
                        switch (type)
                        {
                        case 1:
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Prepend(tmp);
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Prepend(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Prepend(tmpss);
                            break;
                        }
                        break;
                    case 13:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина второго массива: ";
                            size_t arr_length; cin >> arr_length;
                            cout << " >>> Введите массив: ";
                            intSeqC = new ArraySequence<int>(arr_length);
                            for (size_t i = 0; i != arr_length; ++i) {
                                int tmp;
                                cin >> tmp;
                                intSeqC->Set(i, tmp);
                            }
                            intSeq->Concat(intSeqC);
                            break;
                        case 2:
                            cout << " >>> Длина второго массива: ";
                            size_t arr_length1; cin >> arr_length1;
                            cout << " >>> Введите массив: ";
                            doubleSeqC = new ArraySequence<double>(arr_length1);
                            for (size_t i = 0; i != arr_length1; ++i) {
                                double tmp1;
                                cin >> tmp1;
                                doubleSeqC->Set(i, tmp1);
                            }
                            doubleSeq->Concat(doubleSeqC);
                            break;
                        case 3:
                            cout << " >>> Длина второго массива: ";
                            size_t arr_length2; cin >> arr_length2;
                            cout << " >>> Введите массив: ";
                            stringSeqC = new ArraySequence<string>(arr_length2);
                            for (size_t i = 0; i != arr_length2; ++i) {
                                string tmp2;
                                cin >> tmp2;
                                stringSeqC->Set(i, tmp2);
                            }
                            stringSeq->Concat(stringSeqC);
                            break;
                        }
                        break;
                    case 14:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина второго массива: ";
                            size_t arr_length; cin >> arr_length;
                            cout << " >>> Введите массив: ";
                            intSeqC = new ArraySequence<int>;
                            for (size_t i = 0; i != arr_length; ++i) {
                                int tmp;
                                cin >> tmp;
                                intSeqC->Append(tmp);
                            }
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Prepend(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Prepend(tmpss);
                            break;
                        }
                        break;
                    case 15:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->InsertAt(tmp, ind);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->InsertAt(tmp1, ind1);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmp2;
                            cout << " >>> Значение: ";
                            cin >> tmp2;
                            stringSeq->InsertAt(tmp2, ind2);
                            break;
                        }
                        break;
                    case 16:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->InsertAt(tmp, ind);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->InsertAt(tmp1, ind1);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmp2;
                            cout << " >>> Значение: ";
                            cin >> tmp2;
                            stringSeq->InsertAt(tmp2, ind2);
                            break;
                        }
                        break;
                    case 17:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> массив: ";
                            for (size_t i = 0; i != intSeq->GetLength(); ++i) {
                                cout << intSeq->Get(i) << " ";
                            }
                            cout << endl;
                            break;
                        case 2:
                            cout << " >>> массив: ";
                            for (size_t i = 0; i != doubleSeq->GetLength(); ++i) {
                                cout << doubleSeq->Get(i) << " ";
                            }
                            cout << endl;
                            break;
                        case 3:
                            cout << " >>> массив: ";
                            for (size_t i = 0; i != stringSeq->GetLength(); ++i) {
                                cout << stringSeq->Get(i) << " ";
                            }
                            cout << endl;
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 2:
                while(userChoice != 18) {
                    cout << lstMenu;
                    userChoice = getUserChoice(1, 18);
                    switch (userChoice)
                    {
                    case 1:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина списка: ";
                            size_t arr_length; cin >> arr_length;
                            cout << " >>> Введите список: ";
                            for (size_t i = 0; i != arr_length; ++i) {
                                int tmp;
                                cin >> tmp;
                                intSeq->Append(tmp);
                            }
                            break;
                        case 2:
                            cout << " >>> Длина списка: ";
                            size_t arr_length1; cin >> arr_length1;
                            cout << " >>> Введите список: ";
                            for (size_t i = 0; i != arr_length1; ++i) {
                                double tmp1;
                                cin >> tmp1;
                                doubleSeq->Append(tmp1);
                            }
                            break;
                        case 3:
                            cout << " >>> Длина списка: ";
                            size_t arr_length2; cin >> arr_length2;
                            cout << " >>> Введите список: ";
                            stringSeq = new ListSequence<string>(arr_length2);
                            for (size_t i = 0; i != arr_length2; ++i) {
                                string tmp2;
                                cin >> tmp2;
                                stringSeq->Set(i, tmp2);
                            }
                            break;
                        }
                        break;
                    case 2:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            cout << " >>> " << intSeq->Get(ind - 1);
                            cout << endl;
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            cout << " >>> " << doubleSeq->Get(ind2 - 1);
                            cout << endl;
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind3; cin >> ind3;
                            cout << " >>> " << stringSeq->Get(ind3 - 1);
                            cout << endl;
                            break;
                        }
                        break;
                    case 3:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина списка: ";
                            size_t arr_length; cin >> arr_length;
                            for (size_t i = 0; i != arr_length; ++i) {
                                intSeq->Append(0);
                            }
                            break;
                        case 2:
                            cout << " >>> Длина списка: ";
                            size_t arr_length1; cin >> arr_length1;
                            for (size_t i = 0; i != arr_length1; ++i) {
                                doubleSeq->Append(0);
                            }
                            break;
                        case 3:
                            cout << " >>> Длина списка: ";
                            size_t arr_length2; cin >> arr_length2;
                            for (size_t i = 0; i != arr_length2; ++i) {
                                stringSeq->Append("");
                            }
                            break;
                        }
                        break;
                    case 5:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> " << intSeq->GetLast();
                            break;
                        case 2:
                            cout << " >>> " << doubleSeq->GetLast();
                            break;
                        case 3:
                            cout << " >>> " << stringSeq->GetLast();
                            break;
                        }
                        break;
                    case 4:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> " << intSeq->GetFirst();
                            break;
                        case 2:
                            cout << " >>> " << doubleSeq->GetFirst();
                            break;
                        case 3:
                            cout << " >>> " << stringSeq->GetFirst();
                            break;
                        }
                        break;
                    case 6:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> " << intSeq->GetLength();
                            break;
                        case 2:
                            cout << " >>> " << doubleSeq->GetLength();
                            break;
                        case 3:
                            cout << " >>> " << stringSeq->GetLength();
                            break;
                        }
                        break;
                    case 7:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Set(ind, tmp);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Set(ind1, tmp1);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Set(ind2, tmpss);
                            break;
                        }
                        break;
                    case 8:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Set(ind, tmp);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            doubleSeq->Set(ind, tmp);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Set(ind2, tmpss);
                            break;
                        }
                        break;
                    case 9:
                        switch (type)
                        {
                        case 1:
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Append(tmp);
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Append(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Append(tmpss);
                            break;
                        }
                        break;
                    case 10:
                        switch (type)
                        {
                        case 1:
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Append(tmp);
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Append(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Append(tmpss);
                            break;
                        }
                        break;
                    case 12:
                        switch (type)
                        {
                        case 1:
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->Prepend(tmp);
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Prepend(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Prepend(tmpss);
                            break;
                        }
                        break;
                    case 13:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина второго списка: ";
                            size_t arr_length; cin >> arr_length;
                            cout << " >>> Введите список: ";
                            intSeqC = new ListSequence<int>(arr_length);
                            for (size_t i = 0; i != arr_length; ++i) {
                                int tmp;
                                cin >> tmp;
                                intSeqC->Set(i, tmp);
                            }
                            intSeq->Concat(intSeqC);
                            break;
                        case 2:
                            cout << " >>> Длина второго списка: ";
                            size_t arr_length1; cin >> arr_length1;
                            cout << " >>> Введите список: ";
                            doubleSeqC = new ListSequence<double>(arr_length1);
                            for (size_t i = 0; i != arr_length1; ++i) {
                                double tmp1;
                                cin >> tmp1;
                                doubleSeqC->Set(i, tmp1);
                            }
                            doubleSeq->Concat(doubleSeqC);
                            break;
                        case 3:
                            cout << " >>> Длина второго списка: ";
                            size_t arr_length2; cin >> arr_length2;
                            cout << " >>> Введите список: ";
                            stringSeqC = new ListSequence<string>(arr_length2);
                            for (size_t i = 0; i != arr_length2; ++i) {
                                string tmp2;
                                cin >> tmp2;
                                stringSeqC->Set(i, tmp2);
                            }
                            stringSeq->Concat(stringSeqC);
                            break;
                        }
                        break;
                    case 14:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Длина второго списка: ";
                            size_t arr_length; cin >> arr_length;
                            cout << " >>> Введите список: ";
                            intSeqC = new ListSequence<int>;
                            for (size_t i = 0; i != arr_length; ++i) {
                                int tmp;
                                cin >> tmp;
                                intSeqC->Append(tmp);
                            }
                            break;
                        case 2:
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->Prepend(tmp1);
                            break;
                        case 3:
                            string tmpss;
                            cout << " >>> Значение: ";
                            cin >> tmpss;
                            stringSeq->Prepend(tmpss);
                            break;
                        }
                        break;
                    case 15:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->InsertAt(tmp, ind);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->InsertAt(tmp1, ind1);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmp2;
                            cout << " >>> Значение: ";
                            cin >> tmp2;
                            stringSeq->InsertAt(tmp2, ind2);
                            break;
                        }
                        break;
                    case 16:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> Индекс: ";
                            size_t ind; cin >> ind;
                            int tmp;
                            cout << " >>> Значение: ";
                            cin >> tmp;
                            intSeq->InsertAt(tmp, ind);
                            break;
                        case 2:
                            cout << " >>> Индекс: ";
                            size_t ind1; cin >> ind1;
                            double tmp1;
                            cout << " >>> Значение: ";
                            cin >> tmp1;
                            doubleSeq->InsertAt(tmp1, ind1);
                            break;
                        case 3:
                            cout << " >>> Индекс: ";
                            size_t ind2; cin >> ind2;
                            string tmp2;
                            cout << " >>> Значение: ";
                            cin >> tmp2;
                            stringSeq->InsertAt(tmp2, ind2);
                            break;
                        }
                        break;
                    case 17:
                        switch (type)
                        {
                        case 1:
                            cout << " >>> список: ";
                            for (size_t i = 0; i != intSeq->GetLength(); ++i) {
                                cout << intSeq->Get(i) << " ";
                            }
                            cout << endl;
                            break;
                        case 2:
                            cout << " >>> список: ";
                            for (size_t i = 0; i != doubleSeq->GetLength(); ++i) {
                                cout << doubleSeq->Get(i) << " ";
                            }
                            cout << endl;
                            break;
                        case 3:
                            cout << " >>> список: ";
                            for (size_t i = 0; i != stringSeq->GetLength(); ++i) {
                                cout << stringSeq->Get(i) << " ";
                            }
                            cout << endl;
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                }
                break;
            }
            break;
        case 2:
            //testsLoop();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << " >>> Неправильная команда!\n";
            break;
        }
    }
}






#endif /* USERINTERFACE_H */
