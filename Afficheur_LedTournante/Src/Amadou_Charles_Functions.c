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
void Attente(int n){  // Par defaut 1106
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

/*
 * Affiche un caractère sur la plaquette tournante (blooquante)
*/
void afficheChar(GPIO_TypeDef *GPIOx, int poids, unsigned char tabLettre[]){

	volatile int countlettre;
	for(countlettre = 0; countlettre < 6; countlettre++){
		GPIOx->ODR |= (0xFF << poids);
		GPIOx->ODR &= (tabLettre[countlettre] << poids);
		Attente(1106);
	}
}

/*
 * Affiche un indice du caractère sur la plaquette tournante (timer)
*/
void affiche_I_timer(GPIO_TypeDef *GPIOx, int poids, unsigned char tabLettre[], int countlettre, TIM_HandleTypeDef *htim){

	GPIOx->ODR |= (0xFF << poids);
	GPIOx->ODR &= (tabLettre[countlettre] << poids);
	HAL_TIM_Base_Start_IT(htim);

}

/*
 * Affiche n caractère sur la plaquette tournante (timer)
*/
void affiche_Nchar_timer(GPIO_TypeDef *GPIOx, int poids, char mot[], volatile int *count_indice_lettre, volatile int *count_lettre, TIM_HandleTypeDef *htim, int nb_lettre){

	if (*count_lettre < nb_lettre){
		if(*count_indice_lettre < 6){
			affiche_I_timer(GPIOx, poids, &lettre[mot[*count_lettre] - 65][0], *count_indice_lettre, htim);
			(*count_indice_lettre)++;

			if (*count_indice_lettre == 5){
				*count_indice_lettre = 0;
				(*count_lettre)++;
			}
		}

	}
}

