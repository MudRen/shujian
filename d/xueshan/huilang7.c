// Room: huilang7.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ������̫��ĳ��ȣ�ͨ������Ҫ�Ĵ��ȶ��������������ڻ�����д
����ʷ�����¼��ͷ�̹��£�ɫ��������������档
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"zhudubadian",
                "west" : __DIR__"yushengdian",
                "south" : __DIR__"huilang5",
	]));
        set("outdoors", "ѩɽ");
        set("objects", ([CLASS_D("xueshan") + "/hubayin" : 1,]));
	setup();
}
int valid_leave(object me, string dir)
{
        if ((string)me->query("family/family_name") != "������" 
           && dir == "west"  
           && present("hu bayin", environment(me)))
	return notify_fail(
"��������һ�죬��������λʩ�����˴�ֻ����ެ����ſ��Խ�ȥ����ȥ����ϲ�ɡ�\n");

	return ::valid_leave(me, dir);
}
