// huang

inherit NPC;

void create()
{
	set_name("�ƴ���", ({ "huang daxiong", "huang" }));
	set("title", "������ؽ�");
	set("gender", "����");
	set("age", 43);
	set("str", 25);
	set("dex", 20);
	set("long", "���Ǹ������׳�������ݵľ��٣��������ף��ֳֵָ���\n");
        set("combat_exp", 250000);
        set("unique", 1);
	set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 90);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("liuhe-daofa", 90);
	map_skill("parry", "liuhe-daofa");
	map_skill("blade", "liuhe-daofa");
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("max_qi", 700);
	set("neili", 700); 
	set("max_neili", 700);
	set("jiali", 20);

	setup();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/armor")->wear();
}

int accept_fight(object me)
{
	command("say ���ٹ���������Ը��ͽ����˶��ֹ��С�");
	return 0;
}
