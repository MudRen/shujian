// yulingzi.c (kunlun)

inherit NPC;

void create()
{
	set_name("������", ({ "yuling zi","yuling", "zi" }));
	set("long",
		"���������ɵ�������ӣ�������������ķ���������Ͷ�����ŵ�����֮�⡣\n");
	set("gender", "Ů��");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 600);
	set("max_jing", 400);
	set("eff_jingli", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 70000);
	set("score", 5000);

	set_skill("force", 40);
	set_skill("xuantian-wuji", 65);
	set_skill("dodge", 60);
	set_skill("taxue-wuhen", 65);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("liangyi-jian", 65);
	set_skill("leg", 50);
	set_skill("chuanyun-tui", 60);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("leg", "chuanyun-tui");
              map_skill("sword", "liangyi-jian");
              map_skill("parry", "liangyi-jian");


        prepare_skill("leg", "chuanyun-tui");
	create_family("������", 5, "����");
	setup();
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}
void attempt_apprentice(object ob)
{
        if(ob->query("gender")=="����"){
	    command("fear");
	    command("say "+RANK_D->query_respect(ob)+"ʦ����׼�����е��ӣ���ȥ����ʦ��ȥ�ɡ�");
   	    return;
	}
	if(ob->query("appren_hezudao") == 1) {
	    command("say ʦ�����ҿ������Ц����ȴ�����򲻸ҵģ�");
	    return;
	}
	command("say �ðɣ��Ҿ������㣬����һЩƤë����");
	command("recruit " + ob->query("id"));
}
