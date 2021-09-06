// Write By Yanyang@SJ 2001.10.2
// NPC : /d/changan/npc/liyuanwai.c

inherit NPC;

void create()
{
        set_name("��Ա��", ({ "li yuanwai", "yuanwai","li"}));
        set("age", 54);
        set("title","�󸻴��");
        set("gender", "����");
        set("long", "���װ����֣�һ���ĸ��ࡣ\n�������ͽ�������򽻵����书Ҳϰ��һ�а�ʽ��\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 500000);
        set("shen_type", 1);

        set("max_neili", 1500);
        set("neili", 3000);
        set("max_qi", 2000);
        set("qi", 2000);
        set("max_jing", 1500);
	set("eff_jingli", 2200);

        set_skill("cuff", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("xiaoyaoyou",150);
        set_skill("yijin-jing",150);
        set_skill("xiaoyaoyou",150);
        set_skill("luohan-quan",150);

        map_skill("cuff", "luohan-quan");
        map_skill("parry", "luohan-quan");
        map_skill("force", "yijin-jing");
        map_skill("dodge", "xiaoyaoyou");
        prepare_skill("cuff", "luohan-quan");

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}