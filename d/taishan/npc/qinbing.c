// wu-shi1.c �ױ��ӳ�

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ױ��ӳ�", ({ "qinbing duizhang", "duizhang", "qinbing" }) );
	set("gender", "����");
	set("age", 40);
	set("long",
		"�����ǵ�������ͨ�����ױ��ӳ�, �������ף���ִ�ֽ���\n");

	set("combat_exp", 400000);
	set("attitude", "heroism");
        set("unique", 1);

	set("str", 24);
	set("con", 22);
	set("int", 22);
	set("dex", 22);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 300);
	set("jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 50);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("sword", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
        set("chat_chance", 3);

	setup();

        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/armor")->wear();
}
