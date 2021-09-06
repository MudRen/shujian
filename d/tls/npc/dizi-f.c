// /d/dali/npc/dizi-f.c
// By jpei
//update bye cool

inherit NPC;

void create()
{
    int name_no = random(2); 
	string *name_string = ({"����","СС��"});

	set_name("Ů����", ({"nv dizi", "nv", "dizi"}) );
	set("long", "������ר����־����ϰ����\n");
	set("gender", "Ů��" );
	set("age", 23);
	set("attitude", "peaceful");
	set("str",18);
	set("int",28);
	set("con",19);
	set("dex",22);
	set("max_qi", 650);
	set("max_jing", 250);
	set("neili", 500);
	set("max_neili", 320);
	set("jiali", 10);
	set("combat_exp", 15000);

	set_skill("force", 30);
	set_skill("qiantian-yiyang", 27);
	set_skill("dodge", 30);
	set_skill("tianlong-xiang", 28);
	set_skill("parry", 32);
	set_skill("cuff", 32);
	set_skill("duanjia-quan", 30);
	set_skill("sword", 30);
	set_skill("literate", 35);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("cuff", "duanjia-quan");
	map_skill("force", "qiantian-yiyang");
	prepare_skill("cuff","duanjia-quan");

	set("shen_type", 0);
	create_family("������", 16, "����");

	set("inquiry", ([
		"name": "ū�ҽ���" + name_string[name_no] + "����С�������ʦ��������",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}
