// Room: /d/shaolin/fotaout
// Date: hunthu

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "�ŷ�������");
	set("long", @LONG
��������ͨ���γɵ���ɫ�������㣬�˽����ܣ��Թ��ƴ�ש���졣����
�Ի���ʯ������������ש������������ɣ�������������һ�����˸ߵĹ���
С�š�
LONG
);

	set("exits", ([
		"south"     : __DIR__"talin11", 
                "enter"     : __DIR__"fota1",       
         	]));

	set("outdoors", "shaolin");

	set("coor/x",10);
  set("coor/y",310);
   set("coor/z",120);
   setup();

}

