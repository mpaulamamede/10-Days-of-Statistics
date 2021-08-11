#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    //input do usuário: número de elementos no vetor array[].
    int numElem = 0;       
    do{
        printf("number of elements in the array: ");
        scanf("%d", &numElem);
    }while(numElem<10 || numElem>2500);    
    
    //input do usuário: elementos do vetor array[].
    double array[numElem];   
    int arrayfreq[numElem];//vetor de frequência de cada elemento.
    int i = 0;
    printf("array elements: ");
    for(i=0; i<numElem; i++){
        do{            
            scanf("%lf", &array[i]);
        }while(array[i]<=0 || array[i]>100000);   
        
        arrayfreq[i] = -1;//preenchendo com 1 arrayfreq[] que armazena a frequência de cada elemento.
    }

    //ordenando o vetor array[] em ordem crescente.
    int j = 0;
    int l = 0;
    for(i=0; i<numElem; i++){
        for(j=i+1; j<numElem; j++){
            if(array[i]>array[j]){
                l = array[i];
                array[i] = array[j];
                array[j] = l;
            }   
        }
    }

    //teste print array[] ordenado.
    /*printf("\n");
    for(i=0; i<numElem; i++){
        printf("%.1f ", array[i]);
    }*/
    
    //calculando média simples dos elementos do vetor array[].
    double sum = 0;
    double mean = 0;
    for(i=0; i<numElem; i++){
        sum += array[i];
    }
    mean = sum/numElem;
    printf("Mean: %.1f ", mean);   

    //calculando mediana entre os elementos do vetor array[].
    double median = 0;
    if(numElem%2!=0){
        median = array[numElem/2];
    }else if(numElem%2==0){
        median = (array[numElem/2]+array[(numElem/2)-1])/2;
    }
    printf("Median: %.1f ", median);

    //Checando quantas vezes cada número aparece em array[] e preenchendo arrayfreq[] com a frequência.
    int freq = 0;
    for(i=0; i<numElem; i++){
        freq = 1;
        for(j=i+1; j<numElem; j++){
            if(array[i]==array[j]){
                freq++;
                arrayfreq[j] = 0;
            }
        }
        if(arrayfreq[i]!=0){
            arrayfreq[i] = freq;
        }
    }

    //garantindo que elementos iguais em array[] tenham a mesma frequência em arrayfreq[].
    for(i=0; i<numElem; i++){
        for(j=i+1; j<numElem; j++){
            if(array[i]==array[j]){
                arrayfreq[j] = arrayfreq[i];
            }
        }
    }

    //teste print arrayfreq[].
    /*printf("\n");
    for(i=0; i<numElem; i++){
        printf("%d ", arrayfreq[i]);
    }*/

    //calculando a moda.
    int mode = 0;
    int modefreq = 0;
    int modein = 0;
    for(i=0; i<numElem; i++){
        for(j=i+1; j<numElem; j++){
            if(arrayfreq[i]>arrayfreq[j] && arrayfreq[i]>modefreq){
                modefreq = arrayfreq[i];
                modein = i;
                mode = array[i];                
            }else if(arrayfreq[i]>arrayfreq[j] && arrayfreq[i]==modefreq){
                if(array[i]<array[modein]){
                    mode = array[i];
                }else if(array[i]>array[modein]){
                    mode = array[modein];
                }
            }else if(arrayfreq[i]==arrayfreq[j] && arrayfreq[i]>=modefreq){
                if(array[i]<array[j] && array[i]<array[modein]){
                    mode = array[i];
                }else if(array[j]<array[i] && array[j]<array[modein]){
                    mode = array[j];
                }else if(array[modein]<array[i] && array[modein]<array[j]){
                    mode = array[modein];
                }
            }
        }
    }    
    printf("Mode: %d", mode);    
   
    return 0;
}
