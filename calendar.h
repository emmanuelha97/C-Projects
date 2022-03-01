#include<stdio.h>
#include<string.h>
#define MAX_COMMAND_TOKEN_LENGTH 15
char getCommandWord(char command[], int maxLength);
int getMonth(char token[]);
int getDay(char token[]);
int getYear(char token[]);
int monthDays(int month, int year);
int isValidDate(int month, int day, int year);
int compareTo(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear);
void handleCount(void);
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear);
void handlePrint(void);
int isLeapYear(int year);
/*Returns amount of days in a given year if leap (366) or not (365)*/
int amountOfDays(int year);

/*Returns amounts of days in curren year with date month and day */
int daysFromBeg(int year, int month, int day);

/*Determine days between months*/
int daysBetweenMon(int startYear, int endYear);

/*Month Code functions*/
int monthCode(int month, int year);

/*Returns the day code*/
int yearCode(int year, int month);

/*Determine day of week*/
int dayOfWeek(int year, int month);

