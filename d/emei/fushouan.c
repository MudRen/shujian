// Room: /d/emei/fushouan.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",YEL "������" NOR);
	set("long", @LONG
����������ˮ���ϣ���һ���������Ե�ɮ�˽���ġ���ǰ�о�����������
�أ����������ڴ������������۾���ʫ����ӽ��̾����֪Ϧ�ա����������
���������ٲ��䣬�ߴ�ʮ���ɡ�
LONG
	);
	set("outdoors", "��üɽ");
	set("exits", ([ 
	  "north" : __DIR__"shenshuian",
	  "enter" : __DIR__"lingwenge",
]));
	set("objects",([
		CLASS_D("emei") + "/jing-zhen" : 1,
		"/d/emei/npc/dizi" : 1,
]));
	setup();
}
