#include"game.h"


//

int main()
{
	//init_ui();
	//�����ߵĽṹ��
	Snake* snake =(Snake*) malloc(sizeof(Snake));
	//��ʼ���߽�
	init_wall(snake);
	//��ʼ���ߺ�ʳ��
	init_game(snake);
	//��ʾ����
	show_game(snake);
	//��ʼ��Ϸ
	start_game(snake);
	return 0;
}