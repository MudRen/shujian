// Room: /d/village/sexit.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
����һ��С��ׯ�������������˼Ҳ��࣬�����ǹ����ճ������������Ϣ
����������������С���ӣ������ϻ�ɽ��ɽ·�ˡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"shilu1",
		"south" : __DIR__"hsroad3",
	]));

	set("objects", ([
		NPC_D("dog"): 1,
	]) );
	set("no_clean_up", 0);
	set("outdoors", "��ɽ" );

	setup();
}