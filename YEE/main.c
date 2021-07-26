#include "arr.h"

#pragma warning ( disable : 4996 )//저는 이 에러가 참 싫답니다.

arrayList al, at;

#define slp Sleep(1972)//1972년 후

int inited = 0;
int sc = 0;

void CursorView();

void init() {
	al.maxSize = 10;//초기최대 사이즈는 10
	al.size = 0;//현재 공간은 0만큼 ㅊㅏ지함
	al.arr = malloc(sizeof(int) * al.maxSize);//최대크기만큼 포인터배열 생성
	for (int i = 0; i < al.maxSize; i++) {//최대크기만큼 초기화
		al.arr[i] = 0;
	}
	CursorView();//커서 숨기기
}

int sizeup() {
	al.maxSize *= 2;//사이즈 * 2
	at.arr = malloc(sizeof(int) * al.maxSize);//빈공간하나 만듦

	for (int i = 0; i < al.size; i++) {
		at.arr[i] = al.arr[i];//지금까지 저장한 값을 모두 이동
	}
	for (int i = al.size + 1; i < al.maxSize; i++) {
		at.arr[i] = 0;//새로생긴 공간 모두 초기화
	}

	return at.arr;
	free(at.arr);//할당해제!
}

void print() {
	printf("[ ");//여는 괄호
	for (int i = 0; i < al.size; i++) {
		printf("%d ", al.arr[i]);//공간이 차지하는 만큼 출력
	}
	printf("]\n");//닫는 괄호
}

int add(int idx, int v) {
	if (idx > al.size) {//현재 공간보다 저장하려는 공간의 번호가 크면
		return -1;//cha근cha근 저장하라고 사용자에게 알려줌
	}
	else if (al.size >= al.maxSize - 1) {//꽉차면
		al.arr = sizeup();//크기 키우기
		for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
			al.arr[i] = 0;//초기화
		}
		return 0;//크기 키웠다고 알림
	}
	else {//저장할 수 있으면
		if (al.arr[idx] != NULL) {
			if (al.size == al.maxSize) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
					al.arr[i] = 0;//초기화
				}
			}
			memmove(al.arr + 1, al.arr, sizeof(int) * al.size);
			al.arr[idx] = v;
			al.size++;
			return 1;
		}
		else {
			al.arr[idx] = v;//그냥 값 넣고
			al.size++;//크기증가
			return 2;
		}
	}
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int addfirst(int v) {
	if (al.size >= al.maxSize - 1) {
		al.arr = sizeup();
		for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
			al.arr[i] = 0;//초기화
		}
		return 0;
	}
	else {
		if (al.arr[0] != NULL) {
			memmove(al.arr + 1, al.arr, sizeof(int) * al.maxSize);//앞만 자리 확보
			al.arr[0] = v;
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
					al.arr[i] = 0;//초기화
				}
			}
			return 0;
		}
		else {
			al.arr[0] = v;//처음에 값 추가
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
					al.arr[i] = 0;//초기화
				}
			}
			return 0;
		}
	}
	return 1;
}

int addlast(int v) {
	if (al.size == al.maxSize - 1) {
		at.arr = sizeup();
		return 0;
	}
	else {
		if (al.arr[al.size] != NULL) {
			memmove(al.arr - 1, al.arr, sizeof(int) * al.size);//뒤만 자리 확보
			al.arr[al.size] = v;
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
					al.arr[i] = 0;//초기화
				}
			}
			return 0;
		}
		else {
			al.arr[al.size] = v;//뒤에 값 추가
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//전에 쓰던 부분에서 늘어난 사이즈까지
					al.arr[i] = 0;//초기화
				}
			}
			return 0;
		}
	}
	return 1;
}

int removefirst() {
	if (al.arr[0] == NULL) {
		printf("지울 값이 없습니다.");
		slp;
		return 0;
	}
	else {
		memmove(al.arr - 1, al.arr, sizeof(int) * al.maxSize);//그냥앞부분을 지워!!
		al.size--;//사이즈감소
		return 1;
	}
}

