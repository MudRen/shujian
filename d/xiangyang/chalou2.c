// Room: d/fuzhou/chalou2.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"��¥��¥"NOR);
        set("long", @LONG
���ǲ�¥�Ķ�¥�����ڰ��ż��ų��������Աߵ��������˼�λ��ͣ����
��̸Ц����ͷ�Ӷ������Ը��صĿ���������һ���������������֡�����Ʈ
ɢ��һ�ɵ����Ĳ��㡣
LONG
        );
        set("resource/water", 1);
        set("xyjob", 1);
        set("exits", ([
                "down" : __DIR__"chalou",
        ]));
        set("objects", ([
                __DIR__"npc/gongzi" : 1,
                __DIR__"npc/haoke" : 1,
        ]));
        set("incity",1);
	setup();
}
