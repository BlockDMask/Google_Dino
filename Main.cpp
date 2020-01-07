//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//안녕하세요. BlockDMask 입니다.
//사용하실땐 꼭 출처를 남겨주세요. 
//블로그 : https://blockdmask.tistory.com/344

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs. By BlockDMask.");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//공룡을 그리는 함수
void DrawDino(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$     \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}

//나무를 그리는 함수
void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$ ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$ ");
}

int main()
{
	SetConsoleView();

	bool isJumping = false;
	bool isBottom = true;
	const int gravity = 3;

	int dinoY = DINO_BOTTOM_Y;
	int treeX = TREE_BOTTOM_X;

	while (true)
	{
		//z키가 눌렸고, 바닥이 아닐때 점프
		if (GetKeyDown() == 'z' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		//점프중이라면 Y를 감소, 점프가 끝났으면 Y를 증가.
		if (isJumping)
		{
			dinoY -= gravity;
		}
		else
		{
			dinoY += gravity;
		}

		//Y가 계속해서 증가하는걸 막기위해 바닥을 지정.
		if (dinoY >= DINO_BOTTOM_Y)
		{
			dinoY = DINO_BOTTOM_Y;
			isBottom = true;
		}

		//나무가 왼쪽으로 (x음수) 가도록하고
		//나무의 위치가 왼쪽 끝으로가면 다시 오른쪽 끝으로 소환.
		treeX -= 2;
		if (treeX <= 0)
		{
			treeX = TREE_BOTTOM_X;
		}

		//점프의 맨위를 찍으면 점프가 끝난 상황.
		if (dinoY <= 3)
		{
			isJumping = false;
		}

		DrawDino(dinoY);		//draw dino
		DrawTree(treeX);		//draw Tree
		Sleep(60);
		system("cls");	//clear
	}
	return 0;
}
