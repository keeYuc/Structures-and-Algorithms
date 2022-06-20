#include<iostream>
using namespace std;





class SqList
{
	int lengh;
	int maxSize;
	int* data;
	void expand(float k, int in)
	{
		int size = this->lengh * k;
		int* newData = new(int[size]);
		if (newData != nullptr && size > this->lengh) {
			for (int i = 0; i < this->lengh; ++i)
			{
				newData[i] = this->data[i];
			}
			newData[lengh] = in;
			++this->lengh;
			this->maxSize = size;
			delete this->data;
			this->data = newData;
			cout << "expand:" << k << "   " << "lengh:" << this->lengh << "   " << "maxSize:" << this->maxSize << endl;
		}
	}
public:
	SqList(int size)
	{
		lengh = 0;
		maxSize = size;
		data = new(int[size]);
	}
	~SqList()
	{
		if (this->data != nullptr)
		{
			delete this->data;
			cout << "Îö¹¹" << endl;
		}
	}
	void PushBack(int in)
	{
		if (this->lengh + 1 <= this->maxSize)
		{
			this->data[lengh] = in;
			++this->lengh;
		}
		else
		{
			float k = 1;
			switch (this->lengh / 500)
			{
			case 0:
				k += 1.;
				break;
			case 1:
				k += .5;
				break;
			default:
				k += .2;
			}
			this->expand(k, in);
		}
	}
	void Show()
	{
		if (this->data != nullptr) {

			for (int i = 0; i < this->lengh; ++i)
			{
				cout << this->data[i] << ' ';
			}
		}
	}
};


int main()
{
	auto x = SqList(1);
	for (int i = 0; i < 1000; ++i)
	{
		x.PushBack(i);
	}
	x.Show();
}