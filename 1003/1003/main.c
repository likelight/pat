//
//  main.c
//  1003
//
//  Created by apple on 14-2-4.
//  Copyright (c) 2014年 zju. All rights reserved.
//
/*
 5 6 0 2
 1 2 1 5 3
 0 1 1
 0 2 2
 0 3 1
 1 2 1
 2 4 1
 3 4 1
 */

#include <stdio.h>
#define MAX 501
#define MAX_DISTANCE 10000000
int map[MAX][MAX];
int help[MAX];
int S[MAX];
int dist[MAX];
int Visit[MAX];

int min_value;
int count = 0;
int max_value = 0;


void dijkstra(int n,int start,int end)
{
    //init
    int i,j,point;
    int min;
    
    int tmp_value;
    for(j = 0; j < n; j++)
    {
        dist[j] = map[start][j];
        S[j] = 0;
        
    }
    
   
    
    S[start] = 1;  //add the start;
    
    for(i = 0; i < n-1; i++)
    {
        min = MAX_DISTANCE;
        point = 0;
        for(j = 0; j < n;  j++)
        {
            if(min > dist[j] && !S[j])
            {
                min = dist[j];
                point = j;
            }
        }
        
        S[point] = 1; // added the new number into 
        
        for(j = 0; j < n; j++)
        {
            if((dist[j] > dist[point] + map[point][j]) && map[point][j] < MAX_DISTANCE)
            {
                dist[j] = dist[point] + map[point][j];
                
            }
        }
    
    }
    
}




void dfs(int n,int start,int end,int final_value,int tmp)
{
    int i;
    Visit[start] = 1;
    if(start == end)
    {
        if(final_value == dist[end])
        {
            
            count ++;
            if(max_value < tmp )
            {
                max_value = tmp;
            }
        }
        return;
    }
    
    if(final_value > dist[end])
    {
        return;
    }
    
        
    for(i = 0; i < n; i++)
    {
        if(!Visit[i] && map[start][i] < MAX_DISTANCE)
        {
            int tm = final_value + map[start][i];
            dfs(n,i,end,tm,tmp+help[i]);
            Visit[i] = 0;
        }
    }
    
    
}




int main(int argc, const char * argv[])
{
    int n,m,c1,c2;
    int i,j;
    int a,b;
    int value;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    
    for(i = 0; i < n; i++)
    {
        help[i] = 0;
        for(j = 0 ; j < n; j++)
        {
            if(i != j)
            {
                map[i][j] = MAX_DISTANCE;
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }
    
    for(i = 0; i < n; i++)
    {
        scanf("%d",&help[i]);
    }
    
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d",&a,&b,&value);        
        map[a][b] = value;
        map[b][a] = value;
        
    }
    
    
    dijkstra(n,c1,c2);
    
    for(i = 0; i < n; i ++)
    {
        Visit[i] = 0;
    }
    
    dfs(n,c1, c2, 0,help[c1]);
    
    printf("%d %d\n",count,max_value);
    
    return 0;
    
    
    
    
    
}

