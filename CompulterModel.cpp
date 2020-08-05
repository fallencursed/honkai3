// CompulterModel.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<ctime>
int JJ[20] = { 100,95,89,84,79,74,68,63,58,47,42,37,32,26,21,16,11,5,0 };
int YZ[20] = {120,110,100,90,80,70,60,50,40,30,20,10,0,-10,-20,-30,-40,-50,-60,-70};
int KT[20] = {160,143,126,109,93,76,59,42,25,8,-8,-25,-42,-59,-76,-93,-109,-126,-143,-160 };
int HL[20] = {200,179,158,137,116,95,74,53,32,11,-11,-32,-53,-74,-95,-116,-137,-1528,-179,-200};
int LevelScore[13] = { 0,100,200,300,500,700,900,1200,1500,1800,2200,2600,3200 };
class player {
public:
	int VoidScore;
	unsigned int Level,Score;
	bool FirestKT, FirestHL;
	player():Score(0), VoidScore(0), Level(0), FirestKT(true), FirestHL(true){}
	void CheckLevel() {
		if (Score < 100) {//禁忌1
			Level = 0;
		}
		else if (Score < 200) {//禁忌2
			Level = 1;
		}
		else if (Score < 300) {//禁忌3
			Level = 2;
		}
		else if (Score < 500) {//原罪1
			Level = 3;
		}
		else if (Score < 700) {//原罪2
			Level = 4;
		}
		else if (Score < 900) {//原罪3
			Level = 5;
		}
		else if (Score < 1200) {//苦痛1
			Level = 6;
			if (FirestKT) {
				VoidScore += 180;
				FirestKT = false;
			}
		}
		else if (Score < 1500) {//苦痛2
			Level = 7;
			if (FirestKT) {
				VoidScore += 180;
				FirestKT = false;
			}
		}
		else if (Score < 1800) {//苦痛3
			Level = 8;
			if (FirestKT) {
				VoidScore += 180;
				FirestKT = false;
			}
		}
		else if (Score < 2200) {//红莲1
			Level = 9;
			if (FirestHL) {
				VoidScore += 100;
				FirestHL = false;
			}
		}
		else if (Score < 2600) {//红莲2
			Level = 10;
			if (FirestHL) {
				VoidScore += 100;
				FirestHL = false;
			}
		}
		else if (Score < 3200) {//红莲3
			Level = 11;
			if (FirestHL) {
				VoidScore += 100;
				FirestHL = false;
			}
		}
		else if (Score >= 3200) {//寂灭
			Level = 12;
		}
	}
	void GetScore() {//得分
		if (Level < 3) {
			int a = rand() % 20;
			Score += JJ[a];
			CheckLevel();
		}
		else if (Level < 6) {
			int a = rand() % 20;
			if (YZ[a] >= 0) {//如果分数增加
				Score += YZ[a];
			}
			else {//分数降低
				if (VoidScore > -YZ[a]) {//虚拟奖杯数够
					VoidScore += YZ[a];
				}
				else {
					VoidScore += YZ[a];//算出虚拟奖杯缺的那部分
					Score += VoidScore;//减去虚拟奖杯缺的部分
					VoidScore = 0;//虚拟奖杯清0;
				}
			}

			CheckLevel();
		}
		else if (Level < 9) {
			int a = rand() % 20;
			if (KT[a] >= 0) {//如果分数增加
				Score += KT[a];
			}
			else {//分数降低
				if (VoidScore > -KT[a]) {//虚拟奖杯数够
					VoidScore += KT[a];
				}
				else {
					VoidScore += KT[a];//算出虚拟奖杯缺的那部分
					Score += VoidScore;//减去虚拟奖杯缺的部分
					VoidScore = 0;//虚拟奖杯清0;
				}
			}

			CheckLevel();
		}
		else if (Level >= 9) {
			int a = rand() % 20;
			if (HL[a] >= 0) {//如果分数增加
				Score += HL[a];
			}
			else {//分数降低
				if (VoidScore > -HL[a]) {//虚拟奖杯数够
					VoidScore += HL[a];
				}
				else {
					VoidScore += HL[a];//算出虚拟奖杯缺的那部分
					Score += VoidScore;//减去虚拟奖杯缺的部分
					VoidScore = 0;//虚拟奖杯清0;
				}
			}

			CheckLevel();
		}
	}
	void SjRsult() {
		if (Level == 12) {//寂灭组
			int a=(Score - LevelScore[Level]) * 0.1;
			Score = LevelScore[Level - 2];
			Score += a;
			CheckLevel();
		}
		else {//正常组
			int a= (Score - LevelScore[Level]) * 0.2;
			Score = LevelScore[Level - 2];
			Score += a;
			CheckLevel();
		}
		if (Level>5 and Level<9) {
			VoidScore += 180;
			FirestKT = false;
		}
		else if (Level>8 and Level<12) {
			VoidScore += 280;
			FirestKT = false;
		}
	}
};
player AllPlayer[100000];
using namespace std;
int main()
{
	srand(unsigned(time(0)));
	for (int i = 0; i < 100000; i++) {
		if (i < 5000) {//禁忌3
			AllPlayer[i].Level = 2;
			AllPlayer[i].Score = 200;
			
		}
		else if (i<10000) {//原罪1
			AllPlayer[i].Level = 3;
			AllPlayer[i].Score = 300;
			
		}
		else if (i < 20000) {//原罪2
			AllPlayer[i].Level = 4;
			AllPlayer[i].Score = 500;
			
		}
		else if (i < 30000) {//原罪3
			AllPlayer[i].Level = 5;
			AllPlayer[i].Score = 700;
			
		}
		else if (i < 70000) {//苦痛1
			AllPlayer[i].Level = 6;
			AllPlayer[i].Score = 900;
			
		}
		else if (i < 90000) {//苦痛2
			AllPlayer[i].Level = 7;
			AllPlayer[i].Score = 1200;
			
		}
		else if (i < 100000) {//苦痛3
			AllPlayer[i].Level = 8;
			AllPlayer[i].Score = 1500;
			
		}
	}
	for (int i = 1; i <=240; i++) {
		for (int i = 0; i < 100000; i++) {
			AllPlayer[i].GetScore();
		}
		
		int m = i % 24;
			if (m == 0 and i!=240) {
				AllPlayer[i].SjRsult();
		}
	}
	int jj1=0, jj2=0, jj3=0, yz1=0, yz2=0, yz3=0, kt1=0, kt2=0, kt3=0, hl1=0, hl2=0, hl3=0, jm=0;
	for (int i = 0; i < 100000; i++) {
		if (AllPlayer[i].Level == 0) {
			jj1 += 1;
		}
		else if (AllPlayer[i].Level == 1) {
			jj2 += 1;
		}
		else if (AllPlayer[i].Level == 2) {
			jj3 += 1;
		}
		else if (AllPlayer[i].Level == 3) {
			yz1 += 1;
		}
		else if (AllPlayer[i].Level == 4) {
			yz2 += 1;
		}
		else if (AllPlayer[i].Level == 5) {
			yz3 += 1;
		}
		else if (AllPlayer[i].Level == 6) {
			kt1 += 1;
		}
		else if (AllPlayer[i].Level == 7) {
			kt2 += 1;
		}
		else if (AllPlayer[i].Level == 8) {
			kt3 += 1;
		}
		else if (AllPlayer[i].Level == 9) {
			hl1 += 1;
		}
		else if (AllPlayer[i].Level == 10) {
			hl2 += 1;
		}
		else if (AllPlayer[i].Level == 11) {
			hl3 += 1;
		}
		else if (AllPlayer[i].Level == 12) {
			jm += 1;
		}
	}
	cout << "禁忌1人数" << jj1 << endl;
	cout << "禁忌2人数" << jj2 << endl;
	cout << "禁忌3人数" << jj3 << endl;
	cout << "原罪1人数" << yz1 << endl;
	cout << "原罪2人数" << yz2 << endl;
	cout << "原罪3人数" << yz3 << endl;
	cout << "苦痛1人数" << kt1 << endl;
	cout << "苦痛2人数" << kt2 << endl;
	cout << "苦痛3人数" << kt3 << endl;
	cout << "红莲1人数" << hl1 << endl;
	cout << "红莲2人数" << hl2 << endl;
	cout << "红莲3人数" << hl3 << endl;
	cout << "寂灭人数" << jm << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
