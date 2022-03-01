#include"calendar.h"
/* This file contains count function and 
some relevant functions
*/

int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	/* Your code comes here */
	int total, temp, temp2;
	int temp1 = 0;
	int daysOfYears = 0;
	if(compareTo(fromMonth, fromDay, fromYear, toMonth, toDay, toYear) == 0){
			return 0;
	} 
	else if (compareTo(fromMonth, fromDay, fromYear, toMonth, toDay, toYear) < 0) {
		/* Check if years are the same */
		if(fromYear == toYear){
			/* Check if months are the same */
			if(fromMonth == toMonth) {
				/* return the difference in days */
				total = toDay - fromDay;
				return total;
			} 
			/* Months are not the same */
			else {
				total = monthDays(fromMonth, fromYear);
				total = total - fromDay;
				
				/*total is number of days in current month until next month*/
				/*for loop to count number of months in between*/
				for(int i = fromMonth + 1; i < toMonth; i++){

					total = total + monthDays(i,fromYear);
				}

				/*Total now has all days up to 1 month before*/
				/*Make a temporay value to store amount of days of the toMonth*/
				temp = toDay;
				/*Add both together*/
				total = total + temp;
				return total;
			}

		}
		/*Years do not match*/
		 else {
			/*Assigns temp the amount of days in year*/
			temp = amountOfDays(fromYear);
			/*Assigns temp 1 the amount of days in the months from the beginning of the year*/
			temp1 = daysFromBeg(fromYear, fromMonth, fromDay);
			/*temp 2 has amount of days remaining in year*/
			temp2 = temp - temp1;

			/*daysOfYears has amount of days in between fromYear + 1 and the toYear - 1*/
			daysOfYears = daysBetweenMon(fromYear,toYear);
			total = temp2 + daysOfYears;	

			/*Repeating here*/
			temp = 0;
			temp1 = 0;
			temp2 = 0;
			/*Assigns temp the amount of days in year*/
			temp = amountOfDays(toYear);
			/*temp currently holds amount of days in whole year*/
			temp1 = daysFromBeg(toYear, toMonth, toDay);
			/*Repeating here*/
			total = total + temp1;

			return total ;
		}
	} 
	else {
		/* Check if years are the same */
		if(toYear == fromYear){
			/* Check if months are the same */
			if(toMonth == fromMonth) {
				/* return the difference in days */
				total = fromDay - toDay;
				return total;
			} 
			/* Months are not the same */
			else {
				total = monthDays(toMonth, toYear);
				total = total - toDay;
				
				/*total is number of days in current month until next month*/
				/*for loop to count number of months in between*/
				for(int i = toMonth + 1; i < fromMonth; i++){

					total = total + monthDays(i,toYear);
				}

				/*Total now has all days up to 1 month before*/
				/*Make a temporay value to store amount of days of the fromMonth*/
				temp = fromDay;
				/*Add both together*/
				total = total + temp;
				return total;
			}

		}
		/*Years do not match*/
		 else {
			/*Assigns temp the amount of days in year*/
			temp = amountOfDays(toYear);
			/*Assigns temp 1 the amount of days in the months from the beginning of the year*/
			temp1 = daysFromBeg(toYear, toMonth, toDay);
			/*temp 2 has amount of days remaining in year*/
			temp2 = temp - temp1;

			/*daysOfYears has amount of days in between toYear + 1 and the toYear2 - 1*/
			daysOfYears = daysBetweenMon(toYear,fromYear);
			total = temp2 + daysOfYears;	

			/*Repeating here*/
			temp = 0;
			temp1 = 0;
			temp2 = 0;
			/*Assigns temp the amount of days in year*/
			temp = amountOfDays(fromYear);
			/*temp currently holds amount of days in whole year*/
			temp1 = daysFromBeg(fromYear, fromMonth, fromDay);
			/*Repeating here*/
			total = total + temp1;
			/*After determing days convert to negative*/
			total = -total;
			return total ;
		}
	}
	return -1;

}
int getMonth(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the month
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 12)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getDay(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' || token[1] < '0' || token[1]> '9')
		return 0;//error in retrieving the day
	n = 10 * (token[0] - '0') + token[1] - '0';
	if (n > 31)
		return 0;//error, month should be from 1 and 12...
	return n;
}

int getYear(char token[]) {
	int n;
	if (token[0] < '0' || token[0]> '9' ||
		token[1] < '0' || token[1]> '9' ||
		token[2] < '0' || token[2]> '9' ||
		token[3] < '0' || token[3]> '9')
		return 0;//error in retrieving the year
	n = 1000 * (token[0] - '0') + 100 * (token[1] - '0') + 10 * 
	(token[2] - '0') + token[3] - '0';
	return n;
}
void handleCount(void) {
	/* Your code comes here */
	char date1[25];
	char date2[25];
	int d1, m1, y1, d2, m2, y2, amount_Days;
	getCommandWord(date1, 25);
	getCommandWord(date2, 25);

	if(date1[2] != '/' &&  date1[5] != '/' &&  date2[2] != '/' && date2[5] != '/' ){{
		fprintf(stderr, "Error: invalid dates passed to count command1\n");
	}}
	
	date1[2] = date1[5] = date2[2] = date2[5] = '\0';
	m1 = getMonth(date1);
	m2 = getMonth(date2);
	d1 = getDay(date1 + 3);
	d2 = getDay(date2 + 3);
	y1 = getYear(date1 + 6);
	y2 = getYear(date2 + 6);

	if (m1 * m2 * d1 * d2 * y1 * y2 == 0){
		fprintf(stderr, "Error: invalid dates passed to count command");
	}

	printf("\nDate 1: %d/%d/%d\nDate 2: %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
	amount_Days = count(m1, d1, y1, m2, d2, y2);
	printf("\nThe amount of days is %d\n", amount_Days);

}
int monthDays(int month, int year) {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	return -1;
}
int isValidDate(int month, int day, int year) {
	return year >= 1 && month >= 1 && month <=12 && day >= 1 && day <= monthDays(month, year);
}
int compareTo(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	//returns negative int if from date < to date
	//return zero if from date == to date
	//returns positive int otherwise
	if (fromYear != toYear)
		return fromYear - toYear;
	if (fromMonth != toMonth)
		return fromMonth - toMonth;
	return fromDay - toDay;
}
int isLeapYear(int year) //97 leap years in every 400 years... 365 days + 97/400
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);//2000, 2020, 1600, 2024, 2016,... are leap years...
	//1900, 1800, 1700, 2100, 2002, 2019,... are not leap years...
}

/*My Functions*/

int amountOfDays(int year){
	/*Get amount of days in year*/
	if(isLeapYear(year) == 0){
		/*366 days*/
		return 365;
	} else {
		/*365 days*/
		return 366;
	}
}

int daysFromBeg(int year, int month, int day){
	int temp1 = 0;
	/*if month is not january*/
			if(month != 1){
				/*For loop starts at first month of current year and */
				/*continues until before current month of current year */
				for(int i = 1; i < month; i++){
					temp1 = temp1 + monthDays(i, year);
				}
				temp1 = temp1 + day;
			} 
			/*if january use current days*/
			else {
				temp1 = day;
			}
			return temp1;
}

int daysBetweenMon(int startYear, int endYear){
	int days = 0;
	/*For loop starts at first year after current year and */
	/*continues until before year of current year */
	for(int i = startYear + 1; i < endYear; i++){
		if(isLeapYear(i) == 0){
		/*366 days*/
		days = days + 365;
	} else {
		/*365 days*/
		days = days + 366;
	}
	}
	return days;

}