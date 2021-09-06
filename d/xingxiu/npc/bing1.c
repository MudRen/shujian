// bing.c �ٱ�
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�߷��ٱ�", ({ "guan bing", "bing" }));
        set("age", 32);
        set("gender", "����");
        set("long", "���Ǹ�����פ������ı߷�����\n");
        set("attitude", "peaceful");
        set("str", 33);
        set("int", 16);
        set("con", 25);
        set("dex", 20);
        set("combat_exp", 30000);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);        
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("junfu"))->wear();
}

int accept_fight(object me)
{
	command("say ��ү���ر߹��۵�Ҫ����û�պ�"+RANK_D->query_respect(me)+"�����档\n");
	return 0;
}

void init()
{
	object ob, me, money;
	::init();

	me=this_object();

	if(interactive(ob = this_player()) && living(this_object()))
	if((int)ob->query_condition("killer") || ob->query_temp("xx_rob")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 0, ob);
	}
	else if(random(50) <=1 && file_name(environment(me)) == me->query("startroom")){
		command("say ���"+RANK_D->query_rude(ob)+"����վס�����м�飡");
		if(ob->query("guanbing")){
			ob->add("guanbing", -1);
			message_vision(HIY"$n����$N���˰��죬�������������$N���ߡ�\n"NOR, ob, me);
			return;
		}
		message_vision(HIY"$n��$N��ס����$N���������˰��졣\n"NOR, ob, me);
		ob->start_busy(5);
		if(money = present("gold_money", ob)){
			money->move(me);
			ob->add("guanbing", 2);
			tell_object(ob, HIR "����㷢�ֱ߷��ٱ��������ϵĻƽ������ˣ�\n"NOR);
		}
		else if(money = present("silver_money", ob)){
			money->move(me);
			ob->add("guanbing", 1);
			tell_object(ob, HIR "����㷢�ֱ߷��ٱ��������ϵİ��������ˣ�\n"NOR);
		}
		else command("say �������⵰��������ˮ��û�У����ҹ���");
		command("kick "+ ob->query("id"));                
	}
}
