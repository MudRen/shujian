#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short","ʯ��");
       set("long", @LONG
һ����ʯ���ɵ����ȣ���Χ���ް�������ʯɫ���࣬ʯ��������̤
��ʯ��֮�ϣ��չ�����������Ͼ�벻�ѡ������ˬ�������������㣬����ʹ
�˳��׽�����
LONG
     );
	set("exits", ([
                "east" : __DIR__"xctang",
              //"west"  : __DIR__"nxaju",
            //  "north" : __DIR__"dmtang",
              "northwest" : __DIR__"gygu",	
       ]));
        set("coor/x",50);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}
