#include<iostream>  
#include<cmath>  
using namespace std;  
int main()  
{  
    int m, n, num;  
    cin>>m;  
    while(m--){  
        cin>>n;  
        if(n == 0){  
            cout<<3<<endl;  
            if(m)  cout<<endl;  
            continue;  
        }  
        n = (int)fabs(n);  
        num = (int)sqrt(n);  
        while(1){  
            if(num * (num + 1) >= 2 * n ){  
                if(!(num & 1) && !((num / 2 * (num + 1) - n) & 1)){ //避免num * (num + 1)直接相乘益处  
                    break;  
                }else if((num & 1) && !(((num + 1) / 2 * num - n) & 1))  
                    break;  
            }  
            num++;  
        }  
        cout<<num<<endl;  
        if(m)  cout<<endl;  
    }  
    return 0;  
}  
