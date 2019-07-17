#include <Windows.h>
#include <graphics.h>
#include <iostream>
#include "星空.h"
#include <stdio.h>

using namespace std;


SqList starList;

void initStar(struct STARS &star){
	/*if(i<0 || i > STAR_MAX){

		cout <<"老司机,您的传值我受不了";
		return;
	}*/
	int red;
	star.x = rand() % SCREEN_WIDTH;
	star.y = rand() % (SCREEN_HEIGHT - BOTTOM_MARGIN);
	star.step = 1+(rand() % STEP);
	star.radius = 1+(rand() % RADIUS);
	star.stat = UP;
	red = 255*star.step / STEP;
	star.color =RGB(red,red,red);
}

void MoveStar(SqList &L,int i){

	/*if(i<0 || i > STAR_MAX){
		cout <<"老司机,您的传值我受不了";
		return;
	}*/
	if(L.elems[i].stat == STOP) return;
	
	setfillcolor(BLACK);
	solidcircle(L.elems[i].x,L.elems[i].y,L.elems[i].radius);

	if(L.elems[i].stat == UP){

		L.elems[i].y -= L.elems[i].step;
		if(L.elems[i].y < 0){
			listDelete(L,i);
		}

	}else if(L.elems[i].stat == DOWN){

		L.elems[i].y += L.elems[i].step;
		if( L.elems[i].y > SCREEN_HEIGHT){
			listDelete(L,i);
		}

	}else if(L.elems[i].stat == LEFT){

		L.elems[i].x -= L.elems[i].step;
		if(L.elems[i].x<0 ){
			listDelete(L,i);
		}

	}else if(L.elems[i].stat == RIGHT){

		L.elems[i].x += L.elems[i].step;
		if(L.elems[i].x > SCREEN_WIDTH){
			listDelete(L,i);
		}
	}

	setfillcolor(L.elems[i].color);
	solidcircle(L.elems[i].x,L.elems[i].y,L.elems[i].radius);
}

/*bool Isquit(){

	for(int i = 0; i < STAR_MAX;i++){

		if(starList.elems[i].x > 0 && starList.elems[i].x < SCREEN_WIDTH && starList.elems[i].y > 0 && starList.elems[i].y < SCREEN_HEIGHT ){
			return false;
		}
	}
	return true;
}*/

int main(void){

	struct STARS _star;
	SqList starList;

	initList(starList);

	bool quit = false;

	initgraph(SCREEN_WIDTH,SCREEN_HEIGHT);

	for(int i = 0;i<STAR_MAX;i++){
		initStar(_star);
		ListAppend(starList,_star);
	}
	for(int i = 0;i<starList.length;i++){
		setfillcolor(starList.elems[i].color);
		solidcircle(starList.elems[i].x,starList.elems[i].y,starList.elems[i].radius);

	}

	
	IMAGE tortoise;
	loadimage(&tortoise,_T("tortoise.jpg"),30,30,false);
	putimage(SCREEN_WIDTH*4/10-30,SCREEN_HEIGHT-30,&tortoise);
	putimage(SCREEN_WIDTH*6/10,SCREEN_HEIGHT-30,&tortoise);

	while(quit == false){
		for(int i = 0;i<starList.length;i++){
			MoveStar(starList,i);
		}
		if(starList.length == 0){
			quit = true;
		}
		Sleep(20);
	}
	destroyList(starList);
	system("pause");
	closegraph();
	return 0;

}