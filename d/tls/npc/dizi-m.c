// /d/dali/npc/dizi-m.c
// By jpei

inherit NPC;

void create()
{
	int name_no = random(4); 
	string *name_string = ({"��","��","��","С"});

	set_name("�е���", ({"nan dizi", "nan", "dizi"}) );
	set("long", "������ר����־����ϰ����\n");
	set("gender", "����" );
	set("age", 26);
	set("attitude", "peaceful");
	set("str",22);
	set("int",28);
	set("con",18);
	set("dex",20);
	set("max_qi", 700);
	set("max_jing", 270);
	set("neili", 500);
	set("max_neili", 340);
	set("jiali", 12);
	set("combat_exp", 20000);

	set_skill("force", 35);
	set_skill("qiantian-yiyang", 32);
	set_skill("dodge", 35);
	set_skill("tianlong-xiang", 31);
	set_skill("parry", 40);
	set_skill("finger", 38);
	set_skill("yiyang-zhi", 37);
	set_skill("sword", 40);
	set_skill("literate", 40);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "yiyang-zhi");
	map_skill("finger", "yiyang-zhi");
	map_skill("force", "qiantian-yiyang");
	prepare_skill("finger","yiyang-zhi");

	set("shen_type", 0);
	create_family("������", 10, "����");

	set("inquiry", ([
		"name": "������ɱ������" + name_string[name_no] + "�֣���ʮ�������Ͷ������ѧ�ա�",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}
