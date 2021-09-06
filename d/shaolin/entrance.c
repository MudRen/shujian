// Room: entrance.c ľ�������

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "ľ�������");
	set("long", @LONG
������ľ�������ڡ�һ���ߵ�������Ѿ��޷��ٻ�ͷ�ˣ���Ȼ��֪ǰ
�潫���ǲ��������ޱȣ�Ҳֻ��Ӳ��ͷƤ��ǰ���ˡ�
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"murenxiang",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	this_player()->delete_temp("murenxiang");
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && __DIR__"murenxiang.c"->query("busy")) {
		return notify_fail("�������ڴ�ľ������ȵȻ�ɣ�\n");
	}
	return ::valid_leave(me, dir);
}
