// Room: /d/dzd/shibi.c

#include <ansi.h>
#define OUT_DOWN __DIR__"shidong4" 
#define W_MSG "����ʯ����"
inherit __DIR__"dzd_room";
#include "yinmi.h"

string look_down();

void create()
{
	set("short","ʯ��");
	set("long",@LONG
������ɽ������һ��͹��Ĵ�ʯ����������,ֻ�����������䳱ʪ��
ͷ������ˮ�������ص��£�����ʯ���������죬������ŵ�ɽ���л����š�
ʯ�Ϸǳ����������ץסʯͷ��ͻ�𲿷֣����µ�����ȥ������Լ���Կ���
�±�(down)�������
LONG
	);
	set("item_desc",([
		"down" : (: look_down :),
	]));
	setup();
}