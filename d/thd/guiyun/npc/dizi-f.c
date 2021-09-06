// /u/jpei/guiyun/npc/dizi-f.c

inherit NPC;

void create()
{
	int name_no = random(3); 
	string *name_string = ({"������","���","ʯ���"});

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
	set_skill("bihai-chaosheng", 27);
	set_skill("dodge", 30);
	set_skill("suibo-zhuliu", 28);
	set_skill("parry", 32);
	set_skill("strike", 22);
	set_skill("luoying-zhang", 18);
	set_skill("leg", 20);
	set_skill("xuanfeng-tui", 15);
	set_skill("sword", 30);
	set_skill("yuxiao-jian", 25);
	set_skill("taoism", 20);
	set_skill("literate", 35);
	set_skill("qimen-bagua", 40);

	map_skill("force", "bihai-chaosheng");
	map_skill("dodge", "suibo-zhuliu");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-tui");
	map_skill("parry", "luoying-zhang");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");

	set("shen_type", 0);
    create_family("�һ���", 4, "����");
	set("class", "fighter");

	set("inquiry", ([
		"name": "ū�ҽ���" + name_string[name_no] + "����ʮ�������Ͷ������ѧ�ա�",
		"rumors": "��˵ʦ����ͽ���������Ժ��Ļ����ҵö�ѧЩ����д���ˡ�",
		"here": "�����ǹ���ׯ�������תת�ɣ������뵽�ͷ���Ϣ��",
		"��а": "����ʦ��ѽ�����������˼Ҷ�׼���Ҳ��ܸ�½ׯ��ѧ�ա�",
		"��ҩʦ": "����ʦ��ѽ�����������˼Ҷ�׼���Ҳ��ܸ�½ׯ��ѧ�ա�",
		"����": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"jpei": "˵����Ҳ�����������ң�������һ��Ǹ�����������",
		"�һ���": "��˵��ʦ��ס�ĵط�����ϧû��ȥ������",
		"½�˷�": "���ҵ�ʦ���������ׯ�������������˼���ʲô����",
		"����ׯ": "��˵�����ǻ���ׯ��������Ѫ�Ž������ģ�����ׯԺ�����Σ�",
		"̫��": "����ׯǰ��Զ����һ���̲����Ĵ����",
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}
