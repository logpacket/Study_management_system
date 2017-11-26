//db 관리함수 삭제 조회 수정 저장
#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUF_SIZE 1024
int rm(char *filepath, char *key) //삭제함수
{
	int i = 0;
	char temp[BUF_SIZE];
	char temp2[BUF_SIZE];
	char *tempkey;
	FILE *fp = NULL;
	if ((fp = fopen(filepath, "r")) == NULL) {
		return -1;
	}
	FILE *fp2 = NULL;
	if ((fp2 = fopen("temp.txt", "a")) == NULL) {
		return -1;
	}
	while (fgets(temp, BUF_SIZE, fp)) {
		i++;
		strcpy(temp2, temp);
		tempkey = strtok(temp, ":");
		if (!strcmp(tempkey, key)) {
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
int edit(char *filepath, char  *key, char * value) //수정 함수
{
	int i = 0;
	char temp[BUF_SIZE];
	char temp2[BUF_SIZE];
	char temp3[BUF_SIZE];
	char *tempkey;
	FILE *fp = NULL;
	if ((fp = fopen(filepath, "r")) == NULL) {
		return -1;
	}
	FILE *fp2 = NULL;
	if ((fp2 = fopen("temp.txt", "a")) == NULL) {
		return -1;
	}
	while (fgets(temp, BUF_SIZE, fp)) {
		i++;
		strcpy(temp2, temp);
		tempkey = strtok(temp, ":");
		if (!strcmp(tempkey, key)) {
			strcpy(temp3, key);
			strcat(temp3, ":");
			strcat(temp3, value);
			strcat(temp3, "\n");
			fputs(temp3, fp2);
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
char * read(char *filepath, char *key) //조회 함수
{
	int i = 0;
	char temp[BUF_SIZE];
	char *temp2 = (char*)malloc(sizeof(char)*BUF_SIZE);
	char * tempkey;
	FILE *fp = NULL;
	if ((fp = fopen(filepath, "r")) == NULL) {
		return NULL;
	}
	while (fgets(temp, BUF_SIZE, fp)) {
		strcpy(temp2, temp);
		tempkey = strtok(temp, ":");
		if (!strcmp(tempkey, key)) {
			i = 1;
			break;
		}
	}
	fclose(fp);
	char * result = (i == 0) ? NULL : temp2;
	return result;
}
int save(char *filepath, char *value) // 저장 함수
{
	char temp[1011];
	strcpy(temp, value);
	char * key = (char*)malloc(sizeof(char)*BUF_SIZE);
	FILE *fp = NULL;
	if ((fp = fopen(filepath, "a")) == NULL) {
		return -1;
	}
	key = strtok(value, ":");
	if (read(filepath, key) != NULL) return -1;
	if (fputs(temp, fp) == EOF) {
		fclose(fp);
		return -1;
	}
	else {
		fclose(fp);
		return 0;
	}
}