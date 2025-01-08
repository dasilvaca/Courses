/*sine.c
 * Description: Given any floating number X,
 * output the sine value of it. X is assumed
 * to be in radians, and it must have to be
 * in the exclusive range (0,1). To achieve
 * this is going to be used math.h library
 * and the respective conditionals using
 * correctly C datatypes.
 *
 * Made by: Daniel Santiago Silva Capera
 * For a Coursera project
 * 24/July/2020*/

#include<stdio.h>
#include<math.h>
#define pi 3.141592654
int main(void){
	//option is going to be the input that the user must to give to
	//indicate if the given value is goint to be in degrees or in rads
	unsigned short int option = 0;
	//Verify if the selected option is appropiate
	while (option == 0 || option > 2){
		printf("Input:\n[1]Radians Value\n[2]Degree value\n");
		scanf("%d", &option);
		if(option == 0||option > 2){
			printf("try again\n");
		};
	};
	// uses valid in the verification of x limits
	short int valid = 1;
	//x is going to be the number in which sine is going to be applied
	double x = -1;
	//transforms x into radians if it's needed	
	while (x > 1 || x < 0){

		printf("\nPlease, input any floating point number to apply sine: ");
		scanf("%lf", &x);
		if (option == 2){
			x = x * pi/ 180.0;
		};
		if (x > 1 || x < 0){
			printf("try again\n");
		}
	};
	
	printf("\n %lf", sin(x));
	return 0;
	}

	


