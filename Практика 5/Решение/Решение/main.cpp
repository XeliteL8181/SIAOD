#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>
#include <unordered_set>
using namespace std;

int randomNums() {
	const int targetSize = 1024 * 1024;
	const int maxValue = 10000000;

	ofstream fout("input.txt");

	unordered_set<int> used; // ����� �������� ��������
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, maxValue);

	int written = 0;
	while (fout.tellp() < targetSize) {
		int num = dist(gen);
		if (used.insert(num).second) { // ���� ����� ��� �� �����������
			fout << num << "\n";
			written++;
		}
	}

	fout.close();
	return 0;
}

int a1_a() {
	unsigned char x;
	int input;
	cin >> input;
	x = input; //��� �������� �� 32 ��� � 8
	bitset<8> original(x);
	cout << "Original: " << original << " " << (int)x << endl;

	unsigned char maska = 1; //����� � ������� ����� ������ 1
	x = x & (~(maska << 4)); //����� ����� �� 4 �������, ��������, ��������� � 

	bitset<8> result(x);
	cout << "Result: " << result << " " << (int)x << endl;
	cout << "===========================" << endl;
	return 0;
}

int a1_b() {
	unsigned char x;
	int input;
	cin >> input;
	x = input;
	bitset<8> original(x);
	cout << "Original: " << original << " " << (int)x << endl;

	unsigned char maska = 1;
	x = x & (~(maska << 1));

	bitset<8> result(x);
	cout << "Result: " << result << " " << (int)x << endl;
	cout << "===========================" << endl;
	return 0;
}

int a1_c() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int x = 5555;
	const int n = sizeof(int) * 8; // = 32 - ���������� �������� � ����� ���� int
	unsigned maska = (1 << n - 1); // 1 � ������� ���� 32-��������� �����
	cout << "��������� ��� �����: " << bitset<n>(maska) << endl;
	cout << "���������: ";
	for (int i = 1; i <= n; i++) { // 32 ���� �� ���������� ��������
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1; // �������� 1 � ����� �� ������ ������ 
	}
	cout << endl;
	system("pause");
	return 0;
}

int a2_a() {
	unsigned maska = 0;	
	int n; // ���������� �����
	cin >> n;

	cout << "Numbers to sort: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x; // ���� ����� �� 0 �� 7

		maska |= (1 << x);
	}

	cout << "Sorted list: ";
	for (int i = 0; i < 8; i++) { // ����� ���������������� �������
		if (maska & (1 << i)) {
			cout << i << " ";
		}
	}

	cout << endl;
	return 0;
}

int a2_b() {
	unsigned long long maska = 0;
	int n; // ���������� �����
	cin >> n;

	cout << "Numbers to sort: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x; // ���� ����� �� 0 �� 63

		maska |= (1ULL << x);
	}

	cout << "Sorted list: ";
	for (int i = 0; i < 64; i++) { // ����� ���������������� �������
		if (maska & (1ULL << i)) {
			cout << i << " ";
		}
	}

	cout << endl;
	return 0;
}

int a2_c() {
	const int SIZE = 8; // 8 ������ = 64 ����
	unsigned char bitmask[SIZE] = { 0 }; // ������ �� 8 ������
	int n;
	cin >> n;

	cout << "Numbers to sort: ";
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int index = x / 8;     // ����� �����
		int pos = x % 8;       // ������� � �����
		bitmask[index] |= (1 << pos);
	}

	cout << "Sorted list: ";
	for (int i = 0; i < 64; i++) { // ����� ���������������� �������
		int index = i / 8;
		int pos = i % 8;
		if (bitmask[index] & (1 << pos)) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}

int a3_a() {
	randomNums();
	const string inFile = "input.txt";
	const string outFile = "output.txt";

	const size_t SIZE = 1024 * 1024; //1 ��
	vector<uint8_t> bits(SIZE, 0); //������� ������
	const size_t MAXN = SIZE * 8; //���� �����, ������� ����� �������

	ifstream fin(inFile);
	ofstream fout(outFile);

	auto t1 = chrono::high_resolution_clock::now();

	unsigned int x;
	while (fin >> x) {
		if (x < MAXN)
			bits[x >> 3] |= (1 << (x & 7));
	}

	for (size_t i = 0; i < MAXN; i++)
		if (bits[i >> 3] & (1 << (i & 7)))
			fout << i << '\n';

	auto t2 = chrono::high_resolution_clock::now();
	cout << "Time: "
		<< chrono::duration<double>(t2 - t1).count()
		<< " s\n";
	cout << "Size massive in bit: " << bits.size() << endl;

	return 0;
}

int main() {
	//a1_a();
	//a1_b();
	//a1_c();

	//a2_a();
	//a2_b();
	//a2_c();

	//a3_a();

	return 0;
}