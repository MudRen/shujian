//Cracked by Roath
// liu yan ����

inherit NPC;

void create()
{
	set_name("����", ({ "liu yan","liu" }));
//      set("nickname", "");
	set("long",
		"�ŵ��µĵ��ӣ���̬���ʣ��������£���С���\n");
	set("gender", "Ů��");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 25);
	set("con", 26);
	set("dex", 26);
	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jingli", 500);
	set("max_jingli", 500);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("score", 50000);
	set("shen", -6000);

	set_skill("force", 40);
	set_skill("dulong-dafa", 30);
	set_skill("dodge", 50);
	set_skill("lingshe-shenfa", 50);
	set_skill("strike", 30);
	set_skill("huagu-mianzhang", 20);
	set_skill("parry", 40);
	set_skill("kick", 50);
	set_skill("jueming-tui", 40);
	set_skill("hook", 20);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("kick", "jueming-tui");

	prepare_skill("kick", "jueming-tui");

	create_family("������", 3, "�����ŵ���");

	setup();
	carry_object("/clone/armor/flower_shoe")->wear();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/hook")->wield();

}
