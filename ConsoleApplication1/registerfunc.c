#include <stdio.h>
#include <string.h>
#include <Windows.h>

void regis() {
	char idbuf[100]="12345678901";     //buf를 10으로 만들면 사용자의 입력에서 10 초과 입력을 받을 경우 buffer over flow 발생
	char pwbuf[100] = "12345678901";
	FILE* id = fopen("id.db", "a");
	FILE* pw = fopen("pw.db", "a");

	while (strlen(idbuf) > 10){       //id의 길이가 10보다 작거나 같을 때까지 반복문
		printf("아이디를 입력해 주세요.(최대 10자)\n->");
		scanf("%s", idbuf);
		if (strlen(idbuf) > 10) {
			printf("\n아이디는 최대 10자입니다!");
			Sleep(500);
			system("cls");
			continue;
		}
		fputs(idbuf, id);
		fputs("\n", id);
	}
	while (strlen(pwbuf) > 10) {      //id의 길이가 10보다 작거나 같을 때 까지 반복문
		printf("비밀번호를 입력해 주세요.(최대 10자)\n->");
		scanf("%s", pwbuf);
		if (strlen(pwbuf) > 10) {
			printf("\n비밀번호는 최대 10자입니다!");
			Sleep(500);
			system("cls");
			continue;
		}
		fputs(pwbuf, pw);
		fputs("\n", pw);
		printf("회원가입이 성공적으로 되었습니다!\n");
	}
	fclose(id);
	fclose(pw);
}
