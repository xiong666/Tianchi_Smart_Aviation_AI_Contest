#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;

//存储你们输出结果的数据结构
struct flight_x {
	char flightID[20];//航班ID
	char from[20];//起飞机场
	char to[20];//降落机场
	char start_d[20];//起飞日期
	char start_t[20];//起飞时间
	char end_d[20];//降落日期
	char end_t[20];//降落时间
	char planeID[20];
	char cancel[20];//取消
	char straight[20];//拉直
	char voidfly[20];//空飞
	char signchange[20];//签转
	char signchange_detail[100];//签转情况
};


//存储原始数据的数据结构
struct flight_y {
	char y_flightID[20];//原始数据航班ID
	char y_from[20];//原始数据起飞机场
	char y_to[20];  //原始数据降落机场
	char y_start_d[20];//原始数据起飞日期
	char y_start_t[20];//原始数据起飞时间
	char y_end_d[20]; //原始数据降落日期
	char y_end_t[20]; //原始数据降落时间
	char y_planeID[20];//原始数据飞机ID
	char y_plNum[20];//原始数据普通旅客数量
	char y_llNum[20];//原始数据联程旅客数量
	char y_seatNum[20];//原始数据座位数
}y_table[5000];


int main()
{
	FILE *fp = NULL;//定义读取你们输出结果文件的指针
	FILE *yuandata = NULL;//定义读取原数据文件的文件指针
	char line[2048];//定义读取原数据文件每行2048个字符
	char yuan[2048];//定义读取你们输出结果文件每行2048个字符
	struct flight_x x_table[5000];


	//将原始数据存入内存当中
	//yuandata2 = fopen("hangxia20170823.csv", "r");
	//if (yuandata2 == NULL) cout << "cuowu" << endl;
	if ((yuandata = fopen("hangxia20170823.csv", "r+")) != NULL)
	{
		char douhao[] = ",";//逗号
		char space[] = " ";//空格
		char *result2 = NULL;

		//记录原始数据的各项指标
		char *y_flightID;//原始数据航班ID
						 /*		char *y_from;//原始数据起飞机场
						 char *y_to;  //原始数据降落机场
						 char *y_start_d;//原始数据起飞日期
						 char *y_start_t;//原始数据起飞时间
						 char *y_end_d; //原始数据降落日期
						 char *y_end_t; //原始数据降落时间
						 char *y_planeID;//原始数据飞机ID
						 char *y_plNum;//原始数据普通旅客数量
						 char *y_llNum;//原始数据联程旅客数量
						 char *y_seatNum;//原始数据座位数
						 */
						 //fgets(yuan, sizeof(yuan), yuandata);//跳过原始数据的第一行
		int ii = 1;
		while (fgets(yuan, 2048, yuandata))
		{
			//cout << yuan << endl;
			result2 = strtok(yuan, douhao);
			y_flightID = result2;  //存储原始数据的y_flightID
			int temp = atoi(y_flightID);
			memcpy(y_table[ii].y_flightID, result2, (strlen(result2) + 1));
			//y_table[ii].y_flightID = result2;
			//sscanf(result2, "%s", y_table[ii].y_flightID);

			//逗号分割之后第五个数据为原始数据航班起飞机场
			//	result2 = strtok(NULL, douhao);
			//	result2 = strtok(NULL, douhao);
			//	result2 = strtok(NULL, douhao);
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_from = result2;
			memcpy(y_table[ii].y_from, result2, (strlen(result2) + 1));

			//逗号分隔之后第六个数据为原始数据航班降落机场
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_to = result2;
			memcpy(y_table[ii].y_to, result2, (strlen(result2) + 1));

			//空格分隔之后第七个数据为原始数据航班起飞日期
			result2 = strtok(NULL, space);
			//y_table[ii].y_start_d = result2;
			memcpy(y_table[ii].y_start_d, result2, (strlen(result2) + 1));

			//原始数据的起飞时间
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_start_t = result2;
			memcpy(y_table[ii].y_start_t, result2, (strlen(result2) + 1));

			//原始数据的降落日期
			result2 = strtok(NULL, space);
			//y_table[ii].y_end_d = result2;
			memcpy(y_table[ii].y_end_d, result2, (strlen(result2) + 1));

			//原始数据的降落时间
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_end_t = result2;
			memcpy(y_table[ii].y_end_t, result2, (strlen(result2) + 1));

			//原始数据planeID
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_planeID = result2;
			memcpy(y_table[ii].y_planeID, result2, (strlen(result2) + 1));

			//紧接着两个逗号之后是原始数据普通旅客数量
			//	result2 = strtok(NULL, douhao);
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_plNum = result2;
			memcpy(y_table[ii].y_plNum, result2, (strlen(result2) + 1));

			//接着一个逗号后是联程旅客数量
			result2 = strtok(NULL, douhao);
			//y_table[ii].y_llNum = result2;
			memcpy(y_table[ii].y_llNum, result2, (strlen(result2) + 1));

			//接着一个逗号后是飞机座位数
			result2 = strtok(NULL, "\n");
			//y_table[ii].y_seatNum = result2;
			memcpy(y_table[ii].y_seatNum, result2, (strlen(result2) + 1));

			//if(ii>3)cout <<"now i ="<<ii<<"\n in i="<<ii-1<<" "<< y_table[ii-1].y_flightID << "," << y_table[ii-1].y_from << "," << y_table[ii-1].y_to << "," << y_table[ii-1].y_start_d << " " << y_table[ii-1].y_start_t << "," << y_table[ii-1].y_end_d << " " << y_table[ii-1].y_end_t << "," << y_table[ii-1].y_planeID << endl;
			//cout << "i=1  "<< y_table[1].y_flightID << "," << y_table[1].y_from << "," << y_table[1].y_to << "," << y_table[1].y_start_d << " " << y_table[1].y_start_t << "," << y_table[1].y_end_d << " " << y_table[1].y_end_t << "," << y_table[1].y_planeID << endl;
			ii++;
		}
		fclose(yuandata);
		yuandata = NULL;
	}

	//将你们输出结果数据存入内存当中
	if ((fp = fopen("quickWithZero.csv", "at+")) != NULL)
	{
		char comma[] = ",";//逗号
		char space[] = " ";//空格
		char *result = NULL;
		char gogo[20];//一个中间变量，方便中间字符的转换

		while (fgets(line, 2048, fp))//逐行读取文件中的数据
		{
			result = strtok(line, comma);//将此行数据按空格分隔开
			memcpy(gogo, result, (strlen(result) + 1));
			//存储你们输出结果中的航班ID
			memcpy(x_table[atoi(gogo)].flightID, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].flightID = flightID;

			//存储你们输出结果中的起飞机场
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].from, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].from = result;

			//存储你们输出结果中的降落机场
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].to, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].to = result;

			////存储你们输出结果中的起飞日期
			result = strtok(NULL, space);
			memcpy(x_table[atoi(gogo)].start_d, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].start_d = result;

			//存储你们输出结果中的起飞时间
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].start_t, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].start_t = result;

			//存储你们输出结果中的降落日期
			result = strtok(NULL, space);
			memcpy(x_table[atoi(gogo)].end_d, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].end_d = result;

			//存储你们输出结果中的降落时间
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].end_t, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].end_t = result;

			//存储你们输出结果中的planeID
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].planeID, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].planeID = result;

			//存储你们输出结果中的取消
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].cancel, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].cancel = result;

			//存储你们输出结果中的拉直
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].straight, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].straight = result;

			//存储你们输出结果中的调机
			result = strtok(NULL, comma);
			memcpy(x_table[atoi(gogo)].voidfly, result, (strlen(result) + 1));
			//x_table[atoi(flightID)].voidfly = result;
		}
		fclose(fp);
		fp = NULL;
	}


	//思路;1、先检测其是否为联程拉直所造成的取消，如果是，则不管
	//     2、若检测到不是由联程拉直所造成的取消，则进行签转处理
	//     3、找出和此取消航班具有相同起飞和降落机场的航班，进行签转
	//     4、找出两个对应航班的普通旅客数和座位数，如果能一次签转完毕，则结束
	//     5、否则，再找出第二个航班进行签转
	//     6、重复过程3、4、5，直至这个航班的所有旅客签转完毕为止
	//     7、若找完所有能让此航班进行签转的航班，仍然不能使这个航班的旅客签转完毕，则结束，其他取消

	int sseatNum = 0;//某架航班剩余的座位数量
	int anpai_sNum = 0;//某架航班的旅客被安排后还剩多少
	string aa = "1";
	string bb = "0";
	string dd = " ";
	char *end;
	char *aa1 = "1";
	char *aa0 = "0";
	char *aak = " ";
	//std::string x_cancel_s;
	for (int i = 1; i <= sizeof(y_table) / sizeof(y_table[1]); i++)//循环原始数据中的2048个航班
	{
		memcpy(x_table[i].signchange, aa0, (strlen(aa0) + 1));//给你们输出结果中的旅客签转先全置“0”
		memcpy(x_table[i].signchange_detail, aak, (strlen(aak) + 1));//给你们输出结果中的旅客签转先全置空格

		if (x_table[i].cancel == aa)//若你们输出结果中的那条航班对应的是取消，则进行下一步
		{
			if (x_table[i].straight == bb)//若你们输出结果中的那条航班对应的取消行不是由于联程造成，则进行下一步
			{
				std::string yplNum_s = std::string(y_table[i].y_plNum);
				anpai_sNum = static_cast<int>(strtol(yplNum_s.c_str(), &end, 10));//把你们输出结果中的这个航班所对应的原始航班找出来，并将其普通旅客的那个字符数组转化为整数

																				  //遍历你们的输出结果，找出和上述取消航班所的对应的起飞机场和降落机场一致的航班j
				for (int j = 1; j <= sizeof(x_table) / sizeof(x_table[1]); j++)//
				{
					if (anpai_sNum > 0)//如果航班i待安排的旅客数量大于0，则进行下一步
					{
						if (std::string(x_table[i].from) == std::string(x_table[j].from) && std::string(x_table[i].to) == std::string(x_table[j].to))//排定航班i与航班j起始机场是否一致,若一志，则进行下一步
						{
							std::string yseatNum_s = std::string(y_table[j].y_seatNum);
							std::string yplNum_s = std::string(y_table[j].y_plNum);
							std::string yllNum_s = std::string(y_table[j].y_llNum);
							int ystNum = static_cast<int>(strtol(yseatNum_s.c_str(), &end, 10));
							int yplNum = static_cast<int>(strtol(yplNum_s.c_str(), &end, 10));
							int yllNum = static_cast<int>(strtol(yllNum_s.c_str(), &end, 10));
							sseatNum = ystNum - yplNum - yllNum;//算出航班j中还有多少空位可以接纳旅客
							if (sseatNum > 0)//若还有空位，则进行下一步
							{
								if (x_table[j].cancel == bb)//判断此架航班是否取消，若没被取消，则进行下一步
								{
									cout << j << endl;
									//	std::string yseatNum_s = std::string(y_table[j].y_seatNum);
									//	std::string yplNum_s = std::string(y_table[j].y_plNum);
									//	std::string yllNum_s = std::string(y_table[j].y_llNum);
									//	int ystNum = static_cast<int>(strtol(yseatNum_s.c_str(), &end, 10));
									//	int yplNum = static_cast<int>(strtol(yplNum_s.c_str(), &end, 10));
									//	int yllNum = static_cast<int>(strtol(yllNum_s.c_str(), &end, 10));
									//	sseatNum = ystNum - yplNum - yllNum;

									std::string yplNum_si = std::string(y_table[i].y_plNum);
									int yplNumi = static_cast<int>(strtol(yplNum_si.c_str(), &end, 10));//将航班i中的普通旅客数量转换为整数


									if (sseatNum >= yplNumi)//若航班j中剩余座位数大于等于航班i中待安排的普通旅客数量，则下一步
									{
										//下面思路：1、将你们输出结果中的航班i的签转标记置为“1”
										//           2、将航班i中待安排的普通旅客全部安排入航班j
										//           3、将航班j中的原始普通旅客加上被安排进来的旅客，并将总数量赋给航班j中的普通旅客，以方便下一步循环计算还剩多少空位
										//           4、将航班i中还未安排的旅客数量置0
										char temp11[20];
										//x_table[i].signchange = (char*)"1";
										memcpy(x_table[i].signchange, aa1, (strlen(aa1) + 1));
										_itoa(j, temp11, 10);
										//snprintf(temp11, sizeof(temp11), "%d", j);
										string temp21(temp11);
										string temp22(y_table[i].y_plNum);
										string temp3 = temp21 + ":" + temp22;
										char *temp121 = NULL;
										int len = temp3.length();
										temp121 = (char*)malloc((len + 1) * sizeof(char));
										temp3.copy(temp121, len, 0);
										//x_table[i].signchange_detail = temp12;
										memcpy(x_table[i].signchange_detail, temp121, (strlen(temp121) + 1));
										free(temp121);
										//temp12 = NULL;
										int zhuan = 0;
										zhuan = yplNumi + yplNum;
										char yp[20];
										//snprintf(yp, sizeof(yp), "%d", zhuan);
										_itoa(zhuan, yp, 10);
										memcpy(y_table[j].y_plNum, yp, (strlen(yp) + 1));
										//itoa(zhuan, y_table[j].y_plNum, 10);
										//snprintf(y_table[j].y_plNum, sizeof(y_table[j].y_plNum), "%d", zhuan);
										anpai_sNum = 0;
									}
									else if (sseatNum < yplNumi)//若航班j中剩余座位数小于航班i中待安排的普通旅客数量，则下一步
									{
										//下面思路：1、将你们输出结果中的航班i的签转标记置为“1”
										//           2、将航班i中待安排的一部分普通旅客全部安排入航班j
										//           3、将航班j中的原始普通旅客加上被安排进来的旅客，并将总数量赋给航班j中的普通旅客，以方便下一步循环计算还剩多少空位
										//           4、将航班i中还未安排的旅客数量记入anpai_sNum，以进行下一步循环
										//char *temp11 = NULL;
										//char *temp66 = NULL;
										char temp11[20];
										char temp66[20];
										char res2[5];
										memcpy(x_table[i].signchange, aa1, (strlen(aa1) + 1));
										//x_table[i].signchange = "1";
										_itoa(j, temp11, 10);
										_itoa(sseatNum, temp66, 10);
										//snprintf(temp11, sizeof(temp11), "%d", j);
										//snprintf(temp66, sizeof(temp66), "%d", sseatNum);
										string temp21(temp11);
										string temp22(temp66);
										string temp4(x_table[i].signchange_detail);
										//string temp4;
										//int hh = 0;
										//while (48 <= x_table[i].signchange_detail[hh] <= 57 && x_table[i].signchange_detail[hh] == 58 && x_table[i].signchange_detail[hh] == 38&&x_table[i].signchange_detail[hh]==32)
										//{
										//	sprintf(res2, "%c", x_table[i].signchange_detail[hh]);
										//	temp4 = temp4 + res2;
										//}
										if (x_table[i].signchange_detail == dd)//判断航班i中的安排情况是否为空，若为空，则航班细节的字符串前面不加"&"标记
										{
											string temp32;
											char *temp123 = NULL;
											int len32;
											temp32 = temp21 + ":" + temp22;
											len32 = temp32.length();
											temp123 = (char*)malloc((len32 + 1) * sizeof(char));
											temp32.copy(temp123, len32, 0);
											memcpy(x_table[i].signchange_detail, temp123, (strlen(temp123) + 1));
											free(temp123);
											temp123 = NULL;
										}
										else//判断航班i中的安排情况是否为空，若不为空，则航班细节的字符串前面加"&"标记，以此来连接多个安排情况
										{
											string temp33 = temp4 + "&" + temp21 + ":" + temp22;
											char *temp12 = NULL;
											int len33 = temp33.length();
											temp12 = (char*)malloc((len33 + 1) * sizeof(char));
											temp33.copy(temp12, len33, 0);
											memcpy(x_table[i].signchange_detail, temp12, (strlen(temp12) + 1));
											//x_table[i].signchange_detail = temp12;
											free(temp12);
											temp12 = NULL;
										}
										int zhuan = 0;
										zhuan = sseatNum + yplNum;
										//zhuan = sseatNum + atoi(y_table[j].y_plNum);
										char yp2[20];
										//snprintf(yp2, sizeof(yp2), "%d", zhuan);
										_itoa(zhuan, yp2, 10);
										memcpy(y_table[j].y_plNum, yp2, (strlen(yp2) + 1));
										//itoa(zhuan, y_table[j].y_plNum, 10);
										//snprintf(y_table[j].y_plNum, sizeof(y_table[j].y_plNum), "%d", zhuan);
										//anpai_sNum = atoi(y_table[i].y_plNum) - sseatNum;
										anpai_sNum = yplNumi - sseatNum;
									}
									//	else
									//	{
									//		memcpy(x_table[i].signchange, aa0, (strlen(aa0) + 1));
									//		memcpy(x_table[i].signchange_detail, aak, (strlen(aak) + 1));
									//	}
								}
							}
						}

					}
				}
			}
		}
	}

	//最后新建csv文档以存储原结果数据经过旅客调度后的值
	ofstream outfile;
	outfile.open("qianzhuanlvke.csv", ios::out);
	int tt666 = sizeof(x_table) / sizeof(x_table[1]);
	for (int tt = 1; tt <= tt666; tt++)
	{
		outfile << x_table[tt].flightID << "," << x_table[tt].from << "," << x_table[tt].to << "," << x_table[tt].start_d << " " << x_table[tt].start_t << "," << x_table[tt].end_d << " " << x_table[tt].end_t << "," << x_table[tt].planeID << "," << x_table[tt].cancel << "," << x_table[tt].straight << "," << x_table[tt].voidfly << "," << x_table[tt].signchange << "," << x_table[tt].signchange_detail << "\n";
	}
	outfile.close();
	system("pause");
	return 0;
}




