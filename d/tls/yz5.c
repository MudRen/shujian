#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"����Ժ"NOR);
        set("long", @LONG
����һ����ֲ�����СԺ�ӣ�����һ��С·��ͨ����ס������ʯ��
���ɨ�÷ǳ��ɾ�����紵����ֻ������Ҷ���Ʈ��������ɳɳ�����죬
ȴ������һ˿�ҳ���
LONG);
        set("outdoors", "dali");

       set("exits", ([                           
               "east" : __DIR__"men2",
               "west" : __DIR__"men4",
               "north" : __DIR__"ta3",
               "southeast"  : __DIR__"dizangdian",
        ]));
set("objects",([
		__DIR__"npc/guest" : 2,
		__DIR__"npc/shami" : 1,
		]));
        set("coor/x",-370);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}