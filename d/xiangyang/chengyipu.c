// /d/xiangyang/chengyipu.c ������
// Lklv 2001.9.26

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������һ�ҳ����̣������С����ǰ����ǽ������һ���Խ�С�ӡ�������
Ҳ���Ǻܿ������Ŷ���ļ��Ϲ��ż������ۡ��������������Ĺ���Χ��һ��
������������ʲô��ǽ�Ϲ���һ��ľ��(paizi)��
LONG
        );
        set("xyjob", 1);
        set("item_desc", ([
                "paizi" : "ֻ�����£�ˡ������\n",
        ]));

        set("exits", ([
                "west" : __DIR__"dcx3",
        ]));

        set("objects", ([
		__DIR__"npc/yusan" : 1,
        ]));

        set("incity",1);
	setup();
}
