// Room: d/fouzhou/bank.c
// Looklove y2k/4/09
// lklv modify 2001.9.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"ͨ��ի"NOR);
        set("long", @LONG
���Ǹ��ݵ�һ��Ǯׯ�����м�������ʷ����ԭǮׯ���˵����Ϸֵꡣ����
���Ϸ��е���Ʊ�����ǳ��ã�ͨ��ȫ�����������ڵش��Ƕ�������ƽ��������
�˲��Ǻܶࡣ
LONG
        );

        set("exits", ([
                "west" : __DIR__"dongxiang2",
        ]));

        set("objects", ([
                __DIR__"npc/banker" : 1,

        ]));

	setup();
}
