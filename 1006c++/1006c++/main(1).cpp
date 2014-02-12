//
//  main.cpp
//  1006c++
//
//  Created by apple on 14-2-6.
//  Copyright (c) 2014年 zju. All rights reserved.
//
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef struct  CRecord
{
    string id;
    string in;
    string out;
}Record;


Record record[1000];

bool lessthan(Record a, Record b)
{
    return a.in < b.in;
}

bool greatthan(Record a, Record b)
{
    return a.out > b.out;
}

int main()
{
    
    int n;
    int i;
    cin>>n;
    for(i = 0 ; i < n; i++)
    {
        cin>>record[i].id>>record[i].in>>record[i].out;
    }
    
    sort(record,record+n,lessthan);
    cout<<record[0].id<<" ";
    sort(record,record+n,greatthan);
    cout<<record[0].id<<endl;
    
    
    
    return 0;
}

