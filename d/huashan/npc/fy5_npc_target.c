// By lsxk@hsbbs 2007/8/31

#include <ansi.h>
inherit NPC;

void create()
{
	mapping name;
	int i;
        
	i = random(4);

	name = RNAME_D->get_random_name(i);
	set_name(name["name"], name["id"]);
   set("title",HIR"��������"NOR);
	set("gender", (i==0?"Ů��":"����"));
	set("age", random(20)+25);      
	set("str", 20+random(5));
	set("int", 20+random(5));  
	set("con", 20+random(5));     
	set("dex", 20+random(5));
	set("location", 1);
	set("combat_exp", 100000);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("no_quest", 1);
	set("max_qi",1200);
	set("max_jing",1200);
	set("neili",1000);
	set("eff_jingli", 1200);
	set("max_neili",1000);

	set_skill("force", 100); 
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("literate", query("int")* 10);

	setup();
	call_out("dest", 900, this_object());
	carry_object(ARMOR_D("cloth"))->wear();
//	if (clonep())
//		call_out("go", 1, 3+random(2));
}

void init()
{
    object ob,me;

    me = this_player();
    ob = this_object();

    if(ob->query("escape_id")==me->query("id")){
        remove_call_out("check_escape");
        call_out("check_escape",2,me,ob);
    }
     return;
}

void check_escape(object me,object ob)
{
    if(!objectp(me)) return;

    if(me->is_fighting()){
        message_vision(HIC"\n$N��$n��ס�˶��֣� ��æ��׼�������˿�ȥ��\n"NOR,ob,me);
        destruct(ob);
        return;
    }

    remove_call_out("check_escape");
    call_out("check_escape",2,me,ob);
    return;
}

void go(int step)
{
	if (step-- && environment()) {
		random_move();
		call_out("go", 1, step);
	}
}

void dest(object ob)
{
	if (!ob) return;
	if (!environment(ob)) return;
    message_vision("$NͻȻ������Χûɶ�ˣ�����ææ���߿��ˡ�\n", ob);
	destruct(ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

void kill_ob(object ob)
{
	object me = this_object();

	command("!!!");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

void accept_fight(object ob)
{
	command("peace "+ ob->query("id"));
	return;
}
