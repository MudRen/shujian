// sheshenya.c
// ������

// Modified by mxzhao 2004/04/11 for do_jump function

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",MAG "�ù�̨������" NOR);
	set("long",@long
�������ֳ����������ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ�
�����޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ����Ϊ����
�������࣬�������棬���������ã�������������Ͷ���ƺ��������������
long);
	set("outdoors", "����ɽ");
	set("exits",([
		"east" : __DIR__"duguangtai",
	]));
	
	setup();
}

void init()
{

	add_action("do_jump", "tiao");	// �޸� ���� jump
	add_action("do_look", "look");
}

int do_look()
{
	object me = this_player();
	mixed *local;
	local = localtime(time() * 60);
	if(local[2] < 4 || local[2] >= 21)
	{
		write(BLU"�������º�����һƬ���������ֳ�һ�㡢�������ɫ�����⣬��������\n"
			"Խ��Խ�࣬ת�۱㲼��ɽ�ȣ��е�����өƮ�ɣ��е��緱����˸��\n"NOR, me);
	}
	if(local[2] >= 4 && local[2] < 8)
	{
		write(HIR"�����Ǹո�����һ����΢�׵Ĺ��ڶ����Ʋ����֣�һ�ֺ����е�������\n"
			"��ǧ�����ʱ�ڲ���ӳ���³��ֳ�����������\n"NOR, me);
	}
	if(local[2] >= 8 && local[2] <= 13)
	{
		write(HIC"���ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���\n"
			"̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������\n"
			"�����г�������֮�⡣\n"NOR, me);
	}
	if(local[2] > 13 && local[2] < 16)
	{
		write(YEL"�����羲���ƺ�ƽ�̣������Լ���������㱳��б��������������������\n"
			"�ɲ�ɫ�⻷��������Լ�����Ӱ�����س�������ɫ�����ϡ����⻷���˶���\n"
			"��Ӱ�ڻ��С������������ġ�����������������������������������\n"
			"������һ��ʹ������ĳ������������㲻����Ҫ�ڴ�Ͷ���ƺ�����������\n"
			"�����ۣ�������ӡ�\n"NOR, me);
	}
	if(local[2] >= 16 && local[2] < 21)
	{
		write(HIC"���ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���\n"
			"̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������\n"
			"�����г�������֮�⡣\n"NOR, me);
	}
}

int do_jump(string arg)
{
	object me = this_player();

	mixed *local = localtime(time() * 60);
	
	if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("����æ���ģ�\n");
	}
	
	if(arg != "cliff")
	{
		return notify_fail("��Ҫ����������\n");
	}
	
	if (me->query("quest/jiuyin2/fail") >= 3 
		&& me->query("registered") < 3)
	{
		return notify_fail("����Ҳ��������������Ц�ˡ�\n");
	}
	
	if ( me->query("quest/jiuyin2/fail") 
                >= (int)((me->query("combat_exp") - 1000000)/100000) 
		|| (time() - me->query("quest/jiuyin2/time")) < 86400)
	{
		return notify_fail("����ԥ�˰��죬���뻹�����˰ɡ�\n");
	}
	
	{
		object *ob = deep_inventory(me);
		int i = sizeof(ob);

		while (i--)
		{
			if (userp(ob[i]))
			{
				ob[i]->move(this_object());
			}
		}

		message_vision(HIR"$N�������������¡�\n"NOR, me);
		me->move(__DIR__"bankong");

		if(local[2] > 13 && local[2] < 15 )
		{
			if (random(me->query("kar")) > 15
                                 && (int)me->query_dex(1) > 32 
)
			{
				call_out("do_wait", 2, me);
			}
			else if ( me->query("hanshui_food") && random(3) == 1  )
			{
				call_out("do_wait", 2, me);
			}
			else 
			{
				call_out("do_wait1", 2, me);
			}

			return 1;
		}

		call_out("do_wait2", 2, me);
		return 1;
	}
}

void do_wait(object me)
{
	tell_object(me, HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR);
	tell_object(me, "ͻȻ�㱻ʲô�����赲��һ��........\n");
        me->move(__DIR__"wanniansong");
	me->set("quest/jiuyin2/emeijump", 1);
	log_file("quest/jiuyin",sprintf("%-18s��ü��������ʧ��%s�κ�������³ɹ����£�����%d��\n",
		me->name(1)+"("+capitalize(getuid(me))+")",
		chinese_number(me->query("quest/jiuyin2/fail")), me->query("kar")), me);
//	me->unconcious();
}

void do_wait1(object me)
{
	object *ob, *inv;
	int i, j;
	ob = all_inventory(environment(me));
	tell_object(me, HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR);
        me->move(__DIR__"shuitan");
	me->set("water", 666); 
	me->add("quest/jiuyin2/fail",1);
	me->set("quest/jiuyin2/time", time());
	log_file("quest/jiuyin",sprintf("%-18s��������������ʧ�ܣ���ü��������ʧ��%s�Ρ�\n",
		me->name(1)+"("+capitalize(getuid(me))+")",chinese_number(me->query("quest/jiuyin2/fail"))), me);
	tell_object(me, HIC"ֻ������ͨһ�����������һ����ˮ̶�У���ཹ�ེ��˺ü���ˮ....\n"NOR);
        for(i=0; i<sizeof(ob); i++) {
		inv = all_inventory(ob[i]);
		for (j = 0; j < sizeof(inv); j++)
		if (!inv[j]->query_autoload()) destruct(inv[j]);
		ob[i]->unconcious();
	}
}

void do_wait2(object me)
{
        object tmp;
        object *ob;
        int i;
	tell_object(me, HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR);
	tell_object(me, HIW"��ֻ����������������Զȥ........\n"NOR);
        me->move(__DIR__"shuitan");
        me->set_temp("last_damage_from","ˤ��ɽ�µ�");
        me->add("quest/jiuyin2/fail", 1);
        me->set("quest/jiuyin2/time", time());
	log_file("quest/jiuyin",sprintf("%-18s��������������ʧ�ܣ�������ü��������ʧ��%s�Ρ�\n",
		me->name(1)+"("+capitalize(getuid(me))+")",chinese_number(me->query("quest/jiuyin2/fail"))), me);
        me->unconcious();
        me->die();
        if (tmp = present("corpse", this_object())) {
		ob = deep_inventory(tmp);
		i = sizeof(ob);
		while (i--) if (userp(ob[i])){
			ob[i]->move(this_object());
			ob[i]->set_temp("last_damage_from","ˤ��ɽ�µ�");
			ob[i]->die();
		}
		destruct(tmp);
		if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
	}
}
