// Room: bank.c
// Looklove y2k/4/09
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIR"����ի"NOR);
        set("long", @LONG
���ޱ��ϵ�һ��Ǯׯ��������ʰ�ĺܸɾ����·��ܸо���������������
����Ϣ��Ǯׯ�������ƺ�������ԭ������Ʒλ�Ľ������ÿ�����䶼���õľ�
�����������������Ƕ��������������һ�Ǯׯͨ��ȫ������Ʊ���еĻ�ϲ��ͣ
���������ϰ������졣
LONG
        );

        set("exits", ([
                "east" : __DIR__"shejing",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,
          
        ]));
 
        setup();
}

