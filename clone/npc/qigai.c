// qigai.c ��ؤ

inherit NPC;
#include "/kungfu/class/gaibang/begger.h";

void create()
{
        set_name("������ؤ", ({ "qi gai", "qigai", "beggar" }) );
	set("title","ؤ��һ������");
	set("gb/bags", 1);
        set("long","һ��һ����ɫ����ؤ�����������󻹶��Ŷ��ӡ�\n");
        set("gender", "����");
        set("age", 30+random(10));
        set("attitude", "peaceful");
        set("shen_type", 0+random(10));

        set("str", 20+random(10));
        set("int", 16+random(10));
        set("con", 22);
        set("dex", 24+random(10));

        set("max_qi", 300+random(800));
        set("max_jing", 300+random(400));
        set("neili", 300+random(400));
        set("max_neili", 300+random(800));
        set("jiali", 10+random(30));
        set("combat_exp", 43000+random(10000));

        set_skill("force", 30+random(30));
        set_skill("dodge", 30+random(30));
        set_skill("xiaoyaoyou", 30+random(30));
        set_skill("parry", 30+random(30));
        set_skill("cuff", 30+random(30));
        set_skill("taizu-quan", 30+random(30));
        set_skill("begging", 120);

	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
	map_skill("dodge", "xiaoyaoyou");
        prepare_skill("cuff", "taizu-quan");
        set("chat_chance", 10);
	set("chat_msg", ({
		"��ؤ���˸�����������½�ǡ���\n",
		"��ؤ���ĵض����������ƺ���ҪѰ��ʲô��\n",
		(: random_move :)
        }) );
	create_family("ؤ��", 19, "һ������");
        setup();

	carry_object(ARMOR_D("caoxie"))->wear();
	carry_object(ARMOR_D("bainayi"))->wear();
	carry_object(CLASS_D("gaibang/obj/gb_budai1"))->wear();
}
