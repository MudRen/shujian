// moshenggu.c
// by ydh
// Modified by Lklv for raozhi Quest @@
// 2002.12.12 lane add gold
// By Spiderii �޸�GIVE GOLD ������
inherit NPC;
inherit F_MASTER;

int ask_me_1(object who);
int ask_raozhi();

void create()
{
        set_name("Ī����", ({ "mo shenggu", "mo" }));
        set("nickname", "�䵱����");
        set("long",
                "��������������ߵ���Ī���ȡ�\n"
                "��������ᣬ����Ŀ��࣬�����ܸɡ�\n");
        set("gender", "����");
        set("age", 22);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("unique", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);

        set("max_qi", 1800);
        set("eff_jingli",1000);
        set("max_jing",1300);
        set("neili", 3500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 900000);
        set("score", 5000);

        set_skill("force", 150);
        set_skill("yinyun-ziqi", 160);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 160);
        set_skill("cuff", 180);
        set_skill("taiji-quan", 160);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("taiji-jian", 170);
        set_skill("taoism", 120);
        set_skill("literate", 130);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");

        create_family("�䵱��", 2, "����");

        set("inquiry", ([
                //"��ɽ" : (: ask_me_1 :),
                "��ָ�ὣ" : (: ask_raozhi :),
                "��ָ" : (: ask_raozhi :),
        ]));

        setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object("/d/wudang/obj/white-robe")->wear();
        carry_object("/d/wudang/obj/daolv")->wear();
}

int ask_raozhi()
{
        object me = this_player();

        if (me->query("raozhi")){
        	command("knock "+me->query("id"));
		return 1;
	}
        if (me->query_temp("raozhi")) {
            command("say ���Ǹ�������ô��");
            return 1;
        }
        if (me->query("family/family_name") != "�䵱��") {
		command("mimi "+me->query("id"));
		return 1;
        }
        if (random(3)>1 && me->query("family/family_name") == "�䵱��") {
		command("say ���Ƕ�ʦ�����ҵ�һ�����⽣�С�");
		command("say ����ѧ���ã��޷���ͨ���㻹������ȥ������ɡ�");
		me->set_temp("raozhi",1);
		return 1;
        }
        return 0;
}


int ask_me_1(object who)
{
	object me = this_player();
	

	if( me->query("family/family_name") != "�䵱��" ) {
		command("hmm "+(string)me->query("id"));
		command("say ������ɵ��ӣ�Ҳ�������ĳ�����\n");
		return 1;
	}

	if( me->query("shen") < 10000 ) {
		command("pat "+(string)me->query("id"));
		command("say ��������������������Ǳ���ɽ�ĺã�\n");
		return 1;
	}
        if( (int)me->query_skill("yinyun-ziqi", 1) < 216 ) {
		command("pat "+(string)me->query("id"));
		command("say ���书δ�ɣ����Ǳ���ɽ�ĺð���\n");
		return 1;
	}

	if( (int)me->query("wudang_given") <(int)me->query("age")){
		 command("nod "+(string)me->query("id"));
               who->add_money("gold",(int)(me->query_skill("yinyun-ziqi", 1)/2) );
               command("give "+me->query("id")+" "+(int)(me->query_skill("yinyun-ziqi", 1))/2+" gold");
                me->set("wudang_given",(int)me->query("age"));

		command("say ���䵱�������������£������ЩǮȥ��ǿ�����ɣ�");
	} else command("say ����ɽ��Ҫ���������壬Ҫ��Ϊ���������ұ������Ż���");
	return 1;
}

void attempt_apprentice(object ob)
{
       if( (int)ob->query("shen") < 10000 ) {
	       command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
	       command("say �ڵ��з��棬" + RANK_D->query_respect(ob) + "�Ƿ����ò�����");
	       return;
	}
	if( (int)ob->query_skill("yinyun-ziqi", 1) < 30 ) {
		command("say ���䵱�����ڼ��书���������ڹ��ķ���");
		command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�����������϶��µ㹦��");
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
