//song.c ���ϰ� 

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("���ϰ�", ({ "song", "laoban" }));
	set("long",
		"���ϰ������������ķ�ɽ�ˣ�������һ�ڷ��Խк��š�\n");
	set("title", "С�Ե��ϰ�");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen", 1000);

	set("str", 22);
        set("int", 25);
        set("con", 18);
        set("dex", 18);

	set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 100);
        set("max_neili", 100);

        set("jingli",100);
        set("max_jingli",100);
        set("jiali", 1);   
	set("combat_exp", 5000);

	set_skill("cuff", 50);
	set_skill("dodge", 50);
	set_skill("force", 50);
        set_skill("parry", 50);
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
