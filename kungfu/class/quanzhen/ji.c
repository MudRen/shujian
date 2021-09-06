inherit NPC;

void create()
{
        set_name("������", ({"ji qingxu", "ji"}));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long",
                "����һλ���ǿ���������ʿ���ƺ������ա�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 60000);

        set_skill("force", 40);
        set_skill("xiantian-gong", 40);
        set_skill("sword", 40);
        set_skill("quanzhen-jianfa",40);
        set_skill("dodge", 40);
        set_skill("jinyan-gong", 40);
        set_skill("parry", 40);
        set_skill("strike",40);
        set_skill("haotian-zhang", 40);
        set_skill("literate",40);
        set_skill("taoism",40);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 4, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}
