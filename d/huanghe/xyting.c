// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
���ǻƺӰ����µĴ��������Ϲ��š��������������Ҷ���￿�����Ϸ�
��һ�Ż�Ƥ���Σ����߰����ż�����ľ���Σ��ǳ������ɡ�ǽ�ϸ�ӹ���ŵع�
�˼��������鷨��
LONG );
	set("exits", ([
                "east"  : __DIR__"gchang",
	]));
	set("objects", ([
		__DIR__"npc/sha" : 1,
		__DIR__"npc/peng" : 1,
		__DIR__"npc/liang" : 1,
	]));

	setup();
}
