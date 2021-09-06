// /clone/npc/xu.c
// by snowman 12.feb.98
// Lklv modify 2001.7.27

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ϼ��", ({ "xu xiake", "xu", "xiake" }) );
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 35);
	set("str", 15);
	set("con", 15);
	set("int", 27);
	set("dex", 20);
	set("env/wimpy", 110);
	set("long", "��λ�����α�ǧɽ��ˮ��̤�����ϱ�����ʿ��ϼ�͡�\n" );
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("max_qi", 200);
	set("max_jing", 200);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set("inquiry", ([
		"��ϼ���μ�" : "�������߱�ǧɽ��ˮ��д�ɵ��μǡ�\n",
		"����" : "��Ҳ���ȥ�������ðɣ�����һ���ƽ��Ҿʹ������ߡ�\n",
	]));

	set("chat_chance", 3);
	set("chat_msg", ({
		(: random_move :),
		CYN"��ϼ��ҡͷ���Եؽ������㿴����ϱ��õط����治�٣�\n"NOR,
		CYN"��ϼ�͵����뵱�����߱���ɽ����������ɽ������ɽ���䵱ɽ������\n"NOR,
		(: random_move :),
		CYN"��ϼ����˵�������Ͻ�����Ǻ������������С��ȴ�����ǽ������ݡ�����һ��������\n"NOR,
		(: random_move :),
		CYN"��ϼ��¶���־�ı��飺ȥ���޺��������������Ʒ嶼��������ͽ������\n"NOR,
		CYN"��ϼ���������Դ����ϴ�ȥ������������˵�����и��һ����ɾ�����֪�����Ǽ١�\n"NOR,
		(: random_move :),
	}) );
	setup();
	carry_object(ARMOR_D("ruanxue2"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
	carry_object("/clone/book/xu-book");
}

void init()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	::init();
	if(ob->query_temp("money_paid"))
		ob->delete_temp("money_paid");
//	add_action("do_go","ȥ");
}

int do_go(string target)
{
	object ob1,me;
	ob1=this_object();
	me=this_player();

	if (me->is_busy())
		return notify_fail("����æ���ء�\n");

	message_vision(CYN"$N����ϼ��˵��������������ȥ" + target +"��\n"NOR,me);
	if( !this_player()->query_temp("money_paid") )
		return notify_fail("��ϼ��ҡ��ҡͷ�����䲻�������ˣ���ûǮ��ô�߰���\n");
	if( !target || target==" ")
		return notify_fail("��ϼ��������ü���ǵط��ҿ�ûȥ����\n");

	if (target=="�ؽ�") me->set_temp("go_hj", 1);
	if (target=="����" || target=="���޺�") me->set_temp("go_xx", 1);
	if (target=="����" || target=="�����") me->set_temp("go_yili", 1);
	if (target=="����" || target=="������" || target=="��ɽ������" || target == "��ɽ") me->set_temp("go_sl", 1);
	if (target=="�䵱" || target=="�䵱ɽ") me->set_temp("go_wd", 1);
	if (target=="����" || target=="���ݳ�") me->set_temp("go_yz", 1);

//	if (target=="����" || target=="�����") me->set_temp("go_dali", 1);
//	if (target=="����" || target=="����ɽ") me->set_temp("go_kl", 1);
//	if (target=="���ư�" || target=="���Ʒ�" || target=="��צɽ") me->set_temp("go_tzb", 1);
	if (target=="�һ���" || target=="�������") me->set_temp("go_thd", 1);

	if (target=="����" || target=="������") me->set_temp("go_mj", 1);
	if (target=="����" || target=="���ݳ�") me->set_temp("go_sz", 1);
	if (target=="����ɽ" || target=="ȫ���") me->set_temp("go_zns", 1);
	if (target=="����" || target=="���ݳ�") me->set_temp("go_hz", 1);

	else return notify_fail("��ϼ��������ü���ǵط��ҿ�ûȥ����\n");
	call_out("do_goto", 0, me);
	return 1;
}

void do_goto()
{
	object me, ob;
	me = this_player();
	ob = this_object();
	command("nod");
	command("say ����͸������߰ɡ�");
	message_vision("\n$n����$N��ʼ���������ó̡�\n" NOR, ob, me);
	me->move("/d/wizard/room3");
	me->delete_temp("money_paid");
	destruct(this_object());
}
/*
int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 2000) {
		message_vision("��ϼ�Ͷ�$NһЦ����Ҫ����ȥ����ѽ��˵�ɡ�\n", who);
		tell_object(who, "����룺ȥ �ط���������\n");
		who->set_temp("money_paid",1);
		return 1;
	}
	else if (ob->query("money_id") && ob->value() < 2000) {
		tell_object(who, "��ϼ�Ͷ�����ҡ��ҡͷ��\n");
		return 1;
	}
	return 0;
}
*/
