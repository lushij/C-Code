#include"game.h"


//

int main()
{
	//init_ui();
	//申请蛇的结构体
	Snake* snake =(Snake*) malloc(sizeof(Snake));
	//初始化边界
	init_wall(snake);
	//初始化蛇和食物
	init_game(snake);
	//显示界面
	show_game(snake);
	//开始游戏
	start_game(snake);
	return 0;
}