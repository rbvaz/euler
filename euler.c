/*  https://github.com/jg2kpy
    Student at Polytechnic of the National University of Asunción
    Estudiante en Facultad Politecnica de la Universidad Nacional de Asuncion
    https://www.pol.una.py/ 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double xo = 0;
double yo = 0;
double x = 0;
double h = 0;

double funtion(double x, double y){
    return (1+pow(y,2.0))/4;
}

double euler(){
    int N = abs(((x - xo)/h)) + 1;
    double xn,yn,yn2;
    xn = xo;
    yn = yo;
    yn2 = yn;
    printf("\nDEBUG: x%d,y%d = (%lf,%lf)\n",0,0,xn,yn);
    for (int i = 1; i <= N; i++){
        xn = xn + h;
        yn2 = yn + h*funtion(xn,yn);
        yn = yn + (h/2)*(funtion(xn,yn)+funtion(xn,yn2));
        printf("DEBUG: x%d,y%d = (%lf,%lf)\n",i,i,xn,yn);
    }
    return yn;
}

void funcTutorial();
void funcTutorialEsp();

int main(int argc, char *argv[]){
    if(argc==5){
        xo = atof(argv[1]);
        yo = atof(argv[2]);
        x = atof(argv[3]);
        h = atof(argv[4]);
    }else if(argc==1){
        char tutorial = '1';
        printf("\nPress the key 0 and enter to the tutorial, any other character to skip the tutorial\n");
        printf("\nPresione 0 y enter para ver el tutorial, cualquier otro caracter para no ver\n");
        scanf("%c",&tutorial);
        if(tutorial == '0'){
            char idioma = '0';
            do {
                if(idioma != '\n' && idioma != '\r') { //no desplegar segunda vez por el querido \n que le sigue a los caracteres
                    printf("1 - Espanol\n");
                    printf("2 - English\n");
                }
                scanf("%c",&idioma);
            } while(idioma != '1' && idioma != '2');
            
            if(idioma == 2) funcTutorial();
            else funcTutorialEsp(); 
        }
        
        printf("\nPlese enter the data: \n");
        printf("xo yo X H\n");
        scanf("%lf %lf %lf %lf",&xo,&yo,&x,&h);
    }else{
        printf("ERROR IN ARGUMENT\n");
        fprintf(stderr,"ERROR IN ARGUMENT");
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

void funcTutorialEsp(){
    printf("\n\nTUTORIAL:\n\nSi se muestra lo siguiente en la pantalla: \n\n");

    printf("\"Ingresar los siguientes datos: \n");
    printf("xo yo X H\"\n\n");

    printf("Se deben dar los datos como sigue; primero el valor incial de x, un espacio,\n");
    printf("valor inicial de y, un espacio, la X de la Y que se quiere calcular, un espacio,\n");
    printf(" y finalmente la precisión, eso es, la H, luego apretar enter.\n\n");

    printf("Si quiere usar el programa con argumentos, el orden en que debe poner los valores es\n");
    printf("valor inicial de x, valor inicial de y, la x \n");
    printf("de la y que se quiere calcular, nivel de precisión.\n\n\n");
}