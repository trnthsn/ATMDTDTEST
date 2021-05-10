#include "account.h"
using namespace std;

Account ::Account(string _fullName, string _id, string _password, long long _balance, long long _wrongTime)
{
    fullName = _fullName;
    id = _id;
    password = _password;
    wrongTime = _wrongTime;
    balance = _balance;
}

// lấy data khách hàng vào trong database
void getListData(vector<string> &listData, int &accountNumber)
{
    fstream file;
    file.open("dataBase.txt");
    string s;
    file >> accountNumber;
    getline(file, s);
    while (!file.eof())
    {
        getline(file, s);
        listData.push_back(s);
    }
}

// update lại data vào trong database
void updateListData(vector<string> &listData, int &accountNumber)
{
    remove("dataBase.txt");
    ofstream file("dataBase.txt");
    file << accountNumber << endl;
    for (int i = 0; i < accountNumber * 5; i++)
    {
        file << listData[i] << endl;
    }
}

// chuyển một số thành string
string convertNumber(int number)
{
    vector<int> split;
    int tempNumber = number;
    if (tempNumber == 0)
        return "0";
    else
    {
        while (tempNumber > 0)
        {
            split.push_back(tempNumber % 10);
            tempNumber /= 10;
        }
        string temp = "";
        for (int i = split.size() - 1; i >= 0; i--)
        {
            temp += char(split[i] + 48);
        }
        return temp;
    }
}

// chuyển từ một string số thành số
long long convertStringToNumber(const string &s)
{
    long long number = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i != s.size() - 1)
        {
            number += int(s[i]) - 48;
            number *= 10;
        }
        else
        {
            number += int(s[i]) - 48;
        }
    }
    return number;
}

// so sánh 2 string xem có giống nhau không
bool compare2string(const string &a, const string &b)
{
    if (a.size() != b.size())
        return false;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// kiểm tra xem ID có tồn tại trong cơ sở dữ liệu không
bool checkIDAppear(const string &ID, vector<string> &listData)
{
    int n = listData.size();
    for (int i = 1; i < n; i++)
    {
        if (i % 5 == 1)
        {
            if (compare2string(ID, listData[i]) == true)
                return true;
            else
                continue;
        }
    }
    return false;
}

long long getAddressCustomer(const string &ID, vector<string> &listData)
{
    int n = listData.size();
    for (int i = 1; i < n; i += 5)
    {

        if (compare2string(ID, listData[i]))
            return i;
    }
    return -1;
}

long long getCurrentBalance(const string &ID, vector<string> &listData)
{
    int CustomerAddress = getAddressCustomer(ID, listData);
    long long balance = convertStringToNumber(listData[CustomerAddress + 2]);
    return balance;
}

// kiểm tra xem password có nhập đúng hay không
bool checkPassword(const string &ID, const string &InputedPassword, vector<string> &listData)
{
    if (checkIDAppear(ID, listData))
    {
        int addressCustomerInDataBase = getAddressCustomer(ID, listData);
        if (compare2string(InputedPassword, listData[addressCustomerInDataBase + 1]) == false)
        {
            listData[addressCustomerInDataBase + 4] += 1;
            return false;
        }
        else
        {
            return true;
        }
    }
    else
        return false;
}

// kiểm tra xem tài khoản đã bị khoá chưa
bool checkCondition(const string &ID, vector<string> &listData)
{
    int addressCustomerInDataBase = getAddressCustomer(ID, listData);
    if (convertStringToNumber(listData[addressCustomerInDataBase + 4]) >= 6)
        return false;
    return true;
}

// lấy password của id trong database
string getCorrectPassword(const string &ID, vector<string> &listData)
{
    int addressCustomerInDataBase = getAddressCustomer(ID, listData);
    return listData[addressCustomerInDataBase + 1];
}

// lấy số lần nhập sai
int getWrongTime(const string &ID, vector<string> &listData)
{
    int addressCustomerInDataBase = getAddressCustomer(ID, listData);
    return convertStringToNumber(listData[addressCustomerInDataBase + 3]);
}

// cập nhật số lần điền sai mật khẩu
void updateWrongTime(const string &ID, vector<string> &listData, int &newWrongTime, int &accountNumber)
{
    int addressCustomerInDataBase = getAddressCustomer(ID, listData);
    listData[addressCustomerInDataBase + 3] = convertNumber(newWrongTime);
    updateListData(listData, accountNumber);
}

// thay đổi số dư vào trong cơ sở dữ liệu
void setBankBalance(vector<string> &listData, const string &ID, const long long &Balance)
{
    int addressCustomerInDataBase = getAddressCustomer(ID, listData);
    string StringBalance = convertNumber(Balance);
    listData[addressCustomerInDataBase + 2] = StringBalance;
}

void getBankMoney(int *bankMoney)
{
    fstream file("BankMoney.txt");
    for (int i = 0; i < 9; i++)
    {
        file >> bankMoney[i];
    }
}
void updateBankMoney(int *bankMoney)
{
    remove("BankMoney.txt");
    ofstream file("BankMoney.txt");
    for (int i = 0; i < 9; i++)
    {
        file << bankMoney[i] << endl;
    }
}
void bankingFunction(const char &selectFunction, string &ID,
                     int *denomination, int *bankMoney, vector<string> &listData)
{
    while (true)
    {
        getBankMoney(bankMoney);
        if (selectFunction == '1')
        {
            int money[9];
            long long IdBalance = 0;
            // Render('selectFunction');
            for (int i = 0; i < 9; i++)
            {
                cout << denomination[i] << ": \n";
                cin >> money[i];
                bankMoney[i] += money[i];
                cout << denomination[i] * money[i] << endl;
                IdBalance += denomination[i] * money[i];
                system("cls");
                Render(selectFunction);
            }
            cout << "Nop tien thanh cong! \n";
            cout << IdBalance;
            updateBankMoney(bankMoney);
            // setBankBalance(listData, ID, convertNumber(IdBalance));
            break;
        }
        if (selectFunction == '2')
        {
            break;
        }
        if (selectFunction == '3')
        {
            break;
        }
    }
}