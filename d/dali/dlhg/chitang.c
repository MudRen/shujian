// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "����");
	set("long", @LONG
������һ�������������ﳤ���˺ɻ���ԶԶ��ȥһƬ��ɫ�����磬����ʹ��
���𡰱�Ҷ�������ˮ����ʫ�䡣��ϸ�����в��������ˮ����Ϸ��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"xiaoqiao",
                "northwest" : __DIR__"jiashan",
	]));
	set("outdoors", "����");
	set("coor/x",-320);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}
