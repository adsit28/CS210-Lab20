/** lab20functs.c
 * ===========================================================
 * Name:
 * Section:
 * Project: Lab 20
 * Purpose:
 * ===========================================================
 */

#include <stdbool.h>
#include "lab20functs.h"

double fToC(double degF){ 
    return (degF - 32.0)*(5.0/9.0);
}

double cToK(double degC){ 
    return degC + 273.15;
}

void printTable(double degFlow, double degFhigh, double degFstep){
    fprintf(stdout, "\n|--------------------------------|\n");
    fprintf(stdout, "|                                |\n");
    fprintf(stdout, "|         Temperature Conversions|\n" );
    fprintf(stdout, "|                                |\n");
    fprintf(stdout, "|--------------------------------|\n");
    fprintf(stdout, "|Fahrenheit|  Celsius |  Kelvin  |\n");
    fprintf(stdout, "|--------------------------------|\n");
    while(degFlow <= degFhigh){
        fprintf(stdout, "|    %10.2lf|    %10.2lf|    %10.2lf|\n", degFlow, fToC(degFlow), cToK(fToC(degFlow)));
        degFlow = degFlow + degFstep;
    }
    fprintf(stdout, "|--------------------------------|\n");
}

double getInput(char message[], double min, double max) {  
    double userIn = 0.0;
    bool working = false;
    fprintf(stdout, "%s", message);
    fscanf(stdin, "%lf", &userIn);
    while(working == false){
        if(userIn < max && userIn > min){
            working = true;
        }   
        else{
            fprintf(stdout,"Your input is outside of the range <MIN VALUE -- 2 decimal points> to <MAX VALUE -- 2 decimal points>.\nPlease re-enter.");
            fscanf(stdin, "%lf", &userIn);
        }
    }
    return userIn;
}

bool again(){
    char doAgain = ' ';
    bool decision;
    fprintf(stdout, "Would you like to do this again?");
    fscanf(stdin, " %c", &doAgain);
    if(doAgain == 'y' || doAgain == 'Y'){
        decision = true;
    }
    else{
        decision = false;
    }
    return decision;
}
