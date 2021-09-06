// Room: /d/xingxiu/shanshi.c
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽʯ");
	set("long", @LONG
���������޺�����һ��ɽʯ�������Ƿ�Բ�����ﶼ��һ���޼ʵĺ�������
����Ϊ���䳱ʪ���˴����深ֳ�����������ɵ��ӳ����˲�׽���棬�Ա���
��֮�á��ϱ��и��������ɽ��(cave)��
LONG
        );
	set("outdoors", "����");
	set("objects", ([
		__DIR__"npc/haoshou"  : 1,
		__DIR__"npc/shihou"  : 1,
        ]) );
	set("exits", ([
		"eastdown" : __DIR__"xx6",
        ]));
	set("item_desc", ([
		"cave" : "ɽ����Ʈ��һ�ɹ��ȳ�ζ���㻹�ǿ���뿪�ɡ�\n"
        ]) );
	setup();
}

void init()
{
	object me, ob;
	mapping fam;
	me = this_player();
	fam = (mapping)me->query("family");

	if(( objectp(present("lanyu bo", me)) || objectp(present("shenmu wangding", me)))
	 && objectp(ob = present("shihou zi", environment(me)))){
		message_vision("$N����$n���һ������"+RANK_D->query_rude(me)+"������͵�ñ��ɱ��\n", ob, me);
		ob->kill_ob(me);
	}
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping myfam;
	me = this_player();
	myfam = (mapping)me->query("family");

	if( !arg || arg=="" ) return 0;

	if (arg == "cave" ){
		if (me->is_fighting() || me->is_busy())
			return notify_fail("����һ��������û�����ꡣ\n");
		if ((!myfam || myfam["family_name"] != "������")
		&& objectp(present("shihou zi", environment(me))))
			return notify_fail("ʨ����������������ǰ���ȵ������밤��ľͿ������\n");

		message_vision("$NС���������ɽ����̽��̽��\n", me);
		message("vision",me->name() + "һ������ɽ�������˽�ȥ��\n", environment(me), ({me}) );
		me->move(__DIR__"cave");
		message("vision",me->name() + "���������˽�����\n", environment(me), ({me}) );
		return 1;
	}
}

int valid_leave(object me, string dir)
{
	if((objectp(present("lanyu bo", me)) || objectp(present("shenmu wangding", me)))
	 && objectp(present("shihou zi", environment(me))) && dir == "east")
		return notify_fail("ʨ����������������ǰ���ȵ������û��ô���ף�\n");

	return ::valid_leave(me, dir);
}
