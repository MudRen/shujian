// �ɿ�ɽ·
// caikuang-chang3.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ɽ·");
	set("long",
"����һ�����͵�ɽ·��ɽ����أ����׳��ֻ��󣬹�ȥ�в��ٿ󹤾�����
Ϊ������ߴ���·������ɽ�¶������������ڹٸ��Ѿ��ڴ�������ָʾ��ָ��
����ֻҪС�ĵİ���ָʾ��(sign)��ָʾ�߾Ͳ�����Σ�ա�
"); 
        
	set("exits",([
		"eastdown"	: __DIR__"caikuang-chang10",
		"east"		: __DIR__"caikuang-chang13",
		"south"		: __DIR__"caikuang-chang13",
		"west"		: __DIR__"caikuang-chang13",
		"north"		: __DIR__"caikuang-chang13",
	]));
	
	set("item_desc",([
		"sign" : "\n",
	]));
	
	set("outdoors", "���ݽ���");
	set("signs",6);
	set("incity",1);
	setup();
}

#include "caikuang-shanlu.h"
