#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"������"NOR);
	set("long", @LONG
�����������ݳ��ڵ�һ��Ψһ��һ������ˡ��������Ÿ��ָ������鼮��
ʲôС˵��������������������������������书�����ȵȵȵȡ�ֻ�뻨��
�����ӾͿ�������Ҫ���顣
LONG	);
	set("exits", ([ 
		"west" : __DIR__"nandajie2",
		]));
/*	set("objects", ([ 
		__DIR__"npc/haoke": 1,
	]) );
*/	
	set("no_clean_up", 0);
	set("coor/x",120);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}