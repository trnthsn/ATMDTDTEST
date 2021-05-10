#include "render.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Render(const char &selection)
{
    switch (selection)
    {
    case '0':
    {
        system("cls");
        cout << "=========================================" << endl;
        cout << "=============SownATMSimulation===========" << endl;
        cout << "=========================================" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==  1. Dang nhap.                      ==" << endl;
        cout << "==  2. Dang ky tai khoan.              ==" << endl;
        cout << "==  3. Thoat.                          ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "=========================================" << endl;
        break;
    }
    case '1': //select Dang Nhap
    {
        system("cls");
        cout << "=========================================" << endl;
        cout << "=============SownATMSimulation===========" << endl;
        cout << "=========================================" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==     Vui long nhap id va password    ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "=========================================" << endl;
        break;
    }
    case '2': // select tạo tài khoản
    {
        system("cls");
        cout << "=========================================" << endl;
        cout << "=============SownATMSimulation===========" << endl;
        cout << "=========================================" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==      Ban dang dang ki tai khoan     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "=========================================" << endl;
        break;
    }
    case '3':
    {
        system("cls");
        cout << "=========================================" << endl;
        cout << "=============SownATMSimulation===========" << endl;
        cout << "=========================================" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==   1. Nop tien.                      ==" << endl;
        cout << "==   2. Rut tien.                      ==" << endl;
        cout << "==   3. Thoat.                         ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "==                                     ==" << endl;
        cout << "=========================================" << endl;
        cout << "Vui long chon nhu cau cua ban: " << endl;
        break;
    }
    default:
    {
        cout << "selection not found" << endl;
        break;
    }
    }
}