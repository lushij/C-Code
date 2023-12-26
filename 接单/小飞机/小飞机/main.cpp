#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#undef _UNICODE
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

bool Exit = true;//��Ϸ�Ƿ����
int Score = 0;//����÷�
bool hittarget = false;//�ӵ��Ƿ���а���
int i = 0;//������ӡ��ö�ӵ�ʱ����ı任
int count = 0;//���������ӵ������ٶ�

//��ҵ�����
int player_x = 240;
int player_y = 700;

//���˵�����
int npc_x = 100;
int npc_y = -60;
int npc_move = 1;//�ı���������ƶ����������ң�������

//�ӵ�����
int bullet_x[10] = { 0,0,0,0,0,0,0,0,0,0 };
int bullet_y[10] = { 0,0,0,0,0,0,0,0,0,0 };
int bullet_status[10] = { 0,0,0,0,0,0,0,0,0,0 };//�ӵ��Ƿ���

typedef struct score
{
	char name[40];
	int score;
}rank;

IMAGE bk;//����ͼƬ
IMAGE plane[2];//���ͼƬ
IMAGE Bullet[2];//�ӵ�ͼƬ
IMAGE Npc[2];//����ͼƬ

void GameMap();
void Mode();
void Menu();
void GameMode();
void UpdateWithoutInput();
void UpdateWithInput();
int GetRank();
void End();
int Record();

int main() {
	initgraph(600, 900);
	//���ô��ڳ�������ı�
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "С�ɻ���ս");
	//�������˵�
	Menu();
}

void GameMap() {
	//���ر���
	loadimage(&bk, "./images/background.jpg", 600, 900);
	putimage(0, 0, &bk);
}

void Menu() {
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		GameMap();
		setbkcolor(WHITE);
		setcolor(BLACK);
		setfont(26, 0, "����");
		outtextxy(235, 200, "С�ɻ���ս");
		setfont(20, 0, "����");
		outtextxy(250, 350, "��ʼ��Ϸ");
		outtextxy(250, 400, "�� �� ��");
		outtextxy(250, 450, "��    ��");
		setcolor(RED);
		setfont(16, 0, "����");
		outtextxy(245, 600, "��굥��ѡ��");
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
			Mode();
		}
		FlushBatchDraw();
	}
}

//�������˵�������¼�
void Mode() {
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x >= 240 && m.x <= 360 && m.y >= 340 && m.y < 370)
			{
				GameMode();
				break;
			}
			else if (m.x >= 240 && m.x <= 360 && m.y >= 380 && m.y < 430)
			{
				GetRank();
				break;
			}
			else if (m.x >= 240 && m.x <= 360 && m.y >= 440 && m.y < 490)
			{
				closegraph();
				break;
			}
			else
			{
				continue;
			}
		}
	}
}

//��Ϸģ��
void GameMode() {
	// �� Exit �� Score ��ʼΪ0
	Exit = true;
	Score = 0;
	//������ҳ�ʼλ��
	player_x = 240;
	player_y = 700;
	//�������˵ĳ�ʼ����
	npc_x = 100;
	npc_y = -60;
	mciSendString("open ./images/game_music.mp3 alias bkmusic", 0, 0, 0);
	mciSendString("play bkmusic repeat", 0, 0, 0);
	while (1) {
		cleardevice();
		GameMap();
		if (Exit) {
			UpdateWithoutInput();
			UpdateWithInput();
		}
		else {
			End();
			break;
		}
		//��������
		FlushBatchDraw();
	}
}

//���µл��ƶ����Ƿ���С���ǰ�÷ֺ���Ϸ�Ƿ����
void UpdateWithoutInput() {
	//��ӡ�÷�
	outtextxy(250, 870, "Score:");
	char s[5];
	sprintf_s(s, "%d", Score);
	outtextxy(290, 870, s);

	//���ذ���
	loadimage(&Npc[0], "./images/enemyPlane2.jpg", 40, 60);
	loadimage(&Npc[1], "./images/enemyPlane1.jpg", 40, 60);
	putimage(npc_x, npc_y, &Npc[1], NOTSRCERASE);
	putimage(npc_x, npc_y, &Npc[0], SRCINVERT);

	//��������
	if (hittarget) {
		Score++;
		hittarget = false;
		npc_x = rand() % 400 + 100;
		npc_y = -60;
	}
	//�����ƶ�
	npc_x += npc_move * 2;
	npc_y++;
	if (npc_x % 50 == 0) {
		switch (rand() % 2 - 1)
		{
		case 1: {
			npc_move = 1;
			break;
		}
		case -1: {
			npc_move = -1;
			break;
		}
		default:
			break;
		}

	}
	if (npc_x > 540) {
		npc_move = -1;
	}
	else if (npc_x < 0) {
		npc_move = 1;
	}


	//�ӵ�����
	loadimage(&Bullet[0], "./images/bullet2.jpg", 10, 20);
	loadimage(&Bullet[1], "./images/bullet1.jpg", 10, 20);
	for (int j = 0; j < 10; j++)
	{
		if (bullet_status[j] == 1) {
			putimage(bullet_x[j], bullet_y[j], &Bullet[1], NOTSRCERASE);
			putimage(bullet_x[j], bullet_y[j], &Bullet[0], SRCINVERT);
			bullet_y[j] -= 5;
			if (bullet_y[j] < 0) {
				bullet_status[j] = 0;
			}
			if ((bullet_x[j] - npc_x > 5) && (bullet_x[j] - npc_x < 35) && (bullet_y[j] - npc_y < 60) && (bullet_y[j] - npc_y > 0)) {
				hittarget = true;
				bullet_status[j] = 0;
			}
		}
	}

	//�����ж�
	if (npc_y > 900) {
		Exit = false;
	}

}

