#ifndef _�ǿ�_H__
#define _�ǿ�_H__


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
	struct STARS  *elems;			//����ַ
	int sise;			//��󳤶�
	int length;			//��ǰ����

}SqList;

bool initList(SqList &L);						//��ʼ��
bool ListAppend(SqList &L,struct STARS e);		//���
bool listDelete(SqList &L,int i);
void destroyList(SqList &L);

//struct STARS star[STAR_MAX];

#endif