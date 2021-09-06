// ��ħ

#include "ansi.h"

inherit NPC;

int check();

void create()
{
	set_name("��ħ", ({ "xinmo"}));   
	set("shen", -10000);
	set("attitude", "peaceful");
	set_temp("no_fight",1);
	set("chat_chance", 50);
        set("chat_msg", ({
          (: check :)
        }) );
	set("time",0);
	set("location",1);
	setup();
	carry_object("/d/sld/npc/obj/changsan")->wear();       
}

int check()
{
	object ob=this_object();
	object me;
	int f=0;

	if(!objectp(me=query("owner")) && query("time")>60)
	{
		destruct(ob);
		return 1;
	}
	if(query("time")>660)
	{
		destruct(ob);
		return 1;
	}
	add("time",1);
	if(!living(ob))
		return 1;
	if(ob->query("eff_qi")<me->query("eff_qi"))
	{
		me->set("eff_qi",ob->query("eff_qi"));
		f=1;
	}
	if(ob->query("eff_jing")<me->query("eff_jing"))
	{
		me->set("eff_jing",ob->query("eff_jing"));
		f=1;
	}
	if(ob->query("qi")<me->query("qi"))
	{
		me->set("qi",ob->query("qi"));
		f=1;
	}
	if(ob->query("jing")<me->query("jing"))
	{
		me->set("jing",ob->query("jing"));
		f=1;
	}
	if(f!=0)
		tell_object(me,"��е���ʲô�������صػ���һ�£�\n");
	return 1;
}

void die()
{
	object ob=this_object();
	object me;

	me=ob->query("owner");
	if(me==ob->query_temp("last_damage_from"))
	{
		me->delete("rumo");
		if(!me->query("mkyexp"))
			me->set("mkyexp",100);
		else
			me->add("mkyexp",100);
	}
    	message_vision("$N�����˼��¾���ͬ�������ʧ�����ˡ�\n", ob);
	destruct(ob);
}
