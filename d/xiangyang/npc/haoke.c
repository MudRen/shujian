// /d/xiangyang/npc/haoke.c

inherit NPC;
void create()
{
        set_name("��������", ({ "hao ke", "haoke", "ke" }) );
        set("gender", "����" );
        set("age", 30+random(15));
        set("long", "һ��������������������ĺ��ӡ�\n");
        set("attitude", "friendly");

        set("shen_type", 1);
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);

        set("max_qi", 2500);
        set("max_jing", 2500);
	set("eff_jingli", 1500);
        set("neili", 2500);
        set("max_neili", 2000);
        set("jiali", 100);
        set("shen", 5);
        set("combat_exp", 240000);

        set_skill("force", 120);
        set_skill("strike", 120);
        set_skill("blade", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("huntian-qigong", 120);
        set_skill("literate", 140);
        set_skill("lianhua-zhang", 120);
        set_skill("liuhe-daofa", 120);
        set_skill("xiaoyaoyou", 120);

        map_skill("force", "huntian-qigong");
        map_skill("blade","liuhe-daofa");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("strike", "lianhua-zhang");
        map_skill("parry", "liuhe-daofa");
        prepare_skill("strike", "lianhua-zhang");

        set("chat_msg_combat", ({
                (: perform_action, "blade.sancai" :)
        }));

        set("chat_chance", 3);
        set("chat_msg", ({
                "��������������������������ֵ��ĵ��ʡ�\n",
        }) );

	set("inquiry", ([
		"name" : "������������һ�����ӣ�����������ƾ�㣬������֪����ү�ҵ����֣���\n",
		"rumors" : "ǰһ������˵��������Ը��ϾۻᣬΪ��һ��������������Ӣ�ۡ�\n",
	]));

        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(BINGQI_D("blade"))->wield();
}
