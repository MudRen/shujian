// supu.c ����
// Lklv 2001.9.27 update

#include <ansi.h>
inherit NPC;
int ask_me();

string* goods = ({
       "/d/hj/obj/yangpi",
       BINGQI_D("wandao"),
       BINGQI_D("bishou"),
       "/d/hj/obj/jiunang",
});

void create()
{
	set_name("����", ({ "su pu", "supu", "su"}));
	set("gender", "����");
	set("age", 21);
	set("long", "һ������Ĺ�����������, �����˵�һ��ʿ��³�˵Ķ��ӡ�\n");
	set("attitude", "heroism");
	set("unique", 1);
	set("combat_exp", 70000);
	set("shen", 3000);
	set("str", 32);
	set("int", 20);
	set("con", 24);
	set("dex", 20);
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 400);
	set("max_neili", 400);
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set("inquiry", ([
		"����" : "�������ҵ������ˣ���ÿ��ɱ��Ұ�Ƕ���������Ƥ��\n",
		"������" : "���ĸ質����������ˣ�����˵���������񳪵û��á�\n"+
			"���⼸��������һֱû���������裬һֱû�ڼ�������\n",
		"ˤ��" : (: ask_me :),
		"����" : (: ask_me :),
		"������" : "���Ǽ�үү�����������������ҵ����ƣ���ҽţ����ƥ�ļ�����\n",
		"��³��" : "�����Ұ������ǹ�������ĵ�һ��ʿ��������\n",
	]) );
	setup();
	set("chat_chance", 3);
	set("chat_msg", ({
		"�����Ժ����µ�: ��ҲҪѧ�Ұ�����Ϊ�����˵�һ��ʿ��\n",
		"������������: ���Ķ�ȥŪһ���ϵȵ���Ƥ���͸�������? \n",
	}) );
	carry_object(BINGQI_D("wandao"))->wield();
	carry_object(ARMOR_D("yangao"))->wear();
	carry_object("/d/hj/obj/jiunang");
}

int ask_me()
{
	if ((int)this_player()->query_temp("supu_fight")) {
		command("say ���ǲ��Ǳ��Թ�����");
		return 1;
	}
	if (!this_player()->query_temp("supu_accept")) {
		command("say ��ƾʲô���ұ����أ�");
		return 1;
	}
	else {
	message_vision(CYN"$N����$nһ�ۣ��ò�̫��׼�ĺ���˵��������δ���Ĳ�ԭ��һ��ʿ����λ����"+RANK_D->query_respect(this_player())+"��ͺ����д�(fight)���°ɣ�\n"NOR, this_object(), this_player());
	this_player()->set_temp("supu1", 1);
	return 1;
	}
}

int accept_fight(object ob)
{
	object me;
	me = this_object();
	if(me->query("eff_qi") < me->query("max_qi") ||
	   me->query("qi") < me->query("eff_qi") ||
	   me->query("neili") < me->query("max_neili")){
	   message_vision(CYN"$N��$n˵���һ�û����Ϣ�ã����һ����ɡ�\n"NOR, ob, me);
	   return 0;
	   }
	if( ob->query_temp("supu1") ) {
	message_vision(CYN"$N��$n˵���ðɣ����Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n"NOR, ob, me);
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("supu1");
	ob->delete_temp("supu_accept");
	return 1;
	}
	else return 0;
}

int checking(object me, object ob)
{
	object good;
	int my_max_qi, his_max_qi;
	my_max_qi  = (int)me->query("max_qi");
	his_max_qi = (int)ob->query("max_qi");
	if (me->is_fighting()){
		call_out("checking",1, me, ob);
		return 1;
	}
	if ( !present(ob, environment()) ) return 1;
	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) {
	    message_vision(CYN"$N��$n��ס����̾�����Ǻ��˹�Ȼ��һ�㣬�ҷ����ˣ�����һЩ���\n"NOR, me, ob);
	    if( random(10)> 5){
	     good =unew("/d/hj/obj/shoujuan");
	     if(!clonep(good)){
		good = new(goods[random(sizeof(goods))]);
		good->move(ob);
		ob->set_temp("supu_fight", 1);
		message_vision("$N����$nһ"+good->query("unit")+good->query("name")+"��\n", me,ob);
		return 1;
	     }
	     if(clonep(good) && good->violate_unique()){
		destruct(good);
		good = new(goods[random(sizeof(goods))]);
		good->move(ob);
		ob->set_temp("supu_fight", 1);
		message_vision("$N����$nһ"+good->query("unit")+good->query("name")+"��\n", me,ob);
		return 1;
	     }
	     good->move(ob);
	     ob->set_temp("supu_fight", 1);
	     message_vision("$N����$nһ"+good->query("unit")+good->query("name")+"��\n", me,ob);
	     return 1;
	    }
	    else good = new(goods[random(sizeof(goods))]);
	    good->move(ob);
	    ob->set_temp("supu_fight", 1);
	    message_vision("$N����$nһ"+good->query("unit")+good->query("name")+"��\n", me,ob);
	    return 1;
	}
	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ){
		message_vision(CYN"$N����$nһƲ�죬˵�������Ǻ��˵���ѧ������ˡ�\n"NOR, me,ob);
		message_vision("$N��$n���˸��񣬴�ͷɥ�����뿪�����\n",ob, me);
		ob->move("/d/entry/hjroad");
		message_vision("$N��ͷɥ�����߻�����\n", ob);
		return 1;
	}
	return 1;
}

int accept_object(object who, object ob)
{
	if( !who || environment(who) != environment() ) {return 0;}
	if ( !objectp(ob) ) {return 0; }
	if ( !present(ob, who) ) return notify_fail("��û�����������\n");
	if (userp(ob)) {
	       command("? " + who->query("id"));
	       command("say ���⺺��ǿ�������˴������ʲô��");
	       this_object()->kill_ob(who);
	       return notify_fail("��⣬�����ˣ�\n");
	}
	if ((string)ob->query("name") != "����Ƥ"){
	       command("smile "+ (string)who->query("id"));
	       command("say лл������");
	       return 0;
	}
	command("ah "+(string)who->query("id"));
	command("say ��ɱ���˴���ǣ�������Ҳ�Ǹ���ʿ��Ҫ��Ҫ����"HIY"����"CYN"һ�£�\n"NOR);
	who->set_temp("supu_accept", 1);
	call_out("destroying", 1, ob);
	return 1;
}

void destroying(object ob)
{
	if (!ob) return;
	if (userp(ob)) command("drop "+ob->parse_command_id_list()[0]);
	else destruct(ob);
}
