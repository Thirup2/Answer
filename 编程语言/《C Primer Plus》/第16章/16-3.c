#include <stdio.h>
#include <math.h>
#define PI 3.14
typedef struct{
    double length;
    double angle;
}polar;
typedef struct{
    double x;
    double y;
}rectangular;
rectangular p_to_t(polar pc);
int main()
{
    polar pc;
    scanf("%lf %lf",&pc.length,&pc.angle);
    pc.angle=pc.angle*(PI/180.0);
    rectangular r = p_to_t(pc);
    printf("%lf %lf\n",r.x,r.y);
    return 0;
}
rectangular p_to_t(polar pc){
    rectangular rect;
    rect.x=pc.length*cos(pc.angle);
    rect.y=pc.length*sin(pc.angle);
    return rect;
}