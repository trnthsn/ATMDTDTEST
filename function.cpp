#include "function.h"
// #include "banking.h"
using namespace std;

// start ATM Simulation
void function(vector<string> &listData, int *denomination, int *bankMoney)
{
    bool running = true;
    while (running)
    {
        int accountNumber = 0;
        char defaultSelection = '0';
        char choose;
        Render(defaultSelection);
        cout << "Lua chon cua ban la: \n";
        fflush(stdin);
        cin >> choose;
        cin.ignore();
        if (choose == '1')
        {
            system("cls");
            Render('1');
            int select = 1;
            if (select == 1)
            {
                string id, password;
                getListData(listData, accountNumber);
                cout << "Nhap id" << endl;
                getline(cin, id);
                if (checkIDAppear(id, listData) == false)
                {
                    cout << "Tai khoan khong ton tai! \n";
                    cout << "1. Thoat \n";
                    while (true)
                    {
                        int exitSelection;
                        cin >> exitSelection;
                        if (exitSelection == 1)
                        {
                            cout << "Dang thoat ...";
                            Sleep(1500);
                            system("cls");
                            break;
                        }
                        else
                        {
                            cout << "Dang thoat ...";
                            Sleep(1500);
                            system("cls");
                            break;
                        }
                    }
                }
                else
                {
                    while (true)
                    {
                        cout << "Vui long nhap pass: \n";
                        fflush(stdin);
                        getline(cin, password);
                        // cout << password << endl;
                        // updateWrongTime(id, listData, 5);
                        // updateListData(listData);
                        getListData(listData, accountNumber);
                        int wrongTime = getWrongTime(id, listData);
                        string correctPassword = getCorrectPassword(id, listData);
                        // cout << correctPassword << endl;
                        // cout << wrongTime << endl;
                        if (wrongTime >= 5)
                        {
                            cout << "Tai khoan cua ban da bi khoa! ";
                            Sleep(3000);
                            break;
                        }
                        // trường hợp nhập sai pass
                        if (compare2string(password, correctPassword) == false)
                        {
                            if (wrongTime < 5)
                            /* kiểm tra xem tài khoản có bị khoá không,
                        nếu chưa bị khoá thì tăng số lần sai */
                            {
                                cout << "Ban da nhap sai mat khau: " << endl;
                                wrongTime++;
                                updateWrongTime(id, listData, wrongTime, accountNumber);
                                updateListData(listData, accountNumber);
                                // wrongTime++;
                                cout << wrongTime << endl;
                                // getListData(listData);
                            }
                            else // điều kiện tài khoản đã bị khoá
                            {
                                cout << "Tai khoan ban da bi khoa! \n";
                                cout << "ATM se thoat ve man hinh chinh... \n";
                                Sleep(2000);
                                system("cls");
                                // choose = 1;
                                break;
                            }
                        }
                        else // điều kiện nhập đúng pass
                        {
                            wrongTime = 0;
                            updateWrongTime(id, listData, wrongTime, accountNumber);
                            updateListData(listData, accountNumber);
                            // getListData(listData);
                            cout << "Ban da nhap dung pass" << endl;
                            cout << "Vui long doi..." << endl;
                            Sleep(2000);
                            choose = '3';
                            Render(choose);
                            char selectFunction;
                            cin >> selectFunction;
                            // function nop tien
                            if (selectFunction == '1')
                            {
                                getBankMoney(bankMoney);
                                int money[9];
                                long long IdBalance = 0;
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
                                cout << "Ban da nop tien thanh cong ";
                                cout << IdBalance << " !" <<  endl;
                                getAddressCustomer(id, listData);
                                long long Balance = getCurrentBalance(id, listData);
                                Balance += IdBalance;
                                setBankBalance(listData, id, Balance);
                                updateListData(listData, accountNumber);
                                updateBankMoney(bankMoney);
                                cout << "Dang thoat... \n";
                                Sleep(1500);
                                break;
                            }
                            // function rut tien
                            if (selectFunction == '2')
                            {
                                break;
                            }
                            if (selectFunction == '3')
                            {
                                break;
                            }
                        }
                        // cout << compare2string(password, correctPassword);
                    }
                }
            }
        }
        if (choose == '2')
        {
            Sleep(1500);
            break;
        }
        if (choose == '3')
            running = false;
        if (choose != '1' && choose != '2' && choose != '3')
        {
            system("cls");
            Render(defaultSelection);
            cout << "Vui long chon lai " << endl;
        }
    }
}
