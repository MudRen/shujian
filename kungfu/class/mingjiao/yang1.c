// yang1.c 杨不悔
// Modify By River@sj 99.06
inherit NPC;
void create()
{
        set_name("杨不悔", ({ "yang buhui", "yang", "buhui" }));
        set("gender", "女性");
        set("title","明教光明左使之女");
        set("age", 19);
	set("long","她大大眼睛，眼球深黑，一张园脸。她就是杨左使的女儿。\n");
	set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 26);
        set("per", 26);
        set("combat_exp", 50000);
        set("unique", 1);
        set("attitude", "peaceful");
	set("max_qi",300);
        set("max_jing",300);
        set("neili",300);
        set("max_neili",300);
	set("jiali",10);
	set("no_quest", 1);

        set_skill("cuff", 30);
	set_skill("sword",30);
	set_skill("liehuo-jian",30);
	set_skill("parry",30);
	set_skill("piaoyi-shenfa",30);
        set_skill("dodge", 30);
	set_skill("force",30);
	set_skill("shenghuo-shengong",30);
	map_skill("force","shenghuo-shengong");
	map_skill("dodge","piaoyi-shenfa");
	map_skill("parry","liehuo-jian");
	map_skill("sword","liehuo-jian");
        setup();
	carry_object(ARMOR_D("necklace"))->wear();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
	carry_object(BINGQI_D("changjian"))->wield();
}
