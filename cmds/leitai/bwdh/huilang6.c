//huilang.c ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
	set("short",HIC"����"NOR);
	set("long", @LONG
����һ���ľ��Ļ��ȣ����������˻��ܣ�����Щҩ�ģ��Ե÷ǳ����ľ���
��ǰ�ǳ�������ʯ·��С·һ�˵ľ�ͷ�ƺ���һ��СԲ�ţ�·�����Ǽ��䷿
�ӡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"caodi4",
		"east" : __DIR__"caodi10",
		"south" : __DIR__"huilang4",
	]));
	set("indoors", "�Խ�ɽׯ");
	setup();
}

#include "sjsz_room.h";
