#include<bits/stdc++.h>
using namespace std;
union UnionA{
    int a;
    double b;
};
int main(){
    UnionA A;
    A.a = 5;
    cout << A.a << endl;
    A.b = 7.6;
    cout << A.a << endl;
    cout << A.b << endl;
    
}