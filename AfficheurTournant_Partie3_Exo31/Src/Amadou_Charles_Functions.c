/*
 * Amadou_Charles_Functions.c
 *
 *  Created on: 19 févr. 2020
 *      Author: chalo
 */

#include "Amadou_Charles_Functions.h"
#include "LibCaracteres.h"

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
 * Affiche d'une colonne sur la plaquette tournante
*/
void affiche_Colonne(GPIO_TypeDef *GPIOx, int poids, unsigned const char Motif_Afficheur[], volatile int count_indice_lettre){

	GPIOx->ODR |= (0xFF << poids);
	GPIOx->ODR &= (Motif_Afficheur[count_indice_lettre] << poids);

}

void incremente_heure(volatile int *heu_d, volatile int *heu_u, volatile int *min_d, volatile int *min_u, volatile int *sec_d, volatile int *sec_u){

	(*sec_u)++;
	if ((*sec_u) == 10){
	  (*sec_d)++;
	  (*sec_u) = 0;
	}

	if ((*sec_d) == 6){
	   (*min_u)++;
	   (*sec_u) = 0;
	   (*sec_d) = 0;
	}

	if ((*min_u) == 10){
	   (*min_d)++;
	   (*sec_u) = 0;
	   (*sec_d) = 0;
	   (*min_u) = 0;
	}

	if ((*min_d) == 6){
	   (*heu_u)++;
	   (*sec_u) = 0;
	   (*sec_d) = 0;
	   (*min_u) = 0;
	   (*min_d) = 0;
	}


	if ((*heu_d) < 2){

	   if ((*heu_u) == 10){
		   (*heu_d)++;
		   (*sec_u) = 0;
		   (*sec_d) = 0;
		   (*min_u) = 0;
		   (*min_d) = 0;
		   (*heu_u) = 0;
	   }
	}
	else{

	   if ((*heu_u) == 4){
		   (*heu_d)++;
		   (*sec_u) = 0;
		   (*sec_d) = 0;
		   (*min_u) = 0;
		   (*min_d) = 0;
		   (*heu_u) = 0;
		   (*heu_d) = 0;
	   }

	}
}

void affiche_heure(GPIO_TypeDef *GPIOx, int poids, volatile int heu_d, volatile int heu_u, volatile int min_d, volatile int min_u, volatile int sec_d, volatile int sec_u, volatile int count_indice_lettre, volatile int count_i){
	switch (count_indice_lettre/6){
	case 0:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[heu_d + 48][0], count_i );
	  break;

	case 1:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[heu_u + 48][0], count_i );
	  break;

	case 2:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[58][0], count_i );
	  break;

	case 3:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[min_d + 48][0], count_i );
	  break;

	case 4:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[min_u + 48][0], count_i );
	  break;

	case 5:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[58][0], count_i );
	  break;

	case 6:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[sec_d + 48][0], count_i );
	  break;

	case 7:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[sec_u + 48][0], count_i );
	  break;

	default:
	  affiche_Colonne(GPIOA, 0, &Lib_Caract_8x6[0][0], count_i );
	  break;


	}
}

