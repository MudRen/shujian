// /d/xiangyang/dpailou.c ����¥
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"����¥"NOR);
        set("long",
"���������������ĵ�һ���㳡���㳡��������һ�����������¥����¥��\n"
"�ߣ��������ο��������ڿշ����"HIC"����"NOR"�������м����һͷ����ͦ�ص�"HIY"����"NOR"��\n"
"�ޣ��������������������Ʋ�����������һ����ʯ�����һֱͨ�������ǵı�\n"
"���ţ������š�������һ�����ֵĶ��ֽ֡�\n"
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"cross2",
                "north" : __DIR__"bjie3",
        ]));
        set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));

        set("incity",1);
	setup();
}
