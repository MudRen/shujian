// yu.c ������

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "yu lianzhou", "yu" }));
        set("nickname", "�䵱����");
        set("long", 
                "������������Ķ����������ۡ�\n"
                "��������ʮ�꣬��Ŀ��࣬�������ء�\n"
                "�����䵱�����������ڶ�������ȴ�����\n");
        set("gender", "����");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen", 12000);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        set("unique", 1);
        set("max_qi",5000);
        set("eff_jingli",2500);
        set("max_jing", 1500);
        set("neili",5000);
        set("max_neili", 2500);
        set("jiali", 150);
        set("combat_exp",2000000);

        set_skill("force", 140);
        set_skill("yinyun-ziqi", 140);
        set_skill("dodge",180);
        set_skill("tiyunzong",180);
        set_skill("wudang-quan",180);
        set_skill("cuff",180);
        set_skill("hand",180);
        set_skill("taiji-quan", 150);
        set_skill("juehu-shou",180);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("taiji-jian", 140);
        set_skill("taoism", 140);
        set_skill("literate", 100);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        map_skill("cuff", "wudang-quan");
        map_skill("hand", "juehu-shou");

        prepare_skill("cuff", "wudang-quan");
        prepare_skill("hand", "juehu-shou");

        create_family("�䵱��", 2, "����");

        setup();
//      carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
        carry_object("/d/wudang/obj/daolv")->wear();
}

void kill_ob(object me)
{
        set("neili", 5000); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
              (: perform_action, "dodge.zong" :),
        }));
        ::kill_ob(me);
}

void attempt_apprentice(object ob)
{
        object me;
        me=this_player();
        if ((int)ob->query("shen") < 10000) {
                command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
                command("say " + RANK_D->query_respect(ob) + "��������" +
                   "��������֮�£��ҾͿ������㡣");
                return;
        }
	if ((int)ob->query_skill("taoism",1) < 100) {
                command("say ��ĵ�ѧ��Ϊ������ֻ�������ѧ�����������ֺ��ȥ���ˣ�");
                return;
        }
	if (ob->query("gender") != "����" && ob->query("gender") != "Ů��") {
                command("say �������������������ѧ�����֣�");
                return;
        }
        if (present("letters", me)){
        	destruct(present("letters",me));
                command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "����ʦ�ܵĽ����ţ�Ҳ��" +
                        "�ұ����ˣ������������ɡ�");
                command("recruit " + ob->query("id"));
        }
        else
                command("say �ҶԵ���Ҫ���ϡ����ĵ������߲���ѧ������������!");
        return;
          
}

int do_kill(string arg)
{
        object ob,me = this_player();

        if (!living(this_object())) return 0;
        if (!arg) return 0;
        if (!(ob = present(arg, environment()))) return 0;
        if (ob == me) return 0;
        if (ob->query("family/family_name") != "�䵱��") return 0;
        
        command("say �󵨿�ͽ���������䵱����������");
        command("stare "+this_player()->query("id"));
        message_vision("�����۹�����Ц������\n", this_player());
        kill_ob(me);
        return 1;
}

void init()
{
        ::init();
        if (query("startroom") != base_name(environment())) return;
        add_action("do_kill", "kill");
        add_action("do_kill","hit");
}
