/*  coin_amount
 *  Implementation of the problem from the Skriptim of (p. 22) "Programmazione Procedurale e Logica" 
 *  Universita degli Studi di Urbino "Carlo Bo" Corso di Laurea in Informatica Applicat
 *
 *  Copyright (c) 2013 Julian Sparber <julian@sparber.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
#include <stdio.h>
/*increas this to also include banknotes*/
#define AMOUNT_OF_COINS 8 

int main ()
{
	int i;
	/*2^i costruito recorsivamente = Potenza*/
	int Potenza = 1;
	/*variabile temporanea*/
	int CurrentCoin = 0;
	/*array per la moneta*/
	int AmountCoins [AMOUNT_OF_COINS];
	int CashValue = 0;
	/*2^n + offset_2 + offset_10*/
	double offset_2 = 0.25;
	int offset_10 = 0;
	/*al inizio dobbiamo aspetare 5 step dopo ogni 3 step dobbiamo aumentare offset_10 per offset*10*/
	int n = 0;
	/*offset iniziale dopo 5 step*/
	int offset = 10;
	
	for (i = 0; i < AMOUNT_OF_COINS; i++)
	{
		/*calcolare l' offset*/
		CurrentCoin = Potenza + offset_2 + offset_10;
					
		if (CurrentCoin < 100)
		{
			if (CurrentCoin == 1)
				printf("Please enter the sum of %d cent coin\n", CurrentCoin);
			else
				printf("Please enter the sum of %d cent coins\n", CurrentCoin);
		}
		else
		{
			if (CurrentCoin == 100)
				printf("Please enter the sum of %d Euro coin\n", CurrentCoin/100);
			else
				printf("Please enter the sum of %d Euros coins\n", CurrentCoin/100);
		}
		scanf("%d", &AmountCoins[i]);
		
		CashValue += AmountCoins[i] * CurrentCoin;
		/*calcolare ricorsiva mente il nuovo valore*/
		Potenza += Potenza;
		offset_2 +=  offset_2;
		n++;
		offset_10 += offset_10;
		
		if (n == 5)
		{
			offset_10 += offset;
			n = 2;
			offset *= 10;
		}	
	}
	printf("Thx you for entring the sum of coins!\n\n");
	printf("The sum of all coins is: %d in Cents and %d,%d in Euros\n", CashValue, CashValue/100, CashValue - (CashValue/100)*100);
	return 0;
}
