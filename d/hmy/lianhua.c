// /d/hmy/lianhua.c

inherit ROOM;

void create()
{
        set("short", "��Ѫ��");
	set("long", @LONG
���Ǳ�Ѫ�£������ɹۺ�ľ������ˮ�����٣�����������ľ���ܶ档
LONG
        );
        set("exits", ([ 
	  "eastdown" : __DIR__"xianren",
	  "west" : __DIR__"yupingpu",
	  "east" : __DIR__"wulao",
]));
        set("objects", ([
                __DIR__"npc/bee": 1,
]));
        set("outdoors", "��ľ��");

        setup();
}
 
