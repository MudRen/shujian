#define FLOOR 7
#define SAVE_NPC "���Ǵ�ʦ"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�����߲�");
        set("long","�����������ڱ����ĵ��߲㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-6",
                "up" : __DIR__"baota-8"
        ]));
        setup();
}

#include "baota.h"