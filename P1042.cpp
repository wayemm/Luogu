#include<iostream>
#include<cmath>
using namespace std;
void Ele(char*,int,int);
int main()
{
	using namespace std;
	int i;
	char a[2501 * 25 + 1];
	char c;
	for (i = 1;cin>>c&&c!='E'; i++)
	{
		a[i] = c;
	}
	Ele(a, i, 11);
	cout << endl;
	Ele(a, i, 21);
	return 0;
}

void Ele(char *a, int size, int grade)
{

	int one = 0;
	int two = 0;
	for (int i = 1; i <= size; i++)
	{
		if (a[i] == 'W')
		{
			one++;
		}
		if (a[i] == 'L')
		{
			two++;
		}
		if (i == size)
		{
			cout << one << ":" << two
				<< endl;
		}
		if (abs(one - two) >= 2) {
			if (one >= grade || two >= grade) {
				cout << one << ":" << two << endl;
				one = 0;
				two = 0;
			}
		}
	}
}
