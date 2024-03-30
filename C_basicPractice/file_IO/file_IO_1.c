//파일입출력 fwrite
#include <stdio.h>
#include<stdlib.h>

struct personscore {
	int number;
	char name[40];
	int mid;
	int final;
	int quiz;
};

typedef struct personscore pscore;

int main() {
	char fname[] = "score.bin";
	char line[80];
	FILE* f;
	int cnt = 0;
	pscore score;

	if ((f = fopen(fname, "w")) == NULL) {
		printf("오류");
		exit(1);
	}
	fgets(line, 80, stdin);
	while (!feof(stdin)) {
		sscanf(line, "%s %d %d %d", score.name, &score.mid, &score.final, &score.quiz);
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, f);
		fgets(line, 80, stdin);
	}
	fclose(f);
	return 0;
}