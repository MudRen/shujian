#define FLOOR 4
#define SAVE_NPC "����Ϫ"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����Ĳ�");
        set("long","�����������ڱ����ĵ��Ĳ㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-3",
                "up" : __DIR__"baota-5"
        ]));
        setup();
}

#include "baota.h"