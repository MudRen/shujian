// shatongtian.c ɳͨ��

inherit NPC;
 
void create()
{
	set_name("ɳͨ��", ({ "shatong tian", "tian" }));
	set("nickname", "��������");
	set("long", 
        "�����ǻƺ��Ĺ��ɱͨ�졣\n"
        "�������⣬�۾���ð���׹⡣\n");
	set("gender", "����");
	set("age", 36);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2000);
	set("max_jing", 800);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("combat_exp", 550000);
	set("score", 100000);

    set_skill("force", 120);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 120);

    set_skill("shaolin-shenfa", 120);
    set_skill("cuff", 100);
    set_skill("damo-jian", 100);
    set_skill("parry", 100);
    set_skill("sword", 120);
    set_skill("jingang-quan", 80);
    set_skill("literate", 10);

	map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "jingang-quan");
  	map_skill("parry", "damo-jian");
  	map_skill("sword", "damo-jian");
       prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	carry_object("/clone/weapon/changjian")->wield();
        add_money("gold", 7);
}