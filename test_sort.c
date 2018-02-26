#include <stdio.h>
#include <stdlib.h>
const int Num=50;  
const int Scale=8;//小数组阀值 
void exch(int* s,int a,int b)//交换  
{  
        int mid=s[a];  
        s[a]=s[b];  
        s[b]=mid;  
}  
void Move(int* s,int a,int b)//移动  
{  
        int mid=s[a];  
        for(int i=a;i>b;i--)  
        {  
                s[i]=s[i-1];  
        }  
        s[b]=mid;  
}  
void InsertSort(int* s,int low,int up)//插入排序  
{  
        for(int i=low+1;i<=up;i++)  
        {  
                for(int j=low;j<i;j++)  
                {  
                        if(s[i]<s[j])  
                                Move(s,i,j);  
                }  
        }  
}  
int QSort(int* s,int low,int up)//快速排序  
{  
        if(up<=low+Scale)//是小数组时采用插入排序  
        {  
            InsertSort(s,low,up);  
            return 0;  
        }  
        else  
        {  
                int key=s[low];  
                int i=low;  
                int j=up;  
                up++;  
                while(low<up)  
                {  
                        low++;  
                        while(low<up&&s[low]<=key)  
                                low++;  
                        up--;  
                        while(low<=up&&s[up]>=key)  
                                up--;  
                        if(low<up)  
                                exch(s,low,up);  
                }  
                exch(s,i,up);  
                QSort(s,i,up-1);  
                QSort(s,up+1,j);  
        }  
}  
  
int main()  
{  
        int array[Num];  
        srand(2);//初始化随机数  
        for(int i=0;i<Num;i++)//初始化数组0到100之间  
        {  
                array[i]=rand() % 101;  
        }  
        for(int i=0;i<Num;i++)//输出原数组  
        {  
                printf("%d ",array[i]);  
        }  
        QSort(array,0,Num-1);  
        printf("\n");  
        for(int i=0;i<Num;i++)  
        {  
                printf("%d ",array[i]);  
        }  
    return 0;  
}  