// 5lun_npc.c
// Created by snowman@SJ
// Modified by snowman@SJ 28/11/2000


#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���ִ�ת֮Perform NPC", ({ "wulun npc", "npc"}));
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("str", 40);
        set("int", 40);
        set("con", 30);
        set("dex", 20);
        set("location", 1);
        set("no_quest", 1);
        set("env/invisibility", 1);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 20);
        set("combat_exp", 1000);
        set_temp("hit_ob_hit", 1);
        set_skill("force", 50);
        set_skill("xiangfu-lun", 50);
        set_skill("longxiang-boruo", 50);
        set_skill("hand", 50);
        set_skill("dashou-yin", 50);
        set_skill("hammer", 50);
        set_skill("dodge", 50);
        set_skill("yuxue-dunxing", 50);
        map_skill("force", "longxiang-boruo");
        map_skill("hand", "dashou-yin");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hammer", "xiangfu-lun");
        set_temp("apply/damage", 60);
        setup();
}

void die()
{
        object me, weapon;
        me = query("master_user/user");
        weapon = query("master_user/weapon");
        
        if( me ) {
        	me->delete_temp("dazhuan_npc");
        	me->add_temp("apply/parry", -100);
        	me->add_temp("apply/armor_vs_force", -200);
        }
        if( weapon->query("id")!="fenghuo lun" && (!me 
        || !living(me) 
   || environment(me) != environment(this_object()) ) ){
		if( objectp(weapon) && environment(weapon) == this_object() ){
			message_vision(HIW"\n$N"HIW"�ڿ�����ת����֮�����������������������䵽�˵��ϡ�\n"NOR, weapon);	
   			weapon->move(environment(this_object()));
   		}
   	}
   	
           else if( objectp(weapon) && environment(weapon) == this_object() && weapon->query("id")!="fenghuo lun" ){
        	if( query("dazhuan_finish") ){
        		message_vision(HIW"\n$N"HIW"�ڿ�����ת����֮�����������������������䵽�˵��ϡ�\n"NOR, weapon);	
   			weapon->move(environment(this_object()));
   		}
   		else {
   			message_vision(HIY "\n$n"HIY"��$N�������˸�Ȧ�ӣ�$P����һ�У��Ƿ����е�$n"HIY"�����·ɻ�$P�����У�\n\n"NOR, me, weapon);
   			weapon->move(me);
   			if( !me->query_temp("weapon") )
   				weapon->wield();
   		}
        }
           else if( weapon->query("id")=="fenghuo lun" )
                           message_vision(HIY "\n$n"HIY"��$N�������˸�Ȧ�ӣ�$P����һ�У��Ƿ����е�$n"HIY"�����·ɻ�$P�����У�\n\n"NOR, me, weapon);
        destruct(this_object());
}

void unconcious(){ die(); }

void set_master_player(object me, object weapon)
{
	
        set("name", me->name());
 	set_skill("longxiang-boruo", me->query_skill("longxiang-boruo", 1));
        set_skill("force", me->query_skill("force", 1));
        set_skill("xiangfu-lun", me->query_skill("xiangfu-lun", 1));
        set_skill("hammer", me->query_skill("hammer", 1));
        set_skill("hand", me->query_skill("hand", 1));
        set_skill("dashou-yin", me->query_skill("dashou-yin", 1));
        set_skill("dodge", me->query_skill("dodge", 1));
        set_skill("yuxue-dunxing", me->query_skill("yuxue-dunxing", 1));
        set("combat_exp", me->query("combat_exp"));
        set("max_neili", me->query("max_neili"));
        add_temp("apply/attack", me->query_skill("xiangfu-lun", 1)/2);
        add_temp("apply/damage", me->query_skill("xiangfu-lun", 1)/3);
        set("master_user/user", me);
        set("master_user/weapon", weapon);
        weapon->wield();       
}

void heart_beat()
{
	int i;
	object *enemy, target, me, weapon;
	
	me = query("master_user/user");
	
	if( !objectp(me) 
	|| !me->is_fighting()
	|| !living(me) 
	|| environment(me) != environment(this_object()) 
   || !objectp(weapon = query_temp("weapon"))
   || weapon != query("master_user/weapon") ){
		die();
		return;
	}
	enemy = me->query_enemy();
	i = sizeof(enemy);
   if( i < 1 || ( me->query_temp("weapon") && (me->query_temp("weapon"))->query("id")!="fenghuo lun") ){
		set("dazhuan_finish", 1);
		die();
		return;
	}
	if( me->query_skill_mapped("hammer") != "xiangfu-lun" ){
            	message_vision(HIY"$N�任���ַ������������е�$n"HIY"��ʱ�޷������ˣ�\n"NOR,me, weapon);
            	die();
            	return;
        }
  	else if( me->query_skill_mapped("force") != "longxiang-boruo"){
            	message_vision(HIY"$N�任���ڹ������������е�$n"HIY"��ʱ�޷������ˣ�\n"NOR,me, weapon);
            	die();
            	return;
        }
    	else if( me->query("neili") < 300 ){
            	message_vision(HIY"$N�����������ޣ���Ҳ���Ʋ��˷����е�$n"HIY"�ˣ�\n"NOR,me, weapon);
            	die();
            	return;
        }
        
	set("neili", me->query("neili"));
    	set("jiali", me->query("jiali"));
    	target = enemy[random(i)]; 
    	if( environment(target) == environment(me) ){
 		COMBAT_D->do_attack(this_object(), target, query_temp("weapon"), random(2)?1:3);
 		if( me->is_fighting(target) && random(10) == 5 )
 			COMBAT_D->do_attack(this_object(), target, query_temp("weapon"), 3);
    		me->add("neili", -(30+random(50)));
    	}
	::heart_beat();	
}

