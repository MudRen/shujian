// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/duchang.c

inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
���ǳ������еĵĶĳ���������������СС�Ķ�����ֻҪ��˵�����Ķ�
�ߣ����ﶼ�С�������ͽΧ��һ����ͷ�󺹵������ƾţ�һЩ�����Ա߿��ţ�
�����������ֲ����ߵ��ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"eastjie1",
        ]));

        set("objects", ([
                __DIR__"npc/duke" : 2,
        ]));

        set("incity",1);
	setup();
}