// wanqing.c ������

inherit NPC;

void create()
{
        set_name("������", ({ "wan qingli", "wan","qingli" }));
	set("long", 
		"һ���뺷�ĺ��ӣ����������۵Ĵ���ӡ�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 38);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 1200);
	set("max_jing", 1500);
	set("eff_jingli", 1000);
	set("neili", 1200);
	set("max_neili", 1200);
	set("combat_exp", 450000);
	set("score", 1000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
        set_skill("yinyun-ziqi", 80);
        set_skill("tiyunzong", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
        set_skill("cuff", 80);
        set_skill("taiji-quan", 80);
	set_skill("taiji-jian", 80);
	set_skill("taoism", 80);
        set_skill("hand", 80);
        set_skill("juehu-shou",80);

	map_skill("parry", "taiji-jian");
        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
	map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");
        prepare_skill("cuff", "taiji-quan");
        prepare_skill("hand", "juehu-shou");

	create_family("�䵱��", 3, "����");

	setup();
        carry_object("/d/wudang/obj/white-robe")->wear();
}
