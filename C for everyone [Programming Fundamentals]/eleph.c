/* Average of elephant weights [eleph.c]
 * calculates the average of the weights of elephants stored into a file,
 * the amount of data is unknowned, so with stdio.h and stdlib.h libraries
 * the file is read, added every weight and finally outputs the average with
 * some useful data.
 * Written by: Daniel Santiago Silva Capera
 * 09/11/2020*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
	//Define the pointer of the file
	FILE *fp;
	//Define and initialize sum (storing the sum the weight of all the elephants),
	//count(storing the amount of elephants) and actualNumber(the number isbeing read).
	int sum = 0, count = 0, actualNumber = 0;
	//Opens the file with the data. In this case for tests I used "All data" as file name,
	//that is stored in the same folder of the source and compiled file.
	fp = fopen("All the data","r");
	//Warns if there was a problem openning the file
        if (fp == NULL){   
              printf("Error! Could not open file\n"); 
              exit(-1);
	}
	//Scan each integer number and stores it in the temporal variable actualNumber,
	//then each value is added into sum, and counted to know its average.
	while (fscanf(fp,"%d\t",&actualNumber)==1){
		sum += actualNumber;
		count++;
	}
	//fp (our pointer of the file) is closed, because we already read the data onto it
	fclose(fp);
	//prints the tuncated average value
	printf("The average of the %d elephants in the file is: %d\n",count, sum/count);
	return 0;
}

