#ifndef _星空_H__
#define _星空_H__


#define SCREEN_WIDTH	640
#define SCREEN_HEIGHT	480
#define STAR_MAX		100
#define STEP            5
#define RADIUS			3
#define BOTTOM_MARGIN	100



enum STATS {
	STOP = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	RANDOM,
	ALL
};
struct STARS{
	int x;
	int y;
	int radius;
	int color;
	int step;
	enum STATS stat;


};

typedef struct{
	struct STARS  *elems;			//基地址
	int sise;			//最大长度
	int length;			//当前长度

}SqList;

bool initList(SqList &L);						//初始化
bool ListAppend(SqList &L,struct STARS e);		//添加
bool listDelete(SqList &L,int i);
void destroyList(SqList &L);

//struct STARS star[STAR_MAX];

#endif