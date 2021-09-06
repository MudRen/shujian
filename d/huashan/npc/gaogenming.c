// NPC: /d/huashan/npc/gaogenming.c
// Date: Look 99/03/25
// Lklv Modify at 2001.10.18

inherit NPC;

void create()
{
	set_name("�߸���", ({ "gao genming", "gao", "genming" }));
	set("nickname", "�о�����");
	set("long",
"�߸�����Ľ��֣���һ��С����������������һ�˳ӣ�����\n"
"ͬ�������е��壬�ǻ�ɽ������һ���еĺ��֡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 28);
	set("int", 24);
	set("con", 20);
	set("dex", 20);

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
	set_skill("cuff", 100);
	set_skill("zixia-gong", 100);
	set_skill("huashan-jianfa", 100);
	set_skill("huashan-shenfa", 100);
	set_skill("poyu-quan", 100);
	set_skill("zhengqi-jue", 100);

	map_skill("force", "zixia-gong");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("cuff", "poyu-quan");

	prepare_skill("cuff", "poyu-quan");

	create_family("��ɽ��", 14, "����");

	setup();
	carry_object(BINGQI_D("sword"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}
