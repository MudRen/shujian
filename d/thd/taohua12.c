// Room: /u/jpei/thd/taohua.c

inherit ROOM;

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(12) + 1;
	thd2 = random(12) + 1;
	thd3 = random(12) + 1;
	thd4 = random(12) + 1;
	while (thd1 != 11 && thd2 != 11 && thd3 != 11 && thd4 != 11) {
		thd1 = random(12) + 1;
		thd2 = random(12) + 1;
		thd3 = random(12) + 1;
		thd4 = random(12) + 1;
	}
	set("short", "�һ���");
	set("long", @LONG
����һƬï�ܵ��һ��ԣ���һ�߽�������ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"taohua" + thd4,
	]));
	set("outdoors","�һ���");
	setup();
}

void init()
{
	object ob=this_player();

	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("���������۵þ�ƣ����������������֧�����˹�ȥ��\n");
		write("���Ժ������ƺ����˰���̧�����󣬷·��и����ϵ������ȵ������ӵ�����ȥ����\n");
		ob->unconcious();
          ob->move(__DIR__"haibin", 1);
		message("vision", "��Ȼһ����ӿ�˹�������һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
}

