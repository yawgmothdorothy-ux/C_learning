#include<stdio.h>
#include<math.h>
#include<float.h>

int main(){
    double x[3];
    double y[3];
    for(int i=0;i<3;i++){
        if (scanf("%lf %lf", &x[i], &y[i]) != 2) {
            return 0;
        }
    }
    double p = (x[2] - x[1]) * (y[0] - y[1]);
    double q = (y[2] - y[1]) * (x[0] - x[1]);
    double cross = p - q;
    double tolerance = 16 * DBL_EPSILON * (fabs(p) + fabs(q));
    if (fabs(cross) <= tolerance){
        printf("Impossible\n");
        return 0;
    }
    double a = hypot(x[2] - x[1], y[2] - y[1]);
    double b = hypot(x[0] - x[2], y[0] - y[2]);
    double c = hypot(x[1] - x[0], y[1] - y[0]);

    double perimeter = a + b + c;
    double area = fabs(cross) / 2.0;

    printf("L = %.2lf, A = %.2lf\n",perimeter,area);
    return 0;


}
