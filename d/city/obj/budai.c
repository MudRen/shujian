// Budai.c
// Creator : Numa@Sj 00-6-3

#include <ansi.h>
inherit ITEM;

#define SHU "/d/city/obj/whdmd-book"

void create()
{
        set_name("����", ({"bu dai", "dai"}));
        set_weight(2000);
        set_max_encumbrance(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���ƾɵĲ�����\n");
                set("unit", "��");
                set("no_get", 1);
                set("no_steal", 1);
                set("no_give", 1);
                set("fill_lime", 1);
        }
        setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_sa","sa");
	add_action("do_put","put");
}

int do_put(string arg)
{
        string str;

        if (!arg) return 0;
        if (sscanf(arg,"%s in dai",str) == 1 || sscanf(arg,"%s in bu dai",str) == 1) {
                if (str != "shihui")
                        return notify_fail("���������Ų���ȥ��\n");
        }
        return 0;
}

int do_sa(string arg)
{
	object me = this_player();
	object ob = this_object();
	object ob1, ob2, ob3;
	string msg;
	
	if (!(ob1 = present("shihui", ob)))
		return notify_fail("������ûʯ�ң�����ɶ����\n");

	if (!arg)
		return notify_fail("����Ҫ��ʯ�ҷ۸�ʲô?\n");

	if (arg = "shi song"
	 && ob2 = present("shi song",environment(me))
	 && ob3 = present("mao shiba",environment(me))) {
		if (!me->query_temp("mao18/passed4"))
			return notify_fail("�˼Ҵ���أ���Ϲ���ɶ��\n");
		msg = HIW"$N��$n�������Ӳ������ͳ�ʯ�ҷۣ��͵�����$n���۾���\n"NOR;
		destruct(ob1);
		call_out("do_attack", 1, me, ob2, ob3, msg);
		return 1;
	}
	else
		return notify_fail("ʯ�ҷ�����ܹ�ȥ�����˼ң���\n");
}

int do_attack(object me, object ob2, object ob3, string msg)
{
          ob2 = present("shi song",environment(me));
	if (random(me->query_str()) > 20 && !me->query("fail")) {
		msg += RED"$nļ�ذ�Ӱ�ζ���������ĩ������������һʱ��Ϊ֮�ϣ�����˫\n"+
			"�۾�ʹ��������ö����ͬʱ��һ�㣬�����ſڴ�У������ĩ������ͷ��ס�ˣ�\n"+
			"��Ҳ�в���������\n"NOR;
		msg += CYN"$N���ּ�����ϵ�����˳�ֲ�����$n���С�\n"NOR;
		message_vision(msg, me, ob2);
		ob2->die();
		me->delete_temp("mao18/passed4");
		me->set("mao18/pass",1);
		remove_call_out("do_finish");
		call_out("do_finish", 2, me, ob3);
		return 1;
	}
	else {
		log_file("quest/wuhu",sprintf("%8s%-18s��éʮ�˴�ѧ���廢���ŵ���ʧ�ܣ�����%d��\n",
			me->name(1), "("+capitalize(me->query("id"))+")", me->query("kar") ), me);
		me->set("mao18/fail", 1);
		msg += HIR"˭֪ȴ���˸��գ��Լ�Ҳˤ��һ����\n"NOR;
		message_vision(msg, me, ob2);
		return 1;
	}
}

int do_finish(object me, object ob)
{
	object ob1;
	
	tell_object(me,HIY"éʮ�˵�������Ϊʲô��ʯ��������ʷ�ɵ������������������̬�����׶�\n\n"+
			"    ������ʮ�ֺ��£�����éʮ�˱㽫��ʯ�ҡ����ɺ�ҩ����Щ�����������ݵı����ֶ�\n"+
			"�������㡣�����˵������������һ�����ɵ������ؼ�������ȥ���кú����С�ֻҪ����\n"+
			"��ѧ����������δʼ��������һ������ա����Ǻ�������ˣ���˵��ת����ȥ�ˡ�\n"NOR);
	ob1 = new(SHU);
	ob1->move(me);
	ob1->set_temp("mao18/book",me->query("id"));
	log_file("quest/wuhu",sprintf("%8s%-18s��éʮ�˴�ѧ���廢���ŵ�������%d��\n",
		me->name(1), "("+capitalize(me->query("id"))+")", me->query("kar") ), me);
	if (ob) destruct(ob);
	return 1;
}
