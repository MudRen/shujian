// ɣ��С��
// sanglin2.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ɣ��С·");
	set("long",
"������ɣ���е�һ��С�������ܶ��ǿ�������ͷ��ɣ�������˺���������
����ʧ���򡣺������ڹٸ��Ѿ��ڴ�������ָʾ��ָ������ֻҪ����ָʾ��
(sign)��ָʾ�߾Ͳ�����·��
"); 
        
	set("exits",([
		"northwest"	: __DIR__"sanglin0",
		"east"		: __DIR__"sanglin12",
		"south"		: __DIR__"sanglin12",
		"west"		: __DIR__"sanglin12",
		"north"		: __DIR__"sanglin12",
	]));
	
	set("item_desc",([
		"sign" : "\n",
	]));
	
	set("outdoors", "��������");
	set("signs",6);
	set("incity",1);
	setup();
}

#include "sanglin-xiaolu.h"
