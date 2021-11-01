#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "readMNIST.h"

#define MAX_SIZE 1024

using namespace std;

class Pair {
public:
	string word;
	string definition;
	Pair(string _word) {
		word = _word;
		definition = "";
	}
	Pair(string _word, string _definition) {
		word = _word;
		definition = _definition;
	}
	bool isWord();
	int GetHash();
	bool operator == (const Pair &right) const;
};

bool Pair::operator == (const Pair &right) const
{
	if (word == right.word) return true;
	else return false;
}

int Pair::GetHash() {
	int sum = 0;
	for (size_t i = 0; i < word.length(); i++) {
		sum += (int)word[i];
	}
	return sum % 256;
}

bool Pair::isWord() {
	bool isWord = true;
	for (size_t i = 0; i < word.length(); i++) {
		if (!isalpha(word[i])) {
			isWord = false;
		}
	}
	if (isWord) return true;
	else return false;
}

int getHash(uchar* image) 
{
	int s = 0;
	for (int i = 0; i < 28*28; i++) {
		s += image[i];
	}
	return s;
}

class Image {
public:
	uchar* data;

	Image() { data = new uchar[784]; }

	Image(uchar* image) {
		for (int i = 0; i < 28 * 28; i++) {
			data[i] = image[i];
		}
	}
	
	bool operator == (const Image &right) const;
};

bool Image::operator == (const Image &right) const
{
	for (int i = 0; i < 28*28; i++) {
		if (data[i] != right.data[i]) {
			return false;
		}
	}
	return true;
}

class hashTable 
{
private:
	list <Image> table[MAX_SIZE];
public:
	// constructors and destructors

	hashTable() = default;
	~hashTable() {};

	// functions

	void Add(Image image);
	void Del(Image image);
	//bool Find(Image image);
	int RowSize(int x);
	int FindMaxRow();
};

int hashTable::RowSize(int x) {
	list <Image> row = table[x];
	int size = row.size();
	return size;
}

int hashTable::FindMaxRow() {
	int max = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		int size = RowSize(i);
		if (size > max) {
			max = size;
		}
		else continue;
	}
	return max;
}

void hashTable::Del(Image image) 
{
	uchar* img = image.data;
	int hashValue = getHash(img);
	auto it = find(table[hashValue].begin(), table[hashValue].end(), image);
	if (it != table[hashValue].end()) {
		table[hashValue].erase(it);
	}
}

void hashTable::Add(Image image) 
{
	uchar* img = image.data;
	int hashValue = getHash(img);
	table[hashValue].push_back(image);
}

//bool hashTable::Find(Image image)
//{
//	uchar* img = image.data;
//	int hashValue = getHash(img);
//	list <Image> row = table[hashValue];
//	auto it = find(row.begin(), row.end(), image);
//	if (it != row.end()) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}


int main() {
	hashTable Table;
	uchar *pData;
	int number_of_images = 10000;
	int image_size = 28 * 28;
	int maxChain;
	int pDataSize = number_of_images * 28 * 28;

	pData = read_mnist_images((char*)"images.ubyte", number_of_images, image_size);
	
	for (int i = 0; i < number_of_images*image_size; i++) {
		uchar image[784];
		image[i] = pData[i];
	}

	maxChain = Table.FindMaxRow();

	system("pause");
	return 0;
}
