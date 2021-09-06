// /d/city/npc/wenyi

inherit NPC;
 
void create()
{
	set_name("����", ({ "wen yi", "wen" }));
	set("long", 
        "�����ǽ����ɾ����������ǡ�\n"
        "һλ��ʮ�����Ů�ӣ���ò���㣬����һ�ֳ������ζ��\n");
	set("gender", "Ů��");
	set("age", 36);
	set("attitude", "friendly");
	set("shen", 1000);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 10);
	set("combat_exp", 5000);
	 

    set_skill("force", 10);
    set_skill("yijin-jing", 10);
    set_skill("dodge", 10);

    set_skill("shaolin-shenfa", 10);
    set_skill("cuff", 10);
    set_skill("wenjia-daofa", 10);
    set_skill("parry", 10);
    set_skill("blade", 10);
    set_skill("wenjia-quan", 10);
    set_skill("literate", 10);

	map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-daofa");
  	map_skill("blade", "wenjia-daofa");
       prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
  	 
     
}
void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("���Ƕ�$N����һЦ����ת����ȥ��ü���û��˿���־塣��\n", ob);
	message_vision("$N���к�Ȼ���ã����Լ����������޳ܣ���һ�����޴�������ҲҪ�´˶��֣���\n", ob);
}