// gf_wanted_npc.c
// By snowman@SJ 10/06/2000

#include <ansi.h> 
#include <guanfu.h>

inherit NPC;

int d_time;

void create()
{
	mapping name;
	int i;
	
	i = random(4);
	name = RNAME_D->get_random_name(i);
	
	set_name(name["name"], name["id"]);
	set("gender", (i==0?"Ů��":"����"));
	set("age", 18+random(40));
	set("attitude", "killer");
	set("no_quest",1);
	set("shen", -1000);
	set("str", 26 + i);
	set("int", 18 + i);
	set("con", 25 + i);
	set("dex", 24 + i);
set("no_party_job",1);
	set("max_qi", 1500 + (200 * (1+i)));
	set("max_jing", 1300 + (200 * (1+i)));
	set("jiali", 20 + (15 * (1+i)));
	set("combat_exp", 100000 + (100000 * (i))); 
	set("chat_chance", 40);
     	set("chat_msg", ({ (: random_move :), }));
        set_skill("force", 100 + (10 * (1+i)));
        set_skill("huagong-dafa", 100 + (10 * (1+i)));
        set_skill("dodge", 100 + (10 * (1+i)));
        set_skill("shaolin-shenfa", 100 + (10 * (1+i)));
        set_skill("strike", 100 + (10 * (1+i)));
        set_skill("sword", 100 + (10 * (1+i)));
        set_skill("parry", 100 + (10 * (1+i)));
        set_skill("huashan-jianfa", 100 + (10 * (1+i)));
        set_skill("kunlun-zhang", 100 + (10 * (1+i)));
        set_skill("literate", 100);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("strike", "kunlun-zhang");
  	map_skill("parry", "huashan-jianfa");
        prepare_skill("strike", "kunlun-zhang"); 
 	set_temp("apply/armor", 30);
 	set_temp("apply/parry", 10);
        setup(); 
        if( clonep() ){
        	carry_object((i==0?ARMOR_D("buqun"):ARMOR_D("pao4")))->wear();
        	carry_object(BINGQI_D("changjian"));
  		add_money("silver", random(50));
  		call_out("dest", 600+random(1200), this_object());
  		d_time = 3;
  	}
}


void copy_random_player(object *all)
{
	object weapon, ob, me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i;
	
	if ( !sizeof(all) || sizeof(all) < 1 || !clonep(this_object()) ) return;
	ob = all[random(sizeof(all))];
	if ( !ob ) ob = all[random(sizeof(all))];
	if ( !ob ) {
		command("wield all");
		return;
	}
	
	if( query("combat_exp") > ob->query("combat_exp") )
		return;
	
	set("player_ob", ob->query("id"));
	me = this_object();
		
	if ( mapp(skill_status = query_skills()) ) {
                sname  = keys(skill_status);
                i = sizeof(sname);
                while (i--) delete_skill(sname[i]);
        }

        if ( mapp(skill_status = ob->query_skills()) ) {
                sname  = keys(skill_status);
                i = sizeof(sname);
                while (i--) set_skill(sname[i], skill_status[sname[i]]);
        }

        if ( mapp(map_status = query_skill_map()) ) {
                mname  = keys(map_status);
                i = sizeof(mname);
                while (i--) map_skill(mname[i]);
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);
                i = sizeof(mname);
                while (i--) map_skill(mname[i], map_status[mname[i]]);
        }

        if ( mapp(prepare_status = query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                i = sizeof(pname);
                while (i--) prepare_skill(pname[i]);
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                i = sizeof(pname);
                while (i--) prepare_skill(pname[i], prepare_status[pname[i]]);
        }
        
        hp_status = ob->query_entire_dbase();
        if( !mapp(hp_status) ) return;
        
	set("str", hp_status["str"]+5);
        set("int", hp_status["int"]+5);
        set("con", hp_status["con"]+5);
        set("dex", hp_status["dex"]+5);
        set("per", hp_status["per"]);
        set("jiali", hp_status["jiali"]+20);
        set("max_qi", hp_status["max_qi"]/4*5);
        set("max_jing", hp_status["max_jing"]);
        set("max_neili", hp_status["max_neili"]/2*3);
        set("eff_jingli", hp_status["eff_jingli"]);
        set("combat_exp", hp_status["combat_exp"]/9*10);
        if( ob->query("family/family_name") ){
        	set("family/family_name", ob->query("family/family_name"));
        	set("title", ob->query("family/family_name")+(random(2)?"��ͽ":"��ͽ"));
        }
        
        me->reincarnate();
        if (objectp(ob = ob->query_temp("weapon")) ){
        	if( stringp(query_skill_mapped(ob->query("skill_type"))) ) {
        		switch (ob->query("skill_type")){
          			case "sword":                
          			case "jian": 	break;   
          			case "blade":   weapon = new(BINGQI_D("blade")); break;   
          			case "whip":    weapon = new(BINGQI_D("whip")); break;
          			case "staff":   weapon = new(BINGQI_D("gangzhang")); break;
          			case "club":	weapon = new(BINGQI_D("tiegun")); break;           
          			case "hammer":	weapon = new(BINGQI_D("falun1")); break;
          			case "stick":	weapon = new(BINGQI_D("zhubang")); break;
          			case "hook":    weapon = new(BINGQI_D("hook")); break; 
          			case "dagger":	weapon = new(BINGQI_D("dagger")); break;
          			default :	break;;
        		}
        		if( weapon ){
       				weapon->move(me);
        			weapon->wield();
        		}
        	}
        }
}

