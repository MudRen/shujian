// NPC: /d/huashan/npc/shidaizi.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
	set_name("ʩ����", ({ "shi daizi", "shi", "daizi" }));
	set("long",
"ʩ������ĸ�������������ͨͨ����˫�۾�����������\n"
"ͬ�������е��ģ��ǻ�ɽ������һ���еĺ��֡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 20);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 3000);
	set("max_jing", 1800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("eff_jingli", 1800);

	set("jiali", 50);
	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("blade", 100);
	set_skill("strike", 100);
	set_skill("zixia-gong", 100);
	set_skill("huashan-jianfa", 100);
	set_skill("huashan-shenfa", 100);
	set_skill("zhengqi-jue", 100);

	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}
