#define FLOOR 9
#define SAVE_NPC "��̫��"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����Ų�");
        set("long","�����������ڱ����ĵھŲ㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-8",
                "up" : __DIR__"baota-10"
        ]));
        setup();
}

#include "baota.h"