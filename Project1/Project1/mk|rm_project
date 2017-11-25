#include <stdio.h>
#include <string.h>
#include <Windows.h>

void makeproject() {
	SP project[1];
	char filepath[10] = "project.db";
	char result[1010] = { '\0', };
	while (1) {
		printf("과제의 날짜 설정(type 20170124)\n->");
		scanf("%s", project->when);
		if (strlen(project->when) != 8) {
			printf("type을 지켜주세요!");
			Sleep(500);
			system("cls");
			continue;
		}
		break;
	}
	while (1) {
		printf("과제를 작성해주세요.(최대1000자)\n->");
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {
			printf("과제는 1000자를 넘어갈 수 없습니다!");
			Sleep(500);
			system("cls");
			continue;
		}
		break;
	}
		strcat(result, project->when);
		strcat(result,":");
		strcat(result, project->description);
		save(filepath, result);
		printf("성공적으로 과제가 작성되었습니다!");
		Sleep(500);
		system("cls");
}
void readproject() {
    SP project[20];
	UI user[MAX];
	char filepath[10] = "project.db";
	char result[1000] = { '\0', };
	while (1) {
		printf("확인하고싶은 과제의 날짜를 입력해주세요.(type 20170811)\n->");
		scanf("%s", project->when);
		if (strlen(project->when) != 8) {
			printf("type을 지켜주세요!");
			Sleep(500);
			system("cls");
			continue;
		}
		strcpy(project->description, read(filepath, project->when));
		if ( project->description[0] == '-1') {
			printf("과제가 존재하지 않습니다!");
			Sleep("cls");
			system("cls");
			continue;
		}
		printf("%s일의 과제\n",project->when);
		printf("%s", project->description);
		break;
	}
}
void rmproject() {
	SP project[1];
	char filepath[10] = "project.db";
	while (1) {
		char y_n;
		printf("지울 과제의 날짜를 입력해주세요!(type 20171108)\n->");
		scanf("%s", project->when);
		if (strlen(project->when) != 8) {
			printf("type을 지켜주세요!");
			Sleep(500);
			system("cls");
			continue;
		}
		printf("정말로 %s날의 과제를 지우시겠습니까?(y,n)",project->when);
		y_n = getch();
		if (!(y_n == 'y' || y_n == 'Y')) {
			system("cls");
			continue;
		}
		if (rm(filepath, project->when) == -1) {
			printf("과제를 지우는 데 실패했습니다!");
			Sleep(500);
			system("cls");
			continue;
		}
		printf("성공적으로 과제가 지워졌습니다!");
		Sleep(500);
		system("cls");
	}
}
void editproject() {
	SP project[1];
	char filepath[10] = "project.db";
	char result[1010] = { '\0', };
	while (1) {
		printf("수정할 과제의 날짜를 입력해주세요.(type 20170124)\n->");
		scanf("%s", project->when);
		if (strlen(project->when) != 8) {
			printf("type을 지켜주세요!");
			Sleep(500);
			system("cls");
			continue;
		}
		printf("수정할 과제의 내용을 입력해주세요.(최대1000자)\n->");
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {
			printf("과제는 1000자를 넘어갈 수 없습니다!");
			Sleep(500);
			system("cls");
			continue;
		}
		if (edit(filepath, project->when, project->description) == -1) {
			printf("과제 수정에 실패했습니다!");
			Sleep(500);
			system("cls");
			continue;
		}
		break;
	}
	printf("성공적으로 과제가 수정되었습니다!");
	Sleep(500);
	system("cls");
}
int main() {
	makeproject();
	readproject();
}
