//
//  main.cpp
//  Homework3-4
//
//  Created by christopher kha on 2/9/19.
//  Copyright © 2019 christopher kha. All rights reserved.
//

#include <iostream>
using namespace std;

int countIncludes(const double a1[], int n1, const double a2[], int n2)
{
    if(n2 <= 0){
        return 1;
    }
    if(n1 <= 0){
        return 0;
    }
    
    int count = 0;
    
    if(a1[0] == a2[0]){
        count += countIncludes(a1+1, n1-1, a2+1, n2-1);
    }
    count += countIncludes(a1+1, n1-1, a2, n2);

    return count;
}

// Exchange two doubles
void exchange(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

void divide(double a[], int n, double divider,
            int& firstNotGreater, int& firstLess)
{
    if (n < 0)
        n = 0;
    
    firstNotGreater = 0;
    firstLess = n;
    int firstUnknown = 0;
    while (firstUnknown < firstLess)
    {
        if (a[firstUnknown] < divider)
        {
            firstLess--;
            exchange(a[firstUnknown], a[firstLess]);
        }
        else
        {
            if (a[firstUnknown] > divider)
            {
                exchange(a[firstNotGreater], a[firstUnknown]);
                firstNotGreater++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n)
{
    if(n <= 1)
        return;
    
    int notGreater, less = 0;
    divide(a, n, a[0], notGreater, less);
    
    order(a, notGreater);
    order(a+less, n-less);
}

int main() {
    double a1[] = { 50, 20, 20, 30, 30, 50, 20 };
    double a2[] = { 50, 30, 20 };
    
    double a3[] = { 53, 234, 61, 1, -34 };
    double a4[] = { 1, 5, 6 };
    
    cout << countIncludes(a1, 7, a2, 3) << endl << endl;
    
    
    order(a1, 7);
    for(int i = 0; i < 7; i++){
        cout << a1[i] << endl;
    }
    cout<<endl;
    
    order(a2, 3);
    for(int i = 0; i < 3; i++){
        cout << a2[i] << endl;
    }
    cout<<endl;
    
    order(a3, 5);
    for(int i = 0; i < 5; i++){
        cout << a3[i] << endl;
    }
    cout<<endl;
    
    order(a4, 3);
    for(int i = 0; i < 3; i++){
        cout << a4[i] << endl;
    }
}
