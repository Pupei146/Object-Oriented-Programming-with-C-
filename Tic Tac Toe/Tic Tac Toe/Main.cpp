#include<iostream>
using namespace std;
void Player1(void); //玩家1输入(操作)函数
void Player2(void); //玩家2输入(操作)函数
void game_judge(void); //输赢判断
void game_start(void); //游戏开始
int rows = 3, cols = 3; //棋盘大小
bool win1_flag = false; //玩家1获胜标志位
bool win2_flag = false; //玩家2获胜标志位
char pieces[3][3] = { {' ',' ',' '},
{' ',' ',' '},
{' ',' ',' '} };; //初始化
void draw(void) //打印出棋盘
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << pieces[i][j];
			if (j < cols - 1)
				cout << " | ";
		}
		cout << "\n";
		if (i < rows - 1)
			cout << "－－－－－" << endl;
	}
	cout << "\n";
}
void game_start(void) //游戏开始
{
	int n = 0; //总3*3=9个输入位,用于判断是否填完
	bool flag = false; //玩家切换标志位
	cout << "游戏开始" << endl;
	while (n < 9 & win1_flag == false & win2_flag == false) //未填完,未分出胜负则继续游戏
	{
		if (flag == false) { //切换到玩家1
			cout << "玩家1输入:" << endl;
			Player1(); //玩家1输入棋子位置
			flag = true; //下一步是玩家2
		}
		else { //切换到玩家2
			cout << "玩家2输入:" << endl;
			Player2(); //玩家2输入棋子位置
			flag = false; //下一步是玩家1
		}
		game_judge(); //判断胜负
		draw(); //打印出棋盘
		n++; //棋盘又添了一枚棋子
	}
}
void game_judge(void) //判断胜负
{
	for (int i = 0; i < rows; i++) {
		if (pieces[i][0] == pieces[i][1] & pieces[i][0] == pieces[i][2] & pieces[i][0] != ' ') //判断横方向满3个相同的棋子
		{
			if (pieces[i][0] == 'O') //判断是玩家1的棋子还是玩家2
				win1_flag = true; //玩家1获胜
			else
				win2_flag = true; //玩家2获胜
		}
		if (pieces[0][i] == pieces[1][i] & pieces[1][i] == pieces[2][i] & pieces[0][i] != ' ') //判断纵方向满3个相同的棋子
		{
			if (pieces[0][i] == 'O') //判断是玩家1的棋子还是玩家2
				win1_flag = true;
			else
				win2_flag = true;
		}
		if ((pieces[0][0] == pieces[1][1] & pieces[1][1] == pieces[2][2] & pieces[0][0] != ' ') //判断斜方向满3个相同的棋子
			| (pieces[0][2] == pieces[1][1] & pieces[1][1] == pieces[2][0] & pieces[2][0] != ' '))
		{
			if (pieces[1][1] == 'O') //判断是玩家1的棋子还是玩家2
				win1_flag = true;
			else
				win2_flag = true;
		}
	}
}
void Player1(void)
{
	int row0, col0;
	cin >> row0 >> col0; //玩家1输入位置
	while (pieces[row0 - 1][col0 - 1] != ' ') //判断该位置是否已有棋子,或不存在
	{
		cout << "该位置输入错误,请重新输入" << endl;
		cout << "请输入行列数(1-3),以空格隔开:";
		cin >> row0 >> col0; //重新输入位置
	}
	pieces[row0 - 1][col0 - 1] = 'O'; //棋盘中放置玩家1棋子
}
void Player2(void)
{
	int row1, col1;
	cin >> row1 >> col1; //玩家1输入位置
	while (pieces[row1 - 1][col1 - 1] != ' ') //判断该位置是否已有棋子,或不存在
	{
		cout << "该位置输入错误,请重新输入" << endl;
		cout << "请输入行列数(1-3),以空格隔开:";
		cin >> row1 >> col1; //重新输入位置
	}
	pieces[row1 - 1][col1 - 1] = 'X'; //棋盘中放置玩家2棋子
}
int main(int argc, char** argv)
{
	cout << "游戏加载中" << endl;
	draw(); //打印初始棋盘
	game_start(); //开始游戏
	if (win1_flag == true) //玩家1获胜
		cout << "玩家1获胜!" << endl;
	if (win2_flag == true) //玩家2获胜
		cout << "玩家2获胜!" << endl;
	if (win1_flag == win2_flag) //均未获胜,平局
		cout << "平局!" << endl;
	return 0;
}