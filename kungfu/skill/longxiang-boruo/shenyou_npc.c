#include <ansi.h>
inherit NPC;

void create()
{
	set_name("���", ({ "shenyou npc" }) );
	set("gender", "����");
	set("env/invisibility", 1);    
	set_skill("dodge", 500);
	set_skill("longfeng-xiang", 500);
	map_skill("dodge", "longfeng-xiang");       
	set("attitude", "friendly");
	set("location", 1);
	set_temp("apply/id", ({ "" }));
	set_temp("apply/short", ({""}));
	setup();
}

void do_setup(object me, object target)
{
	set("name", me->name()+"�����");
	set("master", me);
	set("target", target);
	this_object()->set_leader(target);  
	this_object()->move(environment(target));  
	"/cmds/std/look"->look_room(this_object(), environment(target));  
	call_out("checking", 1, target);	  
}

void do_remove()
{
	destruct(this_object());  
}

int checking(object target)
{
	object where, me;
       
	if(!objectp(me = query("master"))){
		destruct(this_object());  
		return 0;
	}
	       
	if(!objectp(target) || !objectp(where = environment(target))){
		me = query("master");
		tell_object(me , GRN"�����Ρ���Ȼ�䣬һ�����Ϯ������������һ����\n"NOR);
		me->halt_exercise(me);
		return 0;
	}
	       
	if( strsrch(file_name(environment(target)),"/d/wizard/") >= 0
	|| strsrch(file_name(environment(target)),"/d/") <0
	|| strsrch(file_name(environment(target)),"/u/") < 0){
		me = query("master");
		tell_object(me , RED"�����Ρ���Ȼ�䣬����ǰ���һ����������˻�����\n"NOR);
		me->halt_exercise(me);
		return 0;
	}
	if(where != environment())
		this_object()->move(where);

	call_out("checking", 1, target);
	return 1;
}


void relay_message(string msgclass, string msg)
{
	object player;
	string *ary;
	int i;

	if (msgclass[0..5] == "wizard") return;
	msg = "1\n" +environment(this_object())->query("short")+" - " + msg;
	ary = explode(msg, "\n");
	player = query("master");
	for (i=1;i<sizeof(ary);i++)
		if (player)
			tell_object(player, GRN"�����Ρ�"NOR+ary[i]+NOR+"\n");
}
