// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
������һ��Ƭũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ��һ��
�����أ�������һЩ���ڸ�����ũ�ˡ����ﲻʱ����һ������Ȯ�͡�
LONG );
	set("exits", ([
		"southwest" : __DIR__"tiandi3",
		"north"     : __DIR__"huanghe1",
                "east"     : "/d/taishan/hsroad2",
	]));
	set("objects", ([
		NPC_D("dog") : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "�ƺ�");
	setup();
}
