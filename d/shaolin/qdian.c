// Room: /u/zqb/shaolin/qdian.c
// by zqb

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ǰ��");
        set("long", @LONG
������������ǰ��һ��ǰ���ģ��С���������޺ܶ���衣ֻ�м���
Сɳ���ڽӴ�����������͡�͸�������Ĵ��ţ����Կ���ǰ���ģ��ΰ����
���
LONG
        );

        set("exits", ([
                "south" : __DIR__"gchang-1",
                "north" : __DIR__"twdian",
        ]));

        set("objects",([
                CLASS_D("shaolin") + "/qing-shan" : 1,
                __DIR__"npc/xiang-ke" : 1, 
        ]));

        set("coor/x",50);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}

void init()
{
        object me = this_player();
        
	if (userp(me) && me->query("jingli") < 50) {
                message_vision(HIY"ֻ��$N����һ��������ˤ�˸�����ſ��ԭ��$N���˸��㽶Ƥ��\n"NOR,me);
                me->start_busy(2);
        }
}
