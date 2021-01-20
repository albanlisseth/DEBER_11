
/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS
 * LISSETH ALBAN
 * DEBER#11 - Regresión lineal exponencial
*/

float x=0;      //para evaluar un punto de x
float y=0;      //Predicción de Y
float ElnY=0;   //Sumatoria lnY
float ExlnY=0;  //Sumatoria xlnY
float Ex2=0;    //Sumatoria x^2
float Ex=0;     //Sumatoria x^2
int   aux=0;    //Para que no se imprima todo el tiempo
float a=0;
float b=0;


//Matriz de información
int matriz[14][2]={
{170,67},
{180,80},
{170,65},
{178,75},
{160,55},
{163,60},
{165,63},
{170,70},
{164,62},
{176,77},
{164,60},
{170,76},
{170,56},
{168,60},
};

int n=14;

void setup() {
Serial.begin(9600);
for (int fil = 0; fil < n; fil++) 
{
Ex=matriz[fil][0]+Ex; 
ElnY=log(matriz[fil][1])+ElnY;
ExlnY=log(matriz[fil][1])*matriz[fil][0]+ExlnY;
Ex2=matriz[fil][0]*matriz[fil][0]+Ex2;
}
a=((n*ExlnY)-(Ex*ElnY))/((n*Ex2)-Ex*Ex);
b=exp(((Ex2*ElnY)-(ExlnY*Ex))/((14*Ex2)-Ex*Ex));
}

void loop() {
   if (Serial.available())
   {
      x = Serial.parseFloat();
      y = b*exp(a*x);
   }
   if (aux==0){
   Serial.println("Ingrese altura en cm para estimar un peso correspondiente en Kg:\n");
   aux=1;
}
   else if (x!=0) {
   Serial.print(y);
   Serial.println(" Kg\n");
   aux=0;}
delay(1000);
}
