#include <iostream>
#include<algorithm>
using namespace std;
#define max 100100
int main()
{
	int N, i, j, result = 0, temp = 0;
	long int p;
	long int A[max];
	cin >> N >> p;
	for (i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	for (i = 0; i < N; i++)
	{
		for (j = i + result; j < N; j++)
		{
			if (A[j] <= A[i] * p)
			{
				temp = j - i + 1;		//temp��ŵ�ǰΪiΪ��СԪ�ص����е�Ԫ��������
			}
			else    //A[j]����p*m
			{
				break;
			}
			if (temp > result)
			{
				result = temp;
			}
		}
	}
	cout << result;
	return 0;
}