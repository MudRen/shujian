//Cracked by Roath
// he sheng ��ʢ

inherit NPC;

void create()
{
	set_name("��ʢ", ({ "he sheng","he" }));
//      set("nickname", "");
	set("long",
		"�޸����˵Ĵ���ӡ�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
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
	set("combat_exp", 20000);
	set("score", 50000);
	set("shen", -5000);

	set_skill("force", 40);
	set_skill("dulong-dafa", 40);
	set_skill("dodge", 40);
	set_skill("lingshe-shenfa", 30);
	set_skill("strike", 40);
	set_skill("huagu-mianzhang", 30);
	set_skill("parry", 30);
	set_skill("blade", 40);
//      set_skill("magic", 60);
	set_skill("literate", 20);
//      set_skill("shenlong-magic", 40);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
//      map_skill("magic", "shenlong-magic");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("������", 3, "�����ŵ���");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();

}
