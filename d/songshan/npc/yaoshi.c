// yaoshi.c ҩʦ
// Created by Numa 1999-12-16

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string do_heal();
int do_give();

void create()
{
	set_name("ҩʦ", ({ "yao shi", "yao", "shi" }) );
	set("gender", "����" );
	set("age", 40);
	set("long","����һλ�곤������,��ҽ���൱��ͨ��\n");
	set("combat_exp", 100000);
	set("unique", 1); 
	set("no_get","ҩʦ�������̫���ˡ�\n");
        set("attitude", "peaceful");
	create_family("��ɽ��", 6, "����");

	set("vendor_goods", ({
		([ "name":MEDICINE_D("huiyang"), "number":3 ]),
		([ "name":MEDICINE_D("jinchuang"), "number":5 ])
	}));

	set("inquiry", ([
		"name":	"�ҵ�ҽ��������һ�����ġ�",
		"����":	(: do_heal :),
		"��ҩ": (: do_give :),
	]));
	set("have_dan",5);
	setup();
	carry_object(ARMOR_D("changpao1"))->wear();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment()) return;
	command("say ��λ"+RANK_D->query_respect(ob)+"���ˣ�����Ҫ��Щʲôҩ��");
}

string do_heal()
{
	object me = this_player();
	object ob = this_object();
//	int hurt;

	if (!me->query_temp("ss/ready_heal"))
		return "��λ"+ RANK_D->query_respect(me) +"�����ܵ���˼��˼�ɣ�";

	if (ob->query_temp("busy"))
		return "��λ"+ RANK_D->query_respect(me) +"������æ���أ�";

/*
	if (ob->query_temp("last") == me->query("id"))
		return "��λ"+ RANK_D->query_respect(me) +"���Ҹո������ƹ������ٵȵȰɣ�";
*/

//	hurt = me->query("max_qi") / me->query("eff_qi");

	if (me->query("eff_qi") >= me->query("max_qi"))
		return "��λ"+ RANK_D->query_respect(me) +"�������ûʲô�˰ɣ�";

	if (me->query("eff_qi")+me->query_temp("apply/qi") < (me->query("max_qi") + me->query_temp("apply/qi")) / 4)
		return "��λ"+ RANK_D->query_respect(me) +"�������ƹ��أ�����ȥ׼�����°ɣ�";

	me->delete_temp("ss/ready_heal");
	ob->set_temp("last",me->query("id"));
	ob->set_temp("busy",1);
	command("nod");
	message_vision(HIR"\n$n���˰�����Ѹ�ٵĵ���$N����ļ�����Ѩ��������˫�Ƶ���$N���Ĵ���������\n"NOR,me,ob);
	message_vision(HIW"ֻ��$N��Ѫ����ֹס������Ҳ��Ϊ��ת��\n"NOR,me,ob);
	me->set("eff_qi", me->query("max_qi"));
//	ob->receive_curing("qi", 100+random(500-hurt));
	remove_call_out("finish");
	call_out("finish", 20, ob);
	return "�������ˣ����Լ���ȥ�����°ɡ�";
}

int finish(object ob)
{
	if (!ob)
		return 1;
	ob->delete_temp("busy");
	return 1;
}

int accept_object(object who, object ob)
{
	int hurt;
	
	if (!who->query("family") || who->query("family/family_name") != "��ɽ��") {
		command("say ��λ"+ RANK_D->query_respect(who) +"�����������ɲ�û��ʲô�����ɣ�");
		return 0;
	}
	if (ob->query("money_id")) {
		hurt = (who->query("eff_qi")/who->query("max_qi"))*10;
		hurt = 10-hurt;
		if ( hurt < 1) hurt = 1;
		if (ob->value() >= hurt*10000) {
			command("hehe");
			command("say ��λ"+ RANK_D->query_respect(who) +"����׼���ã�������������(Ask shi about ����)��");
			who->set_temp("ss/ready_heal",1);
			return 1;
		}
		else {
			command("hmm " + who->query("id"));
			command("say ��λ"+ RANK_D->query_respect(who) +"�����Ҳ̫���˰ɣ���");
			return 0;
		}
	}
	else {
		command("say ����ʲô�������⣬�㻹���Լ����Űɣ�");
		return 0;
	}
}

int do_give()
{
	object me = this_object();
	object ob = this_player();
	object obj;
	
	if (!ob->query("family") || ob->query("family/family_name") != "��ɽ��") {
		command("say ��λ"+ RANK_D->query_respect(ob) +"�����������ɲ�û��ʲô�����ɣ�");
		return 1;
	}
/*
	if (!ob->query_temp("ss/give_dan")) {
		command("shake");
		command("say δ�������������ҿɲ������Խ���ҩ�����㣡");
		return 1;
	}
*/
	if (ob->query_condition("medicine")) {
		command("say ��λ"+ RANK_D->query_respect(ob) +"����ճԹ���ҩ�������ٵȵȰɣ�");
		return 1;
	}
	
	if (!me->query("have_dan") < 1) {
		me->set("have_dan",0);
		command("say ��ҩ�Ѿ������ˡ�");
		return 1;
	}
	
	if (!(obj=load_object("/clone/medicine/songyang-dan"))) {
		command("say ��λ"+ RANK_D->query_respect(ob) +"����ҩ��û�����Ƴ�����");
		return 1;
	}
	
	message_vision("$n�ݸ�$Nһ����������\n",ob,me);
	obj->move(ob);
	message_vision("$n����$N˵���������������ɽ����ҩ������ҪС��ʹ�ã�\n",ob,me);
	me->add("have_dan",-1);
	return 1;
}
