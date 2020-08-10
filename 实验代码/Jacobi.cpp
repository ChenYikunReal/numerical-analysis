    #include <iostream>   
    #include<stdlib.h>   
    #include<math.h>   
    using namespace std;   
    int main()   
    {   
        float a[20][20], b[20],x_0[20],x[20];   
        int n, N,k,i,j;   
        float error;   
        printf("????????? ?????\n");   
        scanf("%d",&n);   
        printf(??????? ?????? ?? ??????\n");   
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
           
        printf("x_0 = \n");   
        for(i = 0;i <n;i++)   
        {   
            printf("x_0[%d] = ",i);   
            scanf("%f",x_0 + i);   
        }   
        k = 1;   
        float temp;   
        for(i = 0;i < n;i++)   
        {   
            temp = 0;   
            for(j = 0;j < n;j++)   
            {   
                if(j != i)   
                {   
                    temp += a[i][j] * x_0[j];   
                }   
                else   
                continue;    
            }   
            x[i] = (b[i] - temp)/a[i][i];   
        }   
        float m;   
        temp = 0;   
        for(i = 0;i <n;i++)   
        {   
            if((m = fabs(x[i] - x_0[i]))>temp)   
            {   
                temp = m;   
            }   
        }   
        while(temp > error && k <= N)   
        {   
            for(i = 0;i < n;i++)   
            {   
                x_0[i] = x[i];   
            }   
            for(i = 0;i < n;i++)   
            {   
                temp = 0;   
                for(j = 0;j < n;j++)   
                {   
                    if(j != i)   
                    {   
                        temp += a[i][j] * x_0[j];   
                    }   
                    else   
                    continue;    
                }   
                x[i] = (b[i] - temp)/a[i][i];   
            }   
            temp = 0;   
            for(i = 0;i <n;i++)   
            {   
                if((m = fabs(x[i] - x_0[i]))>temp)   
                {   
                    temp = m;   
                }   
            }   
            k++;   
        }   
        if(k< N)   
        {   
            printf("???????? k = %d\n",k);   
            for(i = 0;i < n;i++)   
            {   
                printf("x_%d = %f\t",i,x[i]);   
            }   
        }   
        else    
        {   
            printf("???? ????????????\n");   
        }   
        return 0;   
    }  

