#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <bitset>
using namespace std;

int bit_replace(unsigned char num, unsigned char pos)
{
	unsigned char maska = 1; //1=00000001 – 8-разрядная маска 
	maska = maska << pos;
	num = num | maska;
	return num;
}

int bit_replaceV2(unsigned long long num, unsigned long long pos)
{
	unsigned long long maska = 10000000; //10000000 – 8-разрядная маска 
	maska = maska >> pos;
	num = num | maska;
	return num;
}

int main1()
{
	unsigned char x = 0b11001001; //1=11001001
	x = bit_replace(x, 0);
	cout << int (x);
	return 0;
}

int main1a() //1a
{
	unsigned char x = 255; //8-разрядное двоичное число 11111111
	unsigned char maska = 1; //1=00000001 – 8-разрядная маска 
	x = x & (~(maska << 4)); //результат x=239
	cout << int(x);
	return 0;
}

int main1b() //1b	
{
	unsigned char x = 255; //8-разрядное двоичное число 11111111
	unsigned char maska = 1; //1=00000001 – 8-разрядная маска 
	x = x & (maska << 7); //результат x=239
	cout << bitset<8>(x) << " " << int(x);
	return 0;
}

int main1v() //1v
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int x = 25;
	const int n = sizeof(int) * 8; //=32 - количество разрядов в числе типа int
	unsigned maska = (1 << n - 1); //1 в старшем бите 32-разрядной сетки
	cout << "Начальный вид маски" << bitset<n>(maska) << endl;
	cout << "Наш x: " << bitset<n>(x) << endl;
	cout << "Результат: ";
	for (int i = 1; i <= n; i++) //32 раза - по количеству разрядов:
	{
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1; //смещение 1 в маске на разряд вправо
	}
	cout << endl;
	system("pause");
	return 0;
}

int main3()
{
	int n = 8;
	int n2 = 6;
	unsigned char arr = 0b00000000;

	unsigned char randArr[6] = { 1, 0, 5, 7, 2, 4 };
	for (int i = 0; i < 6; i++)
	{
		arr = bit_replaceV2(arr, randArr[i]);
	}

	int j = 0;
	for (int i = 7; i >= 0; i--)
	{
		if (bitset<8>(arr)[i] == 1) {
			randArr[j] = 7 - i;
			j++;
		}
	}

	for (size_t i = 0; i < 6; i++)
	{
		cout << int (randArr[i]) << " ";
	}
	return 0;
}

int main4()
{
	int n = 8;
	int n2 = 6;
	unsigned long long arr = 0;

	unsigned long long randArr[6] = { 20, 30, 50, 70, 23, 46 };
	for (int i = 0; i < 6; i++)
	{
		arr = bit_replaceV2(arr, randArr[i]);
	}

	cout << bitset<sizeof(arr)*8>(arr) << endl;

	int j = 0;
	for (int i = 7; i >= 0; i--)
	{
		if (bitset<sizeof(arr)>(arr)[i] == 1) {
			randArr[j] = sizeof(arr) * 8 - i;
			j++;
		}
	}

	for (size_t i = 0; i < 6; i++)
	{
		cout << int (randArr[i]) << " ";
	}
	return 0;
}

int main2a() //2a
{
	unsigned char arr = 0;
	unsigned char maska = 1;

	unsigned char randArr[6] = { 1, 0, 5, 7, 2, 4 };

	for (int i = 0; i < 6; i++)
		arr = arr | (maska << (7 - randArr[i]));

	cout << bitset<8>(arr) << endl;

	int j = 5;
	for (int i = 0; i < 8; i++)
	{
		if (bitset<8>(arr)[i] == 1)
		{
			randArr[j] = (7 - i);
			j--;
			if (j == -1)
				break;
		}
	}

	for (int i = 0; i < 6; i++)
		cout << int (randArr[i]) << " ";

	return 0;
}

int main2b() //2b
{
	unsigned long long arr = 0;
	unsigned long long maska = 1;

	int randArr[7] = { 10, 7, 56, 43, 23, 49, 63 };

	for (int i = 0; i < 7; i++)
		arr = arr | (maska << (63 - randArr[i]));

	cout << bitset<64>(arr) << endl;

	int j = 6;
	for (int i = 0; i < 64; i++)
	{
		if (bitset<64>(arr)[i] == 1)
		{
			randArr[j] = (63 - i);
			j--;
			if (j == -1)
				break;
		}
	}

	for (int i = 0; i < 7; i++)
		cout << int(randArr[i]) << " ";

	return 0;
}

int main2v() //2v
{
	bitset<256> arr = 0;
	bitset<256> maska = 1;
	unsigned char randArr[8] = { 105, 57, 255, 56, 0, 55, 3, 216 };

	for (int i = 0; i < 8; i++)
		arr = arr | (maska << (255 - randArr[i]));

	cout << arr << endl;

	int j = 7;
	for (int i = 0; i < 256; i++)
	{
		if (bitset<256>(arr)[i] == 1)
		{
			randArr[j] = (255 - i);
			j--;
			if (j == -1)
				break;
		}
	}

	for (int i = 0; i < 8; i++)
		cout << int(randArr[i]) << " ";

	return 0;
}