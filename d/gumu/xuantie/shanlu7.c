// shanlu7.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
       set("short", YEL"���"NOR);
       set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ����н��ͣ��߽���һ��ɽ
�ȣ���Χ�������ԡ���������ԶԶ�غ�����һ���߶����ͱڡ�
LONG
        );

       set("exits", ([ 
		"northwest"  : __DIR__"shanlu8",
  		"south"  : __DIR__"shandong",  	
       ]));

       set("outdoors", "����");

       setup();
}
