// jianjie ���
// Lklv modify 2001.9.27

inherit NPC;
void create()
{
	set_name("���", ({ "jian jie", "jian" }));
	set("nickname", "ʥ������");
	set("long", "��ʮ��������ӣ�һ˫�۾�΢΢�з졣\n"
			"��˵һ��������˵á�\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen", -10000);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);

	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 800000);


	set_skill("force", 110);
	set_skill("huagong-dafa", 110);
	set_skill("dodge", 110);

	set_skill("zhaixingshu", 110);
	set_skill("cuff", 110);
	set_skill("wudang-quan", 110);
	set_skill("parry", 110);
	set_skill("staff", 110);
	set_skill("tianshan-zhang", 110);
	set_skill("literate", 110);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixingshu");
	map_skill("cuff", "wudang-quan");
	map_skill("parry", "wudang-quan");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("cuff", "wudang-quan");

//	create_family("", 2, "����");

	setup();
	carry_object(BINGQI_D("gangzhang"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("gold", 1);
}