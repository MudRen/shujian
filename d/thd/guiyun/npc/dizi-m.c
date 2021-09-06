// /u/jpei/guiyun/npc/dizi-m.c

inherit NPC;

void create()
{
	int name_no = random(4); 
	string *name_string = ({"��","��","��","��"});

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
	set_skill("bihai-chaosheng", 30);
	set_skill("dodge", 35);
	set_skill("suibo-zhuliu", 30);
	set_skill("parry", 40);
	set_skill("strike", 30);
	set_skill("luoying-zhang", 28);
	set_skill("leg", 30);
	set_skill("xuanfeng-tui", 25);
	set_skill("sword", 40);
	set_skill("yuxiao-jian", 35);
	set_skill("taoism", 20);
	set_skill("literate", 40);
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
		"name": "���¸���˾�գ�����" + name_string[name_no] + "�ģ���ʮ�������Ͷ������ѧ�ա�",
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
