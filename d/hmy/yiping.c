// /d/hmy/yiping.c

inherit ROOM;

void create()
{
        set("short", "һƷ��");
	set("long", @LONG
�߹����Ϸ壬ǰ����һ��Ҫ�����ͱڡ�һƷ�¡���������ɽ����������
����Ьһ����������ȥ���ǾͲ�����;��ˡ�
LONG
        );
        set("exits", ([ 
	  "south" : __DIR__"wulao",
]));
        set("objects", ([
                __DIR__"npc/wolf": 2,
]));

        set("outdoors", "��ľ��");

        setup();
}
 
