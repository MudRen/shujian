// Room: /d/village/minfang2.c

inherit ROOM;

void create()
{
        set("short", "��");
	set("long", @LONG
����һ�������вݶ�����񷿣��ɼ����ݵ����˲�����ʮ�ָ�ԣ�����Ӳ�
��������һ�ɴ̱ǵ�ζ����
LONG
        );
        set("exits", ([
		"north" : __DIR__"shilu6",
	]));
        set("objects", ([
		__DIR__"npc/oldwoman": 1 ]) );
	setup();
}
