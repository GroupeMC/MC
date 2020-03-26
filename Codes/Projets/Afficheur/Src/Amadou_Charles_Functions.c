/*
 * Amadou_Charles_Functions.c
 *
 *  Created on: 19 févr. 2020
 *      Author: chalo
 */

#include "Amadou_Charles_Functions.h"

/*
 * Eteindre la led
*/
void RESET_PATTE(GPIO_TypeDef *GPIOx, int NumPatte){

	GPIOx->ODR |= (0x1 << NumPatte);
}

/*
 * Allumer la led
*/
void SET_PATTE(GPIO_TypeDef *GPIOx, int NumPatte){

	GPIOx->ODR &= ~(0x1 << NumPatte);
}

/*
 * Allumer les 8 leds
*/
void SET_BUS(GPIO_TypeDef *GPIOx, int poids){

	GPIOx->ODR &= ~(0xFF << poids);

}

/*
 * Eteindre les 8 leds
*/
void RESET_BUS(GPIO_TypeDef *GPIOx, int poids){

	GPIOx->ODR |= (0xFF << poids);

}

/*
 * Fonction Attente
*/
void Attente(int n){
	volatile int i;
	for (i = 0; i<n; i++){};
}

/*
 * Lire l'entrée n° N d'un port GPIO
 * Renvoie soit 0 soit 1, suivant l'état de l'entrée
*/
int LIRE_ENTREE(GPIO_TypeDef *GPIOx, int N){

	if (GPIOx->IDR & (0x1 << N)) {
		return 1;
	}
	else {
		return 0;
	}
}

