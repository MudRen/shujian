// ROOM:mudao1.c
// Created by Numa 19990910
// Revised by Darken

inherit ROOM;

void create()
{
        set("short","Ĺ��");
        set("long",@LONG
����һ��ͨ��Ĺ�ҵ�ͨ�������Ծ��ǹ����䱦��
LONG);
        set("exits",([
             "down" : __DIR__"mudao2",
                "out"   : __DIR__"tomb",
        ]));

        set("no_clean_up",0);
        setup();
}

