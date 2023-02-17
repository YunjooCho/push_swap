#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int arr[501];

int	all()
{
	for(int i = 0; i<500; i++)
	{
		if (arr[i] == 0)
			return (1);
	}
	return (0);
}

int main()
{
	srand((unsigned int)time(NULL));
	while (all())
	{
		int num = rand() % 500;
		if (arr[num] == 0)
		{
			cout << num << " ";
			arr[num] = 1;
		}
	}
}