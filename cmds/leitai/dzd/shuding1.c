// Room: /d/dzd/shuding1.c

#include <ansi.h>
#define OUT_DOWN __DIR__"senlin2" 
#define W_MSG "������"

inherit __DIR__"dzd_room";
#include "yinmi.h"

string look_down();

void create()
{
	set("short","����");
	set("long",@LONG
�����Ǵ��������������涼���м���������Ĵ�����֦Ҷ��ʢ��ȫ��ס�������Ӱ��
͸����Ҷ�Ŀ�϶�������Լ�Կ�������(down)���龰��
LONG
	);
	set("outdoors","���ǵ�");
	set("item_desc",([
		"down" : (: look_down :),
	]));
	setup();
}