#define FLOOR 8
#define SAVE_NPC "������"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����˲�");
        set("long","�����������ڱ����ĵڰ˲㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-7",
                "up" : __DIR__"baota-9"
        ]));
        setup();
}

#include "baota.h"