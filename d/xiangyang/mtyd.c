// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;

void meet();
void create()
{
        set("short", "Ħ���¶�");
        set("long", @LONG
������һ��ʮ�־�����ɽ�£��ųơ�Ħ���¡�������ɽ�紵����������Ƣ��
LONG
        );
        set("outdoors", "��������");
        set("exits", ([
                "down" :"/d/xiangyang/motianya",
        ]));
        set("objects",([
                "/d/xiangyang/npc/shipotian" : 1,
         ]));

        
        setup();
}


