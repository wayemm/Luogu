#include<iostream>
using namespace std;
int main()
{
    int time,num;
    int single_time[1000],price[1000],f[100000]={0};
    int i,j;
    cin>>time>>num;
    for(i=1;i<=num;i++)        
    cin>>single_time[i]>>price[i];
    for(i=1;i<=num;i++)
    {
        for(j=time;j>=single_time[i];j--)
        {
            if(f[j]<f[j-single_time[i]]+price[i])
                f[j]=f[j-single_time[i]]+price[i];
        }
    }
        cout<<f[time]<<endl;
    return 0;
}