// customer	�˿�
// by augx@sj	9/11/2001

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>

string ask_buliao();

void create()
{
	mapping name;
	int i = random(3);

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"]);
	set("gender", (i==0?"Ů��":"����"));

	set("age", 15 + random(15));
	set("long", "����λ�����·��Ĺ˿͡�\n");
	set("combat_exp", 3000000);
	set("meitude", "peaceful");
        set("no_bark", 1);
	set("str", 36);
	set("int", 36);
	set("con", 36);
	set("dex", 36);
	set("shen",10000);
	set("max_qi", 90000);
	set("eff_jingli",90000);
	set("max_jing", 90000);
	set("max_neili",90000);
	set("neili", 90000);
	
	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
	set_skill("sword", 300);
	
	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);
	
	set("inquiry", ([
		"����"		: (: ask_buliao :),
		"��"		: (: ask_buliao :),
		"����"		: (: ask_buliao :),
		"buliao"	: (: ask_buliao :),
		"bu"		: (: ask_buliao :),
		"job"		: (: ask_buliao :),
	]));
	        
	set_temp("no_return",1);
	set("no_clean_up",1);
	set("give_bu",0);
	setup();
	carry_object(BINGQI_D("sword"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", random(35));
	
	call_out("dest", 30 * 60);
}       

void init()
{
	object ob;
        
	::init();
        
	if( interactive(ob = this_player()) ) {
		remove_call_out("greeting");
		call_out("greeting", 0, ob);
	}
}

void greeting(object ob)
{
	command("visit");
}

void dest()
{
        command("emote �����뿪�ˡ�");
	destruct(this_object());
}

void kill_ob(object ob)
{
	command("fear");
	command("!!!");
        ob->remove_killer(this_object());
        this_object()->remove_enemy(ob);
        return;
}

int accept_fight(object me)
{
	command("shake");
	return 0;       
}

void finish()
{
	int i = remove_call_out("dest");
	if(i>20) i=20;
	if(i>=0) call_out("dest",i);
}

string ask_buliao()
{
	object me = this_player() , obj;
	int i,count=16;
	
	if( query("player") != me->query("id") )
		return "�Ҳ�û�������ǵĲ÷�궨���·�����";
	if( query("give_bu") )
		return "���Ѿ������㲼�ϰ���";
		
	for(i=0;i<count;i++) {
		obj = new("/d/zhiye/obj/buliao");
		if(!obj) return "BUG���뱨����ʦ��\n";
		obj->set_level(11);
		obj->set("target",this_object());
		obj->move(me);
	}
	set("give_bu",1);
	
	message_vision(CYN"$N��$n"+CHINESE_D->chinese_number(count)+"ƥ��˹��˿��\n"NOR,this_object(),me);
	return "����ǲ÷����������˰�����"+CHINESE_D->chinese_number(count)+"ƥ��˹��˿����ȥ�ɣ���Ҫ��ϧ���ð���";
}

int accept_object(object me, object ob, object who)
{
	object bu;
	
	if( !ob->query("job_cloth") || ob->query("target")!=this_object() ){
		command("? "+me->query("id"));
		command("say ����������ʲô��");
		return 0;
	}
	
	if( ob->query("makeby") != me->query("id") ) {
		command("hmm "+me->query("id"));
		command("say ��"+ob->query("unit")+ob->name()+"����֯����𣿺��ҵ�Ҫ�󲻷��ϰ���");
		me->add("combat_exp",-500-random(1000));
		if(me->query("combat_exp")<0) me->set("combat_exp",0);
		call_out("destroying", 1, ob);
		return 1;
	}
	
	while ( objectp(bu = present("bosi caisi", me)) ) destruct(bu);
	while ( objectp(bu = present("bosi caichou", me)) ) destruct(bu);
	command("emote ȡ�ر߽��ϡ�");	
	
	command("say �ţ������ܺ��ҵ����⡣");
	call_out("destroying", 1, ob);
	me->add("worker/job3_finish",1);
	finish();
	
	return 1;
}
