/*  https://github.com/jg2kpy
    Student at Polytechnic of the National University of Asunción
    Estudiante en Facultad Politecnica de la Universidad Nacional de Asuncion
    https://www.pol.una.py/ 
*/

#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

double xo = 0;
double yo = 0;
double x = 0;
double h = 0;

double funtion(double x, double y){
    return y-x; 
}

double euler(){
    int N = abs(((x - xo)/h)) + 1;
    double xn,yn;
    xn = xo;
    yn = yo;
    printf("\nDEBUG: x%d,y%d = (%lf,%lf)\n",0,0,xn,yn);
    for (int i = 1; i <= N; i++){
        xn = xn + h;
        yn = yn + h*funtion(xn,yn);
        printf("DEBUG: x%d,y%d = (%lf,%lf)\n",i,i,xn,yn);
    }
    return yn;
}

void funcTutorial();

int main(int argc, char *argv[]){
    char tutorial = '1';
    printf("\nPress the key 0 and enter to the tutorial, any other character to skip the tutorial\n");
    scanf("%c",&tutorial);
    if(tutorial == '0'){
        funcTutorial();
    }
    if(argc==1){
        printf("\nPlese enter the data: \n");
        printf("xo yo X H\n");
        scanf("%lf %lf %lf %lf",&xo,&yo,&x,&h);
    }else if(argc==5){
        xo = atof(argv[1]);
        yo = atof(argv[2]);
        x = atof(argv[3]);
        h = atof(argv[4]);
    }else{
        printf("ERROR IN ARGUMENT\n");
        exit(EXIT_FAILURE);
    }
    printf("\nThe approximation for the value %lf is: %lf",x,euler());
    return EXIT_SUCCESS;
}

void funcTutorial(){
    printf("\n\nTUTORIAL:\n\nIf the following is displayed on the screen: \n\n");

    printf("\"Plese enter the data: \n");
    printf("xo yo X H\"\n\n");

    printf("You must enter the data as follows; first the initial value of x, a space,\n");
    printf("the initial value of y, a space, the X of the Y that you want to calculate, a space,\n");
    printf("and finally the precision level, that is, the H, then press the enter key\n\n");

    printf("If you want to use the program with arguments, the order in which you\n");
    printf("must enter the data is: the initial value of x, the initial value of y, the x \n");
    printf("of the y that you want to calculate, the precision level.\n\n\n");
}