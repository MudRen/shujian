// Room: /d/shaolin/shijie1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��������ɽ��´������ɽɽ�š�һ��������ʯ����ͬ���������Ѷ��ϣ�ֱ
û�ƶˡ���ɽȺ���������ɫ��ɽ�����˸����������С֮�⡣�����м�����
����С���������ƺ�������������Щʲô��
LONG
	);

	set("exits", ([
		"east" : __DIR__"ruzhou",
		"west" : "/d/group/entry/slxiaoj1",
		"northup" : __DIR__"shijie2",
	]));
	set("outdoors", "����");
	setup();
}
