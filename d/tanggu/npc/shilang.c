
inherit NPC;

void create()
{
	set_name("ʩ��", ({ "shi lang", "shi" }));
	set("title", "����ˮ���ᶽ");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 30);
	set("long", "���˾��Ǵ���ˮ���ᶽ��һ���佫����������ݡ�\n");

	set_skill("cuff", 120);
	set_skill("dodge", 120);
	set_skill("taizu-quan", 120);
	set_skill("xiaoyaoyou", 120);
	set_skill("force", 120);
	set_skill("huntian-qigong", 120);
	set_skill("parry", 120);
	set_skill("literate", 100);
	
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian-qigong");
	prepare_skill("cuff", "taizu-quan");

	set_temp("apply/damage", 50);

	set("combat_exp", 300000);
	set("attitude", "friendly");
		
	setup();
	carry_object(ARMOR_D("armor"))->wear();
}
