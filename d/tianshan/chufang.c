// Room: /d/tianshan/chufang.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����µ�С�������������װ�λ���Ϊ����ɫ�����������˸о�������
Ŀ������������չ�һ���ò͵ĵط���������һ�ŵ��ε�ʮ��Ѥ���ĳ�������
���ֱַ�������С����
LONG);
	set("exits", ([
		"east" : __DIR__"qiandian",
        ]));       

	set("objects", ([
		FOOD_D("rice") : 2,
		FOOD_D("hulu") : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *ob = deep_inventory(me);
	int i = sizeof(ob);
	if((dir == "east")){
		while (i--)
		if(ob[i]->id("qing hulu") || ob[i]->id("rice"))
			return notify_fail("ʳ�����ڳ����ڳ��꣬��������������š�\n");
	}
	return ::valid_leave(me, dir);
}
