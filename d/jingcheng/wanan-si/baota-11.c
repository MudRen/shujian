#define FLOOR 11
#define SAVE_NPC "���ʦ̫"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����ʮһ��");
        set("long","�����������ڱ����ĵ�ʮһ�㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-10",
                "up" : __DIR__"baota-12"
        ]));
        setup();
}

#include "baota.h"