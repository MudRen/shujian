// Room: /d/fuzhou/feiyuan.c ��԰
// Lklv 2001.9.10
inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ���ķϵ�լԺ����ǰ������ĸ����˼ҵ�һ����԰����ϧ�����Ѿ���
���ˡ�԰�Ӻܴ�ܿտ����������߸ߵĻĲݡ����ܵ���ǽ�Ѿ��кܶദ�����̮
����һֻ��֪����������Ұè����ǽ��׷��һֻ����
LONG
	);
	set("exits", ([
		"west" : __DIR__"xyxiang",
	]));
	set("objects", ([
		NPC_D("tdh/caidezhong"):	1,
		NPC_D("tdh/chen"):		1,
	]));
	set("outdoors", "����");
	setup();
}
