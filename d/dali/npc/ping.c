// ping.c ƽһָ

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���ϰ�", ({ "zhang laoban", "zhang", "laoban" }));
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "���Ǵ������Ψһ��ҽʦ��\n");
	set("age", 65);
        set("unique", 1);
	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("jingli", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 5);
	set("shen_type", 1);

	set("combat_exp", 50000);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 7);
	set_temp("apply/defense", 7);
	set_temp("apply/damage", 5);

	setup();
	add_money("silver", 5);
	carry_object("/clone/armor/cloth")->wear();
}
