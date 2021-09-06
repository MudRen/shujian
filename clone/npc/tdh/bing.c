// guanbing for tdh job by Lklv

inherit NPC;
#include <ansi.h>
#include "skill.h"

//string *rtitle = ({HIY"��ǰ����"NOR, HIR"�̲�����"NOR, HIM"���ڸ���"NOR});

void create()
{
//	string str;
	mapping name;
	name = RNAME_D->get_random_name(1);
//	str = rtitle[random(sizeof(rtitle))];

	set_name(name["name"], name["id"]+({"shi wei"}) );
	set("gender", "����");
	set("long", "��һ�����Բ���������ڣ�����������η��\n");
	set("shen", -5000);
	set("attitude", "friendly");
	set("age", random(20)+25);
//	set("title", str);
	set("title",HIY"��ǰ����"NOR);

	set("no_ansuan", 1);
	set("no_bark", 1);
	set("no_quest", 1);
	set("tdh_bing", 1);

	set("str", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));
	set("dex", 25+random(10));

	set("max_qi",3500);
	set("max_jing", 1600);
	set("eff_jingli", 2000);
	set("max_neili", 4000);
	set("jiali", 40);
	set("combat_exp", 800000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("cuff", 200);
	set_skill("taizu-quan", 200);
	set_skill("taiji-shengong", 200);
	map_skill("force", "taiji-shengong");
	map_skill("parry", "taizu-quan");
	map_skill("cuff", "taizu-quan");

if (!random(4))
{
           set_temp("apply/dodge", 180);
           set_temp("apply/armor", 200);

}


	prepare_skill("cuff", "taizu-quan");
	if ( !random(5))
		add_money("gold", 1);
	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();

	if (clonep())
		call_out("dest", 200, this_object());
}

void dest(object ob)
{
	object jober;

	if ( !ob ) return;
	if ( ob->is_fighting())
		tell_room(environment(ob), "\n"+ob->name()+"��ݺ�˵�����ú�������ǰ���������ȳ��ˡ�\n");
	else
		tell_room(environment(ob), "\n"+ob->name()+"ת�ۼ��ߵ���Ӱ���١�\n");

	if ( stringp(query("��ػ�jober"))
	 && objectp(jober= find_player(query("��ػ�jober")))
	 && jober->query_temp("tdhjob")
	 && !jober->query_temp("��ػ�job/lost")){
		jober->add_temp("��ػ�job/meet", -1);
	}
	destruct(ob);
}

void heart_beat()
{
	object jober;

	::heart_beat();

	if ( stringp(query("��ػ�jober"))
	 && objectp(jober= find_player(query("��ػ�jober")))
	 && jober->query_temp("��ػ�job/lost")){
		dest(this_object());
	}
}

void kill_ob(object ob)
{
	object me = this_object();

	if( me->query("��ػ�jober") != ob->query("id") && userp(ob)){
		me->remove_enemy(ob);
		ob->remove_killer(me);
		return;
	}
	::kill_ob(ob);
}

void fight_ob(object ob)
{
	if( query("��ػ�jober") != ob->query("id") && userp(ob)){
		command("say "+ob->name()+"�����Զ�㣬����������ִ�й���");
		ob->remove_killer(this_object());
	}
	else ::fight_ob(ob);
}

void die()
{
	object ob, jober;
	ob = this_object();

	if ( objectp( jober = ob->query_temp("last_damage_from") )
	&& query("��ػ�jober") == jober->query("id")
	&& !jober->query_temp("��ػ�job/lost")
	&& jober->query_temp("tdhjob")){
		jober->add_temp("��ػ�job/killer", 1);
	}
	if ( random(3)){
		dest(ob);
		return;
	}
	if (objectp(jober= find_player(query("��ػ�jober")))
	 && jober->query_temp("tdhjob")
	 && !jober->query_temp("��ػ�job/lost")){
		jober->add_temp("��ػ�job/meet", -1);
	}
	::die();
}

void unconcious()
{
	object ob = this_object();
	tell_room(environment(ob), "\n"+ob->name()+"��е������������������ܲ��˵ģ���\n");
	die();
}
