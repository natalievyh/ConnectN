#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"


bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); 
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n'); 
  return formatIsGood;
}


int getValidInt(const char* prompt){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num);
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

double getValidDouble(const char* prompt){
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num); 
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

bool inbetween(int val, int lowerBound, int upperBound){
  return val >= lowerBound && val <= upperBound;
}

bool my_isspace(char c){
	return c == ' ' || c == '\n' || c == '\t';
}

int getValidIntInRange(int lowerBound, int upperBound){
  int num;
  do{
    printf("Enter a number between %d-%d: ", lowerBound, upperBound);
    num = getValidInt("");
  }while(!(inbetween(num, lowerBound, upperBound)));

  return num;
}

int getPosInt(){
	int num;
  do{
    num = getValidInt("Enter a positive number: ");
  }while(!(num > 0));

  return num;
}




int getNegInt(){
  int num;
  do{
    num = getValidInt("Enter a negative number: ");
  }while(!(num < 0));

  return num;
}

int getIntAtLeast(int min_val, const char* prompt){
  int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= min_val));

  return num;
}

double getDoubleAtLeast(double min_val, const char* prompt){
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}