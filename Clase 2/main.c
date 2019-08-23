#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
edad(0-100)
altura(1-2 mts)
sexo(m/f)
hasta que la persona quiera*
*altura de la mujer mas vieja*
*altura del hombre mas joven*
*sexo de la persona mas alta*
*edad del hombre mas bajo*
*promedio de edades*
*promedio altura de hombre
*/
int main()
{
    char sexo,seguir='s',sexoMasAlta;
    int edad,edadMujerMasVieja,flagVieja=0,minimaEdad,flagJoven=0,edadHombreJoven,flagMasAlta=0,edadHombreBajo,flagHombreBajo=0;
    int contadorPersonas=0,acumuladorEdades=0;
    float altura,alturaMujerMasVieja,alturaHombreJoven,AlturaMax,alturaHombreBajo,promedioEdades;
    do
    {

        printf("Ingrese edad(0-100):");
        scanf("%d",&edad);
        while(edad<0||edad>100)
        {
            printf("Reingrese edad(0-100):");
            scanf("%d",&edad);
        }

        printf("\nIngrese altura(1-2mts):");
        scanf("%f",&altura);
        while(altura>2||altura<1)
        {
            printf("\nReingrese altura(1-2mts):");
            scanf("%f",&altura);
        }

        printf("\nIngrese sexo(f/m):");
        fflush(stdin);
        scanf("%c",&sexo);
        sexo=tolower(sexo);
        while(sexo!='f' && sexo!='m')
        {
            printf("\nReingrese sexo(f/m):");
            fflush(stdin);
            scanf("%c",&sexo);
            sexo=tolower(sexo);
        }

        if(sexo=='f')
        {
            if(flagVieja==0 || edad>edadMujerMasVieja)
            {
                edadMujerMasVieja=edad;
                alturaMujerMasVieja=altura;
                flagVieja=1;
            }
        }
        else{
            if(flagJoven==0||edad<edadHombreJoven)
            {
                edadHombreJoven=edad;
                alturaHombreJoven=altura;
                flagJoven=1;
            }
            if(flagHombreBajo==0||alturaHombreBajo>altura)
            {
                flagHombreBajo=1;
                alturaHombreBajo=altura;
                edadHombreBajo=edad;
            }

        }

        if(flagMasAlta==0 || AlturaMax<altura)
        {
            AlturaMax=altura;
            sexoMasAlta=sexo;
            flagMasAlta=1;
        }



        printf("\nDesea continuar?(s/n):");
        fflush(stdin);
        scanf("%c",&seguir);
        acumuladorEdades=acumuladorEdades+edad;
        contadorPersonas++;

        system("cls");
    }
    while(seguir=='s');
    promedioEdades=(float)acumuladorEdades/contadorPersonas;
    if(flagVieja==1)
        printf("\nLa altura de la mujer mas vieja es:%.2f\n",alturaMujerMasVieja);
    if(flagJoven==1)
        printf("\nLa altura del hombre mas joven es:%.2f\n",alturaHombreJoven);
    if(flagHombreBajo==1)
        printf("\nLa edad del hombre mas bajo es:%d\n",edadHombreBajo);
    if(flagMasAlta==1)
        printf("\nEl sexo de la persona mas alta es:%c\n",sexoMasAlta);
    printf("\nEl promedio de edades es:%.2f\n",promedioEdades);
    system("pause");
    return 0;
}
