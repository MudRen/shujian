// Write By Yanyang@SJ 2001.9.26
// Room: /d/changan/chaguan.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������ǳ����������Ӿ۵ĳ���������������˵İڷ���һЩľ�Ƶ���
�Ρ�һ��˵���������ϲ����Ľ��顣һЩ���һ��Ʒ�裬һ�����飬һ�߽�ͷ
�Ӷ�С��������ʲô��
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "south" : __DIR__"eastjie2",
        ]));

        set("objects", ([
                __DIR__"npc/chgxiaoer" : 1,
                __DIR__"npc/shshren" : 1,
        ]));

        set("incity",1);
	setup();
}
