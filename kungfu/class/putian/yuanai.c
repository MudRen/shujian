// /kungfu/class/nshaolin/yuanai.c
// looklove 2001.7.21

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ԫ������", ({
                "yuanai zunzhe",
                "yuanai",
                "zunzhe",
        }));
        set("long",
                "��������ݣ���ɫ���ƣ��·�󲡳��������ӡ�\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 45);
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

        set_skill("force", 140);
        set_skill("yijin-jing", 140);
        set_skill("dodge", 140);
        set_skill("shaolin-shenfa", 140);
        set_skill("parry", 140);
        set_skill("strike", 140);
        set_skill("finger", 140);
        set_skill("sanhua-zhang", 140);
        set_skill("nianhua-zhi", 140);
        set_skill("medicine", 120);
        set_skill("buddhism", 120);
        set_skill("literate", 100);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("strike", "sanhua-zhang");
        map_skill("finger", "nianhua-zhi");
        map_skill("parry", "nianhua-zhi");

        prepare_skill("strike", "sanhua-zhang");
        prepare_skill("finger", "nianhua-zhi");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "finger.fuxue" :),
		(: perform_action, "strike.sanhua" :),
	}));

        create_family("������", 23, "����");

        setup();

	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
	carry_object("/d/shaolin/obj/sengxie")->wear();
}
