#include "calendar.h"


void print(int MM, int YYYY)
{
	/* Your code comes here */
	/* Mon = 0, Tue = 1, 
	Wed = 2, Thu = 3, Fri = 4,
	 Sat = 5, Sun = -1, */
	/*Get last two digits*/
	int num, count = -1;
	int day = 1;
	num = dayOfWeek(YYYY,MM) - 1;


	printf("\n%3s%3s%3s%3s%3s%3s%3s\n","Su", "Mo", "Tu", "We", "Th", "Fr", "Sa");
	/*Print first Row*/
	/*Count each day of month format*/
	while (count < 38){
		/*if the count in month format is less than current 
		day of week print empty space*/
		if(count < num || count > 38){
			printf("%3s", "");
		} 
		/*Once count reaches the starting day print day*/
		else if(day < 32) {
			/*if february and/or a leap year do 28/29 days*/
			if(MM == 02 && day == 30 && isLeapYear(YYYY) == 0) {
				break;
			} else if(MM == 02 && day == 29 && isLeapYear(YYYY) != 0) {
				break;
			} 
			printf("%2d ", day++);
			if(count == 0) {
				//do nothing if count is 0
			} /*count == 12 || count == 19 || count == 26 || count == 33*/
			else if(count == 5 || (count - 5) % 7 == 0){
				printf("\n");
			}
		}
		count++;
	}
	printf("\n");

}
void handlePrint(void)
{
	/* Your code comes here */
	char date1[25];
	int m, y;
	getCommandWord(date1, 25);
	date1[2] = '\0';
	m = getMonth(date1);
	y = getYear(date1 + 3);
	print(m,y);

}

/*Returns the day code*/
/*https://www.hackerearth.com/blog/developers/how-to-find-the-day-of-a-week/
this is the source code from where i got this formula
*/
int dayOfWeek(int year, int month)
{
	int day = 1;
	int codes[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	year -= month < 3;
	return (year + year/4 - year/100 + year/400 + codes[month -1] + day) % 7;
}

/*Returns the month code */
int monthCode(int month, int year)
{
	switch (month)
	{
	case 1:
		if (isLeapYear(year) == 0)
			return 5;
		else
			return 6;
	case 2:
		if (isLeapYear(year) == 0)
			return 1;
		else
			return 2;
	case 3:
	case 11:
		return 2;
	case 4:
	case 7:
		return 5;
	case 5:
		return 0;
	case 6:
		return 3;
	case 8:
		return 1;
	case 9:
	case 12:
		return 4;
	case 10:
		return 6;
	}
return -1;
}