#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"Ӧ�ַ山"NOR);
        set("long", @LONG
������ǵ��ɽ��߷�Ӧ�ַ壬ɽ��ֱ����ϼ����ΰ׳�����������
������ɽ���������겻���Ļ�ѩ��ԶԶ��ȥ�������ɫ��ڣ����������
�ġ���ɽѩ������
LONG);
        set("outdoors", "dali");

        set("exits", ([             
             "southup" : __DIR__"ylf",
               "north" : __DIR__"shanlu",
        ]));
set("objects", ([
	      "/d/dali/npc/huanglu" : 1,
          "/d/dali/npc/pig" : 1,
	]));

        set("coor/x",-350);
  set("coor/y",-380);
   set("coor/z",20);
   setup();
}