//Created By: Peter Maksymowsky
//Created On: Sunday, April 9, 2018
//Time Taken: ~1 hour

//Description:
//	This program is meant to compute prime numbers. I added a little bit of functionality by giving the user some options. They can choose how many primes to calculate,
//and whether to print each prime, or store it for later when they can then querry for the n(th) prime as many times as they need.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

void generatePrimesAndPrint(unsigned long long maxAmount);
void generatePrimesInArray(unsigned long long maxAmount, unsigned long long primeArray[]);

int main(void) {
	//using unsigned long longs in case the user wants to wait a while
	unsigned long long amountToFind, primeToFind;
	char printChoice, continueChoice = 'y';

	//prompts
	printf("How many Numbers would you like to generate? ");
	scanf("%llu", &amountToFind);
	printf("Would you like to print each number? (y/n) ");
	scanf(" %c", &printChoice);
	
	printChoice = (char)toupper((int)printChoice);
	
	if (printChoice == 'Y') {
		generatePrimesAndPrint(amountToFind);
	} else {
		unsigned long long primeArray[amountToFind];
		generatePrimesInArray(amountToFind, primeArray);
		
		
		while (continueChoice == 'Y') {
			printf("Would you like to find the n(th) prime number (y/n)? ");
			scanf(" %c", &continueChoice);
			continueChoice = (char)toupper((int)continueChoice);
			
			if(continueChoice == 'Y') {
				printf("n(th) prime: ");
				scanf(" %llu", &primeToFind);
				
				//if statements to get correct grammar for printing
				if (primeArray[primeToFind] % 10 == 1) {
					printf("The %llust prime number is: %llu\n", primeToFind, primeArray[primeToFind]);
				} else if (primeArray[primeToFind] % 10 == 2) {
					printf("The %llund prime number is: %llu\n", primeToFind, primeArray[primeToFind]);
				} else if (primeArray[primeToFind] % 10 == 3) {
					printf("The %llurd prime number is: %llu\n", primeToFind, primeArray[primeToFind]);
				} else {
					printf("The %lluth prime number is: %llu\n", primeToFind, primeArray[primeToFind]);
				}
			}
		}
		
	}
	
	return(0) ;
}

void generatePrimesAndPrint(unsigned long long maxAmount){
	unsigned long long amount = 0;
	for (unsigned long long number = 2; amount < maxAmount; number ++) {
		bool prime = true;
		
		
		for (unsigned long long diviser = 2; diviser <= number/2; diviser ++) {
			if (number % diviser == 0) {
				prime = false;
			}
		}
		
		if (prime) {
			amount ++;
			if (amount % 10 == 1) {
				printf("The %llust prime number is: %llu\n", amount, number);
			} else if (amount % 10 == 2) {
				printf("The %llund prime number is: %llu\n", amount, number);
			} else if (amount % 10 == 3) {
				printf("The %llurd prime number is: %llu\n", amount, number);
			} else {
				printf("The %lluth prime number is: %llu\n", amount, number);
			}
		}
	}
}



void generatePrimesInArray(unsigned long long maxAmount, unsigned long long primeArray[]) {
	unsigned long long amount = 0;
	for (unsigned long long number = 2; amount < maxAmount; number ++) {
		bool prime = true;
		
		
		for (unsigned long long diviser = 2; diviser <= number/2; diviser ++) {
			if (number % diviser == 0) {
				prime = false;
			}
		}
		
		if(prime) {
			amount ++;
			primeArray[amount] = number;
		}
	}
}