#include<iostream>
#include<string>
#include<algorithm>
#include"apps.cpp"
using namespace std;

void Text_analysis_service()
{
    
    //get array
    system("clear");
    cout<<"\n=====Array of Pharses=====\n";
    int p_len;
    p_len = Get_length("\nEnter The Number of items : ");
    string Pharses[p_len];
    Get_Array(Pharses,p_len);
    
    //get queries

    system("clear");
    cout<<"\n=====Array of Queries=====\n";
    int Q_len;
    Q_len = Get_length("\nEnter The Number of items : ");
    Set Queries[Q_len];
    Get_Query(Queries,Q_len);

    //sorting the array 
    
    sort(Pharses,Pharses+p_len);
     
    //searching the queries & printing the ranges
    system("clear");
    cout<<"========Ranges========\n\n";
    
    int r1,r2;    


    cout<<"Sorted data : [";
    for (int i = 0; i < p_len - 1; i++)
    {
        cout<<Pharses[i]<<" ,";
    }
    cout<<Pharses[p_len-1]<<" ]\n";
    
    for (int i = 0; i < Q_len; i++)
    {
        r1 = BinarySearch(Pharses,0,p_len-1,Queries[i].first_item);
        r2 = BinarySearch(Pharses,0,p_len-1,Queries[i].second_item);
        cout<<"Number of String in Range [ "<<Queries[i].first_item<<", "<<Queries[i].second_item<<"] : ";
        //     :))
        (r1 == -1 || r2 == -1 || r2 < r1)
            ? cout<<"   Error   \n"
            : cout<<r2 - r1<<endl;
    }
    cout<<endl;
    system("pause");
}




void Transport_routing_service()
{
    // Get length and fill distances
    system("clear");
    int N  = Get_length("\nEnter The Number of Nodes : ");
    
    int Matrix[N][N];
     
    for (int i = 0; i < N; i++)
    {
        Matrix[N][N] = 0;
    }
    system("clear");
    cout<<"======== Distances ========\n\n";   
    string temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            while (true)
            {
                cout<<"Distance Between "<<i<<" and "<<j<<" : ";
                getline(cin,temp);
                if(is_Num(temp) == 1)
                {
                    break;
                }
                cout<<"Error\n";
            }
            if(stoi(temp) == 0)
            {
                Matrix[i][j] = Matrix[j][i] = 5000;
            }
            else
            {
                Matrix[i][j] = Matrix[j][i] =  stoi(temp);
            }
        }
    }
    
    int Starter_node;
    
    while (true)
    {
        cout<<"\nEnter The Starter Node : ";    
        getline(cin,temp);
        if(is_Num(temp) == 1)
        {
            if(0 <= stoi(temp) && stoi(temp)< N)
            {
                Starter_node = stoi(temp);
                break;
            }
        }
        cout<<"Error\n";
    }    
    
    int visited[N];

    visited[0]= Starter_node;
    
    int distances[N];
    int min_distance;
    for (int i = 0; i < N; i++)
    {
        distances[i] = 5000;
        min_distance = i; 
    }
    
    distances[Starter_node] = 0;
    
    
    
    int key = 0;
    
    int temp_node = Starter_node;

    
    
    while(key != N-2)
    {
        for(int i = 0;i < N; i++ )
        {
            if (check_in_array(visited,i,N)==0)
            {
                if(distances[i]==5000)
                {
                    distances[i]=Min(distances[i],Matrix[temp_node][i]);
                }else{
                    distances[i]=Min(distances[i],distances[min_distance] + Matrix[temp_node][i]);
                }

                if(distances[min_distance] >= distances[i])
                {
                    min_distance =  i;
                }
            }
        }
        visited[key]=temp_node;
        key++;
        temp_node = min_distance;
    }
    
    cout<<"\nShortest Distance From "<<Starter_node<<" : \n";
    for (int i = 0; i < N; i++)
    {
        cout<<"To "<<i<<" : "<<distances[i]<<endl;
    }
    system("pause");


}


void Cloud_computing_service()
{
    //get the sets 
    system("clear");
    cout<<"\n===== Array of ITEMS =====\n";
    int S_len;
    S_len = Get_length("\nEnter The Number of items : ");
    int W_max = Get_length("\nEnter The Max weight : ");
    int Values[S_len];
    int Weight[S_len];
    for (int  i = 0; i < S_len; i++)
    {
        cout<<"ITEM ["<<i<<"] \n";
        Values[i] = Get_length("Value : ") ;
        Weight[i] = Get_length("Weight : ") ;
        
    }
    cout<<endl;
    for (int i = 0; i < S_len; i++)
    {
        cout<<Values[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < S_len; i++)
    {
        cout<<Weight[i]<<" ";
    }
    cout<<endl;


    int V_selected[S_len+1][W_max+1];
    int selected[S_len];
    int counter = 0;
    

    cout<<endl;
    for (int i = 0; i < S_len +1; i++)
    { 
        for (int j = 0; j < W_max+1 ; j++ )
        {
            if (i==0 || j==0)
            {
                V_selected[i][j] = 0;
                
            }
            else if ( j >= Weight[i-1])
            {
                V_selected[i][j] = Max(V_selected[i-1][j],V_selected[i-1][j-Weight[i-1]]+Values[i-1] );
                if ( V_selected[i-1][j] < V_selected[i-1][j - Weight[i-1]] + Values[i-1] )
                {
                    cout<<"2.*";
                    if( check_in_array(selected,i,S_len) == 0 )
                    {
                        selected[counter] = i;
                        counter++;
                        cout<<V_selected[i-1][j]<<" < "<<V_selected[i-1][j - Weight[i-1]] + Values[i-1]<<" *";
                    }
                }
                else
                {
                    cout<<"3.";
                }
            }
            else
            {
                V_selected[i][j] = V_selected[i-1][j] ;
                
            }
            cout<<V_selected[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for (int i = 0; i <= S_len; i++)
    {
        for (int j = 0; j <= W_max; j++)
        {
            cout<<V_selected[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //system("clear");
    cout<<"\n======= Answer =======\n";
    cout<<"\nMaximum Value Achivable : "<<V_selected[S_len][W_max]<<endl;
    for (int i = 0; i < counter; i++)
    {
        cout<<selected[i]<<" Value : "<<Values[selected[i]-1]<<" | Resources : "<<Weight[selected[i]-1]<<endl;
    }
    system("pause");
}





void Stock_buying_and_selling_service()
{
    system("clear");
    int len = Get_length("Please Enter The Numbers of Prices : ");
    int Chart[len];
    for (int i = 0; i < len; i++)
    {
        Chart[i]=Get_length("["+to_string(i+1)+"] : ");
    }
    system("clear");
    cout<<"\n======= Explaination =======\n";

    int counter = 0;

    cout<<"\nThe reverse pairs are : \n\n";
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (Chart[i]>2*Chart[j])
            {
                cout<<"( "<<i<<" , "<<j<<") ----> Nums["<<i<<"] = "<<Chart[i]<<" ,"<<"Nums["<<j<<"] = "<<Chart[j]<<" ; "<<Chart[i]<<" > 2 * "<<Chart[j]<<endl;
                counter++;
            }
            
        }
        
    }
    cout<<"\nOutput = "<<counter<<endl;
    system("pause");

}


















