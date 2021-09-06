// job_npc.c by Lane@ln 2004.7.28
// Lane 2004.11.25 �����Ѷȣ�NPC �Զ� pfm 

#include <ansi.h>
inherit NPC;

int yun_force();
int pfm_skill();

int sort_skill(string file)
{
	int i;
	if ( file[<2..<1] != ".c" ) return 0;
	if ( !sscanf(file, "%*s.c") )  return 0;
	if ( sscanf(file, "%*s_noshow.c") )  return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( file[i] < 'a' || file[i] > 'z' )
			return 0;
	}

	return 1;
}

void create()
{
        set_name("������å", ({ "liu mang", "liumang", "liu" }) );

        set("gender", "����" );
        set("age", 30);
        switch (random(8)) {
                case 0:set("title", BLU"�޾������"NOR); break;
                case 1:set("title", HIR"��ȭ�ŵ���"NOR); break;
                case 2:set("title", HIB"��ɳ�ɰ���"NOR); break;
                case 3:set("title", YEL"ũ������"NOR); break;
                case 4:set("title", HIG"��������"NOR); break;
                case 5:set("title", HIC"�񻢹�����"NOR); break;
                case 6:set("title", HIM"۶�������"NOR); break;
                case 7:set("title", YEL"���������"NOR); break;
        }
        set("long", "һ����Ŀ������ˣ��沿���������⡣\n");
        set("meitude","friendly");

        set("combat_exp", 2000000);
        set("str", 25);
        set("con", 25);
        set("dex", 25);
        set("int", 25);

        set("max_qi", 20000);
        set("max_jing", 20000);
        set("max_neili", 5000);
        set("max_neili", 20000);
        set("neili", 5000);
        set("neili", 20000);
set("no_party_job",1);
        set("eff_jing", 20000);
        set("eff_jingli", 20000);
        set("jingli", 20000);
        set("max_jingli", 20000);

        set("no_ansuan",1);

        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :)
        }) );


        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({ 
                (: yun_force :),
                (: pfm_skill :),
                (: pfm_skill :),
        }));    

        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("strike", 300);
        set_skill("claw", 300);
        set_skill("leg", 300);
        set_skill("finger", 300);
        set_skill("cuff", 300);
        set_skill("hand", 300);
        set_skill("unarmed", 300);
        set_skill("sword", 300);
        set_skill("blade", 300);
        set_skill("hammer", 300);
        set_skill("stick", 300);
        set_skill("club", 300);
        set_skill("staff", 300);
        set_skill("whip", 300);
        set_skill("dagger", 300);
        set_skill("literate", 200);

        setup();
        if( random(5) ) add_money("gold", random(5) + 1 );
        else carry_object("/clone/misc/yushi");
        carry_object("/clone/armor/shuikao")->wear();

}

void init()
{
        object ob = this_player();
        object me = this_object();

        ::init();

        if( interactive(ob) && !environment(ob)->query("no_fight")
         && me->query("kill_party") == ob->query("family/family_name") ) {
                command("grin " + ob->query("id"));
                command("knock " + ob->query("id"));
//                if( random(2) ) ob->start_busy(random(2))
        }
}       

void do_copy(object ob)
{
        object weapon;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i;

        set_name(ob->name(), ({ ob->query("id")+"'s dummy", "dummy", ob->query("id")+"'s" }) );
        set("nickname", ob->query("title") );
        set("long", ob->query("long") );
        set("gender", ob->query("gender") );
        set("per", ob->query("per") );
        set("age", ob->query("age") );

        set_temp("apply/damage",  10 + random(20) );
        set_temp("apply/attack",  20 + random(40) );
        set_temp("apply/armor",   30 + random(60) );

// copy skills

        if( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        set_skill(sname[i], skill_status[sname[i]]);
                }
        }

        command("jifa all"); 

// copy skill maps

        if( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        map_skill(mname[i], map_status[mname[i]]);
                }
        }


