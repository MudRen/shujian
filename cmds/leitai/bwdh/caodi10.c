//caodi.c �ݵ� 

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
	set("short",HIG"�ݵ�"NOR);
	set("long", @LONG
һƬ�����ĵĲ�ƺ�����ɵ������ˣ��޴���Ϊ���軺��Ũ�̿���������
�������������������ɫһ���£����Ӳ��������أ�����Զ�����ഺ����ӽ
�����졣
LONG
        );

	set("exits", ([
		"west" : __DIR__"huilang6",
		"southeast" : __DIR__"shulin12",
		"northeast" : __DIR__"shulin14",
		"east" : __DIR__"shulin13",
	]));
        
	set("outdoors", "�Խ�ɽׯ");
	setup();
}

#include "sjsz_room.h";
