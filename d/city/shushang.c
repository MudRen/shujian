// /u/jpei/guiyun/shushang.c

#include <ansi.h>

#define DOWN_TREE __DIR__"guangchang"

inherit ROOM;

int do_kill(string arg);
int do_climb(string arg);
int my_drop(string arg);
string look_down();

void create()
{
	set("short", "����");
	set("long",@LONG
�����Ǵ���������������Χ�������涼���������¿���֦Ҷ��ʢ��͸����
Ҷ�Ŀ�϶������Լ�Կ�������(down)���龰��
LONG
);
/*	set("exits",([
		"down" : __DIR__"shulin5",
	]) );*/
	set("item_desc", ([
		"down" : (: look_down :),
	]) );

	set("no_clean_up",0);
	set("outdoors", "����");
	set("coor/x",110);
  set("coor/y",-10);
   set("coor/z",10);
   setup();
}

void init()
{
	object room, *ob;
	object here = this_object();
	object me = this_player();
	int i;

	if (userp(me) && !wizardp(me)) {
		if (!room = find_object(DOWN_TREE)) 
			room = load_object(DOWN_TREE);
		ob = all_inventory(here);
		for (i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i]) && !wizardp(ob[i]) && ob[i] != me) {
				write("û�뵽" + ob[i]->name() + "Ҳ�������ϣ�\n");
				message_vision("��Ϊ��֦�޷����������˵���������ž����һ���۶��ˣ�\n", me);
				me->move(DOWN_TREE, 1);
				ob[i]->move(DOWN_TREE, 1);
				message_vision("ֻ��������������һ�����죬$N��$n�����ϵ���������\n", me, ob[i]);
				message_vision("$N��ŭ����$n�µ�����" + RANK_D->query_self_rude(ob[i]) + "��������ĺúõģ����" + RANK_D->query_rude(me) + "���������ң���\n", ob[i], me);
				message_vision("$NҲ�������ط�����������������棬һ����֪�����Ǻ��ˣ���\n", me);
				message_vision("����Խ˵Խ��������ȭ����ӣ�\n", me);
				me->fight_ob(ob[i]);
				ob[i]->fight_ob(me);
				return;
			}
		}
	}
	"/cmds/std/look.c"->look_room(me, here);
	add_action("do_kill", "kill");
	add_action("do_kill", "sha");
	add_action("do_kill", "touxi");
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("my_drop", "drop");
}

string look_down()
{
	object down;

	if (!down = find_object(DOWN_TREE))
		down = load_object(DOWN_TREE);
	"/cmds/std/look.c"->look_room(this_player(), down);
	return "";
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg != "down")
		return notify_fail("��Ҫ�������\n");
	message_vision("$N˳������������ȥ��\n", me);
	me->move(DOWN_TREE);
	message("vision", me->name() + "����������������\n", DOWN_TREE, ({me}));
	return 1;
}

int do_drop(object me, object obj)
{
	object down, *inv;
    
	if ((obj->query("no_drop") || obj->query("unique")) && !wizardp(me))
		return 0;
        // add by hello 1996.12.3
        // Donnot let the user drop more than 50 things to room.
	if (!down = find_object(DOWN_TREE))
		down = load_object(DOWN_TREE);

	inv = all_inventory(down);  
        if (sizeof(inv) > 49)
		return notify_fail("�����Ѿ���ô�ණ���ˣ�������\n");
        
        if (obj->move(down)) {
		if (obj->is_character()) {
			message_vision("$N��$n�ӱ��Ϸ����������ӵ������¡�\n", me, obj);
			tell_room(down, obj->name() + "���˴���������������\n", ({}));
		}
		else {
			message_vision( sprintf("$N��һ%s$n���������¡�\n", obj->query("unit")), me, obj );
			if( (!obj->query("value") && !obj->value())) {
				write("��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ��ڡ�\n");
				destruct(obj);
			}
			else
				tell_room(down, "��Ȼ�����ϵ���һ" + obj->query("unit") + obj->name() + "��������ҵ��㡣\n", ({}));
		}
		return 1;
	}
	return 0;
}

int my_drop(string arg)
{
	object me = this_player();
	object obj, *inv, obj2;
	int i, amount;
	string item;

	if (!arg) return notify_fail("��Ҫ����ʲô������\n");

	if (sscanf(arg, "%d %s", amount, item) == 2) {
		if (!objectp(obj = present(item, me)))
			return notify_fail("������û������������\n");
		if (stringp(obj->query("no_drop")))
			return notify_fail((string)obj->query("no_drop"));
		if (!obj->query_amount())
			return notify_fail( obj->name() + "���ܱ��ֿ�������\n");
		if (amount < 1)
			return notify_fail("����������������һ����\n");
		if (amount > obj->query_amount())
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else if (amount == (int)obj->query_amount())
			return do_drop(me, obj);
		else {
			obj->set_amount((int)obj->query_amount() - amount);
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_drop(me, obj2)) return 1;
			obj2->move(me);
			return 0;
		}
	}

	if (arg == "all") {
		inv = all_inventory(me);
		for (i = 0; i < sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if (!objectp(obj = present(arg, me)))
		return notify_fail("������û������������\n");
	return do_drop(me, obj);
}

int do_kill(string arg)
{
	object room, ob;
	object me = this_player();
//	int temp;
	string callname;

	if (me->is_busy())
		return notify_fail("����æ���ģ�\n");

	if (!arg || !(room = find_object(DOWN_TREE)))
		return notify_fail("��Ҫ͵Ϯ˭��\n");

	if (!(ob = present(arg, room)))
		return notify_fail("��Ҫ͵Ϯ˭��\n");

	if (!ob->is_character() || ob->is_corpse())
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if (!userp(ob)) {
		write("͵ϮNPC���������װ���\n");
		return 1;
	}

	if (wiz_level(me) < wiz_level(ob))
		return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");

	message("vision", me->name() + "һԾ���£������µ�" + ob->name() + "������͵Ϯ��\n", this_object(), ({me}));
	me->move(room, 1);
//	temp = me->query("dex") / 10 + 1;
	if (random(4)) {
		message_vision("$N�����ϼ�Ծ���£���������$n��$n��㵼侹Ȼ�����ˣ�\n", me, ob);
		ob->start_busy(3);
	}
	else {
		message_vision("$N�����ϼ�Ծ���£���������͵Ϯ$n��ȴ�����ʱ��С�ĵ���һ�ӣ�$n�û����̷���������\n", me, ob);
		me->start_busy(5);
	}

/*
        if ( userp(me) && userp(obj) && obj->query("combat_exp") < 1000 )
                return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");
*/
	callname = RANK_D->query_rude(ob);

	message_vision("\n$N����$n�ȵ�����" 
		+ callname + "�����ղ������������һ��\n\n", me, ob);

	me->delete_temp("guarding");
	ob->set_temp("guarding", 1);
	me->kill_ob(ob);
	if( !userp(ob) )
		ob->kill_ob(me);
	else {
		ob->fight_ob(me);
		if (userp(me))
			tell_object(ob, HIR "�����Ҫ��" + me->name()
			+ "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);
	}

	return 1;
}
