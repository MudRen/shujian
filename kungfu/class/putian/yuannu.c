// /kungfu/class/nshaolin/yuannu.c
// looklove 2001.7.21

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ԫŭ����", ({
                "yuannu zunzhe",
                "yuannu",
                "zunzhe",
        }));
        set("long",
                "һλ��ɫ���ϵ�����ɮ�ˣ����ϵ����鲻ŭ������\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 41);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3200);
        set("max_jing", 2000);
        set("neili", 6000);
        set("max_neili", 4000);
        set("jiali", 20);
        set("combat_exp", 1200000);

        set("fenwo", 1000);
        set_skill("force", 180);
        set_skill("yijin-jing", 180);
        set_skill("dodge", 180);
        set_skill("shaolin-shenfa", 180);
        set_skill("parry", 180);
        set_skill("claw", 180);
        set_skill("blade", 180);
        set_skill("finger", 180);
        set_skill("longzhua-gong", 180);
        set_skill("ranmu-daofa", 180);
        set_skill("yizhi-chan", 180);
        set_skill("medicine", 120);
        set_skill("buddhism", 200);
        set_skill("literate", 140);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "longzhua-gong");
        map_skill("finger", "yizhi-chan");
        map_skill("blade", "ranmu-daofa");
        map_skill("parry", "yizhi-chan");

        prepare_skill("claw", "longzhua-gong");
        prepare_skill("finger", "yizhi-chan");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.wofo" :),
		(: perform_action, "claw.canyun" :),
		(: perform_action, "blade.fenwo" :),
		(: perform_action, "blade.fenxin" :),
		(: perform_action, "blade.fentian" :),
	}));

        create_family("������", 23, "����");

        setup();

	carry_object("/d/shaolin/obj/mudao")->wield();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
	carry_object("/d/shaolin/obj/sengxie")->wear();
}

