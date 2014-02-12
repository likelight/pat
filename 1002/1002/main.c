//
//  main.c
//  1002
//
//  Created by apple on 14-2-4.
//  Copyright (c) 2014年 zju. All rights reserved.
//

#include <stdio.h>
#define MAX 1001
double array_a[MAX];
double array_b[MAX];
double sum[MAX];



int main(int argc, const char * argv[])
{
    int i;
    int a_h,b_h;
    int tmp;
    double value;
    int count = 0;
    for(i = 0; i < MAX; i++)
    {
        array_a[i] = 0;
        array_b[i] = 0;
        sum[i] = 0;
    }
    
    scanf("%d",&a_h);
    for(i= 0;i < a_h; i++)
    {
        scanf("%d",&tmp);
        scanf("%lf",&value);
        array_a[tmp] = value;
        
    }
    
    scanf("%d",&b_h);
    for(i = 0; i < b_h; i++)
    {
        scanf("%d",&tmp);
        scanf("%lf",&value);
        array_b[tmp] = value;
    }
    
    for(i = 0; i < MAX; i++)
    {
        if(array_a[i] || array_b[i])
        {
            sum[i] = array_a[i] + array_b[i];
            if(fabs(sum[i]) > 1e-6)
            count ++;
            
        }
    }
    
    printf("%d",count);
    for(i = MAX - 1; i >= 0; i--)
    {
        if(sum[i])
        {
            if(fabs(sum[i]) > 1e-6)
            printf(" %d %.01f",i,sum[i]);
        }

    }
    
    return  0;
    
    
    
}

