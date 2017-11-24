#include<stdio.h>
#include<string.h>
int save(char *filepath, char *value){
	strlen(value);
	FILE *fp = NULL;
	fp = fopen(filepath, "a");
	if (fputs(value, fp) == EOF) return -1;
	else return 0;
}
int remove(char *filepath, char *key){
	char temp[10];
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	FILE *fp2 = NULL;
	fp2 = fopen("temp.txt", "a");
	while (fscanf(fp, "%s", temp)){
		if (temp == key) continue;
		fprintf(fp2, "%s", temp);
	}
	if (remove(filepath)) {
		fclose(fp);
		fclose(fp2);
		return -1;
	}
	rename("temp.txt", filepath);
	fclose(fp);
	fclose(fp2);
	return 0;
}
int edit(char *filepath, char  *key,char * value) {
	char temp[10];
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	FILE *fp2 = NULL;
	fp2 = fopen("temp.txt", "a");
	while (fscanf(fp, "%s", temp)) {
		if (temp == key) {
			if (fputs(value, fp2) == EOF) {
				fclose(fp);
				fclose(fp2);
				return -1;
			}
			else
				continue;
		}
		fprintf(fp2, "%s", temp);
	}
	if (remove(filepath)) {
		fclose(fp);
		fclose(fp2);
		return -1;
	}
	rename("temp.txt", filepath);
	fclose(fp);
	fclose(fp2);
	return 0;
}
char * read(char *filepath, char *key) {
	char temp[100];
	char * tempkey;
	FILE *fp = NULL;
	fp = fopen(filepath, "r");
	while (fscanf(fp, "%s", temp)) {
		tempkey = strpbrk(key, temp);
		if (tempkey != NULL)
			break;
	}
	fclose(fp);
	return tempkey;
}