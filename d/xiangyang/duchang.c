// Room: d/xiangyang/duchang.c

#include <ansi.h>

inherit ROOM;


void create()
{
	set("short", HIY"���ķ�"NOR);
	set("long",
"���Ƿ�Բ����Զ��������һ���ķ���ƽ��������ǳ���𣬾���������\n"
"��ϯ������Ѿ�˥�䣬����Ъҵ�ˡ�\n"
	);
	set("indoors", "����");
	set("no_fight", 1);	
        set("xyjob", 1);
	set("exits", ([
		"west" : __DIR__"bjie1",
	]));

	set("objects", ([
		__DIR__"npc/duke" : 2,
		__DIR__"npc/dclaoban" : 1,
	]));

	set("incity",1);
	setup();
}
