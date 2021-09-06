// wangzhi.c ��־̹

inherit NPC;

void create()
{
        set_name("��־̹", ({"wang zhitan", "wang"}));
        set("gender", "����");
        set("age", 24);
        set("class", "taoist");
        set("long",
                "������ȫ��̵����������еĺ��֣��������ĵ��ӡ�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);

        set("combat_exp", 160000);

        set_skill("force", 80);
        set_skill("xiantian-gong", 80);
        set_skill("sword", 80);
        set_skill("quanzhen-jianfa",70);
        set_skill("dodge", 70);
        set_skill("jinyan-gong", 70);
        set_skill("parry", 80);
        set_skill("strike",80);
        set_skill("haotian-zhang", 70);
        set_skill("literate",60);
        set_skill("taoism",60);
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 3, "����");

        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}
