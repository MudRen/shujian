// /d/wudang/zxgdamen.c  ����������
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",MAG"����������"NOR);
        set("long", @LONG
���ѵ���չ����£�ǰ������䵱ɽ��Ϊ���Ĺ����������ˡ�������ɽ
�������ߵʹ������¡���Χ��ľ���죬������֣����ﻨ�㣬��ɫ���ģ���һ
���޵����ɴ����������䵱ʦͽ����Ҫ�������
LONG
        );
        set("exits", ([
                "enter" : __DIR__"zixia",
                "northdown" :__DIR__"shijie3",
        ]));

        set("objects",([
                CLASS_D("wudang")+ "/fengsong" : 1,
                __DIR__"npc/daotong" :2,
        ]));
        
        set("outdoors","�䵱");
        setup();
}
