//연결리스트 입력, 프린트, 업데이트, 삭제 기능 구현코드
#include <stdio.h>
#include <stdlib.h>

void input(), print(), update(), delete(),memory_free();

struct NODE {
	int ID;
	int value;
	struct NODE* next;
}*head, *tail, *ptr;

int main() {
	head = NULL;
	int index, flag = 0;
	while (flag == 0) { // 5를 입력하면 flag값이 1이 되어서 종료
		printf("1. input, 2. print, 3. update, 4. delete, 5.exit\n");
		scanf("%d", &index);
		if (index == 1) { input(); }
		else if (index == 2) { print(); }
		else if (index == 3) { update(); }
		else if (index == 4) { delete(); }
		else if (index == 5) { printf("Exit this Program\n"); flag = 1; }
		else { printf("다시입력"); }
	}
	memory_free();
	return 0;
}

void input() {
	int i_ID, i_value;
	printf("\t ID, value : "); scanf("%d %d", &i_ID, &i_value);
	ptr = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == NULL) { head = ptr; }
	else { tail->next = ptr; }
	ptr->ID = i_ID;
	ptr->value = i_value;
	ptr->next = NULL;
	tail = ptr;
	print();
}

void print() {
	ptr = head;
	while (ptr != NULL) {
		printf(" %d %d", ptr->ID, ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
}

void update() {
	int update_ID, update_value;
	printf("\tID for update : "); scanf("%d", &update_ID);
	ptr = head;
	while (ptr != NULL) {
		if (ptr->ID == update_ID) {
			printf("\tEnter the value for this ID : ");
			scanf("%d", &update_value);
			ptr->value = update_value;
			print();
			return;

		}
		ptr = ptr->next;
	}
}

void delete() {
	int delete_ID;
	printf("ID for delete : "); scanf("%d", &delete_ID);
	ptr = head;
	if (ptr->ID == delete_ID) {// 첫번째 노드 삭제
		head = ptr->next;
		free(ptr);
		print();
	}
	struct NODE* tmp;
	while (ptr != NULL) { // 다른 노드를 삭제
		tail = ptr;
		ptr = ptr->next;
		if (ptr != NULL) {
			tail->next = ptr->next;
			tmp = tail;
			free(ptr);
			while (tail->next != NULL) {
				tail = tmp;
				tmp = tmp->next;
			}
			print();
			return;
		}
	}
}
void memory_free() {
	struct NODE* search, * previous;
	search = head;
	while (search != NULL) {
		previous = search->next;
		free(search);
		search = previous;

	}
}