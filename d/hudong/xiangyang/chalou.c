// Room: d/xiangyang/chalou.c ����¥
// Lklv 2001.9.25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"����¥"NOR);
        set("long", @LONG
����������������һ�Ҳ�¥��ֻ�����ڼ��ų������ſ���������������
���ֿ����Ĳ�ͣ������̸Ц����ͷ�Ӷ������������Ϻ�����������������
һ�𡣲�¥��Ʈɢ��һ�ɵ����Ĳ��㣬���Ÿ��������
LONG
        );
        set("resource/water", 1);
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"bjie2",
                "up" : __DIR__"chalou2",
        ]));

        set("item_desc", ([
                "up" : "¥�ϵ��˺ܶ࣬�����￴�������\n"
        ]));
        set("objects", ([
                __DIR__"npc/chaboshi" : 1,
        ]));
        set("incity",1);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( me->query("id") == "cha boshi" &&  dir == "west" ) return 0;
        return ::valid_leave(me, dir);
}
