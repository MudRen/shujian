// /d/hmy/xianren.c

inherit ROOM;

void create()
{
        set("short", "����ָ·");
	set("long", @LONG
������ָ·��ʵ�Ƕ������˶������µ�һ��ʯ����ԶԶ�������ߵ������¡�
LONG
        );
        set("exits", ([ 
	  "eastup" : __DIR__"xian",
	  "westup" : __DIR__"lianhua",
	]));
	set("objects", ([
                __DIR__"npc/hudie": 2,
	]));
        set("outdoors", "��ľ��");

        setup();
}