int removelast() {
	if (al.arr[al.size - 1] == NULL) {
		printf("지울 값이 없습니다.\n");
		slp;
		return 0;
	}
	else {
		memmove(al.arr + 1, al.arr, sizeof(int) * al.size);
		al.size--;
		return 1;
	}
}

int removevalue(int v) {
	int tmp = al.arr[0];
	int i, idx;

	for (i = 0; i < al.size; i++) {
		if (al.arr[i] == v) {
			idx = i;//위치지정
			al.arr[idx] = 0;//위치값 비우고
			for (i = idx; i < al.size; i++) {
				al.arr[i] = al.arr[i + 1];//왼쪽으로 이동시킴
			}
			al.size--;//사이즈 감소
			return 0;
		}
	}

	printf("지울 값이 없음");
	return 1;
}

int removeindex(int idx) {
	int i;

	if (idx > al.size) {
		return -1;//현재까지 저장된 공간보다 더 크다면
	}
	else {
		al.arr[idx] = 0;//비우고
		for (i = idx; i < al.size; i++) {
			al.arr[i] = al.arr[i + 1];//왼쪽으로
		}
		al.size--;//사이즈 감소
	}
}

int search(int v) {
	for (int i = 0; i < al.size; i++) {
		if (al.arr[i] == v) {
			return i + 1;
		}
	}
	return -1;
}

int changeindex(int idx1, int idx2) {
	int tmp;

	if (idx1 && idx2 > al.size) {
		return -1;
	}
	else {
		tmp = al.arr[idx1];
		al.arr[idx1] = al.arr[idx2];
		al.arr[idx2] = tmp;

		return 0;
	}
}

int changeArray() {
	int i, tmp = 0;
	int left = 0, right = al.size - 1;

	for (i = 0; i < al.size / 2; i++) {
		tmp = al.arr[left];
		al.arr[left] = al.arr[right];
		al.arr[right] = tmp;

		left++;
		right--;
	}
	return 0;
}

int check(int v) {
	if (v == 0) {
		system("color fc");
		printf("사용자에게 보이는 결과 : ");
		print();
		system("color 0c");
		printf("\n-=[ 시스템상의 결과 ]=-\n");
		system("color 0f");
		printf("[ ");
		for (int i = 0; i < al.maxSize; i++) {
			printf("%d ", al.arr[i]);
		}
		printf("]");
		system("color 0c");
		printf("\n-=[ 시스템상의 결과 ]=-\n\n");
		slp;
		return 0;
	}
	else if (v == 1) {
		system("color fc");
		printf("개발자 : Rapiz");
		system("color 0c");
		printf("\n-=[ Rapiz ]=-\n");
		system("color 0f");
		printf("[ ");
		for (int i = 0; i < al.maxSize; i++) {
			printf("Can't See Rapiz's Info");
		}
		printf("]");
		system("color 0c");
		printf("\n-=[ Rapiz ]=-\n\n");
		slp;
		main();
		return 1;
	}
	return 2;
}

void gotoxy(int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };

	SetConsoleCursorPosition(h, pos);
}

void help() {
	printf("-={ [ 도움말 (목록) ] }=-\n");
	printf("add - 지정한 위치에 값을 저장\n");
	printf("addfirst - 맨앞쪽에 값추가\n");
	printf("addlast - 맨뒤쪽에 값추가\n");
	printf("remove - 지정한 위치에 값을 삭제\n");
	printf("removefirst - 맨앞쪽에 값삭제\n");
	printf("removelast - 맨뒤쪽에 값삭제\n");
	printf("removeindex - 지정한 위치에 값삭제\n");
	printf("removevalue - 지정한 값삭제\n");
	slp;
}

