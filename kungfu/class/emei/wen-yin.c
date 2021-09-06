// /kungfu/class/emei/wen-yin.c
// Lklv 2001.10.18 update

inherit NPC;

void create()
{
	set_name("����Сʦ̫", ({ "wenyin" }));
	set("long","���Ǹ����䲻��ü��Ŀ���Сʦ̫����һ��������������Ц�Ź�ȥ�д���\n");

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("unique", 1);
	set("class", "bonze");

        set("age", 19);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 0);
	set("combat_exp", 120000);
	set("score", 100);

	set_skill("dacheng-fofa", 60);
	set_skill("linji-zhuang", 60);
	set_skill("huifeng-jian", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("anying-fuxiang", 60);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("parry", "huifeng-jian");
	map_skill("dodge", "anying-fuxiang");
        create_family("������", 5, "����");

        setup();
	carry_object("/d/emei/obj/changjian")->wield();
	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}
