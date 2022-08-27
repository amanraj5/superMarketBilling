#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void reciept();
};
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t______________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t     |SuperMaret Main Menu|     ";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t______________________________\n";
    cout << "\t\t\t\t     |   1. Administrator |   \n";
    cout << "\t\t\t\t     |   2. Buyer         |   \n";
    cout << "\t\t\t\t     |   3. Exit          |   \n";
    cout << "\t\t\t\t     |   #  Please Select!    \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Please Login!!!\n";
        cout << "Enter Email  \n";
        cin >> email;
        cout << "Password\n";
        cin >> password;
        if (email == "amansingh@gmail.com" && password == "aman240")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email or Password \n";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please Select correct choice\n";
    }
    }
    goto m;
}
void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\t\t\t     Administrator Menu";
    cout << "\n\t\t\t  1) Add the product__________|";
    cout << "\n\t\t\t                              |";
    cout << "\n\t\t\t  2) Modify the product_______|";
    cout << "\n\t\t\t                              |";
    cout << "\n\t\t\t  3) Delete the product_______|";
    cout << "\n\t\t\t                              |";
    cout << "\n\t\t\t  4) Back to the main menu____|";

    cout << "\n\n\t    #  Please enter your choice !";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        edit();
        break;
    }
    case 3:
    {
        rem();
        break;
    }
    case 4:
    {
        menu();
        break;
    }
    default:
    {
        cout << "Invalid Choice !!!\n";
    }
    }
    goto m;
}
void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t  ___Buyer___  \n";
    cout << "\t\t\t______________ \n";
    cout << "\t\t\t               \n";
    cout << "\t\t\t1) Buy Product \n";
    cout << "\t\t\t               \n";
    cout << "\t\t\t2) Go Back     \n";
    cout << "\t\t\t#  Please enter your choice :\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        reciept();
        break;
    }
    case 2:
    {
        menu();
    }
    default:
        cout << "Invalid Choice!!!\n";
    }
    goto m;
}
void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t Add new Product__";
    cout << "\n\n\t Product code of the product-\n";
    cin >> pcode;
    cout << "\n\n\t Name of the Product-\n";
    cin >> pname;
    cout << "\n\n\t Price of the Product-\n";
    cin >> price;
    cout << "\n\n\t Discount on the product-\n";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();


    if (token == 1)
        goto m;
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << " \n";
        data.close();
    }
    }
    cout << "\n\n\t\tRecord Inserted !";
}
void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n!File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code--";
                cin >> c;
                cout << "\n\t\t Name of the product--";
                cin >> n;
                cout << "\n\t\t Price--";
                cin >> p;
                cout << "\n\t\t Discount--";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << " "
                      << "\n";
                cout << "\n\t\t Record edited successfully.";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record Not Found.Sorry!!!";
        }
    }
}
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code--\n";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product Deleted Successfully.\n";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record Not Found!!!\n";
        }
    }
}
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n_______________________________________\n";
    cout << "|ProNo|\t|Name|\t|Price|\n";
    cout << "\n\n_______________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t" << pname << "\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping::reciept()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int count = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t RECIEPT \n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "Nothing in the database!!!\n";
    }
    else
    {
        data.close();
        list();
        cout << "\n____________________________\n";
        cout << "\n                            \n";
        cout << "    Please place the order      ";
        cout << "\n____________________________\n";
        cout << "\n                            \n";

        do
        {
            m:
            cout << "\n\nEnter the product code--\n";
            cin >> arrc[count];
            cout << "\n\nEnter the product quantity--\n";
            cin >> arrq[count];
            for (int i = 0; i < count; i++)
            {
                if (arrc[count] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again!\n";
                    goto m;
                }
            }
            count++;
            cout << "\n\n Do you want to buy the product? if Yes then press y else n :";
            cin >> choice;
        } 
        while (choice == 'y');

        cout << "\n\n\t\t______________RECIEPT______________";
        cout << "\nProduct No\tProduct Name\tProduct Quantity\tPrice\tAmount\tAmount with Discount\n";
        for (int i = 0; i < count; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "\n\n**************\n";
        cout << "\n Total Amount : " << total;
    }
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}