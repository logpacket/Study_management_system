void makeproject() {
	SP project[1];
	char filepath[11] = "project.db";
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
	}
		strcat(result, project->when);
		strcat(result,":");
		strcat(result, project->description);
		strcat(result, "\n");
		if (save(filepath, result) == -1) {
			printf("이미 해당하는 날짜의 과제가 있습니다!!");
			Sleep(500);
			system("cls");
			return;
		}
		printf("성공적으로 과제가 작성되었습니다!");
		Sleep(500);
		system("cls");
		return;
}
void readproject() {
	SP project[20];
	char filepath[11] = "project.db";
	while (1) {
		printf("확인하고싶은 과제의 날짜를 입력해주세요.(type 20170811)\n->");
		scanf("%s", project->when);
		if (strlen(project->when) != 8) {
			printf("type을 지켜주세요!");
			Sleep(500);
			system("cls");
			continue;
		}
		char *result = read(filepath, project->when);
		if (result == NULL) {
			printf("과제가 존재하지 않습니다!");
			Sleep(500);
			system("cls");
			break;
		}
		printf("%s일의 과제\n", project->when);
		printf("%s\n", result + 9);
		printf("선택창으로 가려면 아무키나 눌러주세요.");
		char y_n;
		y_n = getch();
		system("cls");
		return;
	}
	return;
}
void rmproject(s) {
	SP project[1];
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
		printf("정말로 %s날의 과제를 지우시겠습니까?(y,n)\n",project->when);
		y_n = getch();
		if (!(y_n == 'y' || y_n == 'Y')) {
			system("cls");
			break;
		}
		if (rm(filepath, project->when) == -1) {
			printf("과제를 지우는 데 실패했습니다!");
			Sleep(500);
			system("cls");
			break;
		}
		printf("성공적으로 과제가 지워졌습니다!");
		Sleep(500);
		system("cls");
		break;
	}
	return;
}
void editproject() {
	SP project[1];
	char filepath[11] = "project.db";
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
		strcat(project->description, "\n");
		if (edit(filepath, project->when, project->description) == -1) {
			printf("과제 수정에 실패했습니다!");
			Sleep(500);
			system("cls");
			break;
		}
		break;
	}
	printf("성공적으로 과제가 수정되었습니다!");
	Sleep(500);
	system("cls");
	return;
}
