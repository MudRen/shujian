// /kungfu/class/nshaolin/yuanshang.c
// looklove 2001.7.21

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("Ԫ������", ({
                "yuanbei zunzhe",
                "yuanbei",
                "zunzhe",
        }));
        set("long",
                "һλ�еȵ�׳��ɮ�ˣ�����·���������硣\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 39);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2800);
        set("max_jing", 2000);
        set("neili", 6000);
        set("max_neili", 4000);
        set("jiali", 150);
        set("combat_exp", 1000000);
        set("score", 500000);

        set_skill("force", 175);
        set_skill("yijin-jing", 175);
        set_skill("dodge", 175);
        set_skill("shaolin-shenfa", 175);
        set_skill("parry", 175);
        set_skill("claw", 175);
        set_skill("blade", 175);
        set_skill("finger", 175);
        set_skill("longzhua-gong", 175);
        set_skill("xiuluo-dao", 175);
        set_skill("yizhi-chan", 175);
        set_skill("medicine", 120);
        set_skill("buddhism", 200);
        set_skill("literate", 140);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "longzhua-gong");
        map_skill("finger", "yizhi-chan");
        map_skill("blade", "xiuluo-dao");
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

        setup();

	carry_object(BINGQI_D("blade/jiedao"))->wield();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
	carry_object("/d/putian/npc/obj/sengxie")->wear();
}

