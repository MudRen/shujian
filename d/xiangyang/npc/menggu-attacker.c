// Modify By action@SJ 2008/12/5

#include <ansi.h>

inherit FIGHTER;

inherit F_UNIQUE;
inherit F_SAVE;

void create()
{ 
	set_name( "蒙古勇士" , ({"menggu yongshi", "yong shi", "yongshi"}));
	set("title", HIB "蒙古大军" NOR);
	set("init",0);

	set("gender", "男性");
	set("age", 20 + random(60));
	set("long", "这是蒙古身经百战的蒙古勇士。\n" );
	if( random(20) < 1 )
		set("double_attack",1);

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("eff_jingli", 10000);
	set("combat_exp", 2000000);
	set("score", 20000);
	set("jiali",10);
	set("no_get",1);
	set("no_quest", 1);
	set_skill("wuxing-zhen",200);
	
        setup();
}

void init()
{
	object me,ob,cloth;
	int lvl;
	int index;
	object *lineup;

	::init();
	me = this_player();
	ob = this_object();

	if( query("init") == 0
	 && me->query_temp("xykm_job")
	 && userp(me) ) {
	 	
	 	set("init", 1);
	 	
		if( me->query_temp("xykm_job/lvl")){
			lvl = me->query_temp("xykm_job/lvl");
		}
				
		else {
			if(!me->query_lineup()){
				lvl = me->query("max_pot");
			}
			else {
				lineup = me->query_lineup();
				lvl = 0;
				for(index=0;index<sizeof(lineup);index++){
					if( lineup[index]->query("max_pot") > lvl )
						lvl = lineup[index]->query("max_pot");
				}
			}
			lvl = lvl - 105 + random(5);
		}
		
		lvl += me->query_temp("xykm_job/finish")*5;
		
		setparty(me->query_temp("xykm_job/finish"),lvl,lvl*lvl*lvl/10*8/5 );

		set("ciwei_level",me->query_temp("xykm_job/finish"));
				
		set_name( "蒙古勇士" , ({"menggu yongshi", "yong shi", "yongshi"}));
	  set("title", HIB "蒙古大军" NOR);	
		
		set("max_neili",query_skill("force")*8 + query("combat_exp")/1000);
		set("max_jingli",query_skill("force")*8);
		set("eff_jingli",query_skill("force")*8);

		copy_state();
		setup();
		reincarnate();
								
		cloth = new(ARMOR_D("cloth"));
		cloth->set("name",HIB"蒙古战袍"NOR);
		cloth->move(ob);
		cloth->wear();
		add_money("silver", 20+random(30));
		
		if(me->query_temp("xykm_job/finish")>4) add_money("gold", 1+random(3));
		
		set("neili",query("max_neili")* 2);
		
		call_out("check",1,ob,me);
		if(!me->query_lineup()) {
			ob->kill_ob(me);
		}
		else {
			lineup = me->query_lineup();
				for(index=0;index<sizeof(lineup);index++){
					if( present(lineup[index]->query("id"),environment(me) ))
						ob->kill_ob(lineup[index]);
				}
		}
	}
}

void check(object ob, object me)
{
	if( !ob ) return;
		
	checking(ob,me);
	
	command("lineup with menggu yongshi 1");
	command("lineup with menggu yongshi 2");
	command("lineup with menggu yongshi 3");
	command("lineup with menggu yongshi 4");
	command("lineup with menggu yongshi 5");
	command("lineup form wuxing-zhen");
	command("lineup with menggu yongshi 1");
	command("lineup with menggu yongshi 2");
	command("lineup with menggu yongshi 3");
	command("lineup with menggu yongshi 4");
	command("lineup with menggu yongshi 5");
					
	if( !me
	 || !me->query_temp("xykm_job")
	 || me->query("qi")<1000
	 || environment(me)!=environment(ob)){
		tell_room(environment(ob), "蒙古勇士说：终于攻下了襄阳城玄武门，马上派人通知陛下。\n");
		me->delete_temp("xykm_job");
		me->apply_condition("job_busy",20+random(20));
		me->apply_condition("xykm_job",0);
		destruct(ob);
		return;
	}
	call_out("check",1,ob,me);
}

void unconcious()
{
	object ob = this_object(),me;
	me = ob->query_temp("last_damage_from");
	if(!me || !objectp(me)){
		::unconcious();
		return;
	}
	if( userp(me)
	 && !me->query_temp("xykm_job")
	 && !me->query_lineup()
	 && me->query("combat_exp") > ob->query("cobmat_exp")/2 ){
	 	
	 	me->add_condition("killer", 5);
	 	
		reincarnate();
		set("eff_qi", query("max_qi")*2);
		set("qi", query("max_qi")*2);
		set("eff_jing", query("max_jing"));
		set("jing", query("max_jing"));
		set("jingli", query("eff_jingli"));
		set("neili",query("max_neili")*3/2);
		return;
	}
	::unconcious();
	return;
}

void die()
{
	object me, ob;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

	if(!objectp(me)){
		::die();
		return;
	}
	if( userp(me)
	 && !me->query_temp("xykm_job")
	 && !me->query_lineup()
	 && me->query("combat_exp") > ob->query("combat_exp")/2 ){
	 	me->add_condition("killer", 5);
		new(__DIR__"menggu-attacker")->move(environment(me));
	}
	::die();
}
