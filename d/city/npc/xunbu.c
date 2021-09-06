// xunbu.c Ѳ��

#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
	set_name("��Ѳ��", ({ "zhang xunbu", "xun bu", "xunbu", "zhang"}));
	set("title", "��͢����Ʒ��ͷ");
	set("gender", "����");
	set("age", random(20) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("blade",200);
	set_skill("force", 200);
	set_skill("claw", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("literate", 150);
	set_skill("liuhe-daofa", 200);
	set_skill("tianwang-zhua", 200);
	set_skill("tiyunzong", 200);
	set_skill("huntian-qigong", 200);

	map_skill("force", "huntian-qigong");
	map_skill("parry","tianwang-zhua");
	map_skill("dodge","tiyunzong");
	map_skill("claw","tianwang-zhua");
	map_skill("blade","liuhe-daofa");
	prepare_skill("claw", "tianwang-zhua");

	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 50);

	set("max_qi", 2500);
	set("eff_jingli", 2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("inquiry", ([
		"ͨ����"  : (: ask_me :),
	]));

	setup();
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("ruanxue2"))->wear();
	carry_object(ARMOR_D("armor"))->wear();
	if (clonep()) call_out("randommove", 10);
}

void init()
{
	object ob;

	ob = this_player();
        if (interactive(ob)
        && !environment(ob)->query("no_fight")
        && !ob->query_condition("pk") // ciwei add it 
        && userp(ob)
        && !ob->query_temp("armor/cloth")){
                        message_vision(CYN "$N����$n���˼��۾���ͻȻһ�°�$n��ס��\n" NOR, this_object(),ob);
                        if (!ob->is_busy())
                        	ob->start_busy(1);
                        ob->add_temp("nude",1);
                        switch ((int)ob->query_temp("nude"))
		       	{
		       		case 1:
		       			command("say ���ڳ��ϣ������·�����ʲô���Ӱ����´�ע��Ŷ��\n");
		       			command("rumor ���˿���" + ob->query("name") + "�ڴ�����㱼Ŷ��");
		       		break;
		       		case 2:
		       			command("say ���ڳ��ϣ������·�����ʲô���Ӱ����ϴθպ���˵�����㵱�һ��Ƕ��߷簡��\n");
		       		break;
		       		case 3:
		       			command("say ���ڳ��ϣ��ǵô��·�����Ȼ�����Ĳ�����Ҳû��Ҫ�����ַ�ʽչʾ�ɡ�\n");
		       		break;
		       		case 4:
		       			command("say ���ڳ��ϣ��ǵô��·�����Ȼ���ϴ�˵�����Ĳ����࿴������˵Ҳû��˼���»�ע���ˡ�\n");
		       		break;
		       		case 5:
		       			command("say ����ҩ�ɾ��ˣ��ڲ����·������Ҵܣ��ҿ�Ҫ��ȡ��ʩ��Ŷ��\n");
		       		break;
/*
		       		case 6:
		       			command("say ����Ȩ���ֳ�Ĭ����������˵��һ�ж�����Ϊ�������������ݡ������ڡ���������ͷ��ʽ���˺��绯������㡣\n");
		       			command("rumor " + ob->query("name") + "��Ϊ�Ŵ��ڴ�����㱼������Ѳ�����˺��绯�������");
		                        ob->add_busy(1);
		                        ob->move("/d/city/laofang2");
                			ob->set("eff_jing",1);
*/
		       	}
                
        }
	
	if (!ob->query_condition("killer")) {
		if (query_leader() == ob)
			set_leader(0);
		if (!ob->is_killing(query("id")))
			remove_killer(ob);
	}

	::init();
	if( ob->query_condition("killer") && userp(ob) ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob)
{
	object me;

	me=this_object();
	if (is_fighting()) return;
	if (wizardp(ob)) return;
	if(interactive(ob) && !ob->is_fighting() && ob->query_condition("killer"))
	{
		me->set("killer_name",ob->query("name"));
	    	call_out("do_kill", 0, me, ob);
	}
}

int do_kill(object me,object ob)
{
	if(me->is_fighting()) return 0;
	if (wizardp(ob)) return 0;
	if( objectp(ob) && present(ob, environment(me))
		 && !environment(me)->query("no_fight"))
	{	if (!me->query_temp("marks/ɱ1")){
			command("look "+ob->query("id"));
			message_vision(CYN "$N��$n˵����ɱ���ˣ���Ҫ������"
				+RANK_D->query_rude(ob)+"����Ͽ������ɣ�\n" NOR, me,ob);
			me->set_temp("marks/ɱ1",1);
		}
		me->set_leader(ob);
		me->kill_ob(ob);
		call_out("checking", 0,  me);
	}

	else
		call_out("waiting", 1, me);
	return 1;
}

int waiting(object me)
{
	object ob;

	if ( objectp(ob) ){
		if (ob->is_ghost()){
			me->delete_temp("marks/ɱ1");
			call_out("do_back", 1, me);
			return 1;
		}
		else if (me->is_fighting() && present(ob, environment(me))) {
			call_out("checking", 0, me);
			return 1;
		}
	}

	remove_call_out("waiting");
	call_out("waiting", 60, me);
	return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()){
		call_out("checking", 1, me);
		return 1;
	}
	if( objectp(ob = present("corpse", environment(me)))
	&&ob->query("victim_name") ==me->query("killer_name") ) {
		command("say ��������ɱ��һ��ͨ����������ѽ�������Ȼ�ȥ����ɡ�");
		me->delete("killer_name");
		this_object()->delete_temp("marks/ɱ1");
		call_out("do_back", 1, me);
		return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{
	me=this_object();
	message("vision", "Ѳ��ɱ�����ڵ��뿪�ˡ�\n",
		environment(), me );
	me->move("/d/city/guangchang");
	message("vision", "Ѳ��ɱ�����ڵ����˹�����\n",
		environment(), me );

	me->set_leader(0);
	return 1;
}

void randommove()
{
	call_out("randommove", 10);
	if (living(this_object()) && !is_fighting()) random_move();
}

string ask_me()
{
	object ob=this_player();
	if(ob->query_condition("killer")>0)
		return "�ߣ�ͨ�������������ѣ��㻹�ǹԹԵ������ɣ�";
	if(ob->query("shen")<=-100){
		write("Ѳ���������㿴����֪����Щʲô���⡣\n");
		return RANK_D->query_respect(this_player()) +
		"���ܶԲ��𣬲��ܸ����㣬�����ҿ������ӵ�����ͨ������";
	}
	if(ob->query("shen")>-100){
		write("Ѳ������������ĵ�˵����"+FINGER_D->get_killer());
		message("vision","Ѳ�����ĵ���"+ob->name()+"����˵�˼��仰��\n",
			environment(ob), ({ob}) );
		return "���ӷ�����������ͬ�ɱ���ˣ���Ҫ������";
	}
}