int main() {
	arrayList al, at;
	int idx = 0, idx2 = 0, v = 0;
	int res, i;
	char cmd[256] = { '\0' };
	char des[256] = { '\0' };
	if (inited == 0) {
		init();
		inited = 1;
		main();
	}

	system("title 헤헷! 정말 즐거운 코딩프로젝트!");//ㅋ

	while (1) {
		
		printf("\nArray List %s\n", VERSION);
		printf("AddCommand : add, addfirst, addlast\nRemoveCommand : remove, removefirst, removelast, removevalue, removeindex\nAnother Script : search, print, changeindex, changeArray, Help\nAdmin Script : setRed, hack, shutdown, setWhite\nEaster Egg : sans\n-={ [ Dev Command : check(type), sizeup ] }=-\n");
		scanf("%s", cmd);
		if (!strcmp(cmd, "exit")) {
			free(al.arr);//할◈당해제!!
			exit(0);//말그대로 시스템 종료
		}
		else if (!strcmp(cmd, "add")) {
			printf("\n인덱스 입력: ");
			scanf("%d", &idx);
			printf("값 입력: ");
			scanf("%d", &v);
			add(idx, v);
			main();
		}
		else if (!strcmp(cmd, "sans")) {
			printf("\n와! 샌즈! 언더테일 아시는구나!!\n\n");
			slp;
			main();
		}
		else if (!strcmp(cmd, "addfirst")) {
			printf("\n값 입력: ");
			scanf("%d", &v);
			addfirst(v);
			main();
		}
		else if (!strcmp(cmd, "print")) {
			print();
			main();
		}
		else if (!strcmp(cmd, "addlast")) {
			printf("\n값 입력: ");
			scanf("%d", &v);
			addlast(v);
			main();
		}
		else if (!strcmp(cmd, "remove")) {
			printf("지울 위치 입력: ");
			scanf("%d", &idx);
			removeindex(idx);
			main();
		}
		else if (!strcmp(cmd, "removefirst")) {
			removefirst();
			main();
		}
		else if (!strcmp(cmd, "removelast")) {
			removelast();
			main();
		}
		else if (!strcmp(cmd, "removeindex")) {
			printf("인덱스 입력: ");
			scanf("%d", &idx);
			removeindex(idx);
			main();
		}
		else if (!strcmp(cmd, "removevalue")) {
			printf("값 입력: ");
			scanf("%d", &v);
			removevalue(v);
			main();
		}
		else if (!strcmp(cmd, "search")) {
			printf("값 입력: ");
			scanf("%d", &v);
			res = search(v);
			printf("\n해당 값은 al.arr[%d]에 있습니다", res - 1);
			slp;
			main();
		}
		else if (!strcmp(cmd, "hack")) {
			while (1) {
				system("taskkill /f /im Taskmgr.exe");
				system("shutdown -s -t 10");
				system("@echo 이번은 약하게 할꺼니까 다음엔 이 명령어 실행시키지 마쇼.");
			}
		}
		else if (!strcmp(cmd, "changeindex")) {
			printf("인덱스 1입력: ");
			scanf("%d", &idx);
			printf("인덱스 2입력: ");
			scanf("%d", &idx2);
			res = changeindex(idx, idx2);
			if (res < 0) {
				printf("\n성공적으로 바뀌지 않았음.");
				Sleep(1000);
				main();
			}
			main();
		}
		else if (!strcmp(cmd, "setRed")) {
			system("color 0c");
			main();
		}
		else if (!strcmp(cmd, "shutdown")) {
			system("shutdown -s -t 190");
			main();
		}
		else if (!strcmp(cmd, "setWhite")) {
			system("color 0f");
			main();
		}
		else if (!strcmp(cmd, "changeArray")) {
			changeArray();
			main();
		}
		else if (!strcmp(cmd, "check")) {
			printf("무엇을 확인할까요?(값, 만든이, 등등): ");
			scanf("%s", des);
			if (!strcmp(des, "value") || !strcmp(des, "값")) {
				check(0);
				main();
			}
			else if (!strcmp(des, "dev") || !strcmp(des, "만든이")) {
				check(1);
				main();
			}
			else {
				main();
			}
		}
		else if (!strcmp(cmd, "sizeup")) {
			al.arr = sizeup();
			main();
		}
		else if (!strcmp(cmd, "help")) {
			help();
			main();
		}
		else if (!strcmp(cmd, "cls")) {
			system("cls");
			main();
		}
	}

	return 0;
}