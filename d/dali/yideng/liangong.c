// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ������ڰڷ��Ÿ�������������
������Ҷѷ���һЩɳ����������������ϰ����ָ���õġ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"houyuan",
	]));

	set("objects", ([
		BINGQI_D("sword") : 1,
	]));

	setup();
}
