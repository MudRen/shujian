//fatang.c
//by bren

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", BLU"����"NOR);
	set("long", @LONG
����һ������ĵ��ã�����ͬʱ���ɼ����˶��������⡣������������
˵�𾭣��𷨺���伯��ĳ�������������ķ���һ���ŵ����ţ��Թ�����
�ߴ���֮�á�
LONG
	);

	set("exits", ([
		"north" : __DIR__"kchang",
                "west" : __DIR__"huilang1",
"east" : "/d/shaolin/xcping",
                "southwest" : __DIR__"jietan3",

                "southeast" : __DIR__"jietan4",
       ]));
//         set("objects",([
//		CLASS_D("shaolin") + "/dao-cheng" : 1,
//	]));

	set("coor/x",50);
  set("coor/y",410);
   set("coor/z",130);
   set("coor/x",50);
 set("coor/y",410);
   set("coor/z",130);
   setup();
}



