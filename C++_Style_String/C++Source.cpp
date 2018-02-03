#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void removespace(string &hoten)
{
	while (hoten.front() == ' ')
	{
		hoten.erase(hoten.begin());
	}

	while (hoten.back() == ' ')
	{
		hoten.pop_back();
	}
}

void upper_lower(string &hoten, int sokitu)
{
	hoten[0] = toupper(hoten[0]);
	for (int i = 1; i < sokitu; i++)
	{
		if (hoten[i] == ' ')
		{
			hoten[i + 1] = toupper(hoten[i + 1]);
		}
		else if (isgraph(hoten[i]) && hoten[i - 1] != ' ')
		{
			hoten[i] = tolower(hoten[i]);
		}
	}
}

void remove_excess_space(string &hoten, int sokitu)
{
	for (int j = 1; j < sokitu; j++)
	{
		if (hoten[j] == ' ' && hoten[j + 1] == ' ')
		{
			hoten.erase(hoten.begin() + j);
			sokitu--;
			j--;
		}
	}
}

int main()
{
	string hoten;
	cout << "Nhap ho va ten: ";
	getline(cin, hoten);
	removespace(hoten);
	int sokitu = hoten.size();
	upper_lower(hoten, sokitu);
	remove_excess_space(hoten, sokitu);
	cout << "ho va ten sau khi sua: " << hoten;
	cout << endl;
	system("pause");
	return 0;
}

``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

void removeSpace(string &);
void changeStyle(string &);

int main()
{
	string text;

	cout << "Nhap vao string: ";
	getline(cin, text);

	removeSpace(text);
	changeStyle(text);

	cout << "String theo chuan C-Style String la: " << text;

	system("pause");
	return 0;
}

void removeSpace(string &text)
{
	while (text.front() == ' ')
	{
		text.erase(text.begin());
	}

	while (text.back() == ' ')
	{
		text.pop_back();
	}
}

void changeStyle(string &text)
{
	bool isInText = false;

	for (uint16_t loop = 0; loop < text.size(); loop++)
	{
		if (isgraph(text.at(loop)))
		{
			if (!isInText)
			{
				text.at(loop) = toupper(text.at(loop));
				isInText = true;
			}
			else
			{
				text.at(loop) = tolower(text.at(loop));
			}
		}
		else
		{
			if (isInText)
			{
				isInText = false;
			}
			else
			{
				text.erase(text.begin() + loop);
				loop--;
			}
		}
	}
}
