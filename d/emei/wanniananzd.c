// Room: /d/emei/wanniananzd.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "������ש��");
	set("long", @LONG
�����������ֵĹ�������ש�ש���ı�Ϊ�����Σ���Ϊ���Բ���Σ���
�����������������������ͭ����һ�𡣹�������ש���ı��·�����С���ʮ
�ĸ����ڸ�����������һ���ı��Ϸ����к�������������ͭ��С����������
����
LONG
	);
	set("exits", ([ 
  "east" : __DIR__"chanfang3",
  "out" : __DIR__"wannianan",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-kong" : 1,
		CLASS_D("emei") + "/wen-fang" : 1,
]));
create_door("east", "С��", "west", DOOR_CLOSED);
	setup();
}
