// canroad6.c

inherit ROOM;

#include <ansi.h>
#include "/d/group/entry.h"

void create()
{
	set("short", "��·");
	
	set("long", "����һ�����������·������̫��·�ϼ���û�����ˣ�����һ����į��\n"
		"�о���·������ɢɢ�ķֲ��ż�ƬС��أ�żȻҲ�ܿ��ü�һЩ���̡�����һ\n"
		"Ƭ�Ļļš�\n");

	set("exits", ([
		"southwest":"/d/changan/northroad5",
		"northdown":"/d/changan/northroad7",
		]));

	set("outdoors","������");
	
	set("group",1);
	
	setup();
}
