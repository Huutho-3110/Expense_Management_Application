#include <iostream>
#include "wallet.h"
int main()
{
    int option;
    std::cout << "_CHAO MUNG BAN DEN VOI PROJECT QUAN LI CHI TIEU - WELCOME TO PROJECT DEPARTMENT MANAGEMENT_\n";
    getUser();
    setInitialwallet();
    while (true)
    {
        std::cout << "\n--- Hay chon muc ma ban muon su dung - Choose the options that you want to use ---\n"
                  << "1. Thong tin ca nhan - Personal information.\n"
                  << "2. Them giao dich - Add transaction.\n"
                  << "3. Tong ket chi tieu - Summary of spending.\n"
                  << "4. Thoat - Quit.\n";
        std::cout << "Hay nhap lua chon cua ban - Please enter your option: ";
        std::cin >> option;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Lua chon khong hop le!\n";
            continue;
        }
        else if (option == 1)
            USER();
        else if (option == 2)
            addTransaction();
        else if (option == 3)
            summary();
        else if (option == 4)
            break;
        else
        {
            std::cout << "Hay su dung cac lua chon tu 1 den 4 !! - Please use options 1 to 4.\n";
            continue;
        }
    }
    return 0;
}