// Room: bank.c
// Looklove y2k/4/10
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"ī��ի"NOR);
        set("long", @LONG
���������ֵĳɶ������һ�Ҵ�Ǯׯ�����⿴�����ܲ���������������
��ס�ڸ������˶��Ƚϸ�ԣ�����Ǯׯ���Զһ�ͨ��ȫ������Ʊ��
LONG
        );

        set("exits", ([
                "east" : __DIR__"nandajie2",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,
          
        ]));
 
        set("incity",1);
	setup();
}

