// /d/mingjiao/bidao2.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06

inherit ROOM;
void create()
{
       set("short","�ص�");
       set("long", @LONG
����һ���������µ��ص���
LONG
     );
       set("exits", ([
		"south" : __DIR__"bidao1",
		"east" : __DIR__"bidao3",
       ]));
       setup();
}
