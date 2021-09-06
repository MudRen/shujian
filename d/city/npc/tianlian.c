// penglianhu.c ������

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("������", ({ "penglian hu", "penglian" }));
	set("nickname", "ǧ������");
	set("long", 
        "������ɱ�˲���գ�۵Ĵ��ǧ��������������\n"
        "һ��һ��а��������ʮ�ֽƻ��ļһ\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 40);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 2400);
	set("max_jing", 800);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("score", 100000);

    set_skill("force", 120);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 120);

    set_skill("shaolin-shenfa", 120);
    set_skill("hand", 100);
    set_skill("weituo-zhang", 130);
    set_skill("parry", 100);
    set_skill("staff", 120);
    set_skill("qianye-shou", 120);
    set_skill("literate", 50);

	map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("hand", "qianye-shou");
  	map_skill("parry", "weituo-zhang");
  	map_skill("staff", "weituo-zhang");
    prepare_skill("strike", "chousui-zhang");

	 
         set("inquiry", ([
                "����" : "�ٺ�, ��������������Ϣ��",
                "������" : "���Ǵ�ү�ҡ�",
                "����Ƽ" : "�ǿ��Ǹ����˰���",
                "ɳͨ��" : "���ҵĽ���ֵ�! ",
                "��ͨ��" : "Ҳ���ҵ��ֵܰ���",
                "Ǯ�ཡ" : "����������ʲ�᣿",
                
        ]) );
        
        setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
        add_money("gold", 8);
}