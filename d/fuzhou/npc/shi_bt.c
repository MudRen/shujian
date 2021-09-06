// shi_bt.c ʷ��ͷ

inherit NPC;
void create()
{
	set_name("ʷ��ͷ", ({ "shi biaotou", "shi", "biaotou" }));
	set("gender", "����");
	set("age", 42);
	set("long", "���ǡ������ھ֡���һ����ͷ��\n");
	set("shen_type", -1);

        set("str", 30);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 20);
        set("combat_exp", 260000);

	set_skill("blade", 120);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("linji-zhuang", 120);
	set_skill("shuishangpiao", 120);
	set_skill("wuhu-duanmendao", 120);
	map_skill("force", "linji-zhuang");
	map_skill("blade","wuhu-duanmendao");
	map_skill("parry","wuhu-duanmendao");
	map_skill("dodge","shuishangpiao");

	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/damage", 30);

	setup();
	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("pao2"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