// copy skill prepares

        if( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

// copy weapon

	if( objectp(weapon = ob->query_temp("weapon")) ) {
		if( weapon->query("skill_type") == "sword" )
			carry_object("/clone/weapon/changjian")->wield();
		if( weapon->query("skill_type") == "blade" )
			carry_object("/clone/weapon/blade")->wield();
		if( weapon->query("skill_type") == "axe" )
			carry_object("/clone/weapon/axe")->wield();
		if( weapon->query("skill_type") == "brush" )
			carry_object("/clone/weapon/brush")->wield();
		if( weapon->query("skill_type") == "club" )
			carry_object("/clone/weapon/club")->wield();
		if( weapon->query("skill_type") == "dagger" )
			carry_object("/clone/weapon/dagger")->wield();
		if( weapon->query("skill_type") == "hammer" )
			carry_object("/clone/weapon/hammer")->wield();
		if( weapon->query("skill_type") == "hook" )
			carry_object("/clone/weapon/hook")->wield();
		if( weapon->query("skill_type") == "spear" )
			carry_object("/clone/weapon/spear")->wield();
		if( weapon->query("skill_type") == "staff" )
			carry_object("/clone/weapon/staff")->wield();
		if( weapon->query("skill_type") == "stick" )
			carry_object("/clone/weapon/stick")->wield();
		if( weapon->query("skill_type") == "whip" )
			carry_object("/clone/weapon/whip")->wield();
		if( weapon->query("skill_type") == "throwing" )
			carry_object("/clone/weapon/feihuangshi")->wield();
	}

        hp_status = ob->query_entire_dbase();

        set("str", hp_status["str"]);
        set("int", hp_status["int"]);
        set("con", hp_status["con"]);
        set("dex", hp_status["dex"]);

        set("max_qi",    hp_status["max_qi"]*2);
        set("eff_qi",    hp_status["max_qi"]*2);
        set("qi",        hp_status["max_qi"]*2);
        set("max_jing",  hp_status["max_jing"]*2);
        set("eff_jing",  hp_status["max_jing"]*2);
        set("jing",      hp_status["max_jing"]*2);
        set("max_neili", hp_status["max_neili"]);
        set("eff_jingli", hp_status["max_jingli"]);
        set("max_jingli", hp_status["max_jingli"]);
        set("jingli",     hp_status["max_jingli"]*2);
        set("neili",     hp_status["max_neili"]*2);
        set("jiali",     hp_status["jiali"]*2+1);
        if( query("jiali") > 200 ) set("jiali", 200 );
        set("combat_exp",hp_status["combat_exp"]*11/10);
        call_out("dest", 1000);
}

void die()
{
        object me, ob, killer;
        int exp, pot, tb;

        me = query_temp("last_damage_from");
        ob = this_object();

	        
        if( !objectp(me) || !ob->query("kill_party") ) {
                ::die();
                return;
        }

        if( ob->query("kill_party") == me->query("family/family_name") ) {

                if( ob->query("combat_exp") > me->query("combat_exp")*3/2 )
                        exp = 1500 + random(1500);
                else if( ob->query("combat_exp") > me->query("combat_exp") ) {
                        exp = 600 + random(300) + (ob->query("combat_exp") - me->query("combat_exp"))/20000;
                        if( exp >= 1500 ) exp = 1400 + random(200);
                } else if( ob->query("combat_exp") < me->query("combat_exp")*2/3 )
                        exp = 1200 + random(1000);
                else exp = 1200 + random(500);

                pot = exp/4 + random(50);
                tb = 1+random(2);

                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("SJ_Credit", tb);
                me->add("job_time/chue", 1);
                message_vision(YEL"\n$Nɱ����" + ob->query("title") + YEL"��Ϊ" + me->query("family/family_name") + "����������Ķ�����\n",me);
                message_vision(YEL"$N��ϸ����ղź�" + ob->name() + "�Ĵ򶷾����������Լ�����ѧ�������ָ�����һ�㣡\n"NOR,me);
                tell_object(me, HIW"������" + CHINESE_D->chinese_number(exp) + HIW"�㾭�飬" + CHINESE_D->chinese_number(tb) + HIW"�齣ͨ��" +
                        CHINESE_D->chinese_number(pot) + HIW"��Ǳ�ܣ��㹲Ϊ" + me->query("family/family_name") + HIW
                        "������" + CHINESE_D->chinese_number(me->query("job_time/chue")) + HIW"��������\n"NOR);

                log_file( "job/chue_job",sprintf("%s %s(%s)��%d�����񣬾��飺%d��Ǳ�ܣ�%d�����˾��飺%d ����־��飺%d\n",
                ctime(time())[4..19], me->name(), me->query("id"), me->query("job_time/chue"), exp, pot,
                ob->query("combat_exp"), me->query("combat_exp")));

                if( objectp(killer = query_temp("last_damage_from")) )
                        CHANNEL_D->do_channel(me, "rumor", "ð��"+ob->name()+"��"+ob->query("title")+"�Ը��书�˵ã���ϧ�����ˣ���"+killer->name()+"�͵�������"NOR);

        }
        ::die();
        return;
}

