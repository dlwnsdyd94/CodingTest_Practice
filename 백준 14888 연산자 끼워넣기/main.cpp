#include<bits/stdc++.h>
using namespace std;

#define MAX 100

int N;
int num[MAX];
int cmd[4];

// + : 0
// - : 1
// * : 2
// / : 3

int Min = 9876543210;
int Max = -9876543210;


void choice_dfs(int result, int num_index)
{
	if (num_index == N - 1)
	{
		if (Min > result)
		{
			Min = result;
		}
		if (Max < result)
		{
			Max = result;
		}

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (cmd[i] != 0)
		{
			cmd[i] -= 1;

			if (i == 0)
			{
				choice_dfs(result + num[num_index + 1], num_index + 1);
			}
			else if (i == 1)
			{
				choice_dfs(result - num[num_index + 1], num_index + 1);
			}
			else if (i == 2)
			{
				choice_dfs(result * num[num_index + 1], num_index + 1);
			}
			else if (i == 3)
			{
				choice_dfs(result / num[num_index + 1], num_index + 1);
			}

			cmd[i] += 1;
		}
		
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N;

	for (int i = 0; i < N; i++)
	{
		readFile >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		readFile >> cmd[i];
	}

	choice_dfs(num[0], 0);
	
	cout << Max << '\n';
	cout << Min << '\n';

	return 0;
}