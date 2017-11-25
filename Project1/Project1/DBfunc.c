#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUF_SIZE 1024
int save(char *filepath, char *value) {
	FILE *fp = NULL;
	fp = fopen(filepath, "a");
	if (fputs(value, fp) == EOF) {
		fclose(fp);
		return -1;
	}
	else {
		fclose(fp);
		return 0;
	}
}
int rm(char *filepath, char *key) {
	int i = 0;
	char temp[BUF_SIZE];
	char temp2[BUF_SIZE];
	char *tempkey;
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	FILE *fp2 = NULL;
	fp2 = fopen("temp.txt", "a");
	while (fgets(temp, BUF_SIZE, fp)) {
		i++;
		strcpy(temp2, temp);
		tempkey = strtok(temp, ":");
		if (!strcmp(tempkey,key)) {
			continue;
		}
		else {
			fputs(temp2, fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	if (i == 0) {
		remove("temp.txt");
		return -1;
	}else if (remove(filepath)<0) {
		printf("실패");
		return -1;
	}
	rename("temp.txt", filepath);
	printf("완료");
	return 0;
}
int edit(char *filepath, char  *key, char * value) {
	int i = 0;
	char temp[BUF_SIZE];
	char temp2[BUF_SIZE];
	char *tempkey;
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	FILE *fp2 = NULL;
	fp2 = fopen("temp.txt", "a");
	while (fgets(temp, BUF_SIZE, fp)) {
		i++;
		strcpy(temp2, temp);
		tempkey = strtok(temp, ":");
		if (!strcmp(tempkey, key)) {
			fputs(value, fp2);
			continue;
		}
		else {
			fputs(temp2, fp2);
		}
	}
	fclose(fp);
	fclose(fp2);
	if (i == 0) {
		remove("temp.txt");
		return -1;
	}
	else if (remove(filepath)<0) {
		return -1;
	}
	rename("temp.txt", filepath);
	return 0;
}
char * read(char *filepath, char *key) {
	char *temp2 = (char*)malloc(sizeof(char)*BUF_SIZE);
	char *temp = (char*)malloc(sizeof(char)*BUF_SIZE);
	char * tempkey;
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	while (fgets(temp,BUF_SIZE,fp)) {
		if (temp == NULL) {
			return NULL;
		}
		strcpy(temp2, temp);
		tempkey = strtok(temp,":");
		if (tempkey == key) {
			break;
		}
	}
	fclose(fp);
	return temp2;
}
	//save함수 사용시에 뒤에 개행문자 꼭넣을것
	//save("test.txt", "ls:ls:ls\n");
	
	//이건 그냥 쓰면됨
	//rm("test.txt", "ls");
	
	//이것도 value dp 개행문자 꼭넣을것
	//edit("test.txt", "ls", "af:af:af\n");

	//read함수 사용의 올바른 예
	/*char *n = read("test.txt", "af");
	printf("\n%s",n);
	free(n);*/
