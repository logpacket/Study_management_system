#include <stdio.h>
#include<Windows.h>
#include<conio.h>
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //윤년판정매크로

int check=0;
char day[9];
int schedule();
int task();
void title(void);
int main(void)
{
	title();
	
}
void title(void)
{
	
	int key;

	char arr[8][1000] = {
		" _______  _______  __   __  ______   __   __     __   __  _______  __    _  _______  _______  _______ ",
		"|       ||       ||  | |  ||      | |  | |  |   |  |_|  ||   _   ||  |  | ||   _   ||       ||       |",
		"|  _____||_     _||  | |  ||  _    ||  |_|  |   |       ||  |_|  ||   |_| ||  |_|  ||    ___||    ___|",
		"| |_____   |   |  |  |_|  || | |   ||       |   |       ||       ||       ||       ||   | __ |   |___ ",
		"|_____  |  |   |  |       || |_|   ||_     _|   |       ||       ||  _    ||       ||   ||  ||    ___|",
		" _____| |  |   |  |       ||       |  |   |     | ||_|| ||   _   || | |   ||   _   ||   |_| ||   |___ ",
		"|_______|  |___|  |_______||______|   |___|     |_|   |_||__| |__||_|  |__||__| |__||_______||_______|"
	};
	char arr1[10][1000] = {
		" _______  ______    _______  _______  ______    _______  __   __ ",
		"|       ||    _ |  |       ||       ||    _ |  |   _   ||  |_|  |",
		"|    _  ||   | ||  |   _   ||    ___||   | ||  |  |_|  ||       |",
		"|   |_| ||   |_ |_ |  | |  ||   | __ |   |_ |_ |       ||       |",
		"|    ___||    __  ||  |_|  ||   | | ||    __  ||       ||       |",
		"|   |    |   |  | ||       ||   |_| ||   |  | ||   _   || ||_|| |",
		"|___|    |___|  |_||_______||_______||___|  |_||__| |__||_|   |_|"
	};


	printf("\n");
	printf("\n");
	printf("\n");




	for (int i = 0; i < 7; i++) {
		printf("        ");
		printf("%s\n", arr[i]);
	}
	for (int i = 0; i < 7; i++) {
		printf("                    ");
		printf("%s\n", arr1[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                  1  ▷ 스터디 그룹 스케줄 관리 ");
	printf("                  2  ▷ 스터디 과제 관리 \n");
	

	while (1)
	{
		//입력을 받음

		key = _getch();
		switch (key)
		{
		case 49:
			schedule();
			break;
		case 50:
			task();
			break;
		case 51:
			//3번함수
			break;
		case 52:
			//4번함수
			break;
		}
	}
}

int schedule()
{
	system("cls");
	int year, month; // 연도와 월을 저장할 변수
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달의 총일 수 (첫번째 수는 제외)
	int lastyear, day, i;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("       몇년 몇월의 달력을 출력하시겠습니까?: ");
	scanf("%d %d", &year, &month);
	if (month == 2 && leapyear(year)) // 해당년도가 윤년이면, 2월은 총 29일
		totalday[2] = 29;

	lastyear = year - 1; // 작년 말까지 진행된 요일을 계산하기 위해 lastyear를 선언

	day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;


	for (i = 1; i<month; i++) // year년 month월 직전까지의 총 일 수를 구하기 위한 for문
		day += totalday[i];

	day %= 7; // year년 month월 1일의 시작 요일


	printf("\n           %d년 %d일\n", year, month); // year년 month월 타이틀 출력
	printf("\n  일  월  화  수  목  금  토"); // 요일 리스트 출력



	for (i = -day; i<totalday[month]; i++)
	{
		if ((i + day) % 7 == 0) // 출력될 차례가 일요일이면, 개행
			printf("\n");
		if (i<0) // month월 1일이 출력되기 이전의 날짜는 공백으로 채움
			printf("    ");
		else // 날짜 출력
			printf("%4d", i + 1);
	}
	printf("\n\n");

	printf("\n");
	printf("  어느 날짜의 일정을 관리할지 입력해주세요(예 20170822) :");
	scanf("%s\n", day);
	check++;
	//makeps(check, day);
}
int task(){
	system("cls");
	int year, month; // 연도와 월을 저장할 변수
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // 각 달의 총일 수 (첫번째 수는 제외)
	int lastyear, day, i;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("       몇년 몇월의 달력을 출력하시겠습니까?: ");
	scanf("%d %d", &year, &month);
	if (month == 2 && leapyear(year)) // 해당년도가 윤년이면, 2월은 총 29일
		totalday[2] = 29;

	lastyear = year - 1; // 작년 말까지 진행된 요일을 계산하기 위해 lastyear를 선언

	day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;


	for (i = 1; i<month; i++) // year년 month월 직전까지의 총 일 수를 구하기 위한 for문
		day += totalday[i];

	day %= 7; // year년 month월 1일의 시작 요일


	printf("\n           %d년 %d일\n", year, month); // year년 month월 타이틀 출력
	printf("\n  일  월  화  수  목  금  토"); // 요일 리스트 출력



	for (i = -day; i<totalday[month]; i++)
	{
		if ((i + day) % 7 == 0) // 출력될 차례가 일요일이면, 개행
			printf("\n");
		if (i<0) // month월 1일이 출력되기 이전의 날짜는 공백으로 채움
			printf("    ");
		else // 날짜 출력
			printf("%4d", i + 1);
	}
	printf("\n\n");
	printf("\n");
	printf("  어느 날짜의 과제를 관리할지 입력해주세요(예 20170822) :");
	scanf("%s\n", day);
	check+=2;
	//makeps(check, day);
}


