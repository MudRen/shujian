#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include "skill.h";
#include <job_mul.h>

string *k_weapon = ({"sword","blade","staff","whip","gun",});
void create()
{
	string weapon;
	weapon = k_weapon[random(sizeof(k_weapon))];

	set_name("ճ����", ({ "zhan ertie","zhan", "ertie" }));
	set("title","�ɹ� �о�Ԫ˧");
	set("gender", "����");
	set("no_quest",1);
	set("long", "���Ǵ˴θ�������������ɹŴ��ͳ˧��\n");
	set("age", 35);
	set("str", 30);
	set("int",20);
	set("con",30);
	set("dex",20);
	set("combat_exp", 650000+random(350000));
	set("attitude", "friendly");
	set("max_qi",4000);
	set("max_jing",2000);
	set("neili",4000);
	set("max_neili",4000);
	set("qi",4000);
	set("jing",2000);
	set("eff_jingli",2500);
	set("score", 100);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("cuff", 200);
	set_skill("jingang-quan", 200);
	set_skill("parry", 200);
	set_skill("yijin-jing", 200);
	set_skill("shaolin-shenfa", 200);
	set_skill("blade", 200);
	set_skill("xiuluo-dao", 200);
	set_skill("buddhism", 200);
	set_skill("literate", 200);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "xiuluo-dao");
	map_skill("blade", "xiuluo-dao");
	map_skill("cuff", "jingang-quan");
	prepare_skill("cuff", "jingang-quan");

	setup();
        add_money("gold",1);
	carry_object(BINGQI_D("blade"))->wield();
	carry_object(ARMOR_D("armor"))->wear();
}

void die()
{
	object ob = this_object(),me;
	object ob1;

	int i, exp, pot, shen;

	me = ob->query_temp("last_damage_from");

	if(!me)
		return;

	if( objectp(me)
	 && userp(me)
	 && me->query_temp("gb_job3")){
		me->delete_temp("gb_job3");
		me->delete_temp("gb_job3_enter");
		me->apply_condition("gb_job3",-1);
	}
	else {
		::die();
		return;
	}

	i = me->query_temp("kill_zhongjun");
	if ( i > 6) i = 6;

	exp = 200 + i * 80 + random(400);
	
	exp = me->add_exp_combat(exp,"�״��","��ɱ");
	
	pot = exp/5+random(exp/10);
	shen = exp/2 + pot/2;
	
	me->add( "potential", pot );
	if ( me->query("gb_job2")){
		me->add("job_time/��Ч����", me->query("gb_job2"));
		me->delete("gb_job2");
	}
	me->add("job_time/��Ч����",1);
		
	if( me->query("potential") > me->query("max_pot") )
        	me->set("potential",me->query("max_pot"));
	me->add( "shen", shen );

    	message_vision( sprintf(HIW "\n�ã���������ˣ���õ���"
	    	+ CHINESE_D->chinese_number(exp)
        	+ "��ʵս���飬"
        	+ CHINESE_D->chinese_number(pot)
        	+ "��Ǳ�ܺ�"
       		+ CHINESE_D->chinese_number(shen)
	        + "������\n" NOR),me);

	log_file("job/zhongjun", sprintf("%8s%-10s��ɱ��Ԫ˧���񣬾��飺%4d��Ǳ�ܣ�%3d��ɱ�У�%d��Ŀǰ���飺%d��\n",
		me->query("name"), "("+me->query("id")+")", exp,pot, i, me->query("combat_exp") ),me);

	if( ob1 = present( "shiwei 3",environment(me)))
		destruct( ob1 );
	if( ob1 = present( "shiwei 2",environment(me)))
		destruct( ob1 );
	if( ob1 = present( "shiwei",environment(me)))
		destruct( ob1 );

	me->set("job_name","��ɱ��Ԫ˧");
	me->delete_temp("kill_zhongjun");
	message_vision(HIW"\n����Ż��ҳ����Ԫ����Ӫ��\n"NOR,me);
	me->move("/d/xiangyang/xuanwumen");
	::die();

}

void kill_ob(object ob)
{
	if( present("zhongjun shiwei",environment(ob))){
	    	ob->remove_killer(this_object());
    		remove_killer(ob);
	    	message_vision(CYN"ճ�������������������ģ�����Ҫ�д̱�˧��\n"NOR, ob);
    		return;
	}
	::kill_ob(ob);
}
