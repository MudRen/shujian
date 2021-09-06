// beauty	��Ů
// by emnil@sj		2/9/2k

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>

string ask_laozu();

string * name1 = ({ "��","��","��","Ѧ","��","��","��","��","ŷ��","�Ϲ�"}); 
string * name2 = ({ "���", "����","С��","����","С��","����","����","����" }); 

void create()
{
	string name = name1[random(sizeof(name1))] + name2[random(sizeof(name2))];
	set_name(name, ({ "beauty" }));
	set("gender", "Ů��");
	set("age", 15 + random(15));
	set("long", "����λ�б����߻�֮ò�ľ�ɫ��Ů���ڱ��ڵı��������е���ɽ��ˮ��\n");
	set("combat_exp", 10000);
	set("meitude", "peaceful");
        set("no_bark", 1);

	set("per", 30+random(10));
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 20);

        set_temp("apply/dexerity", 30);

	set("shen",100);
	set("max_qi", 20000);
	set("eff_jingli",20000);
	set("max_jing", 20000);
	set("max_neili", 5000);
	set("neili", 5000);
	set("inquiry", ([
		"laozu": 	(: ask_laozu :),
		"Ѫ������":	(: ask_laozu :),
		"����"	:	(: ask_laozu :),
        ]));

        set("location",1);
	set("no_quest", 1);

	setup();

	carry_object(ARMOR_D("skirt1"))->wear();
	carry_object(ARMOR_D("flower_shoe"))->wear();
	add_money("silver", random(5));
       
//	this_object()->start_call_out( (: call_other, this_object(), "display", this_object() :), 30);
	this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 1200);
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
	command("emote ��¶����֮ɫ�����ĵĵ���ͷȥ��");
}

void dest()
{
        command("emote �����뿪�ˡ�");
	destruct(this_object());
}
/*
void display()
{
	object me = this_object();

	if(!objectp(me->query("place"))) return;  // means BUG!!!
	me->move(me->query("place"));
        command("emote ���ű������������˹�����");
}
*/
void kill_ob(object ob)
{
	command("fear");
	command("!!!");
        ob->remove_killer(this_object());
        return;
}

void accept_fight(object me)
{
	command("fear");
	command("shake");
	return;       
}

string ask_laozu()
{
	if( this_player()->query("xs/girl_ob") == this_object() )
		return "��������ɱ����������";
	else
		return "�ţ�����˭ѽ��";
}
