#define FLOOR 1
#define SAVE_NPC "�����"
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����һ��");
        set("long","�����������ڱ����ĵ�һ�㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "out" : __DIR__"wanan-siyuan",
                "up" : __DIR__"baota-2"
        ]));
        setup();
}

#include "baota.h"