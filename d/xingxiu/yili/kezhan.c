// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
	set("short", "��ջ");
	set("long", @LONG
����������ǵĿ�ջ����ջ���ſڷ���һ�����Ͱ(tong)������ѵĲ�ˮ
��Ӧ��һ��ά�����С����������������⡣��������˿��Ե�¥��˯һ����
LONG);
	set("resource/water", 1);
        set("exits", ([
		"up" : __DIR__"kezhan2",
		"southeast" : __DIR__"yili2",
	]));
	set("item_desc", ([
		"tong" : "һֻװ����ˮ�Ĵ��Ͱ�������Ҩ(drink)�����ȡ�\n"
	]) );
	set("objects", ([
		__DIR__"../npc/alamuhan" : 1,
		__DIR__"../npc/caiyaoren1" : 1,
		__DIR__"../npc/yin" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}
int do_drink(string arg)
{
	int current_water, max_water;
	object me;

	me = this_player();
        current_water = me->query("water");
	max_water = me->query("str")*10 + 100;

        if (current_water<max_water) {
		me->set("water", current_water+30);
		message("vision", me->name()+"�ò��״Ӳ�Ͱ��Ҩ��һ�ڲ�ˮ���ȡ�\n", environment(me), ({me}) );
		write("��Ҩ��һ��Ͱ�еĲ�ˮ���ȡ�\n");
        }
	else
	write("����Ҳ�Ȳ����ˡ�\n");
        return 1;
}
