// /d/xiangyang/dcx4.c ������
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ͨ�������ŵ�һ��С��ش������Ƕ��������������ŵ�
������ǽ������׺��һ�Դ��ʻ����ֵ��ϵ����˶������У�������������
ǰ����߱�˵Ц�š�·�����ȴ��ų����ţ��ű߹���һ������(paizi)��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "paizi" : HIC"����ϷԺ\n"NOR,
        ]));

        set("exits", ([
                "north" : __DIR__"dcx3",
                "south" : __DIR__"dcx5",
                "east" : __DIR__"xiyuan",
        ]));

        set("objects", ([
		NPC_D("poorman") : 1,
        ]));

        set("incity",1);
	setup();
}
