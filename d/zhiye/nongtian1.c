// ũ��·
// nongtian1.c
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
		"northeast"	: __DIR__"nongtian0",
		"east"		: __DIR__"nongtian11",
		"south"		: __DIR__"nongtian11",
		"west"		: __DIR__"nongtian11",
		"north"		: __DIR__"nongtian11",
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
