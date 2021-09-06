inherit NPC;

void create()
{
        set_name("�ɹ���ʿ", ({ "weishi","fighter" }) );
        set("gender", "����" );
        set("age", 35+random(10));
        set("attitude", "peaceful");
        set("str", 40+random(5));
        set("con", 40+random(5));
        set("int", 20+random(10));
        set("dex", 30+random(10));

        set_temp("special_die",1);
        set("max_qi", 6500+random(500));
        set("max_jing", 6500+random(500));
        set("neili", 5000+random(1000));
        set("eff_jingli", 6500+random(500));
        set("max_neili", 5000+random(500));
        set("jiali", 150);

        set("combat_exp", 1500000);

        set_skill("force", 200);
        set_skill("cuff", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("taizu-quan", 200);
        set_skill("jinyan-gong", 200);
        set_skill("xiantian-gong",200);
        set_skill("spear", 200);
        set_skill("bawang-qiang", 200);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "bawang-qiang");
        map_skill("spear", "bawang-qiang");

        prepare_skill("cuff", "taizu-quan");

        setup();
        carry_object(BINGQI_D("spear"))->wield();
        carry_object(ARMOR_D("armor"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
