#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "render.h"
using namespace std;

class Account
{
    string fullName, id, password;
    long long balance;
    int wrongTime;

public:
    Account(string _fullName, string _id, string _password, long long _balance, long long _wrongTime); // hàm khởi tạo mặc định Data khách hàng
};
void getListData(vector<string> &listData, int &accountNumber);
void updateListData(vector<string> &listData, int &accountNumber);
string convertNumber(int number);
long long convertStringToNumber(const string &s);
bool compare2string(const string &a, const string &b);
bool checkIDAppear(const string &ID, vector<string> &listData);
long long getAddressCustomer(const string &ID, vector<string> &listData);
long long getCurrentBalance(const string &ID, vector<string> &listData);
bool checkPassword(const string &ID, const string &InputedPassword, vector<string> &listData);
bool checkCondition(const string &ID, vector<string> &listData);
string getCorrectPassword(const string &ID, vector<string> &listData);
int getWrongTime(const string &ID, vector<string> &listData);
void updateWrongTime(const string &ID, vector<string> &listData, int &newWrongTime, int &accountNumber);
void setBankBalance(vector<string> &listData, const string &ID, const long long &Balance);
void getBankMoney(int *bankMoney);
void updateBankMoney(int *bankMoney);
void bankingFunction(const char &selectFunction, string &ID,
                     int *denomination, int *bankMoney, vector<string> &listData);
#endif // ACCOUNT_H
