/*Project.c
 * This program must print a series of sine and cosine function table
 * To achieve this, there are going to be used stdio.h and math.h libraries
 * Also, the values on the table must have to be in the range [0,1]
 * Made by: Daniel Santiago Silva Capera
 * 07/August/2020*/

#include<stdio.h>
#include<math.h>

int main(void){

	//the variable rows is going to say how many rows the table is going to have
	int rows;
	//Asks how many items do the user want in the table to set the rows variable
	printf("How many rows are going to be printed in the table?\nPlease, input an integer number(greater than 1):");
	scanf("%d", &rows);
	--rows; //rows are decreased in 1 to have the initial number of rows
	printf("x\t\tsin(x)\t\tcos(x)\n");//prints table header
	double step = 1/(float)rows;//is going to indicate how much do the i value must have to grow
	//initialize i variable which sine and cosine are going to be applied
	// get the values in the inclusive range [0,1] with steps indicated before
	for(double i = 0.0;i<=1.0 + step;i+=step){
		printf("%lf\t%lf\t%lf\n",i,sin(i),cos(i));//prints every row with their values
	}
		
	return 0;
}

