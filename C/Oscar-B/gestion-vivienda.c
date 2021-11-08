#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int lim = 0, estrato = 0, precio = 0, numEjecuciones = 0;

  system("clear");

  printf("\n****************************\nConstructora Vivienda Fedora\n****************************\n");
  printf("\n * * Clasificación del subsidio de vivienda segun el estrato * *\n");
  printf("\n--------Categoría I: Estratos 1 - 2");
  printf("\n--------Categoría II: Estratos 3 - 4");
  printf("\n--------Categoría III: Estratos 5 o 6");

  printf("\n\nIngrese la cantidad de registros a realizar:\n >> ");
  scanf("%d",&lim);

  char nombres[lim][10];
  int cedulas[lim], estratos[lim],  categorias[lim], precios[lim], beneficios[lim];
  float contadores[3] = {0,0,0}, acumuladores[3] = {0,0,0}, porcentajes[3];
  
  printf("\nPresione ENTER para continuar...");
  getchar();
  getchar();
  system("clear");
  
  for (int i = 0 ; i < lim ; i++){
    numEjecuciones++;
    printf("\n****************************\nConstructora Vivienda Fedora\n****************************\n");
    
    printf("\nIngrese su nombre: ");
    scanf("%s",&nombres[i][0]);
    printf("Ingrese su cédula: ");
    scanf("%d",&cedulas[i]);
    printf("Ingrese estrato al que pertenece 1-6: ");
    scanf("%d",&estrato);
    estratos[i] = estrato;

    if(1 <= estrato && estrato <= 6){
      printf("\nIngrese precio de Vivienda en millones de pesos:\n>>");
      scanf("%d",&precio);
      if(0 <= precio){
        precios[i]=precio;
        if(estrato == 1 || estrato == 2){
            categorias[i] = 1;
            contadores[0]++;
            acumuladores[0]=acumuladores[0]+precio;
            if(precio<=80 && precio>=0){
            printf("\nRecibe beneficio del 10 %%");
            beneficios[i] = 10;
            }
            else{
            printf("\nRecibe beneficio del 5 %%");
            beneficios[i] = 5;
            }
        }
        if(estrato == 3 || estrato == 4){
            categorias[i] = 2;
            contadores[1]++;
            acumuladores[1]=acumuladores[1]+precio;
            if(0<=precio && precio<=100){
              printf("\nRecibe beneficio del 8 %%");
              beneficios[i] = 8;
            }
            if(100<precio && precio<=160){
              printf("\nRecibe beneficio del 10 %%");
              beneficios[i] = 10;
            }
            if(160<precio){
                printf("\nRecibe beneficio del 12 %%");
                beneficios[i] = 12;
            }
          }
        if(estrato == 5 || estrato == 6){
          categorias[i] = 3;
          contadores[2]++;
          acumuladores[2]=acumuladores[2]+precio;
          printf("\nNo aplican subsidios");
          beneficios[i] = 0;
        }
      }
      else{
        printf("\nx x xPrecio inválido. Digite una opción correcta o salga del sistema si desea x x x");
        i--;
      }
    }
    else{
      printf("\nx x x Estrato inválido. Digite una opción correcta x x x");
      i--;
    }
    printf("\n\nPresione ENTER para continuar... ");
    getchar();
    getchar();
    system("clear");
  }

  porcentajes[0] = (contadores[0]/lim)*100;
  porcentajes[1] = (contadores[1]/lim)*100;
  porcentajes[2] = (contadores[2]/lim)*100;

  printf("\n****************************\nConstructora Vivienda Fedora\n****************************\n");
  printf("\nTotal de registros: %d",lim);
  printf("\nAcumulado categoria 1: %.1f millones", acumuladores[0]);
  printf("\nAcumulado categoria 2: %.1f millones",acumuladores[1]);
  printf("\nAcumulado categoria 3: %.1f millones",acumuladores[2]);
  printf("\n%% de registros de la categoria 1: %.2f%%",porcentajes[0]);
  printf("\n%% de registros de la categoria 2: %.2f%%",porcentajes[1]);
  printf("\n%% de registros de la categoria 3: %.2f%%",porcentajes[2]);
  printf("\nEl programa se ejecutó: %d veces",numEjecuciones);

printf("\n\nTabla de resumen de usuarios");
printf("\n\nNombre\tCédula\tEstrato\tCategoría\tPrecio\t%% beneficio");
for(int i = 0; i < lim; i++){
printf("\n%s\t%d\t%d\t\t%d\t\t%d\t\t%d",nombres[i],cedulas[i],estratos[i],categorias[i],precios[i],beneficios[i]);
}

  printf("\n\nPresione ENTER para continuar... ");
  getchar();
  getchar();
  return 0;
}