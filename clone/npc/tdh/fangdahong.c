// fangdahong.c ����� tdh

inherit NPC;
#include "tdh_npc.h"

void create()
{
	int x=3;
	set_name("�����", ({ "fang dahong", "fang", "dahong" }));
	set("gender", "����");
	set("age", 40);
	set("shen_type", 1);
	set("��ػ�/tangkou","��˳��");
	set("��ػ�/title","����");
	if ( random(10) >7 ) set("long","������ػ�ĺ�˳��������");

        set("str", 35);
        set("int", 25);
        set("con", 25);
        set("dex", 35);
        set("max_qi", 3600);
        set("max_jing", 1800);
        set("max_jingli", 2200);
        set("neili", 6000);
        set("max_neili", 4400);
        set("jiali", 50);
        set("combat_exp", 2200000);

	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("taizu-quan", 200);
	set_skill("weituo-zhang", 200);
	set_skill("yijin-jing", 200);
	set_skill("shaolin-shenfa", 200);

	map_skill("force", "yijin-jing");
	map_skill("cuff","taizu-quan");
	map_skill("strike","weituo-zhang");
	map_skill("dodge","shaolin-shenfa");
	map_skill("parry","weituo-zhang");
        random(x)>1 ? prepare_skill("cuff","taizu-quan"):prepare_skill("strike","weituo-zhang");

	set_temp("apply/attack", 35);

	set("inquiry", ([
		"������": (: ask_join :),
		"��ػ�": (: ask_tdh :),
		"����": (: ask_tdh :),
		"���帴��": (: ask_fq :),
		"�½���": (: ask_chen :),
		"֣�ɹ�": (: ask_zheng :),
		"����ү": (: ask_zheng :),
		"����ү": (: ask_zheng :),
		"�������ʫ": (: ask_sandian :),
		"�п�": (: ask_qk :),
		"����": (: ask_qk :),
		"�": (: ask_job :),
		"job": (: ask_job :),
	]));
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 10 + random(20));
}
