#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <limits.h>

//Definitions about gravities
#define Pi 3.1416
#define gt 9.81
#define gt20 9.80665215960352001615
#define luna 1.635
#define Io 1.796
#define Europa 1.314
#define Ganimedes 1.428
#define Fobos 0.0057
#define Deimos 0.003
#define Titan 1.352
#define Rea 0.127

//Prefunctions
double rad(double a);
double VoX(double Vo, double a);
double VoY(double Vo, double a);
double distance(double VoX, double tv);
double h(double VoY, double t);
double h2(double VoY, double t);
void hss(double VoY, double t);
double errorAbs(double p, double Ppri);
double errorRel(double p, double Ppri);

//Main
int main(){
    int n;
    double Vo,a,arad,x,y,T,dH,dV,dV2;
    T = 0.1;

    //Initial velocity value
    printf("Give me Vo:\n");
    scanf("%lf",&Vo);

    //Angel Value
    printf("Give me the angle:\n");
    scanf("%lf",&a);

    //Conversion to radians
    arad = rad(a);

    //VoX
    x = VoX(Vo,arad);
    printf("VoX: %lf\n",x);

    //VoY
    y = VoY(Vo,arad);
    printf("VoY: %lf\n",y);

    printf("How many times do you want to check the operation? the time wil vary from 0.1 to 0.01 then 0.001 consecutively\n");
    scanf("%d",&n);

    for(int i =0; i<n;i++){
        printf("Test No:%d\n",i+1);
        
        dH = distance(x,T);
        printf("Horizontal distance: %lf\n",dH);

        printf("Using 2 significant values\n");
        dV = h(y,T);
        printf("Vertical distance: %lf\n",dV);
        printf("----------------------------------------------------------------------------------------------\n");

        printf("Using 20 significant values\n");
        dV2 = h2(y,T);
        printf("Vertical distance: %lf\n",dV2);
        printf("----------------------------------------------------------------------------------------------\n");

        printf("Vertical distance in the moon and the others satellites of different planets\n");
        hss(y,T);
        printf("----------------------------------------------------------------------------------------------\n");
        T=T/10;
    }
    return 0;
}

double rad(double a){
    double Rad;
    int int_part;
    int exponent;
    double mantissa;
    Rad = a*Pi/180;

    int_part = (int)Rad;

    //First, the integer part of the number is checked.
    if(int_part > INT_MAX || int_part < INT_MIN){
        printf("There's an overflow in the integer part\n");
    }

    //Then the floating and exponential part of the number is checked.
    mantissa = frexp(Rad, &exponent);

    if(mantissa < -DBL_MAX || mantissa > DBL_MAX){
        printf("There's an overflow in the mantissa part\n");
    }

    if(exponent < -DBL_MAX || exponent > DBL_MAX){
        printf("There's an overflow in the exponent\n");
    }

    return Rad;
}

// Initial velocity in X
double VoX(double Vo, double a) {
  double vox;
  int int_part;
  int exponent;
  double mantissa;

  vox = Vo * cos(a);

  // Extract the integer part of a number
  int_part = (int)vox;

  // Check the integer part of the number
  if (int_part > INT_MAX || int_part < INT_MIN) {
    printf("There is an overflow in the integer part ): \n");
  }

  // Check the floating-point and exponential parts of the number

  mantissa = frexp(vox, &exponent);

  // Check the mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("There is an overflow in the mantissa\n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("There is an overflow in the exponent\n");
  }

  return vox;
}

// Initial velocity in Y
double VoY(double Vo, double a) {
  double voy;
  int int_part;
  int exponent;
  double mantissa;

  // Convert degrees to radians
  voy = Vo * sin(a);

  // Extract the integer part of a number
  int_part = (int)voy;

  // Check the integer part of the number
  if (int_part > INT_MAX || int_part < INT_MIN) {
    printf("There is an overflow in the integer part\n");
  }

  // Check the floating-point and exponential parts of the number

  mantissa = frexp(voy, &exponent);

  // Check the mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("There is an overflow in the mantissa\n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("There is an overflow in the exponent\n");
  }

  return voy;
}

