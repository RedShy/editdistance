#include <iostream>
#include <cstring>
using namespace std;

int minimum(int a, int b, int c)
{
	int min = a;

	if (b < min) min = b;
	if (c < min) min = c;

	return min;
}

void print_matrix(int** m, string s1, string s2)
{
	int r = s1.length() + 1;
	int c = s2.length() + 1;
	cout << "    ";
	for (int i = 0; i < s2.length(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		if (i == 0)
		{
			cout << "  ";
		}
		else
		{
			cout << s1[i - 1] << " ";
		}
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int edit_distance(string s1, string s2)
{
	int rows = s1.length() + 1;
	int cols = s2.length() + 1;
	int ** m = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		m[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		m[i][0] = i;
	}

	for (int j = 0; j < cols; j++)
	{
		m[0][j] = j;
	}
	int cost_of_substitution = 0;
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				cost_of_substitution = 0;
			}
			else
			{
				cost_of_substitution = 1;
			}
			m[i][j] = minimum(m[i - 1][j - 1] + cost_of_substitution,
					m[i - 1][j] + 1, m[i][j - 1] + 1);
		}
	}


	print_matrix(m, s1, s2);

	return m[rows - 1][cols - 1];

}


int main()
{

	cout << "Edit distance = " << edit_distance("sauron", "saruman");

	return 0;
}
