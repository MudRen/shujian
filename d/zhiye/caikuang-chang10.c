// �ɿ�
// caikuang-chang10.c
// augx@sj 9/10/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�ɿ�");
	set("long",
"������һ����ɽ��ɽ���������Ѿ����ڳ�һ����ӣ����ǻ����в��ٲɿ�
�������˵��ڿ����ϻ��в��ٲɿ󳡣�����ɽ·���ͣ�Σ�����أ�һ������
������ȥ��
"); 
        
	set("exits",([
		"eastdown" : __DIR__"caikuang-chang0",
		"northup"  : __DIR__"caikuang-chang1",
		"southup"  : __DIR__"caikuang-chang2",
		"westup"   : __DIR__"caikuang-chang3",
	]));
	
	set("kuangshi",2);
	set("outdoors", "���ݽ���");
	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "eastdown" )
		me->delete_temp("caikuang1");
	else
		me->set_temp("caikuang1",random(4));
	return ::valid_leave(me , dir);
}

#include "caikuang-chang.h"
