// /d/xiangyang/dcx3.c ������
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�������ŵ�һ��С��ش������Ƕ���·���������˴��
СС����ʯ�������������де������������м��������ڳ�����Զ���������
�����������ɹ̫����·���мҳ����̣��뿪���š�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "north" : __DIR__"dcx2",
                "south" : __DIR__"dcx4",
                "east" : __DIR__"chengyipu",
        ]));

        set("objects", ([
		__DIR__"npc/guofu" : 1,
        ]));

        set("incity",1);
	setup();
}