nosave int init_flag = 0;

void init()
{
        object me;

        ::init();

	if ( !interactive(me = this_player()) ) return;
		
        if ( environment(me)->query("no_fight") || me->is_fighting() ) return;
        
	if (init_flag)
		return;
	init_flag = 1;
        if ( present("tiebu wenshu", me) && random(3) != 1 ) random_move();
	init_flag = 0;
}

int accept_fight(object me)
{
        command("say �߿��������Ⱝ�ְ��ŵ�");
        return 0;
}

void kill_ob(object me)
{     
	object ob, obj;
	int exp = me->query("combat_exp");
	
	obj = this_object();

	if ( ! present("tiebu wenshu", me)) {
		command("?");
		me->remove_enemy(obj);
		obj->remove_killer(me);
		return;
	}

	if( exp < query("combat_exp") / 2 ){
		switch(random(10)){
			case 1: command("consider "+me->query("id")); break;
			case 4: command("grin "+me->query("id")); break;
			case 9: message_vision(HIC"$n��Цһ��˵������ô�಻�����ģ�����ʮ����ү��Ҳ���£�\n"
                                "�漴�۾�һ�ɣ�����$N�ͳ��˹�ȥ��\n"NOR, me,obj); break;
			case 2:
			case 3:
			case 5:
			case 6:
			case 7:
			case 8:
			case 0: break;
		}
		obj->set_leader(me);
		::kill_ob(me);
		return;
	}
	
	if( !objectp(ob = present("tiebu wenshu", me)) ){
		if( exp > query("combat_exp") / 2 * 3 )
			random_move();
		::kill_ob(me);
		return;
	}
	
	if( obj->is_killing(me->query("id")) ){
		message_vision(HIR"$n��ͷ��������������һ��������ͨ����۾�����$N�ͳ��˹�ȥ��\n"NOR, me,obj);
                obj->set_leader(me);
                ::kill_ob(me);
                return;
        }
                
	if( ob->query("target_id") == query("id") ) {
                if( me->query_temp("gf_huilu") == obj ){
                	if( exp > query("combat_exp") )
                		message_vision(HIR"$n�����ܻ��ض�$N�µ���ɱ�˲���ͷ��أ���һ�ٿ����ƣ���ү����ͺ���ƴ���������ơ�\n"NOR, me,obj);
                	else	message_vision(HIR"$n����$N�ߵ���ǰ���ݺݵ��������ʶ̧�ٵĶ������Һ�����Ȱû�ã�\n"
                        "��������㳢����ү��������\n"NOR,me,obj);
                	obj->set_leader(me);
                	me->delete_temp("gf_huilu");
                	obj->add("combat_exp", query("combat_exp")/4);
                	::kill_ob(me);
                        return;
        	}
        
        	if( exp/2 > query("combat_exp") && me->query_temp("gf_release") != obj ){
                        message_vision("$n��Ȼ�������棬һ�������������$N˵����С������������С��������ȫ�ǹٸ���\n"
                        "�ݺ�����˵ز����������������������һ�棬�ҽ���һ���м�������\n",me,obj); 
                        tell_object(me, HIY"�����ѡ��������������(give wenshu to "+obj->query("id")+")�����߲�����\n"NOR);
                        me->set_temp("gf_huilu", obj);
                        me->remove_killer(obj);
			remove_killer(me);
                        return;
                }

                else {
                	if( exp > query("combat_exp") )
                        	message_vision("$N�ٺټ�Ц��������æ��Ц������λ"+RANK_D->query_respect(me)+"��"
				"�ٸ��Ĳ�ͷ�ɣ�����Ҷ����������ˣ������ܷ��̧���֣��ұ�����л����ú�����һ�£��Ƿ�Ը�⣿\n",obj);
                        else 	message_vision("$N�ٺټ�Ц������������λ"+RANK_D->query_respect(me)+"���׻�˵����һ��������ա�������Ź��ң�������л����ú�����һ�£��Ƿ�Ը�⣿\n",obj);
                        tell_object(me, HIY"�����ѡ��������������(give wenshu to "+obj->query("id")+")�����߲�����\n"NOR);
                        me->set_temp("gf_huilu", obj);
                        me->remove_killer(obj);
			remove_killer(me);
                        return;
                }
	}
} 

