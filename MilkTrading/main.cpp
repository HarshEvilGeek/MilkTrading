//
//  main.cpp
//  MilkTrading
//
//  Created by Akhil Verghese on 4/18/13.
//  Copyright (c) 2013 Akhil Verghese. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <cstdio>

namespace IO

{
    
    const int SIZE = 1 << 19;
    
    char buff[SIZE], *p = buff + SIZE;
    
    char read_char()
    {
        if( p == buff + SIZE )
        {
            fread( buff, 1, SIZE, stdin );
            p = buff;
        }
        return *(p++);
    }
    
    inline int read_int()
    {
        char c;
        bool flag=true;
        while( !isdigit( c = read_char() ) )if(c=='-') flag=false;
        int r = c-'0';
        while( isdigit( c = read_char() ) ) r = 10*r + c - '0';
        if(flag) return r;
        else return -r;
    }
}

using namespace IO;
using namespace std;

inline int min(int a,int b)
{
    return (a<b)?(a):(b);
}

int milk[1000003];

int main()
{
    int n,i,j;
    n=read_int();
    
    for(i=0;i<n;i++)
        milk[i]=read_int();
    
    long long t,cost=0;
    
    for(i=0,j=0;i<n;i++)
    {
        while(milk[i]<0)
            i++;
        
        while(j<i)
        {
            if(milk[j]<0)
            {
                t=min(-milk[j],milk[i]);
                milk[j]+=t;
                milk[i]-=t;
                cost+=t*(i-j);
                if(milk[i]==0)
                    break;
            }
            j++;
        }
        
        if(i+1<n)
        {
            milk[i+1]+=milk[i];
            cost+=milk[i];
            milk[i]=0;
        }
    }
    
    printf("%lld",cost);
    
    return 0;
}
