// houtonghai.c ��ͨ��

inherit NPC;
 
void create()
{
	set_name("��ͨ��", ({ "houtong hai", "hai" }));
	set("nickname", "��ͷ��");
	set("long", 
        "�����ǻƺ��Ĺ�ĺ�ͨ����\n"
        "�����������¶а����һ���Ͳ��Ǻ��ˡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 100000);

    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 120);

    set_skill("shaolin-shenfa", 120);
    set_skill("cuff", 100);
    set_skill("parry", 120);
    set_skill("taizu-quan", 140);
    set_skill("literate", 20);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "taizu-quan");
  	map_skill("parry", "taizu-quan");
  	prepare_skill("cuff", "taizu-quan");
 
        setup();
  	carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 5);
}