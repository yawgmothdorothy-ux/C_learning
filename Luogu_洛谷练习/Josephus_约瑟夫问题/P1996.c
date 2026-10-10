#include<stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int p[n];
    int i =0;
    for (i=0;i<n;i++){
        p[i]=1;
    }
    int count =0;
    int m_counter = 0;
    int person = n;

    if(m == 1){
        for(int i=0;i<n;i++){
            printf("%d ",i+1);
        }
        return 0;
    }
    while(person >0){
        if(p[count%n] == 1 && m_counter != m){
            
            m_counter++;
            
            if(m_counter == m){
                p[count%n] = 0;
                person --;
                m_counter = 0;
                printf("%d ",(count)%n + 1);
            }
  

            count ++;
        }else{
            count ++;
        }
    }
}