//����������µ�ǰս�����ӵ�״̬
void UpdateWithInput() {
	if (Exit) {
		if (GetAsyncKeyState(VK_UP) && 0x8000) {
			player_y -= 3;
		}
		else if (GetAsyncKeyState(VK_DOWN) && 0x8000) {
			player_y += 3;
		}
		else if (GetAsyncKeyState(VK_LEFT) && 0x8000) {
			player_x -= 3;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && 0x8000) {
			player_x += 3;
		}
		else if (GetAsyncKeyState(VK_SPACE) && 0x8000 && count++ % 20 == 0) {
			bullet_status[i] = 1;
			bullet_x[i] = player_x + 20;
			bullet_y[i++] = player_y - 14;
			if (i == 10) {
				i = 0;
			}
		}
	}

	//���ؽ�ɫ
	loadimage(&plane[0], "./images/planeNormal_2.jpg", 60, 60);
	loadimage(&plane[1], "./images/planeNormal_1.jpg", 60, 60);
	putimage(player_x, player_y, &plane[1], NOTSRCERASE);
	putimage(player_x, player_y, &plane[0], SRCINVERT);
}

//��ȡ���а�
int GetRank() {

	//���ļ�
	rank a[100];
	int i, j, k;
	FILE* fp;
	fp = fopen("./images/rank.txt", "r");
	if (fp == NULL) {
		system("pause");
		return -1;
	}
	for (k = 0; k < 100; k++) {
		if (fscanf(fp, "%s %d", a[k].name, &a[k].score) == EOF) {
			break;
		}
	}

	//ð������
	rank tem;
	for (i = 0; i < 10; i++)
	{
		for (j = k - 1; j > i; j--)
		{
			if (a[j].score > a[j - 1].score)
			{
				tem.score = a[j].score;
				a[j].score = a[j - 1].score;
				a[j - 1].score = tem.score;

				strcpy(tem.name, a[j].name);
				strcpy(a[j].name, a[j - 1].name);
				strcpy(a[j - 1].name, tem.name);
			}
		}
	}
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		GameMap();
		setbkcolor(WHITE);
		setcolor(BLACK);
		setfont(26, 0, "����");
		outtextxy(240, 200, "�� �� ��");
		setfont(16, 0, "����");
		int w;
		for (i = 0, w = 300; i < (k > 10 ? 10 : k); i++, w = w + 20)
		{
			//������������תΪ�ַ���
			char rankNum[5];
			char rankScore[5];
			sprintf(rankNum, "%d", i + 1);
			sprintf(rankScore, "%d", a[i].score);
			outtextxy(200, w, rankNum);
			outtextxy(230, w, a[i].name);
			outtextxy(400, w, rankScore);
		}
		fclose(fp);
		outtextxy(275, 600, "ESC����");
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Menu();
		}
		FlushBatchDraw();
	}
};

//�л����ף���Ϸ����
void End() {
	mciSendString("close bkmusic", 0, 0, 0);
	Record();
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		GameMap();
		setbkcolor(WHITE);
		setcolor(BLACK);
		setfont(26, 0, "����");
		char scoreResult[20];
		sprintf(scoreResult, "%d", Score);
		outtextxy(200, 400, "��ĵ÷֣�");
		outtextxy(350, 400, scoreResult);
		outtextxy(275, 600, "ESC����");
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Menu();
		}
		FlushBatchDraw();
	}
}

//д�����а�
int Record() {
	FILE* fp;
	fp = fopen("./images/rank.txt", "a");
	if (fp == NULL)
	{
		system("pause");
		return -1;//����ļ����ִ��󷵻�-1  
	}
	rank newscore;
	InputBox(newscore.name, 39, "�������������֣�");
	newscore.score = Score;
	fprintf(fp, "\n%s %d", newscore.name, newscore.score);
	fclose(fp);
	return 0;
};