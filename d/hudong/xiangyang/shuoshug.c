// Room: d/xiangyang/shuoshug.c ˵���
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"˵���"NOR);
        set("long", @LONG
����һ��˵��ݣ��ط����󣬵����뼸�ŷ������ų�����������Χ���˼�
���������ӡ����׷���һ�Ű�������ǽ�Ϲ���һ�������������ϵ���д������
���衣
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"ncx1",
        ]));

        set("objects", ([
                __DIR__"npc/shuren" : 1,
        ]));
        set("incity",1);
	setup();
}
