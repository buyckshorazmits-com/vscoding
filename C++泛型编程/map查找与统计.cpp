#include<iostream>
#include<map>
using namespace std;

void PrintMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key=" << it->first << " " << "value=" << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int, int>m1;

	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>::iterator pos = m1.find(3);//find返回的是 该key值指向的迭代器
    //find 只按 key 查，不按 value。如果想按 value 找，得手动遍历（或用 std::find_if），
    //因为 map 的索引是 key。
	if (pos != m1.end())
	{
		cout << "找到了" <<pos->first<<" "<<pos->second<< endl;
	}
	else
	{
		cout << "没找到" << endl;
	}

	//map不允许插入重复key,0 or 1
	//multimap可以大于1，可以重复
	int num = m1.count(3);
	cout << num << endl;
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}