//
//  main.cpp
//  1007
//
//  Created by apple on 14-2-6.
//  Copyright (c) 2014年 zju. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX 10001
int numlist[MAX];
int result[MAX];
int number[MAX];

int main(int argc, const char * argv[])
{
    int i;
    int num;
    int index;
    int max = 0;
    int zero_flag = 1;
    int start, end;
    cin>>num;
    for(i = 0; i < num; i++)
    {
        cin>>numlist[i];
        if(numlist[i] >= 0)
        {
            zero_flag = 0;
        }
        result[i] = 0;
        number[i] = 0;
    }
    
    result[0] = numlist[0];
    number[0] = 0;
    for(i = 1 ; i < num; i++)
    {
        if(result[i-1] > 0)
        {
            result[i] = result[i-1]+numlist[i];
            number[i] = number[i-1] + 1;
        }
        else
        {
            result[i] = numlist[i];
            number[i] = 0;
        }
    }
    
    
    max = result[0];
    index = 0;
    for(i = 0; i < num; i++)
    {
      if(max < result[i])
      {
          max = result[i];
          index = i;
      }
      
    }
    
    
    if(!zero_flag)
    {
        start = numlist[index-number[index]];
        end = numlist[index];
        
    }
    else
    {
        max = 0;
        start = numlist[0];
        end = numlist[num-1];
    }
    
    cout<<max<<" "<<start<<" "<<end<<endl;
    
    
    return 0;
}

