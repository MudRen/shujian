// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���ܱ���Сʯ�ţ������ǻ�������ˮ��ˮ����ȥ���壬ʹ��������
ȥ��Ӿ�ĳ嶯��������ͨ���󹬵ıؾ�֮·��
LONG
	);

	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"zoulang2",
                "northwest" : __DIR__"chitang",
	]));
	set("outdoors", "����");
	set("coor/x",-310);
  set("coor/y",-400);
   set("coor/z",-20);
   setup();
}
