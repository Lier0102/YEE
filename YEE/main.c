#include "arr.h"

#pragma warning ( disable : 4996 )//���� �� ������ �� �ȴ�ϴ�.

arrayList al, at;

#define slp Sleep(1972)//1972�� ��

int inited = 0;
int sc = 0;

void CursorView();

void init() {
	al.maxSize = 10;//�ʱ��ִ� ������� 10
	al.size = 0;//���� ������ 0��ŭ ��������
	al.arr = malloc(sizeof(int) * al.maxSize);//�ִ�ũ�⸸ŭ �����͹迭 ����
	for (int i = 0; i < al.maxSize; i++) {//�ִ�ũ�⸸ŭ �ʱ�ȭ
		al.arr[i] = 0;
	}
	CursorView();//Ŀ�� �����
}

int sizeup() {
	al.maxSize *= 2;//������ * 2
	at.arr = malloc(sizeof(int) * al.maxSize);//������ϳ� ����

	for (int i = 0; i < al.size; i++) {
		at.arr[i] = al.arr[i];//���ݱ��� ������ ���� ��� �̵�
	}
	for (int i = al.size + 1; i < al.maxSize; i++) {
		at.arr[i] = 0;//���λ��� ���� ��� �ʱ�ȭ
	}

	return at.arr;
	free(at.arr);//�Ҵ�����!
}

void print() {
	printf("[ ");//���� ��ȣ
	for (int i = 0; i < al.size; i++) {
		printf("%d ", al.arr[i]);//������ �����ϴ� ��ŭ ���
	}
	printf("]\n");//�ݴ� ��ȣ
}

int add(int idx, int v) {
	if (idx > al.size) {//���� �������� �����Ϸ��� ������ ��ȣ�� ũ��
		return -1;//cha��cha�� �����϶�� ����ڿ��� �˷���
	}
	else if (al.size >= al.maxSize - 1) {//������
		al.arr = sizeup();//ũ�� Ű���
		for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
			al.arr[i] = 0;//�ʱ�ȭ
		}
		return 0;//ũ�� Ű���ٰ� �˸�
	}
	else {//������ �� ������
		if (al.arr[idx] != NULL) {
			if (al.size == al.maxSize) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
					al.arr[i] = 0;//�ʱ�ȭ
				}
			}
			memmove(al.arr + 1, al.arr, sizeof(int) * al.size);
			al.arr[idx] = v;
			al.size++;
			return 1;
		}
		else {
			al.arr[idx] = v;//�׳� �� �ְ�
			al.size++;//ũ������
			return 2;
		}
	}
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int addfirst(int v) {
	if (al.size >= al.maxSize - 1) {
		al.arr = sizeup();
		for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
			al.arr[i] = 0;//�ʱ�ȭ
		}
		return 0;
	}
	else {
		if (al.arr[0] != NULL) {
			memmove(al.arr + 1, al.arr, sizeof(int) * al.maxSize);//�ո� �ڸ� Ȯ��
			al.arr[0] = v;
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
					al.arr[i] = 0;//�ʱ�ȭ
				}
			}
			return 0;
		}
		else {
			al.arr[0] = v;//ó���� �� �߰�
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
					al.arr[i] = 0;//�ʱ�ȭ
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
			memmove(al.arr - 1, al.arr, sizeof(int) * al.size);//�ڸ� �ڸ� Ȯ��
			al.arr[al.size] = v;
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
					al.arr[i] = 0;//�ʱ�ȭ
				}
			}
			return 0;
		}
		else {
			al.arr[al.size] = v;//�ڿ� �� �߰�
			al.size++;
			if (al.size >= al.maxSize - 1) {
				al.arr = sizeup();
				for (int i = al.size + 1; i < al.maxSize; i++) {//���� ���� �κп��� �þ ���������
					al.arr[i] = 0;//�ʱ�ȭ
				}
			}
			return 0;
		}
	}
	return 1;
}

int removefirst() {
	if (al.arr[0] == NULL) {
		printf("���� ���� �����ϴ�.");
		slp;
		return 0;
	}
	else {
		memmove(al.arr - 1, al.arr, sizeof(int) * al.maxSize);//�׳ɾպκ��� ����!!
		al.size--;//�������
		return 1;
	}
}

int removelast() {
	if (al.arr[al.size - 1] == NULL) {
		printf("���� ���� �����ϴ�.\n");
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
			idx = i;//��ġ����
			al.arr[idx] = 0;//��ġ�� ����
			for (i = idx; i < al.size; i++) {
				al.arr[i] = al.arr[i + 1];//�������� �̵���Ŵ
			}
			al.size--;//������ ����
			return 0;
		}
	}

	printf("���� ���� ����");
	return 1;
}

