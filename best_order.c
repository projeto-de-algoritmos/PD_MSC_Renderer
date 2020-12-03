/*
     *	- Problema: Best Order, URI 2919 - https://www.urionlinejudge.com.br/judge/en/problems/view/2919
     *	- Codigo por: © Erick Giffoni e Elias Bernardo
     *	- Universidade de Brasilia, 2020
     *	
*/

#include <stdio.h>
#include <stdlib.h>

#define type float

int main(){

    type n;
    while(scanf(" %f", &n)!=EOF){
        type * numbers = (type *) calloc(n, sizeof(type));
        type * list = (type *) calloc(n, sizeof(type));

        for(int i=0; i<n; i++){
            scanf(" %f", &numbers[i]);
        }

        for(int j=0; j<n; j++){
            list[j] = 1;
            for(int i=0; i<j; i++){
                if(numbers[i] < numbers[j] && 1+list[i] > list[j]){
                    list[j] = 1+list[i];
                }
            } 
        }

        type bigger = 0;
        for(int i=0; i<n; i++){
            if(bigger < list[i]){
                bigger = list[i];
            }
        }

        printf("%.0f\n", bigger);
    }

    return 0;
}