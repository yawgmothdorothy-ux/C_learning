#include<stdio.h>
int main(){
    int car_v;
    int limit_v;
    scanf("%d %d",&car_v,&limit_v);
    double rate = (car_v - limit_v) * 100.0 / limit_v;

if (rate < 10) {
    printf("OK\n");
} else if (rate < 50) {
    printf("Exceed %.0f%%. Ticket 200\n", rate);
} else {
    printf("Exceed %.0f%%. License Revoked\n", rate);
}
}