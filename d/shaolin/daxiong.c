//daxiong.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"���۱���"NOR);
	set("long", @LONG
�����������µĴ��۱��������䣬�����ļ䡣���й�������������
�����Ҹ������⡢������λ������һȺɮ�����Է����о��������ҷ��黨΢
Ц����̬�����˶ٸ���Ȼ�𾴡�������ÿ�����Ƿ��ɴ�ʦ�ټ�����Ⱥɮ
����֮����
LONG
	);
        set("no_fight",1);
       	
	set("exits", ([
		 "south" : __DIR__ "pingtai",
                 "north" : __DIR__ "stoneroad1",
       ]));

	
	set("coor/x",50);
  set("coor/y",300);
   set("coor/z",120);
   setup();
}



