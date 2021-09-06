// tdhjob ��2������ npc by Lklv

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"
#include "man2.h"

string *rtitle = ({"����־ʿ", "��çӢ��", "���ֺú�"});

void create()
{
	string str, s_sword,s_blade,s_club,s_whip,s_staff,s_dodge, weapon;
	mapping name;

	name = RNAME_D->get_random_name(1);
	str = rtitle[random(sizeof(rtitle))];
	s_sword = sword_skill[random(sizeof(sword_skill))];
	s_blade = blade_skill[random(sizeof(blade_skill))];
	s_club  = club_skill[random(sizeof(club_skill))];
	s_whip  = whip_skill[random(sizeof(whip_skill))];
	s_staff = staff_skill[random(sizeof(staff_skill))];
	s_dodge = dodge_skill[random(sizeof(dodge_skill))];
	weapon = weapon_list[random(sizeof(weapon_list))];

	set_name(name["name"], name["id"]);
	set("gender", "����");
	set("shen", DE_LVL*10);
	set("age", 20 + random(40));
	set("meitude", "peaceful");
	set("title", str);
	set("no_get", 1);
	set("no_quest", 1);
	set("no_bark", 1);

	set("max_qi", DE_LVL*25-DE_GIFT*5);
	set("max_jing", DE_LVL*10-DE_GIFT*10);
	set("eff_jingli", DE_LVL*10);
	set("combat_exp", 500000);

	set("str", DE_GIFT+random(DE_GIFT/4));
	set("dex", DE_GIFT+random(DE_GIFT/4));
	set("int", DE_GIFT+random(DE_GIFT/4));
	set("con", DE_GIFT+random(DE_GIFT/4));

	set_skill("sword", DE_LVL);
	set_skill("dodge", DE_LVL);
	set_skill("cuff", DE_LVL);
	set_skill("force", DE_LVL);
	set_skill("parry", DE_LVL);
	set_skill("blade", DE_LVL);
	set_skill("hammer", DE_LVL);
	set_skill("club", DE_LVL);
	set_skill("staff", DE_LVL);
	set_skill("whip", DE_LVL);
	set_skill("xinyuegong", DE_LVL);
	set_skill("taiji-shengong", DE_LVL);
	set_skill("taizu-quan", DE_LVL);
	set_skill("literate", query("int") * 10);
	set_skill(s_sword, DE_LVL);
	set_skill(s_blade, DE_LVL);
	set_skill(s_club, DE_LVL);
	set_skill(s_whip, DE_LVL);
	set_skill(s_staff, DE_LVL);
	set_skill(s_dodge, DE_LVL);
	map_skill("force", "taiji-shengong");
	map_skill("sword", s_sword);
	map_skill("dodge", s_dodge);
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
	map_skill("hammer", "xinyuegong");
	map_skill("blade", s_blade);
	map_skill("club", s_club);
	map_skill("whip", s_whip);
	map_skill("staff", s_staff);
	prepare_skill("cuff", "taizu-quan");

	set("inquiry", ([
		"��ػ�": (: ask_tdh :),
		"���帴��": (: ask_fq :),
		"�½���": "������˵����ƽ����ʶ�½��ϣ��ͳ�Ӣ��Ҳ��Ȼ����\n",
		"֣�ɹ�": "����ү�ǵ�����һӢ��\n",
		"����ү": "����ү�ǵ�����һӢ��\n",
	]));
	setup();

	carry_object(BINGQI_D(weapon))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 20 + random(20));
	if (clonep())
		call_out("dest", 1200);
}
