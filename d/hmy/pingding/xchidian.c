// xiaochidian.c
// Created by Numa 19991027


inherit ROOM;

void create()
{
        set("short", "С�Ե�");
        set("long", @LONG
����һ��С�꣬���⵹��ͦ��¡�ģ���λ���������ģ�����Щ����վ�ŵ�
�����������Ҳ�����棬���������ӡ����ȡ���Ѽ���׾Ƹ�·�ɡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"cj2",
        ]));

        set("objects", ([
             __DIR__"npc/xiaoer2" : 1,
        ]));

        setup();
}
