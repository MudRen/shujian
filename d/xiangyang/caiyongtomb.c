// /d/xiangyang/caiyongtomb.c

inherit ROOM;

int do_dig(string arg);

void create()
{
	set("short", "����Ĺ");
	set("long", @LONG
�����������ڴ˵أ����Ƕ���ĩ����ʿ����֪�Ƿ񱣴�����Щ�Խ��Ժ��
ʧ���˵Ĺ��
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"caiyongmanor",
	]));
	setup();
}

void init()
{
	add_action("do_dig", ({"dig", "wa", "daomu", "juemu", "jue"}));
}

int do_dig(string arg)
{
	object ob, me = this_player();
	string action = query_verb();

	if ((action == "dig" || action == "wa" || action == "jue") &&
		(arg != "tomb" && arg != "mu" && arg != "caiyong mu")) {
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if (!(ob = present("tie qiao", me))) {
		write("��û�й��ߣ���ô��Ĺѽ��\n");
		return 1;
	}
	destruct(ob);
	write("��������ڿ����ѣ����ڲ��������ѹ��߶��㻵�ˡ����ҵ����������ڳ���һ���������ȥ�Ķ���\n");
	write("����ĹѨ�����˰��죬û���ҵ�ʲô�ö�����ֻ������һ���ܹžɵ����\n");
	write("��ɥ�������ĹѨ�������룬���ǰ�Ĺ��������ֶ��˻�ȥ��\n");
	new("d/meizhuang/obj/guanglingsan")->move(me);
	return 1;
}
