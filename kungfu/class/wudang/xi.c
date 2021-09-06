// xi.c ����Ϫ

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����Ϫ", ({ "zhang songxi", "zhang" }));
	set("nickname", "�䵱����");
	set("long", 
		"��������������ĵ�������Ϫ��\n"
		"��������ʮ�꣬�����ܸɣ������Ƕ�ı���ơ�\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen", 8000);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	set("unique", 1);
	set("max_qi", 1500);
	set("max_jing", 1200);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("eff_jingli",2000);

	set_skill("force", 120);
        set_skill("yinyun-ziqi", 120);
	set_skill("dodge", 120);
	set_skill("tiyunzong", 120);
	set_skill("cuff", 120);
	set_skill("taiji-quan", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("taiji-jian", 120);
	set_skill("taoism", 100);
	set_skill("literate", 100);

        map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	prepare_skill("cuff", "taiji-quan");

	create_family("�䵱��", 2, "����");

	setup();
        carry_object("/d/wudang/obj/white-robe")->wear();
	carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/daolv")->wear();
}

void kill_ob(object me)
{
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
           (: perform_action, "sword.chan" :),
           (: perform_action, "dodge.zong" :),
           (: perform_action, "cuff.zhen" :),
        }));
        ::kill_ob(me);       
}

void attempt_apprentice(object ob)
{
       mapping fam = ob->query("family");
       if (!fam || fam["family_name"] != "�䵱��"){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
       }
       if ((int)ob->query("shen") < 10000) {
	       command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
	       command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
		       "�Ƿ����ò�����");
	       return;
       }
       if ((int)ob->query_skill("yinyun-ziqi", 1) < 80) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ�����������϶��µ㹦��");
                return;
       }
       if (ob->query_int() < 28) {
                command("say ���䵱���书ȫ�ӵ��������");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
       }
       command("say �ðɣ�ƶ�����������ˡ�");
       command("recruit " + ob->query("id"));
}
