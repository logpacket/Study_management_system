#pragma once
#include "psfunc.h"
#define leapyear(year) ((year)%4==0 && ( (year)%100!=0 || (year)%400==0 )) //����������ũ��

int check = 0;
char day[9];
extern void schedule();//���� ���� �Լ�
extern void task();//���� ���� �Լ�
extern void title();
void title() //�������� main�Լ�
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

		while(1){
		system("cls");
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
		printf("                  1  �� ���͵� �׷� ������ ���� ");
		printf("                  2  �� ���͵� ���� ���� \n");
		printf("\n		  3  �� ���α׷� ����\n");
			//�Է��� ����

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
				exit(0);
			}
	}
}

void schedule() // ���� ���� �Լ� 
{
	system("cls");
	int year, month; // ������ ���� ������ ����
	int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // �� ���� ���� �� (ù��° ���� ����)
	int lastyear, day, i;
	char date[10];
	check = 1;
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("       ��� ����� �޷��� ����Ͻðڽ��ϱ�?: ");
	scanf("%d %d", &year, &month);
	if (month == 2 && leapyear(year)) // �ش�⵵�� �����̸�, 2���� �� 29��
		totalday[2] = 29;

	lastyear = year - 1; // �۳� ������ ����� ������ ����ϱ� ���� lastyear�� ����

	day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;


	for (i = 1; i<month; i++) // year�� month�� ���������� �� �� ���� ���ϱ� ���� for��
		day += totalday[i];

	day %= 7; // year�� month�� 1���� ���� ����


	printf("\n           %d�� %d��\n", year, month); // year�� month�� Ÿ��Ʋ ���
	printf("\n  ��  ��  ȭ  ��  ��  ��  ��"); // ���� ����Ʈ ���



	for (i = -day; i<totalday[month]; i++)
	{
		if ((i + day) % 7 == 0) // ��µ� ���ʰ� �Ͽ����̸�, ����
			printf("\n");
		if (i<0) // month�� 1���� ��µǱ� ������ ��¥�� �������� ä��
			printf("    ");
		else // ��¥ ���
			printf("%4d", i + 1);
	}
	printf("\n\n");

	printf("\n");
	printf("  ��� ��¥�� ������ �������� �Է����ּ���(�� 20170822) :");
	scanf("%s", date);
	system("cls");
	printf("%s\n", date);
	printf("\n1.���� �߰�\n");
	printf("2.���� ��ȸ\n");
	printf("3.���� ����\n");
	printf("4.���� ����\n");
	printf("(q.����ȭ������ ���ư���)\n");
	char k = getch();
	switch (k) {
	case '1':
		makeps(check, date);
		system("cls");
		return;
	case '2':
		readps(check, date);
		system("cls");
		return;
	case '3':
		editps(check, date);
		system("cls");
		return;
	case '4':
		rmps(check, date);
		system("cls");
		return;
	case 'q':
		system("cls");
		return;
	}
}
void task() //���� ���� �Լ�
{
		system("cls");
		int year, month; // ������ ���� ������ ����
		int totalday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; // �� ���� ���� �� (ù��° ���� ����)
		int lastyear, day, i;
		char date[10];
		check = 2;
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("       ��� ����� �޷��� ����Ͻðڽ��ϱ�?:");
		scanf("%d %d", &year, &month);
		if (month == 2 && leapyear(year)) // �ش�⵵�� �����̸�, 2���� �� 29��
			totalday[2] = 29;

		lastyear = year - 1; // �۳� ������ ����� ������ ����ϱ� ���� lastyear�� ����

		day = (lastyear + (lastyear / 4) - (lastyear / 100) + (lastyear / 400) + 1) % 7;


		for (i = 1; i < month; i++) // year�� month�� ���������� �� �� ���� ���ϱ� ���� for��
			day += totalday[i];

		day %= 7; // year�� month�� 1���� ���� ����


		printf("\n           %d�� %d��\n", year, month); // year�� month�� Ÿ��Ʋ ���
		printf("\n  ��  ��  ȭ  ��  ��  ��  ��"); // ���� ����Ʈ ���



		for (i = -day; i < totalday[month]; i++)
		{
			if ((i + day) % 7 == 0) // ��µ� ���ʰ� �Ͽ����̸�, ����
				printf("\n");
			if (i < 0) // month�� 1���� ��µǱ� ������ ��¥�� �������� ä��
				printf("    ");
			else // ��¥ ���
				printf("%4d", i + 1);
		}
		printf("\n\n");
		printf("\n");
		printf("  ��� ��¥�� ������ �������� �Է����ּ���(�� 20170822) :");
		scanf("%s", date);
		system("cls");
		printf("%s\n", date);
		printf("\n1.���� �߰�\n");
		printf("2.���� ��ȸ\n");
		printf("3.���� ����\n");
		printf("4.���� ����\n");
		printf("(q.����ȭ������ ���ư���)\n");
			char k = getch();
			switch (k) {
			case '1':
				makeps(check, date);
				system("cls");
				return;
			case '2':
				readps(check, date);
				system("cls");
				return;
			case '3':
				editps(check, date);
				system("cls");
				return;
			case '4':
				rmps(check, date);
				system("cls");
				return;
			case 'q':
				system("cls");
				return;
			}
}