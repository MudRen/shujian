// /d/xiangyang/dcx1.c ������
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������ͨ�������ŵ�һ��С��ش������Ƕ���·���������˴��
СС����ʯ�������������де������������м��������ڳ�����Զ���������
�����������ɹ̫����·����һ���ķϵ�Ժ�ӡ�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"nroad1",
                "south" : __DIR__"dcx2",
                "east" : __DIR__"feizhai",
        ]));

        set("incity",1);
	setup();
}
