#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#undef _UNICODE
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

bool Exit = true;//游戏是否结束
int Score = 0;//计算得分
bool hittarget = false;//子弹是否击中靶子
int i = 0;//用作打印多枚子弹时数组的变换
int count = 0;//用于限制子弹发射速度

//玩家的坐标
int player_x = 240;
int player_y = 700;

//敌人的坐标
int npc_x = 100;
int npc_y = -60;
int npc_move = 1;//改变敌人左右移动方向，正向右，负向左

//子弹坐标
int bullet_x[10] = { 0,0,0,0,0,0,0,0,0,0 };
int bullet_y[10] = { 0,0,0,0,0,0,0,0,0,0 };
int bullet_status[10] = { 0,0,0,0,0,0,0,0,0,0 };//子弹是否发射

typedef struct score
{
	char name[40];
	int score;
}rank;

IMAGE bk;//背景图片
IMAGE plane[2];//玩家图片
IMAGE Bullet[2];//子弹图片
IMAGE Npc[2];//敌人图片

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
	//设置窗口程序标题文本
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "小飞机大战");
	//进入主菜单
	Menu();
}

void GameMap() {
	//加载背景
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
		setfont(26, 0, "黑体");
		outtextxy(235, 200, "小飞机大战");
		setfont(20, 0, "黑体");
		outtextxy(250, 350, "开始游戏");
		outtextxy(250, 400, "排 行 榜");
		outtextxy(250, 450, "退    出");
		setcolor(RED);
		setfont(16, 0, "黑体");
		outtextxy(245, 600, "鼠标单击选择");
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
			Mode();
		}
		FlushBatchDraw();
	}
}

//监听主菜单鼠标点击事件
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

//游戏模块
void GameMode() {
	// 将 Exit 和 Score 初始为0
	Exit = true;
	Score = 0;
	//修正玩家初始位置
	player_x = 240;
	player_y = 700;
	//修正敌人的初始坐标
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
		//画面流畅
		FlushBatchDraw();
	}
}

//更新敌机移动、是否击中、当前得分和游戏是否结束
void UpdateWithoutInput() {
	//打印得分
	outtextxy(250, 870, "Score:");
	char s[5];
	sprintf_s(s, "%d", Score);
	outtextxy(290, 870, s);

	//加载靶子
	loadimage(&Npc[0], "./images/enemyPlane2.jpg", 40, 60);
	loadimage(&Npc[1], "./images/enemyPlane1.jpg", 40, 60);
	putimage(npc_x, npc_y, &Npc[1], NOTSRCERASE);
	putimage(npc_x, npc_y, &Npc[0], SRCINVERT);

	//靶子命中
	if (hittarget) {
		Score++;
		hittarget = false;
		npc_x = rand() % 400 + 100;
		npc_y = -60;
	}
	//靶子移动
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


	//子弹发射
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

	//死亡判定
	if (npc_y > 900) {
		Exit = false;
	}

}

//根据输入更新当前战机和子弹状态
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

	//加载角色
	loadimage(&plane[0], "./images/planeNormal_2.jpg", 60, 60);
	loadimage(&plane[1], "./images/planeNormal_1.jpg", 60, 60);
	putimage(player_x, player_y, &plane[1], NOTSRCERASE);
	putimage(player_x, player_y, &plane[0], SRCINVERT);
}

//获取排行榜
int GetRank() {

	//打开文件
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

	//冒泡排序
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
		setfont(26, 0, "黑体");
		outtextxy(240, 200, "排 行 榜");
		setfont(16, 0, "黑体");
		int w;
		for (i = 0, w = 300; i < (k > 10 ? 10 : k); i++, w = w + 20)
		{
			//将数整型数字转为字符串
			char rankNum[5];
			char rankScore[5];
			sprintf(rankNum, "%d", i + 1);
			sprintf(rankScore, "%d", a[i].score);
			outtextxy(200, w, rankNum);
			outtextxy(230, w, a[i].name);
			outtextxy(400, w, rankScore);
		}
		fclose(fp);
		outtextxy(275, 600, "ESC返回");
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Menu();
		}
		FlushBatchDraw();
	}
};

//敌机掉底，游戏结束
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
		setfont(26, 0, "黑体");
		char scoreResult[20];
		sprintf(scoreResult, "%d", Score);
		outtextxy(200, 400, "你的得分：");
		outtextxy(350, 400, scoreResult);
		outtextxy(275, 600, "ESC返回");
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			Menu();
		}
		FlushBatchDraw();
	}
}

//写入排行榜
int Record() {
	FILE* fp;
	fp = fopen("./images/rank.txt", "a");
	if (fp == NULL)
	{
		system("pause");
		return -1;//如果文件出现错误返回-1  
	}
	rank newscore;
	InputBox(newscore.name, 39, "请输入您的名字：");
	newscore.score = Score;
	fprintf(fp, "\n%s %d", newscore.name, newscore.score);
	fclose(fp);
	return 0;
};