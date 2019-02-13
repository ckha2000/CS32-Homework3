//
//  main.cpp
//  Homework3-2
//
//  Created by christopher kha on 2/6/19.
//  Copyright © 2019 christopher kha. All rights reserved.
//

bool anyTrue(const double a[], int n)
{
    if(n <= 0)
        return false;
    
    bool curr = somePredicate(a[0]);
    return (curr || anyTrue(a+1, n-1));
}


int countTrue(const double a[], int n)
{
    if(n<=0)
        return 0;
    
    int count = countTrue(a+1, n-1);
    
    if(somePredicate(a[0]))
        count++;
    
    return count;
}


int firstTrue(const double a[], int n)
{
    if(n <= 0)
        return -1;
    
    if(somePredicate(a[n-1]) && (firstTrue(a, n-1) == -1))
        return n-1;
    else
        return firstTrue(a, n-1);

    return -2;
}


int positionOfMin(const double a[], int n)
{
    if(n <= 0)
        return -1;
    if(n == 1)
        return 0;
    
    int min = positionOfMin(a, n-1);
    if(min != -1){
        if(a[min] <= a[n-1])
            return min;
        else
            return n-1;
    }
    return -2;
}


bool includes(const double a1[], int n1, const double a2[], int n2)
{
    if(n2 <= 0)
        return true;
    if(n2 > n1)
        return false;
    
    if(a1[0] == a2[0])
        return includes(a1+1, n1-1, a2+1, n2-1);
    else
        return includes(a1+1, n1-1, a2, n2);
    
    return false;
}
