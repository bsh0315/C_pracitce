#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printhead();
int main(void) {
	char fname[] = "grade.txt";
	char names[80];
	FILE* f;
	int point1, point2, cnt = 0;
	if ((f = fopen(fname, "w+")) == NULL) {
		printf("오류");
		exit(1);
	}

	printf("이름과 성적(중간, 기말)을 입력하세요.\n");
	fgets(names, 80, stdin);
	while (!feof(stdin)) {
		fprintf(f, "%d " , ++cnt);
		fputs(names, f);
		fgets(names, 80, stdin);
	
	}
	fclose(f);
	if ((f = fopen(fname, "r")) == NULL) {
		printf("오류");
		exit(1);
	}

	printhead();
	while (!feof(f)) {
		fscanf(f, "%d %s %d %d\n", &cnt, names, &point1, &point2);
		fprintf(stdout, "%6d%18s%8d%8d\n", cnt, names, point1, point2);
	}
	fclose(f);

	return 0;
}
void printhead() {
	fprintf(stdout, "%s\n", "______________________________________");
	fprintf(stdout, "%6s%18s%8s%8s\n", "번호", "이름", "중간", "기말");
	fprintf(stdout, "%s\n", "---------------------------------------");
}