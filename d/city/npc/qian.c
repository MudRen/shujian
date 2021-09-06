// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
// Lklv@SJ 2001.9.28 update

inherit NPC;
inherit F_BANKER;

void create()
{
        set_name("Ǯ��", ({"qian feng", "qianfeng", "feng", "qian"}));
        set("title", "Ǯׯ�ϰ�");
        set("nickname", "ǧ������������");
        set("gender", "����");
        set("age", 34);

        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("shen", 0);
        set("no_get", 1);

        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
		"Ǯ�콾����˵�����������Ѿ����ϰ������ʷ���ڽ��Ͽ���˵�ǵ�һ�ҡ�\n",
		"Ǯ��Ц��˵�����ڱ����Ǯ����Ϣ��ȡǮ�հٷ�֮�������ѣ��͹������Ű�ɡ�\n"
        }));

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(MISC_D("denglong2"));
}

void init()
{
	::init();
	add_action("do_check", ({"check", "chazhang", "����"}));
	add_action("do_convert", ({"convert", "duihuan", "�һ�"}));
	add_action("do_deposit", ({"deposit", "cun", "��"}));
	add_action("do_withdraw", ({"withdraw", "qu", "ȡ"}));
}
