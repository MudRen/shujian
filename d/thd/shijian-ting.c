// ROOM : shijian-ting.c
// Created by Numa 1990830

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIW"�Խ�ͤ"NOR);
        set("long",@LONG
����һ�����ɵ�ͤ�ӣ��Ϸ�����һ������(bian)��ͤ������һ���
ʯ���������ǽ��ۡ�ʯ�Ͽ����������֣��������ۻ����Ѿ�������
���ˡ�ͤ�ӵı�����һ��ͷ���
LONG
        );
        set("exits",([
                "east" : __DIR__"caodi",
                "north" : __DIR__"kefang1",
                ]));
        set("no_clean_up",0);
        set("item_desc",([
                "bian" : "

                ��      ��      ͤ
                \n
",
        ]));
        setup();
}
