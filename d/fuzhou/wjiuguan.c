// Room: d/fouzhou/wjiuguan.c
// lklv 2001.9.7

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","С�ƹ�");
        set("long", @LONG
����һ��·��С�ƹݣ�������Ϊ�����Ӵ�һЩ��ʳ����Ϊ·�Ϲ����Ŀ���
���Ǻܶ࣬��������Ҳ���嵭��ż������Щ���������εĳ����˹�ˣ������
����������һ����ͷ���������ӡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"wroad2",
        ]));

        set("objects", ([
                __DIR__"npc/sa" : 1,

        ]));

	setup();
}