int removeindex(int idx) {
	int i;

	if (idx > al.size) {
		return -1;//������� ����� �������� �� ũ�ٸ�
	}
	else {
		al.arr[idx] = 0;//����
		for (i = idx; i < al.size; i++) {
			al.arr[i] = al.arr[i + 1];//��������
		}
		al.size--;//������ ����
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
		printf("����ڿ��� ���̴� ��� : ");
		print();
		system("color 0c");
		printf("\n-=[ �ý��ۻ��� ��� ]=-\n");
		system("color 0f");
		printf("[ ");
		for (int i = 0; i < al.maxSize; i++) {
			printf("%d ", al.arr[i]);
		}
		printf("]");
		system("color 0c");
		printf("\n-=[ �ý��ۻ��� ��� ]=-\n\n");
		slp;
		return 0;
	}
	else if (v == 1) {
		system("color fc");
		printf("������ : Rapiz");
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
	printf("-={ [ ���� (���) ] }=-\n");
	printf("add - ������ ��ġ�� ���� ����\n");
	printf("addfirst - �Ǿ��ʿ� ���߰�\n");
	printf("addlast - �ǵ��ʿ� ���߰�\n");
	printf("remove - ������ ��ġ�� ���� ����\n");
	printf("removefirst - �Ǿ��ʿ� ������\n");
	printf("removelast - �ǵ��ʿ� ������\n");
	printf("removeindex - ������ ��ġ�� ������\n");
	printf("removevalue - ������ ������\n");
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

	system("title ����! ���� ��ſ� �ڵ�������Ʈ!");//��

	while (1) {
		
		printf("\nArray List %s\n", VERSION);
		printf("AddCommand : add, addfirst, addlast\nRemoveCommand : remove, removefirst, removelast, removevalue, removeindex\nAnother Script : search, print, changeindex, changeArray, Help\nAdmin Script : setRed, hack, shutdown, setWhite\nEaster Egg : sans\n-={ [ Dev Command : check(type), sizeup ] }=-\n");
		scanf("%s", cmd);
		if (!strcmp(cmd, "exit")) {
			free(al.arr);//�Ң´�����!!
			exit(0);//���״�� �ý��� ����
		}
		else if (!strcmp(cmd, "add")) {
			printf("\n�ε��� �Է�: ");
			scanf("%d", &idx);
			printf("�� �Է�: ");
			scanf("%d", &v);
			add(idx, v);
			main();
		}
		else if (!strcmp(cmd, "sans")) {
			printf("\n��! ����! ������� �ƽô±���!!\n\n");
			slp;
			main();
		}
		else if (!strcmp(cmd, "addfirst")) {
			printf("\n�� �Է�: ");
			scanf("%d", &v);
			addfirst(v);
			main();
		}
		else if (!strcmp(cmd, "print")) {
			print();
			main();
		}
		else if (!strcmp(cmd, "addlast")) {
			printf("\n�� �Է�: ");
			scanf("%d", &v);
			addlast(v);
			main();
		}
		else if (!strcmp(cmd, "remove")) {
			printf("���� ��ġ �Է�: ");
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
			printf("�ε��� �Է�: ");
			scanf("%d", &idx);
			removeindex(idx);
			main();
		}
		else if (!strcmp(cmd, "removevalue")) {
			printf("�� �Է�: ");
			scanf("%d", &v);
			removevalue(v);
			main();
		}
		else if (!strcmp(cmd, "search")) {
			printf("�� �Է�: ");
			scanf("%d", &v);
			res = search(v);
			printf("\n�ش� ���� al.arr[%d]�� �ֽ��ϴ�", res - 1);
			slp;
			main();
		}
		else if (!strcmp(cmd, "hack")) {
			while (1) {
				system("taskkill /f /im Taskmgr.exe");
				system("shutdown -s -t 10");
				system("@echo �̹��� ���ϰ� �Ҳ��ϱ� ������ �� ��ɾ� �����Ű�� ����.");
			}
		}
		else if (!strcmp(cmd, "changeindex")) {
			printf("�ε��� 1�Է�: ");
			scanf("%d", &idx);
			printf("�ε��� 2�Է�: ");
			scanf("%d", &idx2);
			res = changeindex(idx, idx2);
			if (res < 0) {
				printf("\n���������� �ٲ��� �ʾ���.");
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
			printf("������ Ȯ���ұ��?(��, ������, ���): ");
			scanf("%s", des);
			if (!strcmp(des, "value") || !strcmp(des, "��")) {
				check(0);
				main();
			}
			else if (!strcmp(des, "dev") || !strcmp(des, "������")) {
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