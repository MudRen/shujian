//jiading.c �Ҷ�

inherit NPC;

void create()
{
	set_name("�Ҷ�", ({ "jia ding", "jia" }));
        set("long", "��ǣ���������ǹ��������������������ӡ�\n");
	set("gender", "����");
	set("age", 35);
	set("shen", -5000);

	set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 10);

	set("max_qi",400);
        set("max_jing",400);
        set("neili",400);
        set("max_neili",400);

          set("jingli",200);
          set("eff_jingli",200);
        set("jiali", 10);   
	set("combat_exp",30000);

	set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("strike", 60);
        set_skill("parry", 60);
	setup();

	add_money("silver",10);
	carry_object("/clone/misc/cloth")->wear();
}
	
