// /d/xiangyang/dcx2.c ������
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�������ŵ�һ��С��ش������Ƕ���·���������˴��
СС����ʯ�������������де������������м��������ڳ�����Զ���������
�����������ɹ̫����·����һ���ӻ��̡�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "north" : __DIR__"dcx1",
                "south" : __DIR__"dcx3",
                "east" : __DIR__"zahuopu",
        ]));
        set("objects", ([
		__DIR__"npc/fengmofeng" : 1,
        ]));
        set("incity",1);
	setup();
}
