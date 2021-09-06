// by cool 98.6.1
// �ı���caiji@SJ 8/24/2000
// River@SJ

#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include "skill.h";

string *color_title = ({YEL+"����ɱ��"+NOR, HIR+"��ȸɱ��"+NOR,HIW+"�׻�ɱ��"+NOR, HIC+"����ɱ��"+NOR});
string *k_weapon = ({"sword","blade","staff","whip","gun",});

void create()
{
	object cloth;
	mapping name;
	int i;

	i = random(4);

	name = RNAME_D->get_random_name(i);

	set_name(name["name"], name["id"]);
	set("title", color_title[random(sizeof(color_title))]);
	set("gender", (i==0?"Ů��":"����"));
	set("long", "��������ɫ��װ����������һ��ڲ���ֻ¶��һ˫�۾����������䡣\n");
	set("age", random(10)+24);
	set("str", 15+random(10));
	set("int",15+random(10));
	set("con",15+random(10));
	set("dex",15+random(10));
	set("combat_exp", 100000);
	set("no_quest", 1);
	set("shen_type", -1);
	set("attitude", "friendly");
	set("max_qi",1200);
	set("max_jing",1200);
	set("neili",1000);
	set("max_neili",1000);
	set("score", 100);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	setup();
	add_money("silver", random(50)+50);

	cloth = new(ARMOR_D("cloth"));
	cloth->set("name","��ɫ��װ");
	cloth->set("apply/armor", 40);
	cloth->move(this_object());
	cloth->wear();
}

#include "shashou.h";
