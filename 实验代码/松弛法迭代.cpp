    #include <iostream>   
    #include<stdlib.h>   
    #include<math.h>   
    using namespace std;   
    int main()   
    {   
        float a[20][20],b[20],x[20];   
        int n,N,k,i,j;   
        float error,w,max;   
        printf("????????? ?????\n");   
        scanf("%d",&n);   
        printf("?????? ??????? ?? ??????\n");   
        for(i = 0;i < n;i++)   
        {   
            for(j = 0;j < n;j++)   
            {   
                printf("a[%d][%d] = \n",i,j);   
                scanf("%f",a[i]+j);   
            }   
            printf("b[%d]= \n",i);   
            scanf("%f",b + i);   
        }   
        printf("?????? ?????????? N = \n");   
        scanf("%d",&N);   
        printf("?????? ??????? error =\n");   
        scanf("%f",&error);   
        printf("?????? ??????? w = \n");   
        scanf("%f",&w);   
           
           
        for(i = 0;i < n;i++)   
        {   
            printf("x[%d]= ",i);   
            scanf("%f",x+i);   
        }   
        k = 1;   
        max = 0;   
        float temp;   
        for(i = 0;i <n;i++)   
        {   
            temp = 0;   
            for(j = 0;j < n;j++)   
            {   
                if(j != i)   
                {   
                    temp += a[i][j] * x[j];   
                }   
                else    
                continue;   
            }   
            temp = (1-w)*x[i] + w * (b[i] - temp)/a[i][i];   
            if(fabs(temp - x[i]) >max)   
            {   
                max = temp;   
            }   
            x[i] = temp;   
        }   
        while(max > error && k < N)   
        {   
            max = 0;   
            float temp;   
            for(i = 0;i <n;i++)   
            {   
                temp = 0;   
                for(j = 0;j < n;j++)   
                {   
                    if(j != i)   
                    {   
                        temp += a[i][j] * x[j];   
                    }   
                    else    
                    continue;   
                }   
                temp = (1-w)*x[i] + w * (b[i] - temp)/a[i][i];   
                if(fabs(temp - x[i]) >max)   
                {   
                    max = temp;   
                }   
                x[i] = temp;   
            }   
            k++;   
        }   
        if(k < N)   
        {   
            printf("???????? k = %d\n",k);   
            for(i = 0;i < n;i++)   
            {   
                printf("x[%d]= %f\t",i,x[i]);   
            }   
        }   
        else    
        {   
            printf("???? ????????????\n");   
        }   
        return 0;   
    }  

