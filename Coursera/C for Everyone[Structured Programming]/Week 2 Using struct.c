/*
 * Made by: Daniel Santiago Silva Capera
 * 7/March/2021
 *
 * Assignment using struct (GENERAL)
 *
 * Description: Given a dete (in day month format) output the next day.
 */

#include<stdio.h>


// Define an enum struct with each month, starting by one to ge easier calculations later

typedef enum month{jan = 1,feb,mar,apr,may,jun,jul,ago,sep,oct,nov,dec} month;

// Define an struct with user defined type month and an integer to specify month and date
// respectively
typedef struct date{month m;int d;}date;

//Lets build next Date function. It's going to receive an User defined type date
//that's going to be the actual day.

date nextDate(date prevDay){
    // In each case, it's evaluated if the prevDay.d (the day) is the last of the month
    // To achieve that we can observe that the months before August and are not divisible by 2
    // In the bijection we build in enum (Jan = 1, March = 3, etc) just ends in 31 days. 
    // And after July the pattern is at the contrary way, those divisible by 2 ends in 31 days.
    // When it's founded that the day in preDay is the last one, we set it to 1 and increment
    // the month in one unit.

    // Our special case is February, which is the only month with 28 days
    if (prevDay.m == feb){
	if (prevDay.d == 28) {
	    prevDay.m = mar;
	    prevDay.d = 1;
	}
	else prevDay.d = prevDay.d + 1;
    }
    else if (prevDay.m < jul){
	if((prevDay.m % 2)) {
	    if (prevDay.d == 31){
		prevDay.m += 1;
		prevDay.d = 1;
	    }
	    else prevDay.d ++;
	}
	else{
	    if (prevDay.d == 30){
		prevDay.d = 1;
		prevDay.m ++;
	    }
	    else prevDay.d ++;
	}
    }
    else {
	if ((prevDay.m % 2)){
	    if (prevDay.d == 30){
		prevDay.d = 1;
		prevDay.m ++;
	    }
	    else prevDay.d ++;
	}
	else{
	    if (prevDay.d == 31){
		prevDay.d = 1;
		//This is also an special case, because if the month is December, it must return to January, which
		//is the next. For that we use modulo operator. (12 % 12 is 0, then, the next must be 1)
		prevDay.m = ((prevDay.m + 1) % 12) + 1;
	    }
	    else prevDay.d ++;
	}
    }
    return prevDay;
}

void printDate(date theDate){
    // Prints out the corresponding date according to it's month
    // So, we use a switch case statement and concatenate the day number.
    switch (theDate.m){
	case jan:
	    printf("Jan %d", theDate.d);
	    break;
	case feb:
	    printf("Feb %d", theDate.d);
	    break;
	case mar:
	    printf("Mar %d", theDate.d);
	    break;
	case apr:
	    printf("Apr %d", theDate.d);
	case may:
	    printf("May %d", theDate.d);
	    break;
	case jun:
	    printf("Jun %d", theDate.d);
	    break;
	case jul:
	    printf("Jul %d", theDate.d);
	    break;
	case ago:
	    printf("Aug %d", theDate.d);
	    break;
	case sep:
	    printf("Sep %d", theDate.d);
	    break;
	case oct:
	    printf("Oct %d", theDate.d);
	    break;
	case nov:
	    printf("Nov %d", theDate.d);
	    break;
	case dec:
	    printf("Dec %d", theDate.d);
	    break;
	default:
	    printf("Something went wrong :c");
	    break;
    }
}

int main(){
    // We declare two dates: the actual and the next of it.
    date actualDate, nextDay;
    // Ask to user for a date in day month format
    printf("Please input your date (DD MM): ");
    //  We store the date that the user input in actualDate
    scanf("%d %d", &actualDate.d, &actualDate.m);
    // we keep the next date to actualDate in nextDay
    nextDay = nextDate(actualDate);
    //We call printDate method to show actualDate and the next
    printf("The next date to ");
    printDate(actualDate);
    printf(" is ");
    printDate(nextDay);
    return 0;
    
}
