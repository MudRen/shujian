// Room: /d/shaolin/xiaowu.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
�����м����һ�Ŵ���ϯ������ߵ��ǰ��������Է������Ϸ��˼�ľ��
�ķĳ��������Ѿ������˻ҳ��������Ǻþ�û�����ˡ������ϵĳ��������м�
��ɢ�ҵ��㼣��ͨ��ϯ����Է���
LONG
	);

	set("exits", ([
		"south" : __DIR__"houshan",
		"north" : __DIR__"woshi",
	]));

	setup();
}
