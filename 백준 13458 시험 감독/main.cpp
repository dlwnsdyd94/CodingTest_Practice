#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
ll B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ifstream readFile;
	readFile.open("input.txt");
	readFile >> N;

	ll* Class = new ll[1000000];

	for (int i = 0; i < N; i++)
	{
		readFile >> Class[i];
	}

	readFile >> B >> C;

	ll main_sup; // 총 감독관 명수
	ll sub_sup; // 부 감독관 명수

	for (int i = 0; i < N; i++)
	{
		if (Class[i] - B < 0)
		{
			Class[i] = 0;
		}
		else
		{
			Class[i] -= B;
		}
	}

	ll num_sup = 0;
	for (int i = 0; i < N; i++)
	{
		num_sup += Class[i] / C;
		if (Class[i] % C != 0)
		{
			num_sup += 1;
		}
	}

	cout << N + num_sup;

	delete[] Class;

	return 0;
}