#define FLOOR 2
#define SAVE_NPC "������"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long","�����������ڱ����ĵڶ��㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-1",
                "up" : __DIR__"baota-3"
        ]));
        setup();
}

#include "baota.h"