// /d/xiangyang/ncx1.c �ϳ���
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ϳ���");
        set("long", @LONG
����������ȸ��ͨ�������ŵ�һ��С��ش��������ϣ�����Ա�����һ
��ʯ��(bei)����д�ż���С�֡�Զ��������м����������ɹ̫��������
��һֱ�����ߣ�����ͨ�������š�·���Ǽ�˵��ݡ�
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "bei" : HIW"�ϳ���\n"NOR,
                "shibei" : HIW"�ϳ���\n"NOR
        ]));

        set("exits", ([
                "west" : __DIR__"njie3",
                "east" : __DIR__"ncx2",
                "north" : __DIR__"shuoshug",
        ]));

        set("incity",1);
	setup();
}
