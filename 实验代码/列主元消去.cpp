    #include<conio.h>   
    #include<stdio.h>   
    #include<math.h>   
    #include<stdlib.h>   
    int main()   
    {   
        int n=3,i,j,k,s;   
        double max,sum,t,l;   
        printf("??????? n:");   
        scanf("%d",&n);   
        double **p;   
     p=(double **)malloc(n*sizeof(double));              
        double *q;   
     q=(double *)malloc(n*sizeof(double));   
        for(i=0;i<n;i++)   
        p[i]=(double *)malloc((n+1)*sizeof(double));      
        printf("??????????? :\n\n");   
        for(i=0;i<n;i++)   
            for(j=0;j<n+1;j++){   
                printf("p[%d][%d]=",i,j);   
                scanf("%lf",&p[i][j]);}   
        for(k=0;k<n;k++)   
        {   
              
           s=k;                        /*?????*/   
           max=fabs(p[k][k]);                
           for(j=k+1;j<n;j++)        
           {   
              if(max<fabs(p[j][k]))   
              {    
                max=fabs(p[j][k]);    
                s=j;   
              }                   
           }   
           if(max==0)   
           {   
              printf("\n???????");   
              getch();    
              exit(0);     
           }    
         if(s!=k)   
            for(j=k;j<n+1;j++)    
            {   
               t=p[k][j];p[k][j]=p[s][j];p[s][j]=t;     /*????????k??,??s?????k?§ß???*/             
            }       
         for(i=k+1;i<n;i++)                 /*???*/    
            {   
               l=p[i][k]/p[k][k];   
               for(j=k;j<=n;j++)    
                p[i][j]=p[i][j]-l*p[k][j];    
            }    
         }   
         if(p[n-1][n-1]==0)   
         {   
            printf("\n???????!");   
            getch();    
            exit(0);                
         }   
        q[n-1]=p[n-1][n]/p[n-1][n-1];            /*???*/    
        for(i=n-2;i>=0;i--)   
        {   
          sum=0;    
          for(j=i+1;j<n;j++)    
            sum+=p[i][j]*q[j];    
          q[i]=(p[i][n]-sum)/p[i][i];                                 
        }   
        printf("\n\n??????\n\n");   
        for(i=0;i<n;i++)   
           printf("x%d=%lf\n",i+1,q[i]);   
        getch();           
        return 0;              
    }            

