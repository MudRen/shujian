#define FLOOR 13
#define SAVE_NPC "���Ŵ�ʦ"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long","�����������ڱ����ĵ�ʮ���㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-12",
        ]));
        setup();
}

#include "baota.h"