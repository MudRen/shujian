// /clone/npc/party_npc.c
// Created by lane@SJ

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���ɵ���", ({ "menpai dizi", "dizi", "npc" }));
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("str", 10+random(20));
	set("int", 10+random(20));
	set("con", 10+random(20));
	set("dex", 10+random(20));
	set("no_get","���˶������̫���ˡ�");
	set("no_bark",1);
	set("no_ansuan",1);

	set("max_qi", 2500);
	set("max_jing", 2500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 20);
	set("combat_exp", 500000);

	set_skill("literate", 200);
	set_skill("strike", 300);
	set_skill("cuff", 300);
	set_skill("hand", 300);
	set_skill("dodge", 300);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("hammer", 300);
	set_skill("stick", 300);
	set_skill("club", 300);
	set_skill("staff", 300);
	set_skill("whip", 300);
	set_skill("dagger", 300);
	set_temp("apply/armor", 60);

	setup();
        carry_object("/clone/armor/shuikao")->wear();
}

void die()
{
	object me;
	me = query("master_user/user");

	if( me ) me->delete_temp("zhaoji_npc");

	if( !me || environment(me) != environment(this_object()) )
		message_vision("$NͻȻ���һԾ���Ҵ�ææ���뿪�ˡ�\n", this_object());

	if( !living(me) ) {
		message_vision("$N���һ���������á�������$n��·���ӡ�\n", this_object(), me);
		me->move("/d/xiangyang/damen");
		if( me->query("eff_qi") < 1 ) me->set("eff_qi",1);
	} else 	if( !me->is_fighting() || !this_object()->is_fighting() )
		message_vision("$N��$n���˸��������������ţ���ֶ��ҪҪ���������и����ˣ���\n˵���Ҵ�ææ���뿪�ˡ�\n", this_object(), me);

	destruct(this_object());
}

void unconcious(){ die(); }

void set_master_player(object ob)
{
	object weapon;
        mapping hp_status, skill_status, map_status, prepare_status;
	string fam;
        string *sname, *mname, *pname;
	int i;

	fam = ob->query("family/family_name");

// copy misc

	set("family/family_name", fam);
	set("master_user/user", ob);
	set("age", ob->query("age")*2/3);
	set("gender", ob->query("gender"));

	if( fam == "������" ) {
		set_name("ѩɽ����", ({ "xueshan dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "longxiang" :),
 			(: exert_function, "shield" :),
		}));
	}
	if( fam == "������" ) {
		set_name("����Ů����", ({ "emei dizi", "dizi" }) );
		set("gender", "Ů��");
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "fengyun" :),
 			(: exert_function, "riyue" :),
 			(: exert_function, "tiandi" :),
 			(: exert_function, "wuwo" :),
 			(: exert_function, "yinyang" :),
 			(: exert_function, "youming" :),
 			(: exert_function, "zhixin" :),
		}));
	}
	if( fam == "����Ľ��" ) {
		set_name("Ľ������", ({ "murong menren", "menren" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "shenyuan" :),
		}));
	}
	if( fam == "��Ĺ��" ) {
		set_name("��Ĺ����", ({ "gumu dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "xinjing" :),
		}));
	}
	if( fam == "��ɽ��" ) {
		set_name("��ɽ����", ({ "huashan dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "zixia" :),
		}));
	}
	if( fam == "����" ) {
		set_name("���̽���", ({ "mingjiao jiaozhong", "jiaozhong" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "jiuyang" :),
		}));
	}
	if( fam == "������" ) {
		set_name("���ֵ���", ({ "shaolin dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "jingang" :),
		}));
	}
	if( fam == "������" ) {
		set_name("�����̵���", ({ "shenlong dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "wudi" :),
 			(: exert_function, "shexin" :),
		}));
	}
	if( fam == "�һ���" ) {
		set_name("�һ�������", ({ "taohuadao menren", "menren" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "qimen" :),
 			(: exert_function, "maze" :),
		}));
	}
	if( fam == "������" ) {
		set_name("�����µ���", ({ "tianlong dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "ku" :),
 			(: exert_function, "rong" :),
 			(: exert_function, "kong" :),
 			(: exert_function, "xinjing" :),
		}));
	}
	if( fam == "���ư�" ) {
		set_name("���ư���", ({ "tiezhang bangzhong", "bangzhong" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "juli" :),
		}));
	}
	if( fam == "�䵱��" ) {
		set_name("�䵱�ɵ���", ({ "wudang dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "taiji" :),
 			(: exert_function, "yinyun" :),
		}));
	}
	if( fam == "������" ) {
		set_name("���޵���", ({ "xingxiu dizi", "dizi" }) );
 		set("chat_chance_combat", 40);
 		set("chat_msg_combat", ({
 			(: exert_function, "huadu" :),
 			(: exert_function, "huagong" :),
 			(: exert_function, "huajing" :),
 			(: exert_function, "judu" :),
		}));
	}
	if( fam == "ؤ��" ) {
		set_name("ؤ�����", ({ "gaibang bangzhong", "bangzhong" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "huntian" :),
 			(: exert_function, "shentong" :),
		}));
	}
	if( fam == "��ɽ��" ) {
		set_name("��ɽ����", ({ "songshan dizi", "dizi" }) );
 		set("chat_chance_combat", 80);
 		set("chat_msg_combat", ({
 			(: exert_function, "hanbing" :),
 			(: exert_function, "huti" :),
 			(: exert_function, "juhan" :),
		}));
	}
	if( fam == "������" ) {
		set_name("���ص���", ({ "kunlun dizi", "dizi" }) );
 		set("chat_chance_combat", 50);
 		set("chat_msg_combat", ({
 			(: exert_function, "riyue" :),
 			(: exert_function, "taxue" :),
		}));
	}
	
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

// copy hp

        hp_status = ob->query_entire_dbase();

        set("str", hp_status["str"]);
        set("int", hp_status["int"]);
        set("con", hp_status["con"]);
        set("dex", hp_status["dex"]);

        set("max_qi",    hp_status["max_qi"]);
        set("eff_qi",    hp_status["max_qi"]);
        set("qi",        hp_status["max_qi"]);
        set("max_jing",  hp_status["max_jing"]);
        set("eff_jing",  hp_status["max_jing"]);
        set("jing",      hp_status["max_jing"]);
        set("max_neili", hp_status["max_neili"]);
        set("eff_jingli", hp_status["max_jingli"]);
        set("max_jingli", hp_status["max_jingli"]);
        set("jingli",     hp_status["max_jingli"]);
        set("neili",     hp_status["max_neili"]);
        set("jiali",     ob->query_skill("force")/5);
        if( query("jiali") > 200 ) set("jiali", 200 );
        set("combat_exp",hp_status["combat_exp"]);

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

}

void heart_beat()
{
	int i;
	object me;
	object *ob;

	me = query("master_user/user");

	if( !objectp(me) || !me->is_fighting()
	 || !living(me)  || environment(me) != environment(this_object()) ) {
		die();
		return;
	}

	ob = all_inventory(environment(me));

	for( i=0; i<sizeof(ob); i++ ) {
		if( !living(ob[i]) || ob[i] == me ) continue;
		if( userp(ob[i]) ) continue;
		if( !ob[i]->is_fighting(me) ) {
			ob[i]->remove_killer(this_object());
			remove_killer(ob[i]);
		} else {
			ob[i]->kill_ob(this_object());
			fight_ob(ob[i]);
		}
	}

	if( !is_fighting() ) {
		die();
		return;
	}
	::heart_beat();	
}
