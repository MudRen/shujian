#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",MAG"�ɻ���"NOR);
	set("long", @LONG
�ɻ������������������䣬��ָ�ˬ������ȡ���䣺��һˮ�����̣�ǧ
���Ա�족֮ʫ�⡣��ǰ����ƽ̨���ٺɳأ�Ϊ�����ͺ�����ʤ�����ʳ�
���ɻ������������л�̨ͥԺ����ʯ�������Գ�һ����
LONG	);
      
        set("exits", ([ 
     "west" : __DIR__"gumujiaohe",
	"east" : __DIR__"liuyuan",
	]));
	set("outdoors", "suzhou" );
	set("no_clean_up", 0);
	set("coor/x",90);
  set("coor/y",-250);
   set("coor/z",0);
   set("incity",1);
	setup();
}
