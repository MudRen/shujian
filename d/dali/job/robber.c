// Modify By River@SJ

inherit FIGHTER;
#include <ansi.h>

void do_kill(object ob);

string *color_title = ({"��ɱ��", "��ɷ��"});

void create()
{
        int i;

	i = random(4);
	set_name("������",({"wuming shi"}));
		
	set("gender", i?"����":"Ů��");
	set("long", "��������ɫ��װ����������һ��ڲ���ֻ¶��һ˫�۾����������䡣\n");
	set("title", color_title[random(sizeof(color_title))]+(i?"":"Ů")+"ɱ��");
	set("age", 20 + random(50));
	
	set("combat_exp", 8000000);
	set("meitude", "peaceful");
	set("str", 25);
	set("dex", 30);
	set("int", 30);
	set("con", 30);
	set("max_qi", 20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("no_heal",1);
	set("no_ansuan",1);
    	set("no_bark", 1);

	setup();

	if (!random(3))
		add_money("silver", random(10)+10);
	carry_object("/d/dali/obj/blackcloth")->wear();
}
void init()
{
	object me, ob;
	string t_name;
	
	::init();

	ob = this_player();
	me = this_object();
	if (ob != query("target")) return;
	t_name = ob->query("name");       
	
	if (interactive(ob)
	 && ob->query_temp("songxin_ok")
	 && me->query_temp("zuji_target")==t_name) {
		call_out("dest",1, ob);
		return;
	}

	if (environment(ob)->query("no_fight")
	 && me->query_temp("zuji_target")==t_name
	 && ob->query_temp("songxin_zuji")) {
		remove_call_out("dest");
		call_out("dest2",1, ob);
		return;
	}

	if (interactive(ob) 
	 && !environment(ob)->query("no_fight")
	 && ob->query_temp("songxin_zuji")
	 && (!me->query_temp("songxin_zuji1")||!(me->query_temp("zuji_target")!=t_name))){
		//me->set_temp("apply/attack",  random(30));
		//me->set_temp("apply/dodge",  50 + random(100));
		me->set_temp("songxin_zuji1",  1);
		if (!me->query_temp("zuji_target")) me->set_temp("zuji_target",t_name);
		if (!me->query_temp("skill_set")) {
			command("say �����������������϶����ˣ�����");
			me->set_temp("skill_set",1);
			ob->set_temp("zuji",1);
//                        me->set_leader(ob);
			remove_call_out("dest");
			call_out("dest",300,ob);
			remove_call_out("do_kill");
			call_out("do_kill", 0, ob); 
		}
		else {
                        command("say Kao������׷��������һ����ɣ�������");
//                        me->set_leader(ob);                     
			remove_call_out("dest");
			call_out("dest",300,ob);
			remove_call_out("do_kill");
			call_out("do_kill", 0, ob); 
		}
	}
}
int checking(object me, object ob)
{
	int ret =  ::checking(me,ob);
	if(!ret) return 0;
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	if(!living(ob)){
		remove_call_out("checking");
		ob->set("qi",100);																			//��ֹ�����������
		ob->set("jing",100);
		ob->set("jingli",100);
		tell_room(environment(me), "\n"+me->query("name")+"��һ����������Ҳ�õ����ˣ�����Ͳ�ɱ���ˣ�˵��ת��������Ͳ����ˡ�\n");
		destruct(me);
		 return 1;
	}
}
/*void heart_beat()
{
	object target = query("target");
	object env;

	::heart_beat();
	if (target && !present(target) && (env = environment(target))
	&& !is_fighting() && !is_busy()
	&& !target->is_ghost() && living(this_object()))
		move(env);
}*/


void dest(object ob)
{
	if (ob) {
		tell_object(ob, query("name")+"���������������\n");
		tell_object(ob, query("name")+"�Ҵ��뿪��\n");
	}
	destruct(this_object());
}

void dest2(object ob)
{
	if (ob) {
		tell_object(ob, query("name")+"�������ù���һ�㲻��ʮ�壬���ǻ������ģ�\n");
		tell_object(ob, query("name")+"�Ҵ��뿪��\n");
		ob->delete_temp("songxin_zuji");
	}
	destruct(this_object());
}
void do_kill(object ob)
{
	object me = this_object();

	if (query("target")!=ob) {
		remove_killer(ob);
		ob->remove_killer(me);
		ob->add_busy(1);
		return;
	}
	remove_call_out("checking");
	call_out("checking", 2, me, ob);
	::do_kill(ob);
}
