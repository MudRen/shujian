// /d/xiangyang/ncx2.c �ϳ���
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ϳ���");
        set("long", @LONG
����������ȸ��ͨ�������ŵ�һ��С��ش��������ϡ�������һֱ����
�ߣ�����ͨ�������š�Զ��������м����������ɹ̫����·����һ�ҳ���
�С��ſ��Ź�һ��ľ��(pai)��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "mupai" : HIY"ȫ�����أ���������\n"NOR,
                "pai" : HIY"���ţ�ͨ�и���\n"NOR
        ]));

        set("exits", ([
                "west" : __DIR__"ncx1",
                "east" : __DIR__"ncx3",
                "north" : __DIR__"chemahang",
        ]));
        set("incity",1);
	setup();
}
