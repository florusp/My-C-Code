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
