// /kungfu/class/nshaolin/tian-hong.c
// looklove 2001.7.21

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����ʦ", ({
                "tianhong chanshi",
                "tianhong",
                "chanshi",
        }));
        set("long",
                "����ɫ�Ͱ���������ɫ��üë���Ʈ�ݣ���������ɫ����\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 62);
        set("shen_type", 100);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 4300);
        set("max_jing", 3100);
        set("neili", 22000);
        set("max_neili", 12000);
        set("jiali", 150);
        set("combat_exp", 3800000);

        set_skill("force", 380);
        set_skill("yijin-jing", 380);
        set_skill("dodge", 380);
        set_skill("shaolin-shenfa", 380);
        set_skill("parry", 380);
        set_skill("claw", 380);
        set_skill("leg", 280);
        set_skill("club", 280);
        set_skill("finger", 380);
        set_skill("longzhua-gong", 380);
        set_skill("weituo-chu", 280);
        set_skill("yizhi-chan", 380);
        set_skill("medicine", 120);
        set_skill("buddhism", 200);
        set_skill("literate", 140);
        set_skill("zui-gun",200);
        set_skill("ruying-suixingtui", 280);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("claw", "longzhua-gong");
        map_skill("finger", "yizhi-chan");
        map_skill("club", "weituo-chu");
        map_skill("parry", "yizhi-chan");
        map_skill("leg", "ruying-suixingtui");

        prepare_skill("claw", "longzhua-gong");
        prepare_skill("finger", "yizhi-chan");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.wofo" :),
		(: perform_action, "claw.canyun" :),
		(: perform_action, "leg.ruying" :),
	}));

        create_family("������", 23, "����");
        set("title", "�����ַ���");

        setup();

	carry_object("/d/shaolin/obj/du-cloth")->wear();
	carry_object("/d/shaolin/obj/sengxie")->wear();
}
