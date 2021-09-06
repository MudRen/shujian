//  /d/dali/npc/dasao.c
// Modify By River 98/12
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("������ʩ", ({ "doufu xishi", "xishi" }));
	set("title", "�������ϰ���");
	set("shen_type", 1);
        set("per", 26);
        set("unique", 1);
	set("gender", "Ů��");
	set("age", 25);
	set("long", "��λ�ϰ���������֣����м�����ɫ��\n");

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/damage", 25);

	set("combat_exp", 8000);
	set("attitude", "friendly");
        set("vendor_goods", ({
		(["name":__DIR__"obj/doufu1","number":10]),
		(["name":__DIR__"obj/doufu2","number":10]),
		(["name":__DIR__"obj/doufu3","number":10]),
        }));	
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
