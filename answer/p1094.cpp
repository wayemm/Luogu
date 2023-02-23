#include <iostream>
#include <algorithm>
using namespace std;
int a[50005];
int main()
{
	int n, w, i, j, k = 0;
	cin >> n >> w;
	for (i = 1; i <= w; i++)
		cin >> a[i];
	sort(a + 1, a + w + 1);
	i = 1;
	j = w;
	while (j >= i)
	{
		if (a[i] + a[j] > n)
		{ 
			k++;
			j--;
		}
		else if (a[i] + a[j] <= n) 
		{
			k++;
			i++;
			j--;
		}
	}
	cout << k; 
	return 0;
}
