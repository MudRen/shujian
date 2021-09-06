// wu-shi1.c 

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������ʿ", ({ "wei shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"����λ������ʿ�������ּף���ִ������˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
	set("combat_exp", 200000);
        set("shen_type", 1);
	set("attitude", "heroism");

        set("str", 25);
	set("con", 25);
	set("int", 20);
        set("dex", 25);
        set("no_get",1);

	set("max_qi", 600);
	set("eff_qi", 600);
	set("qi", 600);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 30);
	set("shen_type", 0);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword", 100);
	set_skill("unarmed", 80);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	setup();

        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object(__DIR__"obj/tiejia")->wear();
}

