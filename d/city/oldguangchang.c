// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����㳡");
	set("long", @LONG
	�����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ���
���������������������������������ݡ�������һ�ô��������̸���ڣ���
������ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�Ķ�(dong)��
����Կ������������Ը��ص��������������������������У�һ�ɷ������󣬶���
��ʱ�ش������ʵĶ�������������������������ˣ�һƬ�ྲ��
LONG
	);
        set("no_sleep_room",1);
        set("outdoors", "city");

	set("item_desc", ([
		"dong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
	]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"nandajie1",
		"west" : __DIR__"xidajie1",
		"north" : __DIR__"beidajie1",
	]));

	set("objects", ([
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/liumangtou" : 1,
	]));

	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( arg=="dong" ) 
	{
		message("vision",
			me->name() + "һ�������������˽�ȥ��\n",
			environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
			me->name() + "�Ӷ������˽�����\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
