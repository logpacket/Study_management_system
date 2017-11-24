typedef struct StudyProject{
	char when[10];
	char description[1000];
}SP;
typedef struct UserInformation{
	SP fuck[10];
	char name[20];
}UI;
typedef struct StudySchedule{
	char when[10];
	char description[100];
}SS;
typedef struct Study{
	UI users[MAX];
	SS schedule[50];
}S;
