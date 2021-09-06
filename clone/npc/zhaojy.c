// zhaojy.c �Ͼ�ү

inherit NPC;

void consider();

void create()
{
	set_name("�Ծ�ү", ({ "zhao jueye","zhao","jueye" }) );
	set("gender", "����" );
	set("age", 67);
	set("long", "��ͷ����������ɫ��������׳�꣬˫Ŀ��������\n");
	set("attitude", "peaceful");
        set("str", 28);
	set("con", 21);
	set("int", 20);
	set("dex", 25);


	set("max_qi", 1500);
	set("max_jing", 1800);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("shen", 8000);
	set("startroom","/d/city/beidajie3");


	set("combat_exp", 950000);

	set_skill("force", 140);
	set_skill("cuff", 150);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("yinyun-ziqi", 140);
	set_skill("literate", 120);
	set_skill("taizu-quan", 150);
	set_skill("tiyunzong", 140);
        map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");


	set("chat_chance", 10);
	set("chat_msg", ({
		"�Ծ�ү����̾�˿������������������������ұ�����Щʲô�أ���\n",
		"�Ծ�ү���˴�ü���ƺ���ҪѰ��ʲô��\n",
		(: random_move :)
	}) );

	setup();
        carry_object(ARMOR_D("changshan4"))->wear();
        carry_object(ARMOR_D("buxue"))->wear();
        carry_object(ARMOR_D("ryyaodai"))->wear();
	add_money("silver",30+random(30));
}
