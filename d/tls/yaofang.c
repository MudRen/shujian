//yaofang.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"ҩ��"NOR);
	set("long", @LONG
�����������µ�ҩ����������������ŨŨ��ҩ�㣬������������װ������
ҩ�ĵĴ�ҩ��ÿ��ҩ�����ϰٸ�װҩ�ĳ��������˸���ҩ����������һ��
�޴��ɼľ�񣬹������ŷ���ӡ�ķ�����һλ����ɮ��������æµ��ָ����ִ��
ɮ����ҩƷ����ҩ������
LONG
	);
 set("exits", ([
             "north" : __DIR__"yaotai", 
        ]));

         set("objects",([
		 __DIR__"npc/liao-ming" : 1,
	]));

	
	set("coor/x",-310);
  set("coor/y",-330);
   set("coor/z",30);
   setup();
}



