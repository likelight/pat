//
//  main.cpp
//  1042
//
//  Created by apple on 14-2-6.
//  Copyright (c) 2014年 zju. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void transform(int i,int index)
{
    int res = 0;
    int mod = 0;
    string str;
    res = i / 13;
    mod = i % 13 + 1;
    switch(res)
    {
        case 0:
        {
            str = "S";
        }
        break;
        case 1:
        {
            str = "H";
        }
        break;
        case 2:
        {
            str = "C";
        }
        break;
        case 3:
        {
            str = "D";
        }
        break;
        case 4:
        {
            str = "J";
        }
        break;
        default:
        {
          str=" ";
        }
        break;
    }
    
    if(index != 53)
    {
        cout<<str<<mod<<" ";
   
    }
    else
    {
        cout<<str<<mod<<endl;
    }
    
    
}

int main(int argc, const char * argv[])
{

    int play_card[54];
    int  position[54];
    int array[54];
    int n;
    int i,j;
    cin >> n;
    
    for(i = 0; i < 54; i++)
    {
        cin>> play_card[i];
        array[i] = i;
    }
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 54; j++)
        {
            position[play_card[j]-1] = array[j];
        }
        
        for(j = 0; j < 54; j++)
        {
            array[j] = position[j];
        }
    }
    
    
   
    for(i = 0; i < 54; i++)
    {
        transform(array[i],i);
        
    }
    
}

