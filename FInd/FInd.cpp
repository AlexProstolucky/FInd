#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector <int>& v) 
{ 
	vector <int> find;
	sort(v.begin(), v.end());
	if (v.size() != 0) {
		cout << "Vector: ";
		for (size_t i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
		int i = 0;
		int step = 0;
		if (v[0] != 1) 
		{
			v.emplace(v.begin(), 1);
			find.push_back(1);
		}

		while (i < v[v.size() - 1]) 
		{
			int buff = v[i];
			if (buff != v[v.size() - 1])
			{
				if (v[i + 1] - (buff + step) != 1)
				{
					find.push_back(v[i + 1] - 1 - step);
					step++;
					continue;
				}
				else
				{
					i++;
					step = 0;
				}
			}
			else break;
		}
		sort(find.begin(), find.end());
		cout << "Find num: ";
		for (size_t i = 0; i < find.size(); i++)
		{
			cout << find[i] << " ";
		}
	}
	else cout << "Vector is empty!";

}

int main()
{
	vector <int> A{4,5,6,7,9};
	solution(A);
}