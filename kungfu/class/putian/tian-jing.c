// /kungfu/class/nshaolin/tian-jing.c
// looklove 2001.9.12

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�쾵��ʦ", ({
                "tianjing chanshi",
                "tianjing",
                "chanshi",
        }));
        set("long",
                "���������ݣ�ȫ���ƺ����⣬����ȥ��ŭ��������\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 62);
        set("shen_type",1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4800);
        set("max_jing", 4000);
        set("neili", 8000);
        set("max_neili", 6000);
        set("jiali", 150);
        set("combat_exp", 3000000);
        set("score", 500000);

        set_skill("force", 280);
        set_skill("yijin-jing", 280);
        set_skill("dodge", 280);
        set_skill("shaolin-shenfa", 280);
        set_skill("parry", 280);
        set_skill("claw", 280);
        set_skill("club", 280);
        set_skill("finger", 280);
        set_skill("longzhua-gong", 280);
        set_skill("weituo-chu", 280);
        set_skill("yizhi-chan", 280);
        set_skill("medicine", 120);
        set_skill("buddhism", 200);
        set_skill("literate", 140);
        set_skill("zui-gun",200);
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "longzhua-gong");
        map_skill("finger", "yizhi-chan");
        map_skill("club", "weituo-chu");
        map_skill("parry", "yizhi-chan");

        prepare_skill("claw", "longzhua-gong");
        prepare_skill("finger", "yizhi-chan");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.wofo" :),
		(: perform_action, "claw.canyun" :),
	}));

        create_family("������", 23, "����");
        set("title", "��ĦԺ����");

        setup();

	carry_object("/d/shaolin/obj/du-cloth")->wear();
	carry_object("/d/shaolin/obj/sengxie")->wear();
}

void init()
{
        object me, ob;

        ::init();

        ob = this_player();
        me = this_object();

	if (interactive(ob) && ob->query_temp("target_putian")){
		command("say �󵨿�ͽ�����Ҵ���������������Ұ������");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);

        }
}