#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

#define MAX 100

typedef struct StudyProject {
	char when[10];
	char description[1001];
}SP;
typedef struct StudySchedule {
	char when[10];
	char description[101];

}SS;
/*사용법
int check=1; ( 1은 과제 2는 일정)
char day[9]="20170111"; (무조건 배열에 넣어서 인자로 넘기기)
makeps(check,day);
 */
void makeps(int check,char *day) {       
 	SP project[1];
	char filepath[11];
	char result[1011] = { '\0', };
	char which[10];
	if (check == 1) {
		strcpy(filepath,"project.db");
		strcpy(which, "과제");
	}
	if (check == 2) {
		strcpy(filepath,"schedul.db");
		strcpy(which, "일정");
	}
	while (1) {
		printf("%s일의 %s(을/를) 작성해주세요.(최대1000자)\n->", day, which);
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {
			printf("%s(은/는) 1000자를 넘어갈 수 없습니다!", which);
			Sleep(500);
			system("cls");
			continue;
		}
		break;
	}
		strcat(result,day);
		strcat(result,":");
		strcat(result, project->description);
		strcat(result, "\n");
		if (save(filepath, result) == -1) {
			printf("이미 해당하는 날짜의 %s(이/가) 있습니다!!",which);
			Sleep(500);
			system("cls");
			return;
		}
		printf("성공적으로 %s(이/가) 작성되었습니다!",which);
		Sleep(500);
		system("cls");
		return;
}
void readps(int check, char *day) {
	SP project[20];
	char filepath[11];
	char which[10];
	if (check == 1) {
		strcpy(filepath, "project.db");
		strcpy(which, "과제");
	}
	if (check == 2) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "일정");
	}
	while (1) {
		char *result = read(filepath, day);
		if (result == NULL) {
			printf("%s(이/가) 존재하지 않습니다!",which);
			Sleep(500);
			system("cls");
			break;
		}
		printf("%s일의 %s\n", day,which);
		printf("%s\n", result + 9);
		printf("선택창으로 가려면 아무키나 눌러주세요.");
		char y_n;
		y_n = getch();
		system("cls");
		return;
	}
	return;
}
void rmps(int check, char *day) {
	SP project[1];
	char filepath[11];
	char which[10];
	if (check == 1) {
		strcpy(filepath, "project.db");
		strcpy(which, "과제");
	}
	if (check == 2) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "일정");
	}
	while (1) {
		char y_n;
		printf("정말로 %s날의 %s를 지우시겠습니까?(y,n)\n",day,which);
		y_n = getch();
		if (!(y_n == 'y' || y_n == 'Y')) {
			system("cls");
			break;
		}
		if (rm(filepath, day) == -1) {
			printf("%s를 지우는 데 실패했습니다!",day,which);
			Sleep(500);
			system("cls");
			break;
		}
		printf("성공적으로 %s(이/가) 지워졌습니다!",which);
		Sleep(500);
		system("cls");
		break;
	}
	return;
}
void editps(int check, char *day) {
	SP project[1];
	char filepath[11];
	char which[10];
	if (check == 1) {
		strcpy(filepath, "project.db");
		strcpy(which, "과제");
	}
	if (check == 2) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "일정");
	}
	while (1) {
		printf("%s일의 수정할 %s의 내용을 입력해주세요.(최대1000자)\n->",day,which);
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {
			printf("%s(은/는) 1000자를 넘어갈 수 없습니다!",which);
			Sleep(500);
			system("cls");
			continue;
		}
		if (edit(filepath, day, project->description) == -1) {
			printf("%s 수정에 실패했습니다!",which);
			Sleep(500);
			system("cls");
			break;
		}
		break;
	}
	printf("성공적으로 %s(이/가) 수정되었습니다!",which);
	Sleep(500);
	system("cls");
	return;
}
