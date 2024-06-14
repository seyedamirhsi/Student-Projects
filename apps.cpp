#include<iostream>
#include"models.cpp"
using namespace std;


bool is_int(char ch)
{
    if (ch >='0' && ch <='9')
    {
        return 1;
    }
    return 0;
}

bool is_Num(string Temp)
{
    for (int i = 0; i < sizeof(Temp)/sizeof(string); i++)
    {
        if (is_int(Temp[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Get_length(string str)
{
    int len;
    string Temp;
    
    while(true)
    {
        cout<<str;
        getline(cin,Temp);
        if(is_Num(Temp)==1)
        {
            return stoi(Temp);
        }
            cout<<"\nEnter a Valid Value...";
    }
}

void Get_Array(string array[],int len)
{
    string pharse;
    cout<<endl;
    for (int i = 0; i < len; i++)
    {
        cout<<"["<<i<<"] : ";
        getline(cin,pharse);
        array[i] = pharse;
    }
    
}

void Get_Query(Set array[],int len)
{
    Set temp;
    cout<<endl;
    for (int i = 0; i < len; i++)
    {
        cout<<"First Item of ["<<i<<"] : ";
        getline(cin,temp.first_item);
        
        cout<<"Second Item of ["<<i<<"] : ";
        getline(cin,temp.second_item);
        
        array[i] = temp;
    }
    
}

int BinarySearch(string Array[], int low, int high, string x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (Array[mid] == x)
            return mid;

        if (Array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}



bool check_in_array(int array[],int target,int n)
{
    for (int  i = 0; i < n; i++)
    {
        if(array[i]==target)
        {
            return 1;
        }
    }
    return 0;
}

int Min(int first,int second)
{
    if (first < second)
    {
        return first;
    }
    return second;
}


int Max(int first,int second)
{
    if (first > second)
    {
        return first;
    }
    return second;
}









