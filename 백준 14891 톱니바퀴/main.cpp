#include<bits/stdc++.h>
using namespace std;

int chain[4][8];
int K;

// dir : 1 시계방향
// dir : -1 반시계방향
void rotate(int chain_num, int dir)
{
	if (dir == 1) // 시계 방향 회전
	{
		int temp = chain[chain_num][7];
		chain[chain_num][7] = chain[chain_num][6];
		chain[chain_num][6] = chain[chain_num][5];
		chain[chain_num][5] = chain[chain_num][4];
		chain[chain_num][4] = chain[chain_num][3];
		chain[chain_num][3] = chain[chain_num][2];
		chain[chain_num][2] = chain[chain_num][1];
		chain[chain_num][1] = chain[chain_num][0];
		chain[chain_num][0] = temp;
	}
	else if (dir == -1) // 반시계 방향 회전
	{
		int temp = chain[chain_num][0];
		chain[chain_num][0] = chain[chain_num][1];
		chain[chain_num][1] = chain[chain_num][2];
		chain[chain_num][2] = chain[chain_num][3];
		chain[chain_num][3] = chain[chain_num][4];
		chain[chain_num][4] = chain[chain_num][5];
		chain[chain_num][5] = chain[chain_num][6];
		chain[chain_num][6] = chain[chain_num][7];
		chain[chain_num][7] = temp;
	}
}

int check_state[3]; 
void check_chain()
{
	for (int i = 0; i < 3; i++)
	{
		if (chain[i][2] == chain[i + 1][6])
		{
			check_state[i] = 0; // 회전 X
		}
		else
		{
			check_state[i] = 1; // 회전하는 바퀴와 반대 방향 회전
		}
	}
}

void arrange(int chain_cmd, int rotate_cmd)
{
	check_chain(); // 각 바퀴에 맞닿아 있는 부분 체크
	if (chain_cmd == 0)
	{
		rotate(0, rotate_cmd); // 0번 바퀴 회전
			
		if (check_state[0]) // 만약 값이 다르면
		{
			rotate(1, -rotate_cmd); // 1번 바퀴 회전

			if (check_state[1]) // 만약 값이 다르면
			{
				rotate(2, rotate_cmd); // 2번 바퀴 회전
					
				if (check_state[2]) // 만약 값이 다르면
				{
					rotate(3, -rotate_cmd); // 3번 바퀴 회전
				}
			}
		}
	}
	else if (chain_cmd == 1)
	{
		if (check_state[0])
		{
			rotate(0, -rotate_cmd);
		}

		rotate(1, rotate_cmd);

		if (check_state[1])
		{
			rotate(2, -rotate_cmd);

			if (check_state[2])
			{
				rotate(3, rotate_cmd);
			}
		}
	}
	else if (chain_cmd == 2)
	{
		if (check_state[1])
		{
			rotate(1, -rotate_cmd);

			if (check_state[0])
			{
				rotate(0, rotate_cmd);
			}
		}

		rotate(2, rotate_cmd);

		if (check_state[2])
		{
			rotate(3, -rotate_cmd);
		}
	}
	else if (chain_cmd == 3)
	{
		if (check_state[2])
		{
			rotate(2, -rotate_cmd);

			if (check_state[1])
			{
				rotate(1, rotate_cmd);

				if (check_state[0])
				{
					rotate(0, -rotate_cmd);
				}
			}
		}

		rotate(3, rotate_cmd);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");

	char char_chain[4][8];
	for (int chain_num = 0; chain_num < 4; chain_num++)
	{
		for (int i = 0; i < 8; i++)
		{
			readFile >> char_chain[chain_num][i];
			chain[chain_num][i] = char_chain[chain_num][i] - '0';
		}
	}

	readFile >> K;
	for (int cmd_num = 0; cmd_num < K; cmd_num++)
	{
		int chain_cmd, rotate_cmd;
		readFile >> chain_cmd >> rotate_cmd;
		arrange(chain_cmd - 1, rotate_cmd);
	}

	int ans = 0;
	ans = chain[0][0] + chain[1][0] * 2 + chain[2][0] * 4 + chain[3][0] * 8;

	cout << ans;

	return 0;
}