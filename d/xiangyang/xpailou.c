// /d/xiangyang/xpailou.c ����¥
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"����¥"NOR);
        set("long",
"���������������ĵ�һ���㳡���㳡��������һ�����������¥����¥��\n"
"�ߣ��������ο��������ڿշ����"HIC"����"NOR"�������м����һͷ����ͦ�ص�"HIY"����"NOR"��\n"
"�ޣ��������������������Ʋ������ϱ���һ����ʯ�����һֱͨ�������ǵ���\n"
"���ţ���ȸ�š�������һ�����ֵĽֵ���\n"
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "north" : __DIR__"cross1",
                "south" : __DIR__"njie1",
        ]));
        set("objects", ([
                NPC_D("guanfu/bing") : 2,
        ]));

        set("incity",1);
	setup();
}
