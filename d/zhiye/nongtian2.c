// ũ��·
// nongtian2.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�﹡");
	set("long",
"��������Ƭũ��Ľ��Ӵ������ܵ�ũ�￴������һģһ������������·��
�������ڹٸ��Ѿ��ڴ�������ָʾ��ָ������ֻҪ����ָʾ��(sign)��ָʾ
�߾Ͳ�����·��
"); 
        
	set("exits",([
		"northwest"	: __DIR__"nongtian0",
		"east"		: __DIR__"nongtian12",
		"south"		: __DIR__"nongtian12",
		"west"		: __DIR__"nongtian12",
		"north"		: __DIR__"nongtian12",
	]));
	
	set("item_desc",([
		"sign" : "\n",
	]));
	
	set("outdoors", "��������");
	set("signs",6);
	set("incity",1);
	setup();
}

#include "nongtian-lu.h"
