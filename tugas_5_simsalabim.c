#include <stdio.h>

struct Date {
  int day;
  int month;
  int year;
};

int isLeapYear(int year);
void nextDay(struct Date *date);

int main() {
  struct Date currentDate;

  printf("Masukkan tanggal (format: dd/mm/yyyy): ");
  scanf("%d/%d/%d", &currentDate.day, &currentDate.month, &currentDate.year);

  nextDay(&currentDate);

  printf("Tanggal berikutnya adalah: %d/%d/%d\n", currentDate.day,
         currentDate.month, currentDate.year);

  return 0;
}

int isLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

void nextDay(struct Date *date) {
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (date->month == 2 && isLeapYear(date->year)) {
    daysInMonth[2] = 29;
  }

  if (date->day < daysInMonth[date->month]) {
    date->day++;
  } else {
    date->day = 1;
    date->month++;
    if (date->month > 12) {
      date->month = 1;
      date->year++;
    }
  }
}