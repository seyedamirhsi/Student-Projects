#include<iostream>
#include"view.cpp"
#include"Tasks.cpp"
using namespace std;


int main()
{   int choice;
    while(true)
    {
        choice = Menu();        
        if     (choice == 1)
        {
            Text_analysis_service();
        }
        else if (choice == 2)
        {
            Transport_routing_service();
        }
        else if (choice == 3)
        {
            Cloud_computing_service();
        }
        else if (choice == 4)
        {
            Stock_buying_and_selling_service();
        }
        else if( choice == 0)
        {
            system("clear");
            exit(0);
        }
        else
        {
            system("clear");
            cout<<"Please Enter a Valid Choice ...";
            system("pause");
        }            
    }

}