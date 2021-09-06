// /d/gb/npc/zfdizi.c ִ������

inherit NPC;

void create()
{
        set_name("ִ������", ({ "zhifa dizi", "dizi", "di zi" }));
        set("title", "ؤ������");
        set("gb/bags", 2);
        set("long","����һ������ִ�����ϵ�ؤ�����, �������̡�\n");

        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 24);
        set("int", 18);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 600);
        set("max_jing", 400);
        set("eff_jingli", 480);
        set("neili", 450);
        set("max_neili", 450);
        set("jiali", 20);
        set("combat_exp", 15000);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("strike", 60);
        set_skill("parry", 60);
        set_skill("huntian-qigong", 60);
        set_skill("xiaoyaoyou", 60);
        set_skill("lianhua-zhang", 60);
        set_skill("begging", 60);

	map_skill("force", "huntian-qigong");
        map_skill("strike","lianhua-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "lianhua-zhang");
	prepare_skill("strike", "lianhua-zhang");

        set("chat_chance", 1);
        set("chat_msg", ({
		"ִ�����ӽе��������û�ã�������ؤ���е�����ô�á���\n",
        }) );
	create_family("ؤ��", 20, "����");
        setup();

        carry_object(CLASS_D("gaibang/obj/gb_budai2"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
}