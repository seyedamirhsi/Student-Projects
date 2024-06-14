#include<iostream>
using namespace std;


int Menu()
{   
    system("cls");
    
    string choice;

    cout<<"==================================================================\n";
    cout<<"==========================  Manage  ==============================\n";
    cout<<"==================================================================\n";
    cout<<"1.Text analysis service\n";
    cout<<"2.Transport routing service\n";
    cout<<"3.Cloud computing service\n";
    cout<<"4.Stock buying and selling service\n";
    cout<<"0.Exit\n";

    while(true)
    {
        cout<<"Your choice : ";
        getline(cin,choice);
        if (choice < "5" && choice >= "0")
        {
            return stoi(choice);
        }
        else
        {
            cout<<"Please Enter a Valid choice\n";
        }
    }
}