// Calculate the horizontal distance or horizontal motion (Vox * tv)
double distance(double VoX, double tv) {
  double dHori;
  int int_part;
  int exponent;
  double mantissa;

  // Calculate the horizontal distance
  dHori = VoX * tv;

  // Extract the integer part of a number
  int_part = (int)dHori;

  // Check the integer part of the number
  if (int_part > INT_MAX || int_part < INT_MIN) {
    printf("There is an overflow in the integer part\n");
  }

  // Check the floating-point and exponential parts of the number

  mantissa = frexp(dHori, &exponent);

  // Check the mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("There is an overflow in the mantissa\n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("There is an overflow in the exponent\n");
  }

  return dHori;
}

// Calculate the vertical distance or height ((VoY * t)-1/2*(g*t)^2)
double h(double VoY, double t) {
  double height;
  int int_part;
  int exponent;
  double mantissa;

  // Calculate the height
  height = VoY * t - 0.5 * gt * pow(t, 2);

  // Extract the integer part of a number
  int_part = (int)height;

  // Check the integer part of the number
  if (int_part > INT_MAX || int_part < INT_MIN) {
    printf("There is an overflow in the integer part\n");
  }

  // Check the floating-point and exponential parts of the number

  mantissa = frexp(height, &exponent);

  // Check the mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("There is an overflow in the mantissa\n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("There is an overflow in the exponent\n");
  }

  return height;
}

// Calculate the vertical distance or height ((VoY * t)-1/2*(gtP*t)^2)
double h2(double VoY, double t) {
  double height;
  int int_part;
  int exponent;
  double mantissa;

  // Calculate the height
  height = VoY * t - 0.5 * gt20 * pow(t, 2);

  // Extract the integer part of a number
  int_part = (int)height;

  // Check the integer part of the number
  if (int_part > INT_MAX || int_part < INT_MIN) {
    printf("There is an overflow in the integer part ): \n");
  }

  // Check the floating-point and exponential parts of the number

  mantissa = frexp(height, &exponent);

  // Check the mantissa
  if (mantissa < -DBL_MAX || mantissa > DBL_MAX) {
    printf("There is an overflow in the mantissa ): \n");
  }

  // Check the exponent
  if (exponent < -DBL_MAX_EXP || exponent > DBL_MAX_EXP) {
    printf("There is an overflow in the exponent ): \n");
  }

  return height;
}

// Calculate the vertical distance of the moon and different satellites of the planets in the solar system
void hss(double VoY, double t){
    double moon,io,eur,gan,fob,dei,tit,rea;
    moon= VoY*t-(0.5)*luna*pow(t,2);
    io = VoY*t-(0.5)*Io*pow(t,2);
    eur = VoY*t-(0.5)*Europa*pow(t,2);
    gan = VoY*t-(0.5)*Ganimedes*pow(t,2);
    fob = VoY*t-(0.5)*Fobos*pow(t,2);
    dei = VoY*t-(0.5)*Deimos*pow(t,2);
    tit = VoY*t-(0.5)*Titan*pow(t,2);
    rea = VoY*t-(0.5)*Rea*pow(t,2);
    printf("Using the Moon gravity: %lf\n",moon);
    printf("**********************\n");
    printf("Using the Io gravity: %lf\n",io);
    printf("**********************\n");
    printf("Using the Europa gravity: %lf\n",eur);
    printf("**********************\n");
    printf("Using the Ganimedes gravity: %lf\n",gan);
    printf("**********************\n");
    printf("Using the Fobos gravity: %lf\n",fob);
    printf("**********************\n");
    printf("Using the Deimos gravity: %lf\n",dei);
    printf("**********************\n");
    printf("Using the Titan gravity: %lf\n",tit);
    printf("**********************\n");
    printf("Using the Rea gravity: %lf\n",rea);
    printf("**********************\n");
}