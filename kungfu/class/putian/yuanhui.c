// /kungfu/class/nshaolin/yuanhui.c
// looklove 2001.7.21

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Ԫ������", ({
                "yuanhui zunzhe",
                "yuanhui",
                "zunzhe",
        }));
        set("long",
                "һλ��ɫ�Ͱ�������ɮ�ˣ����ϴ���һ�����õ���ɡ�\n"
        );

        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 28);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2800);
        set("max_jing", 2000);
        set("neili", 6000);
        set("max_neili", 4000);
        set("jiali", 40);
        set("combat_exp", 1500000);

        set_skill("force", 180);
        set_skill("yijin-jing", 180);
        set_skill("dodge", 180);
        set_skill("shaolin-shenfa", 180);
        set_skill("parry", 180);
        set_skill("strike", 180);
        set_skill("cuff", 180);
        set_skill("banruo-zhang", 180);
        set_skill("jingang-quan", 180);
        set_skill("medicine", 120);
        set_skill("buddhism", 200);
        set_skill("literate", 140);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("strike", "banruo-zhang");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "banruo-zhang");

        prepare_skill("cuff", "jingang-quan");
        prepare_skill("strike", "banruo-zhang");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "cuff.jingang" :),
		(: perform_action, "strike.qiankun" :),
	}));

        create_family("������", 23, "����");

        setup();

	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
	carry_object("/d/shaolin/obj/sengxie")->wear();
}

