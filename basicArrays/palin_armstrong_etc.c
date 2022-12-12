//Program to count palindrome, prime, armstrong, and sum of digits<10
#include <iostream>
#include <cmath>

using namespace std;

//function to give reverse of a number
bool checkPalin(int x){
    int n=0, xcopy=x;
    while(x!=0){
        n=x%10+n*10;
        x/=10;
    }
    return n==xcopy? true: false;
}
//to check prime
bool checkPrime(int x){
    for(int i=2;i<=x/2;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
//to check if sum of digits is less than 10
bool checkSum(int x){
    int sum=0;
    while(x!=0){
        sum+=x%10;
        x/=10;
    }
    return sum<10? true: false;
}
//to check if number is armstrong or not
bool checkArmstrong(int x){
    int sum=0, n=x;
    while(x!=0){
        sum+=pow(x%10, 3);
        x/=10;
    }
    return sum==n? true: false;
}

int main(){
    
    int n, pa=0, pr=0, ar=0, ten=0;
    cout<<"INPUT:\n";
    scanf("%d", &n);
    int *p = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d",(p+i));
        int d= *(p+i);
        
        if(checkPalin(d))
            pa++;
        if(checkPrime(d))
            pr++;
        if(checkArmstrong(d))
            ar++;
        if(checkSum(d))
            ten++;
    }
    cout<<"OUTPUT:\n";
    cout<<"Palindrome: "<<pa<<endl;
    cout<<"Prime: "<<pr<<endl;
    cout<<"Armstrong: "<<ar<<endl;
    cout<<"Sum of digits less than 10: "<<ten<<endl;
    return 0;
}
