#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>


typedef struct Study {		 //과제또는 일정의 내용을 효과적으로 관리하기 위해서 구조체 선언.
	char when[10];
	char description[1001];
}SP;

void makeps(int check, char *day) {               //과제 또는 일정을 만드는함수
	SP project[1];
	char filepath[11];
	char result[1011] = { '\0', };
	char which[10];
	if (check == 1) {							//과제일때의 filepath 즉 db설정과 출력할 때 유동적으로 하기 위해서 따로 배열에 과제, 일정등을 넣는다. 
		strcpy(filepath, "project.db");
		strcpy(which, "과제");
	}
	if (check == 2) {
		strcpy(filepath, "schedul.db");
		strcpy(which, "일정");
	}
	while (1) {
		printf("%s일의 %s(을/를) 작성해주세요.(최대1000자)\n->", day, which);
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {         //과제 또는 일정의 내용이 100자가 넘는지 strlen함수를 이용하여 검사
			printf("%s(은/는) 1000자를 넘어갈 수 없습니다!", which);
			Sleep(500);
			system("cls");
			continue;
		}
		break;
	}
	strcat(result, day);
	strcat(result, ":");									//db를 처리하는 함수에서 ":"값으로 key값을 파싱하기때문에 
	strcat(result, project->description);					//strcat함수를 이용하여 형식에 맞게 배열값을 맞추어준다.
	strcat(result, "\n");
	if (save(filepath, result) == -1) {						//db의 함수인 save함수에서 중복검사를 해서 중복이라면 -1을 리턴해주므로 예외처리
		printf("이미 해당하는 날짜의 %s(이/가) 있습니다!!", which);
		Sleep(500);
		system("cls");
		return;
	}
	printf("성공적으로 %s(이/가) 작성되었습니다!", which);
	Sleep(500);
	system("cls");
	return;
}
void readps(int check, char *day) {							//일정또는과제를 읽어오는 함수
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
		if (result == NULL) {								//db함수인 read함수에서 읽어올 값이 없다면 NULL을 반환하므로 예외처리
			printf("%s(이/가) 존재하지 않습니다!", which);
			Sleep(500);
			system("cls");
			break;
		}
		printf("%s일의 %s\n", day, which);
		printf("%s\n", result + 9);
		printf("선택창으로 가려면 아무키나 눌러주세요.");
		char y_n;
		y_n = getch();
		system("cls");
		return;
	}
	return;
}
void rmps(int check, char *day) {								//일정또는과제를 지우는 함수
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
		printf("정말로 %s날의 %s를 지우시겠습니까?(y,n)\n", day, which);
		y_n = getch();
		if (!(y_n == 'y' || y_n == 'Y')) {
			system("cls");
			break;
		}
		if (rm(filepath, day) == -1) {							//지울 수 있는 과제나 일정이 없을 경우에 -1을 리턴받아 예외처리
			printf("%s를 지우는 데 실패했습니다!", day, which);
			Sleep(500);
			system("cls");
			break;
		}
		printf("성공적으로 %s(이/가) 지워졌습니다!", which);
		Sleep(500);
		system("cls");
		break;
	}
	return;
}
void editps(int check, char *day) {								//일정또는 과제를 수정하는 함수
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
		printf("%s일의 수정할 %s의 내용을 입력해주세요.(최대1000자)\n->", day, which);
		scanf("%s", project->description);
		if (strlen(project->description) > 1000) {			//내용이 1000자를 넘어갈 수 없다.
			printf("%s(은/는) 1000자를 넘어갈 수 없습니다!", which);
			Sleep(500);
			system("cls");
			continue;
		}
		if (edit(filepath, day, project->description) == -1) {		//존재하지 않는 일정또는 과제일 경우 -1을 리턴받아 예외처리
			printf("%s 수정에 실패했습니다!", which);
			Sleep(500);
			system("cls");
			break;
		}
		break;
	}
	printf("성공적으로 %s(이/가) 수정되었습니다!", which);
	Sleep(500);
	system("cls");
	return;
}
