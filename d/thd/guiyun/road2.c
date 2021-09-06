// Room: /u/jpei/guiyun/road2.c

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ��������С·�������濴Զ���ƺ�����һ��С�ӡ������濴��һ����֪
�ж೤��С·��������һ��С�ƹݡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "����ׯ");

	set("exits", ([
		"east": __DIR__"riverw",
		"north": __DIR__"road3",
		"south": __DIR__"jiuguan",
	]) );
	set("objects", ([
		"/clone/npc/kid" : 1,
	]) );

	setup();
	quarter_pass();
}

void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
һ��������С·�������濴Զ���ƺ�����һ��С�ӡ������濴��һ����֪
�ж೤��С·��������һ�Ҵ����˵�С�ƹݡ�
LONG
		);
		delete("exits/south");
	}
	else {
		set("long", @LONG
һ��������С·�������濴Զ���ƺ�����һ��С�ӡ������濴��һ����֪
�ж೤��С·��������һ�ҿ��ŵ�С�ƹݡ�
LONG
		);
		set("exits/south", __DIR__"jiuguan");
	}
	call_out("quarter_pass", 30);
}
