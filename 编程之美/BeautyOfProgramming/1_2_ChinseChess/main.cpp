#include <iostream>

using namespace std;

int main()
{
	const char cCol[3] = {'d', 'e', 'f'};
	const int cRolA[3] = { 8, 9, 10};
	const int cRolB[3] = {1, 2, 3};

	//要求一个变量
	unsigned char cTemp = 0;
	while (cTemp < 170)
	{
		//0000 0000 不需要考虑
		cTemp++;
		//cTemp & 0xc0: 第一组两个bit表示帅（B）的横坐标：d,e,f
		//cTemp & 0x30: 第二组两个bit表示帅（B）的横坐标：1,2,3
		//cTemp & 0x0c: 第三组两个bit表示帅（B）的横坐标：d,e,f
		//cTemp & 0x03: 第四组两个bit表示帅（B）的横坐标：8,9,10
		
		//所有组（每两个字节不会出现11）
		if ((cTemp & 0xc0) == 0xc0 || (cTemp & 0x30) == 0x30 || (cTemp & 0x0c) == 0x0c || (cTemp & 0x03) == 0x03)
			continue;

		if (((cTemp & 0xc0) >> 4) != (cTemp & 0x0c))
		{
			cout << "B(" << cCol[(cTemp & 0xc0) >> 6] << cRolB[(cTemp & 0x30) >> 4] << ") --- A(" << cCol[(cTemp & 0x0c) >> 2] << cRolA[(cTemp & 0x03)] << ")" << endl;
		}

	}
	//总结
	/*
	 1. 一开始没有考虑循环里面也是要变量了，开始准备用for(i=1, 170)来
	 2. 同样的常量数组不知道有没有满足要求，但是细想不需要数组也是可以的，答应的时候多加几行判断语句，麻烦了一点而已，没必要
	 3. 要去掉一组两个bit为0x11的情况，一开始直接写着cTemp & 0xc0  == 去了，如果不移位的话，根本就不是3！！
	 4. 移位操作忘记是不是单目运算了，以为以为会改变变量本身的值。因为产生无线循环了，结果是cTemp++开始放在最后，永远过不了0这关，所以挪到前面去了
	 5. cTemp的char类型默认是-128~127，结果也是无线循环，永远到不了170
	 6. 还是bit的问题，想当然的写：(cTemp & 0xc0) != (cTemp & 0x0c)，同样的需要移位
	 7. 很有点感慨，一开始就知道是利用bit位去实现，结果没想到会遇到这么多的问题，花了一个小时，现在是晚上1：07
	 */
	getchar();
	return 0;
}