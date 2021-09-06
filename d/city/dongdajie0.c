// Room: /d/city/dongdajie0.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ����������س�
�ٱ����̲�����������һ�Ҵ����̣����ô����������ϴ����д��������ϱ�
�Ǽұ����̣����������������������
LONG
	);
	set("outdoors", "����");

	set("objects", ([
		"/d/zhiye/npc/caikuang-shi": 1,
	]) );

	set("exits", ([
		"east" : __DIR__"dongmen",
		"south" : "/d/zhiye/bingqipu1",
		"west" : __DIR__"dongdajie1",
		"north" : "/d/zhiye/datiepu1",
	]));

	set("incity",1);
	setup();
}

void init()
{
        object ob, me;
        me = this_player();

        if ( wizardp(me) && me->query("env/test")== 3) {
		if (!objectp(ob = present("lushi", me))){
			ob = new("/d/zhiye/obj/kuangshi4-2");
			ob->move(me);
			ob = new("/d/zhiye/obj/kuangshi4-2");
			ob->move(me);
        	}
		if (!objectp(ob = present("tiechui", me))){
			ob = new("/d/zhiye/obj/tiechui");
			ob->move(me);
		}
	}
}