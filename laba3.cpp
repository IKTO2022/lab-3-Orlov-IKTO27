#include <iostream>
#include <fstream> 
#include <windows.h>
#include <cstring>

using namespace std;

struct Bank
{
    int id = 0;
    string name;
    string surname;
    int amount_of_credits = 0;
    int balance = 0;
};

void input_struct(struct Bank* P, int n);
void output_struct(struct Bank* P, int n);
void correct(struct Bank* P, int n);
void min_account(struct Bank* P, int n);
void newFile(struct Bank* P, int n);

int main()
{
    Bank* P;
    P = new Bank[3];
    int breaker = 0;

    input_struct(P, 3);
    cout << "Welcome to the Bank OS" << endl;
    cout << "Choose the option: " << endl;
    while (true)
    {
        cout << "If you wanna to check the balance, type 1" << endl;
        cout << "If you wanna to correct the Data, type 2" << endl;
        cout << "If you wanna to find the minimal account, type 3" << endl;
        cout << "If you wanna to save the data and exit, type 4" << endl;
        cin >> breaker;
        switch (breaker)
        {
        case 1:
            output_struct(P, 3);
            cout << endl;
            break;
        case 2:
            correct(P, 3);
            cout << endl;
            break;
        case 3:
            min_account(P, 3);
            cout << endl;
            break;
        case 4:
            newFile(P, 3);
            cout << endl;
            break;
        default:
            cout << "Has typed incorrect input - " << breaker << endl;
            cout << "Please, try again";
        }
        if (breaker == 4)
        {
            break;
        }
    }
    
    cout << "Clearing the data" << endl;
    delete[] P; //очистка памяти 
    return 0;
}



void input_struct(struct Bank* P, int n) // Чтение данных из файла
{
    ifstream fin; 
    fin.open("file2.txt", ios::in);
    for (int i = 0; i < n; i++)
    {
        fin >> P[i].id;
        fin >> P[i].name;
        fin >> P[i].surname;
        fin >> P[i].amount_of_credits;
        fin >> P[i].balance;
    }
    fin.close();
}

void output_struct(struct Bank* P, int n) // Просмотр данных
{

    cout << "id\t" << "name\t" << "surname\t" << "amount_of_credits\t" << "balance" << endl;
    cout << "====================================" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << P[i].id;
        cout << "\t" << P[i].name;
        cout << "\t" << P[i].surname;
        cout << "\t" << P[i].amount_of_credits;
        cout << "\t" << P[i].balance << endl;
    }
    cout << "====================================" << endl;

}

void correct(struct Bank* P, int n) // Корректировка заданной строки
{
    int key0 = 0;
    int key = 0;
    cout << "Type 1 if you wanna correct data, otherwise 0" << endl;
    cin >> key0;
    while (key0 != 0)
    {

        if (key0 == 1)
        {
            cout << "Which line?" << endl;
            cin >> key;
            if ((key != 1) && (key != 2) && (key != 3) && (key != 4))
            {
                cout << "This line does not exist" << endl;
            }
            if ((key == 1) || (key == 2) || (key == 3) || (key == 4))
            {
                cout << "Enter changes in " << key << " line:" << endl;
                cout << "id: ";
                cin >> P[key - 1].id;
                cout << "name: ";
                cin >> P[key - 1].name;
                cout << "surname: ";
                cin >> P[key - 1].surname;
                cout << "amount_of_credits: ";
                cin >> P[key - 1].amount_of_credits;
                cout << "balance: ";
                cin >> P[key - 1].balance;
            }
        }
        cout << endl << "To get out, type 0, otherwise type 1" << endl;
        cin >> key0;
    }
}

void min_account(struct Bank* P, int n) // Рандомная операция для задания
{
    int min = P[0].balance;
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (P[i].balance < min) {
            min = P[i].balance;
            k = i;
        }
    }
    cout << "Account with the minimal balance: " << P[k].id << " " << P[k].name << " " << P[k].surname << " " << P[k].amount_of_credits << " " << min << "\n";
}

void newFile(struct Bank* P, int n)
{
    char name[20];
    cout << endl << "Enter the name of new file: ";
    cin >> name;
    strcat_s(name, ".txt");
    ofstream save;
    save.open(name);
    for (int i = 0; i < n; i++)
    {
        save << P[i].id;
        save << " " << P[i].name;
        save << " " << P[i].surname;
        save << " " << P[i].amount_of_credits;
        save << " " << P[i].balance << endl;
    }
    save.close();
}