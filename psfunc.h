//#include "dbms.h"
/*����
int check=1; ( 1�� ���� 2�� ����)
char day[9]="20170111"; (������ �迭�� �־ ���ڷ� �ѱ��)
makeps(check,day);
*/
#pragma once
#include <Windows.h>
#include <conio.h>
#include "struct.h"
#include "dbms.h"
extern void makeps(int check, char *day) //���� ���� �Լ�
{
	SP project[1];
	char filepath[11];
	char result[1011] = { '\0', };
	char which[10];
	if (check == 2) {
		strcpy(filepath, "project.db");
		strcpy(which, "����");
	}
	if (check == 1) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "����");
	}
	while (1) {
		printf("%s���� %s(��/��) �ۼ����ּ���.(�ִ�1000��)\n->", day, which);
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {
			printf("%s(��/��) 1000�ڸ� �Ѿ �� �����ϴ�!", which);
			Sleep(500);
			system("cls");
			continue;
		}
		break;
	}
	strcat(result, day);
	strcat(result, ":");
	strcat(result, project->description);
	strcat(result, "\n");
	if (save(filepath, result) == -1) {
		printf("�̹� �ش��ϴ� ��¥�� %s(��/��) �ֽ��ϴ�!!", which);
		Sleep(500);
		system("cls");
		return;
	}
	printf("���������� %s(��/��) �ۼ��Ǿ����ϴ�!", which);
	Sleep(500);
	system("cls");
	return;
}
extern void readps(int check, char *day) //���� ��ȸ �Լ�
{
	SP project[20];
	char filepath[11];
	char which[10];
	if (check == 2) {
		strcpy(filepath, "project.db");
		strcpy(which, "����");
	}
	if (check == 1) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "����");
	}
	while (1) {
		char *result = read(filepath, day);
		if (result == NULL) {
			printf("%s(��/��) �������� �ʽ��ϴ�!", which);
			Sleep(500);
			system("cls");
			break;
		}
		printf("%s���� %s\n", day, which);
		printf("%s\n", result + 9);
		printf("����â���� ������ �ƹ�Ű�� �����ּ���.");
		char y_n;
		y_n = getch();
		system("cls");
		return;
	}
	return;
}
extern void rmps(int check, char *day) //���� ���� �Լ�
{
	SP project[1];
	char filepath[11];
	char which[10];
	if (check == 2) {
		strcpy(filepath, "project.db");
		strcpy(which, "����");
	}
	if (check == 1) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "����");
	}
	while (1) {
		char y_n;
		printf("������ %s���� %s�� ����ðڽ��ϱ�?(y,n)\n", day, which);
		y_n = getch();
		if (!(y_n == 'y' || y_n == 'Y')) {
			system("cls");
			break;
		}
		if (rm(filepath, day) == -1) {
			printf("%s�� ����� �� �����߽��ϴ�!", day, which);
			Sleep(500);
			system("cls");
			break;
		}
		printf("���������� %s(��/��) ���������ϴ�!", which);
		Sleep(500);
		system("cls");
		break;
	}
	return;
}
extern void editps(int check, char *day) //���� ���� �Լ�
{
	SP project[1];
	char filepath[11];
	char which[10];
	if (check == 2) {
		strcpy(filepath, "project.db");
		strcpy(which, "����");
	}
	if (check == 1) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "����");
	}
	while (1) {
		printf("%s���� ������ %s�� ������ �Է����ּ���.(�ִ�1000��)\n->", day, which);
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {
			printf("%s(��/��) 1000�ڸ� �Ѿ �� �����ϴ�!", which);
			Sleep(500);
			system("cls");
			continue;
		}
		if (edit(filepath, day, project->description) == -1) {
			printf("%s ������ �����߽��ϴ�!", which);
			Sleep(500);
			system("cls");
			break;
		}
		break;
	}
	printf("���������� %s(��/��) �����Ǿ����ϴ�!", which);
	Sleep(500);
	system("cls");
	return;
}