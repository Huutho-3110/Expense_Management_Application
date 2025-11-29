#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "wallet.h" // Connect to header file

// This file will support for building what function need to do in the project

// get user information -> need to create a
userInfo User;
void getUser()
{

    std::cout << "Hay nhap ten cua ban - Please enter your name: ";
    std::getline(std::cin, User.name);

    std::cout << "Hay nhap dia chi cua ban - Please enter your adress: ";
    std::getline(std::cin, User.address);

    std::cout << "Hay nhap email cua ban - Please enter your email: ";
    std::getline(std::cin, User.email);

    std::cout << "Hay nhap do tuoi cua ban - Please enter your age: ";
    std::cin >> User.age;
}
void USER()
{
    std::cout << "\nTen - Name: " << User.name << std::endl
              << "Dia chi - Adress: " << User.address << std::endl
              << "Email: " << User.email << std::endl
              << "Tuoi - Age: " << User.age << std::endl;
}

// set the initial wallet for user
long long eWallet = 0;
long long rWallet = 0;
std::vector<wallet> history;
std::vector<long long> earn;
std::vector<long long> spend;
double getMoney(std::string nameWallet_V, std::string nameWallet_E)
{
    double money;
    std::cout << "Hay nhap so tien cua " << nameWallet_V << " - Please enter the amount of your " << nameWallet_E << ": ";
    while (true)
    {
        std::cin >> money;
        if (std::cin.fail())
        {
            std::cout << "Xin vui long nhap dung dinh dang cua vi - Please enter the right format of the wallet";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (money < 0)
        {
            std::cout << "\n>> Haha!! Ban dang no tien a? Nhap lai so duong nhe.\n"
                      << ">> Haha!! You owe money? Please enter a positive number.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return money;
        }
    }
}
void setInitialwallet()
{
    std::cout << "\n__CAI DAT VI BAN DAU - SET INITIAL WALLET__\n";
    int choice;
    while (true)
    {
        std::cout << "Hay chon vi cua ban:\n"
                  << "1. Vi dien tu - Electronic wallet - eWallet\n"
                  << "2. Vi thuc te - Real wallet - rWallet\n"
                  << "3. Ca hai - Both\n"
                  << "4. Quay lai - Back\n";
        std::cout << "Hay nhap lua chon cua ban - Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Lua chon khong hop le!\n";
            continue;
        }
        if (choice == 4)
        {
            return;
        }
        else if (choice == 1)
        {
            eWallet = getMoney("vi dien tu", "electronic wallet");
            break;
        }
        else if (choice == 2)
        {
            rWallet = getMoney("vi thuc te", "real wallet");
            break;
        }
        else if (choice == 3)
        {
            eWallet = getMoney("vi dien tu", "electronic wallet");
            rWallet = getMoney("vi thuc te", "real wallet");
            break;
        }
        else
        {
            std::cout << "Lua chon cua ban khong hop le! Hay nhap so tu 1 den 4 - Your choice is invalid! Please enter a number from 1 to 4\n";
            continue;
        }
    }
    std::cout << "\n--- CAI DAT THANH CONG! ---\n";
    std::cout << "Vi Dien Tu: " << (long long)eWallet << "\n";
    std::cout << "Vi Thuc Te: " << (long long)rWallet << "\n";
}

// get transaction (dao dich) spent / earn
wallet t;
void addTransaction()
{
    int choice;

    while (true)
    {
        std::cout << "\n__CHON LOAI DAO DICH - CHOOSE TRANSACTION TYPE__\n"
                  << "1. Thu - Earn\n"
                  << "2. Chi - Spend\n"
                  << "3. Quay lai - Back\n";
        std::cout << ">>> Hay nhap lua chon cua ban - Enter your choice: ";
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Lua chon khong hop le!\n";
            continue;
        }
        else if (choice == 3)
        {
            return;
        }
        else if (choice == 1)
        {

            t.type = "Thu - Earn";
            break;
        }
        else if (choice == 2)
        {
            t.type = "Chi - Spend";
            break;
        }
        else
        {
            std::cout << "--- Vui long chi chon tu 1 den 3 - Please choose the options from 1 to 3 ---\n";
            continue;
        }
    }

    int typeWallet;
    while (true)
    {
        std::cout << "\n>>> Hay chon vi ma ban muon su dung - Please choose type of wallet you want to use.\n"
                  << "1. Vi dien tu - Electronic wallet.\n"
                  << "2. Vi thuc te - Real wallet.\n";
        std::cout << ">>> Hay dua ra lua chon - Please enter your option: ";
        std::cin >> typeWallet;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Lua chon khong hop le!\n";
            continue;
        }

        else if (typeWallet == 1)
        {

            t.typeWallet = "Vi dien tu - Electronic wallet";
            break;
        }
        else if (typeWallet == 2)
        {
            t.typeWallet = "Vi thuc te - Real wallet";
            break;
        }
        else
        {
            std::cout << "-- Vui long chi chon 1 hoac 2 - Please choose 1 or 2 --";
            continue;
        }
    }

    std::cout << ">>> Vui long nhap so tien - Please enter the amount of money.\n";
    std::cin >> t.amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << ">>> Hay nhap danh muc chi hoac tieu - Please enter the item or item category.\n";
    std::getline(std::cin, t.category);
    std::cout << ">>> Hay nhap ghi chu cho so tien do - Please enter a note for that amount.\n";
    std::getline(std::cin, t.description);
    if (t.type == "Thu - Earn")
    {
        earn.push_back(t.amount); // Canculate earning
        if (t.typeWallet == "Vi dien tu - Electronic wallet")
        {
            eWallet += t.amount;
        }
        if (t.typeWallet == "Vi thuc te - Real wallet")
        {
            rWallet += t.amount;
        }
    }
    if (t.type == "Chi - Spend")
    {
        earn.push_back(t.amount);
        if (t.typeWallet == "Vi dien tu - Electronic wallet")
        {
            eWallet -= t.amount;
        }
        if (t.typeWallet == "Vi thuc te - Real wallet")
        {
            rWallet -= t.amount;
        }
    }
    history.push_back(t);
    std::cout << ">>> Giao dich da duoc luu! - Transaction saved! <<<" << std::endl;
}

// summary all the spent and earn for user
void summary()
{
    long long sumEarn = 0;
    long long sumSpend = 0;
    for (int i = 0; i < earn.size(); ++i)
    {
        sumEarn += earn[i];
    }
    for (int i = 0; i < spend.size(); ++i)
    {
        sumSpend += spend[i];
    }
    std::cout << "\n__TONG KET CHI TIEU CUA BAN - SUMMARY OF YOUR SPENDINGS__\n";
    std::cout << "- So du vi dien tu - Electronic wallet balance: " << eWallet << std::endl;
    std::cout << "- So du vi thuc te - Real wallet balance: " << rWallet << std::endl;
    std::cout << "- Tong so tien da chi - Total amount spent: " << sumSpend << std::endl;
    std::cout << "- Tong so tien da thu - Total amount earned: " << sumEarn << std::endl;
    std::cout << "\nDanh sach giao dich:" << std::endl;
    // Vòng lặp để in hết các giao dịch đã lưu
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << i + 1 << ". "
                  << history[i].type << " - "
                  << (long long)history[i].amount << " - "
                  << history[i].category << " ("
                  << history[i].description << ")" << std::endl;
    }
}