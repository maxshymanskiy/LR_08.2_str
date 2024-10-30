#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

string processString(const string& input) 
{
    size_t spacePos = input.find(' ');
    string s = input.substr(0, spacePos);  // ������ ������� �� ������� ������
    string result;
    size_t i = 0;

    while (i < s.length()) 
    {
        if (isdigit(s[i])) {
            // ����������, �� ���� ������ ������
            bool precededByDot = (i > 0 && s[i - 1] == '.');
            size_t j = i;

            // ������� ����� ����
            while (j < s.length() && isdigit(s[j])) {
                j++;
            }
            string digitGroup = s.substr(i, j - i);

            if (!precededByDot) {
                // ��������� �������� ���
                size_t k = 0;

                while (k < digitGroup.length() - 1 && digitGroup[k] == '0')
                    k++;
                digitGroup = digitGroup.substr(k);

                // ���� �� ����� ���� ������ � ���� ��� ��� ������, �������� ���� ����
                if (digitGroup.empty() && j < s.length() && s[j] == '.') 
                    digitGroup = "0";
            }
            else {
                // ��������� ������� ������� �� ���� ����
                if (digitGroup.length() > 2) 
                    digitGroup = digitGroup.substr(0, 2);
            }

            result += digitGroup;
            i = j;
        }
        else {
            result += s[i];
            i++;
        }
    }
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string input;
    cout << "������ �����: ";
    getline(cin, input);
    string output = processString(input);
    cout << "���������: " << output << endl;
    return 0;
}
