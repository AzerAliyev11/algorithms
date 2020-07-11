#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<cmath>
using namespace std;

typedef long long int lli;

struct values
{
	int pi1;
	int pi2;
};

void swap(lli *a, lli *b)
{
	lli c = *a;
	*a = *b;
	*b = c;
}

void print_vector(vector<lli> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

values partition(vector<lli> &v, int low, int high)
{
	values index;

	lli pivot = v[low];
	int i = low;

	for (int j = i+1; j < high; j++)
	{
		if (v[j]<pivot)
		{
			i++;
			swap(&v[i], &v[j]);
		}
	}

	swap(&v[i], &v[low]);
	index.pi1 = i;

	for (int j = i + 1; j < high; j++)
	{
		if (v[j] == pivot)
		{
			i++;
			swap(&v[i], &v[j]);
		}
	}

	index.pi2 = i;

	return index;
}

void quicksort(vector<lli> &v, int low, int high)
{
	if (low < high)
	{
		values index = partition(v, low, high);

		quicksort(v, low, index.pi1);
		quicksort(v, index.pi2+1, high);
	}
}

int main()
{
	int n;
	vector<lli> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		lli a;
		cin >> a;
		v.push_back(a);
	}

	quicksort(v, 0, v.size());
	//partition(v, 0, v.size());
	print_vector(v);

	system("Pause");
}