// mg3.c
// Created by Numa 19991020

inherit ROOM;
#include "midao.h"

void create()
{
	
	set("short","�ص�");
	set("long",@LONG
����һ����ɭɭ�ĵص���ǽ��ÿ�����׾͹���һյ�������ֵ��͵ƣ�һ��
����ֱϮ������
LONG
	);
	set("exits",([
		"east" : __DIR__"midao" + random(7),
		"west" : __DIR__"suo",
		"south" : __DIR__"midao" + random(7),
		"north" : __DIR__"suo",
  	]));
  	set("no_clean_up", 0);
  	setup();
}
