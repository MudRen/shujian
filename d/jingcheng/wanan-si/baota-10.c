#define FLOOR 10
#define SAVE_NPC "��ά��"
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����ʮ��");
        set("long","�����������ڱ����ĵ�ʮ�㣬�䱸ɭ�ϣ�һ����֪����Ѻ����Ҫ���\n");
        set("exits", ([
                "down" : __DIR__"baota-9",
                "up" : __DIR__"baota-11"
        ]));
        setup();
}

#include "baota.h"