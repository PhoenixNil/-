#include <iostream>
#include<algorithm>
using namespace std;
int A[100005];
int B[100005];
int cnt[100005];
int main()
//�ҵ���Ԫ������ǰ��Ķ�����С������Ķ�������
{
	int N, i, max;
	int prvot = 0;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B, B + N);
	max = A[0];
	for (i = 0; i < N; i++)
	{
		if (A[i] > max)
			max = A[i];
		if (A[i] == B[i])		//���������֮�����������ڵ�λ�þ���ԭ���������ڵ�λ�ã����ұ���ǰ������Ԫ�ض�Ҫ��������������Ԫ
		{
			//cnt[prvot++] = A[i];
			if (B[i] >= max)
			{
				max = B[i];
				cnt[prvot++] = B[i];
			}
		}
	}
	cout << prvot << endl;
	cout << cnt[0];
	for (i = 1; i < prvot; i++)
	{
		cout << " " << cnt[i];
	}
	return 0;
}