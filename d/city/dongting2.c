//Yanqi 08/11/2k

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"�ξֶ���"NOR);
	set("long", @LONG
�����������ξֵĶ���������װ�εķǳ��򵥣������Ƕ�����������һЩ
���飬�������Ǿۻ�ĳ������м�������һ�����̣����������������ͷ�ӡ�
LONG
        );
	set("indoors", "����");
    set("no_fight",1);
    set("no_sleep_room",1);
	set("exits", ([
		"west" : __DIR__"yanju",
	]));
	set("objects", ([
		__DIR__"npc/yanshang2" : 1,
	]));
	
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	set("incity",1);
	setup();

}
