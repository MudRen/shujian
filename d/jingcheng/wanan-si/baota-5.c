#define FLOOR 5
#define SAVE_NPC "������"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�������");
        set("long","�����������ڱ����ĵ���㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-4",
                "up" : __DIR__"baota-6"
        ]));
        setup();
}

#include "baota.h"