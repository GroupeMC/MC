/*
 * Amadou_Charles_Functions.h
 *
 *  Created on: 19 févr. 2020
 *      Author: chalo
 */

#ifndef AMADOU_CHARLES_FUNCTIONS_H_
#define AMADOU_CHARLES_FUNCTIONS_H_

	#include "stm32f0xx_hal.h"

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
	 * Affiche un caractère sur la plaquette tournante
	*/
	void afficheChar(GPIO_TypeDef *GPIOx, int poids, unsigned char tabLettre[]);



#endif /* AMADOU_CHARLES_FUNCTIONS_H_ */
