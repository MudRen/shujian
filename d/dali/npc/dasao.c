//  /d/dali/npc/dasao.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�����ɩ", ({ "daizu dasao", "dasao" }));
	set("title", "�ϰ���");
	set("shen_type", 1);

	set("gender", "Ů��");
	set("age", 45);
	set("long","��λ��ɩ���˼�ʮ�������,���ղ���\n");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/damage", 15);
	set("unique", 1);
	set("combat_exp", 4000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		(["name":__DIR__"obj/ao","number":5]),
		(["name":__DIR__"obj/yanzhi","number":15]),
		(["name":__DIR__"obj/huafen","number":15]),
	}));
	
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
