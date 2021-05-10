#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "account.h"
#include "render.h"
#include "function.h"
// #include "banking.h"
using namespace std;

vector<string> listData;
int denomination[] = {1000, 2000, 5000, 10000, 20000,
                      50000, 100000, 200000, 500000};
int bankMoney[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int main()
{
    // getBankMoney(bankMoney);
    function(listData, denomination, bankMoney);
    // cout << convertNumber(15);
    
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << bankMoney[i] << endl;
    // }
}
