// /d/xiangyang/dcx4.c ������
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������������ͨ�������ŵ�һ��С��ش������Ƕ�������Ա�����һ
��ʯ��(bei)����д�ż���С�֡�Զ��������м����������ɹ̫��������
��һֱ�����ߣ�����ͨ�������š�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "bei" : HIW"������\n"NOR,
                "shibei" : HIW"������\n"NOR
        ]));

        set("exits", ([
                "north" : __DIR__"dcx4",
                "south" : __DIR__"djie2",
        ]));

        set("incity",1);
	setup();
}
