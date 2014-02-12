//
//  main.c
//  1011
//
//  Created by apple on 14-2-3.
//  Copyright (c) 2014年 zju. All rights reserved.
//  Sample Input
/*
 1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98
*/
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i;
    double t,w,l;
    double max[3];
    int order[3];
    double multiply = 1;
    for(i = 0; i < 3; i++)
    {
       scanf("%lf %lf %lf",&w,&t,&l);
        if (w >= t) {
            if(w < l)
            {
                max[i] = l;
                order[i] = 3;
            }
            else
            {
                max[i] = w;
                order[i] = 1;
            }
        }
        else if(w < t)
        {
            if(l > t)
            {
                max[i] = l;
                order[i] = 3;
            }
            else
            {
                max[i] = t;
                order[i] = 2;
            }
        }
        
    }
    
    for (i = 0; i < 3; i++) {
        switch (order[i]) {
            case 1:
                printf("W ");
                break;
            case 2:
                printf("T ");
                break;
            case 3:
                printf("L ");
                break;
                
            default:
                break;
        }
        
        multiply *= max[i];
    }
    
    double result = (multiply*0.65-1)*2;
    
    printf("%.2lf\n",result);
    
    return 0;
   
   
}

