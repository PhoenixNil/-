#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, string> Behind;
map<string, int> index;
struct node
{
    int data;
    string address;
    string next;
};
node A[100005];
vector<node> B;
vector<node> C;
vector<node> D;
int count1[100005];
int main()
{
    string s, temp2;
    node temp;
    int N, i, temp3;
    cin >> s >> N;
    for (i = 0; i < N; i++)
    {
        cin >> temp.address >> temp.data >> temp.next;
        Behind[temp.address] = temp.next;
        index[temp.address] = i; //记录当前address在A数组的位置
        A[i] = temp;
    }
    for (temp2 = s; temp2 != "-1"; temp2 = Behind[temp2])
    {
        B.push_back(A[index[temp2]]);
        temp3 = abs(B.back().data);
        count1[temp3]++;
        if (count1[temp3] > 1)
        {
            C.push_back(B.back());
        }
        else
            D.push_back(B.back());
    }
    //然后对这个Vecto执行删除操作,next节点要变
    for (i = 0; i < D.size(); i++)
    {
        if (i == D.size() - 1)
        {
            cout << D[i].address << " " << D[i].data << " " << -1 << endl;
        }
        else
            cout << D[i].address << " " << D[i].data << " " << D[i + 1].address << endl;
    }
    for (i = 0; i < C.size(); i++)
    {
        if (i == C.size() - 1)
        {
            cout << C[i].address << " " << C[i].data << " " << -1 << endl;
        }
        else
            cout << C[i].address << " " << C[i].data << " " << C[i + 1].address << endl;
    }
    return 0;
}