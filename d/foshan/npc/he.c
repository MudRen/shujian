//he.c  ��ʦү

inherit NPC;
//inherit F_DEALER;

void create()
{
        set_name("��ʦү", ({ "he shiye", "he" }));
        set("long", "������һ����ü���۵����ӣ�һ����֪��һ���ӻ�ˮ��\n");
        set("gender", "����" );
        set("age", 35);
	set("attitude", "friendly");
	set("shen", -2000);

	set("str", 22);
        set("int", 25);
        set("con", 22);
        set("dex", 21);

	set("max_qi",300);
        set("max_jing",300);
        set("neili",300);
        set("max_neili",300);

        set("jingli",150);
        set("eff_jingli",150);
        set("jiali", 1);   
	set("combat_exp", 20000);

	set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("strike", 30);
        set_skill("parry", 30);
       
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

