//[C/C++ game] very simple google dinosaur. (by. BlockDMask)
//�ȳ��ϼ���. BlockDMask �Դϴ�.
//����ϽǶ� �� ��ó�� �����ּ���. 
//��α� : https://blockdmask.tistory.com/344
//�ν�Ÿ : https://www.instagram.com/blockdmask/
//���� ��α� �湮, �ν�Ÿ�׷� �ȷο� ��Ź�帳�ϴ�. �����մϴ�.
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45

//�ܼ� â�� ũ��� ������ �����ϴ� �Լ�
void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs. By BlockDMask.");
}

//Ŀ���� ��ġ�� x, y�� �̵��ϴ� �Լ�
void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//Ű������ �Է��� �ް�, �Էµ� Ű�� ���� ��ȯ�ϴ� �Լ�
int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

//������ �׸��� �Լ�
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

//������ �׸��� �Լ�
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
		//zŰ�� ���Ȱ�, �ٴ��� �ƴҶ� ����
		if (GetKeyDown() == 'z' && isBottom)
		{
			isJumping = true;
			isBottom = false;
		}

		//�������̶�� Y�� ����, ������ �������� Y�� ����.
		if (isJumping)
		{
			dinoY -= gravity;
		}
		else
		{
			dinoY += gravity;
		}

		//Y�� ����ؼ� �����ϴ°� �������� �ٴ��� ����.
		if (dinoY >= DINO_BOTTOM_Y)
		{
			dinoY = DINO_BOTTOM_Y;
			isBottom = true;
		}

		//������ �������� (x����) �������ϰ�
		//������ ��ġ�� ���� �����ΰ��� �ٽ� ������ ������ ��ȯ.
		treeX -= 2;
		if (treeX <= 0)
		{
			treeX = TREE_BOTTOM_X;
		}

		//������ ������ ������ ������ ���� ��Ȳ.
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