void dest()
{
        destruct(this_object());
}

void kill_ob(object me)
{
        object ob = this_object();
        if( me->query("family/family_name") == ob->query("kill_party") || wizardp(me) )
                ::kill_ob(me);
        else {
                me->remove_killer(ob);
                remove_killer(me);
                command("!!!");
        }
}

int yun_force()
{
	string arg, force, exert, *file;
	object me;
	int j = 0;

	me = this_object();

	if( me->is_busy() ) return 0;

	if( !(force = me->query_skill_mapped("force")) ) return 0;

	if( file_size(SKILL_D(force)+".c") < 1 ) return 0;

	if( stringp(exert = SKILL_D(force)->exert_function_file("")) ) {
		file = get_dir(exert);
		if( sizeof(file) > 0 ) {
			file = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	if( j && j > 0 ) {
		sscanf(file[random(j)], "%s.c", arg);
		if( arg == "roar" || arg == "play" || arg == "shougong" || arg == "duwu" || 
		    arg == "huagong" || arg == "huajing" || arg == "guiyuan" ) return 0;
		command("exert "+arg);
	}
	return 1;
}

int pfm_skill()
{
	mapping pmap;
	string arg, skill, pfm, *file;
	object me, weapon;
	int j = 0;

	me = this_object();

	if( me->is_busy() ) return 0;

	if( me->is_perform() ) return 0;

	if( me->query_skill("douzhuan-xingyi", 1) >= 120 && random(2) ) {
		command("enable parry douzhuan-xingyi");
		if( random(2) ) command("perform parry.bishen");
		else command("perform parry.xingyi");
		return 0;
	} else if( me->query_skill("qiankun-danuoyi", 1) >= 210 && random(2) ) {
		command("enable parry qiankun-danuoyi");
		if( random(2) ) command("perform parry.yin");
		else if( random(2) ) command("perform parry.xu");
		else command("perform parry.hua");
		return 0;
	}

	if( !(skill = me->query_skill_mapped("dodge")) ) return 0;

	if( file_size(SKILL_D(skill)+".c") < 1 ) return 0;

	if( stringp(pfm = SKILL_D(skill)->perform_action_file("")) ) {
		file = get_dir(pfm);
		if( sizeof(file) > 0 ) {
			file = filter_array(file, (: sort_skill :) );
			j = sizeof(file);
		}
	}
	if( j && j > 0 ) {
		sscanf(file[random(j)], "%s.c", arg);
		if( arg == "baibian" ) return 0;
		command("perform dodge."+arg);
	}

	weapon = me->query_temp("weapon");

	if( objectp(weapon) ) {
		if( !(skill = me->query_skill_mapped(weapon->query("skill_type"))) ) return 0;
		if( file_size(SKILL_D(skill)+".c") < 1 ) return 0;
		if( stringp(pfm = SKILL_D(skill)->perform_action_file("")) ) {
			file = get_dir(pfm);
			if( sizeof(file) > 0 ) {
				file = filter_array(file, (: sort_skill :) );
				j = sizeof(file);
			}
		}
		if( j && j > 0 ) {
			sscanf(file[random(j)], "%s.c", arg);
			if( arg == "tongshou" || arg == "zhuan" || arg == "fentian" || arg == "jue" ) return 0;
			command("enable parry "+skill);
			command("perform "+weapon->query("skill_type")+"."+arg);
		}
	}
	else {
		pmap = me->query_skill_prepare();
		if( !pmap ) pmap = ([]);
		if( !sizeof(pmap) ) {
			command("prepare strike");
			command("prepare cuff");
			command("prepare hand");
			command("prepare leg");
			command("prepare finger");
			command("prepare claw");
			return 0;
		}
		file = keys(pmap);
		foreach (string item in file) {
			if( !(skill = me->query_skill_mapped(item)) ) return 0;
			if( file_size(SKILL_D(skill)+".c") < 1 ) return 0;
			if( stringp(pfm = SKILL_D(skill)->perform_action_file("")) ) {
				file = get_dir(pfm);
				if( sizeof(file) > 0 ) {
					file = filter_array(file, (: sort_skill :) );
					j = sizeof(file);
				}
			}
			if( j && j > 0 ) {
				sscanf(file[random(j)], "%s.c", arg);
				if( arg == "juehu" || arg == "yipai" || arg == "sanyin" || arg == "tiezhang" || arg == "xuanming" || arg == "huagu" ) return 0;
				command("enable parry "+skill);
				command("perform "+item+"."+arg);
			}
		}
	}
	return 1;
}
