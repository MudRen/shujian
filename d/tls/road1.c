#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ʯ·"NOR);
        set("long", @LONG
��������һ�ΰ�ʯ·��������ǰ��Ĵ��۱�������������
ʯ��ƽ������ɨ�øɸɾ�����̧��һ����ѩ��������������ĵ��
ɽ����󣬲������ꡢ��������Ķ���Ƕ��ǰ�������������ţ�����
���أ�������գ��ۻ�׳����Ϊ�Զ����ʤ��֮һ��
LONG);
        set("outdoors", "dali");

        set("exits", ([             
               "southup" : __DIR__"twd",
               "northup" : __DIR__"baodian",     
               "east" : __DIR__"gulou",
               "west" : __DIR__"zhonglou",

        ]));
        set("objects",([
                __DIR__"npc/guest" : 1,
				 __DIR__"npc/xin-qing" : 1,
        ]));


        set("coor/x",-350);
  set("coor/y",-340);
   set("coor/z",20);
   setup();
}