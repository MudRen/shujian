// /u/dubei/miaojiang

#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIY "ҩ����" NOR);
        set("long", @LONG
������һ����ӵ���ի������ȫ��һ����ҩ�񡣿��������������ż���
ҽ�䡣һλ��Ů���ں���ۿ����鼮���Ա�վ��һ��СѾ�ߡ�������һ�ɵ���
�Ĳ�ҩ�ҷ���
LONG
        );
        set("no_fight",1);
	set("no_sleep_room",1);
        set("exits", ([
                "north" : __DIR__"yaofang1",
                "northwest" : __DIR__"jiedao2",
                   
        ]));
        set("objects",([
                __DIR__"npc/chenglingsu" : 1,
                __DIR__"npc/yahuan" : 1,

        ]));

       

        setup();

}
