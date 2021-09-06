// board.c
// Create by mxzhao

inherit ITEM;

#include <ansi.h>
#include <group.h>

void create()
{
	set_name("���԰�", ({ "board", }));
	set_weight(5000);

	if (clonep())
	{
		set_default_object(__FILE__);
	}
	else 
	{
		set("unit", "��");
		set("long", "����һ�����԰塣����԰������ڰ������򣬹�������ԡ�\n");
		set("value", 20000000);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("group", 1);
	}

	setup();
}

void init()
{
	add_action("do_drop", ({"drop","fangzhi","����"}));
}

int do_drop(string arg)
{
	object me = this_player() , env = environment(this_object());

	if( !arg || !id(arg) || env!=me )
	{
		return 0;
	}

	env = environment(me);

	if( !me->query("group/id") ) 
	{
		tell_object(me, "�㲢û�п������ɣ�Ҫ" 
			+ name() + "���ã�\n");
		return 1;
	}

	if( !GROUP_D->site_now(me->query("group/id")) )
	{
		tell_object(me, GROUP_D->get_last_error());
		return 1;
	}

	GROUP_D->drop_board(this_object(), me, env,"$N��ʼС�ĵذڷ�" 
		+ name() + "����\n", "��æµ�˰��죬�����" + name() + "���úá�\n");
	return 1;
}

