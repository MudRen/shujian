// /d/hmy/rusheng.c

inherit ROOM;

void create()
{
        set("short", "��ʤͤ");
	set("long", @LONG
���Ϸ�߱��ϣ���һ���˽�̨ͤ���Ӵ˿��Ϲ����ƣ�������ʯ����������
��ʤ�������顣��һ�ɾ�ɫ��⡣
LONG
        );
        set("exits", ([ 
	  "north" : __DIR__"wulao",
]));
        set("objects", ([
                __DIR__"npc/youke": 1,
]));
        set("outdoors", "��ľ��");

        setup();
}
 
