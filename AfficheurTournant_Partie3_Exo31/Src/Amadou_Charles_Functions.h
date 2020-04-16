/*
 * Amadou_Charles_Functions.h
 *
 *  Created on: 19 févr. 2020
 *      Author: chalo
 */

#ifndef AMADOU_CHARLES_FUNCTIONS_H_
#define AMADOU_CHARLES_FUNCTIONS_H_

	#include "stm32f0xx_hal.h"

	extern unsigned char lettre[26][6];

	/*
	 * Eteindre la led
	*/
	void RESET_PATTE(GPIO_TypeDef *GPIOx, int NumPatte);

	/*
	 * Allumer la led
	*/
	void SET_PATTE(GPIO_TypeDef *GPIOx, int NumPatte);

	/*
	 * Allumer les 8 leds
	*/
	void SET_BUS(GPIO_TypeDef *GPIOx, int poids);

	/*
	 * Eteindre les 8 leds
	*/
	void RESET_BUS(GPIO_TypeDef *GPIOx, int poids);

	/*
	 * Fonction Attente
	*/
	void Attente(int n);

	/*
	 * Lire l'entrée n° N d'un port GPIO
	 * Renvoie soit 0 soit 1, suivant l'état de l'entrée
	*/
	int LIRE_ENTREE(GPIO_TypeDef *GPIOx, int N);

	/*
	 * Affiche d'une colonne sur la plaquette tournante
	*/
	void affiche_Colonne(GPIO_TypeDef *GPIOx, int poids, unsigned const char Motif_Afficheur[], volatile int count_indice_lettre);

	void incremente_heure(volatile int *heu_d, volatile int *heu_u, volatile int *min_d, volatile int *min_u, volatile int *sec_d, volatile int *sec_u);

	void affiche_heure(GPIO_TypeDef *GPIOx, int poids, volatile int heu_d, volatile int heu_u, volatile int min_d, volatile int min_u, volatile int sec_d, volatile int sec_u, volatile int count_indice_lettre, volatile int count_i);

#endif /* AMADOU_CHARLES_FUNCTIONS_H_ */
