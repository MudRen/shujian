// ũ�����
// nongtian0.c
// augx@sj 10/17/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ũ���");
	set("long",
"����Ƭһ��������ͷ��ũ��󲿷�����϶��Ѿ�������ׯ�ڣ�һ������
�ľ�������ũ�ﻹ���ţ��������������ֲ�Լ���ֲ������������ؿ�
������һ��һ��������Ϥ�˵ص��˺�������ʧ���򣬺��ڹٸ��Ѿ������·��
������ָʾ����ָ������ͬʱ����Ѳ��Ѳ��ɽ·����ֹ��ɱ�¼���
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"north"		: "/d/changan/northroad4.c",
		"southwest"	: __DIR__"nongtian1",
		"southeast"	: __DIR__"nongtian2",
		"northeast"	: __DIR__"nongtian3",
	]));
	
	set("outdoors", "��������");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

int valid_leave(object me, string dir)
{
	if( dir == "north" )
		me->delete_temp("nongtian1");
	else
		me->set_temp("nongtian1",random(4));

	if ( me->query("no_quest") && dir != "north")
		return notify_fail("");

	return ::valid_leave(me , dir);
}
