//
//  main.c
//  1006
//
//  Created by apple on 14-2-6.
//  Copyright (c) 2014年 zju. All rights reserved.
//

//#include <stdio.h>
//
//typedef struct CTime
//{
//    int hour[3];
//    int minute[3];
//    int sec[3];
//}Time;
//
//typedef struct CRecord
//{
//    char ID[16];
//    Time in_time;
//    Time out_time;
//}Record;
//
//int main(int argc, const char * argv[])
//{
//    int num;
//    int i,j;
//    scanf("%d",&num);
//    Record r[1000];
//    
//    for(i = 0 ; i < num ; i++)
//    {
//        
//    }
//   
//}


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct person
{
    string pid;
    string in;
    string out;
};
bool my_less(person a,person b)
{
    return a.in<b.in;
}
bool my_great(person a,person b)
{
    return a.out>b.out;
}
person p[1000];
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>p[i].pid>>p[i].in>>p[i].out;
    sort(p,p+n,my_less);
    cout<<p[0].pid<<' ';
    sort(p,p+n,my_great);
    cout<<p[0].pid<<endl;
    return 0;
}

