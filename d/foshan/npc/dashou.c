//dashou.c  ����

inherit NPC;

void create()
{
        set_name("����", ({ "da shou", "da" }));
        set("long", "������ɫ��������ֱ��վ���ţ�Ŀ���׺ݡ�\n");
        set("gender", "����" );
        set("age", random(20) + 30);
        set("combat_exp", 50000);
        set("attitude", "peaceful");

	set("str", 30);
        set("int", 10);
        set("con", 10);
        set("dex", 30);

	set("max_qi",500);
        set("max_jing",500);
        set("neili",500);
        set("max_neili",500);

        set("jingli",500);
        set("eff_jingli",500);
        set("jiali", 30);   
	set("combat_exp", 50000);

        set_skill("cuff", 60);
        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        
        setup();
        add_money("silver", random(20));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