int accept_object(object me, object obj)
{            
	object ob = this_object();
	
      	if( obj->query("id") != "tiebu wenshu" )
      		return 0;
      		
        if( obj->query("target_id") != query("id") ) {
              	command("oh");
              	command("say "+obj->query("target_name")+"��Ȼ��ͨ�����ˣ������Ǳ��ٸ��ݺ�����");
                call_out("dest", 1, obj);
              	return 1;
        }
        else {
        	command("say ��λ"+RANK_D->query_respect(ob)+"һ��ǰ;Զ�󣬺ٺ٣����ǲ��������ġ�\n");
        	ob->add_money("gold",20+random(20));
        	command("give "+me->query("id")+" gold");
        	call_out("dest", 1, ob);
        	return 0;
        }
}

void level_up(int lvl)
{
	mapping skill_status;
	string *skills;
	int i, j;
	if ( !mapp(skill_status = query_skills()) || !sizeof(skill_status) )
		return;
	skills  = keys(skill_status);
        for(i = 0; i < sizeof(skills); i++) {
        	if(intp(j = skill_status[skills[i]]) ){
        		j += lvl;
        		set_skill(skills[i], j);
        	}
	}
}
void unconcious()
{
	object me, ob = this_object();
        
        if( !objectp(me = query_temp("last_damage_from")) )
        	return;
        
        d_time--;
        switch(d_time){
        	case 1: 
        		message_vision(HIR"$Nǿ����ʹ���ͳ�һ��ҩ����������е���������һ����"+RANK_D->query_self_rude(ob)+"�������¶�ҩ������ƴ�ˣ���\n"NOR,ob);
			if( me->query("combat_exp") > query("combat_exp") *2 )
				add("combat_exp", query("combat_exp") / 2);
        		else if( me->query("combat_exp") > query("combat_exp") /2 *3 )
				add("combat_exp", query("combat_exp") / 3);
			else 	add("combat_exp", query("combat_exp") / 4);
			add_temp("apply/damage", 30+random(40));
			add("max_qi", 500 + random(400) );
			add("max_neili", 500 + random(500) );
			add("jiali", 10);
			level_up(15+random(15));
			reincarnate();
			kill_ob(me);
			break;
		case 2: message_vision(WHT"$N����һЦ�����������֣���������"+RANK_D->query_self_rude(ob)+"���ó����ұ������ǲ����ˣ���\n"NOR,ob);
			if( me->query("combat_exp") > query("combat_exp") *2 )
				add("combat_exp", query("combat_exp") / 2);
			else if( me->query("combat_exp") > query("combat_exp") /2 *3 )
				add("combat_exp", query("combat_exp") / 3);
			else 	add("combat_exp", query("combat_exp") / 4);
			add_temp("apply/attack", 30+random(40));
			add_temp("apply/defense", 30+random(40));
			add("max_qi", 700+random(700));
			add("max_neili", 1000 + random(1000) );
			add("jiali", 40);
			level_up(20+random(20));
			reincarnate();
			kill_ob(me);
			break;
		default: ::unconcious();
	}
}

void die()
{
	if ( d_time >= 1 )
    		unconcious();
    	else {
    		::die();
    	}
}


void dest(object ob)
{
	if ( !ob ) return;
    	if (ob->is_character() ){
    		if( environment(ob))
       			message_vision("ֻ��$N��Ȼ��ת���У�ת�۾��ټ����ޡ�\n", ob);  
       	}

       	destruct(ob);
}
/*
void remove(string)
{
	GF_WANTED->del_wanted(query("id"));
	::remove();
}
*/
