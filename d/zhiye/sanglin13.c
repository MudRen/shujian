// ũ��
// sanglin13.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ɣ��");
	set("long",
"����Ƭ�ܴ��ɣ���֣�ɣ�����Ķ���ïʢ�����������������(yangcan)��
��������Ҫע��ιʳ(weishi)����ɨ(qingsao)���ͳ�˿(chousi)��
"); 
        
	set("exits",([
		"out" : __DIR__"sanglin3",
	]));
	
	set("outdoors", "��������");
	set("incity",1);
	set("exam",0);
	setup();
}

#include "sanglin.h"
