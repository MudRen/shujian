// Room: /d/emei/huayanding.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "���϶�" NOR);
	set("long", @LONG
���϶�ͦ�θ��ͣ���ɲ���������ʣ��羰���ա�������Ұ����������
����ΡΡ��������Ⱥ�����У����׷�ɽ�����ԺҲ���۵ס��ɴ���������
�£���������ʯ�����¹�ʮ���̿ɵ������¡�������һ����ǡ�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([
  "westup" : __DIR__"lianhuashi",
  "eastup" : __DIR__"xianfengsi",
  "north" : __DIR__"maji",
  "down" : __DIR__"shierpan4",
]));
	set("objects",([
		CLASS_D("emei") + "/li-mingxia" : 1,
]));
	setup();
}
