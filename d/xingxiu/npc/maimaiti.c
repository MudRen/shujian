// npc: /d/xingxiu/npc/maimaiti.c
// Jay 3/17/96
//Update by caiji@SJ 8/23/2000
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "maimaiti", "seller" }) );
        set("title", "�����ϰ�");
        set("gender", "����" );
        set("age", 43);
        set("long", "�������Ǹ�����ά��������ˣ�ȥ��������ԭ���ܽ�һ���������\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("rank_info/respect", "����");

	set("vendor_goods", ({
		(["name":"/d/xingxiu/obj/hulu","number":10]),
		(["name": "/d/xingxiu/obj/fire","number":10]),
		(["name": "/d/xingxiu/obj/dongbula","number":1]),
		(["name": "/d/hj/obj/yangpi","number":2]),
		(["name": "/d/hj/obj/jiunang","number":10]),
		(["name": "/d/hj/obj/shuinang","number":10]),
		(["name": "/d/hj/obj/cheese","number":2]),
		(["name": "/clone/weapon/madao","number":10]),
		(["name": "/clone/weapon/mabian","number":10]),
		(["name": "/clone/medicine/m-book2","number":1]),
		(["name": "/clone/weapon/wandao","number":10]),
		(["name": "/clone/armor/qun","number":10]),
		(["name": "/clone/armor/yangao","number":10]),
		(["name": "/d/hj/obj/maotan","number":10]),
		(["name": MISC_D("liuhuang"),"number":6]),
		(["name": MISC_D("tanzi"),"number":10])
	}));

        setup();
        carry_object(ARMOR_D("wcloth"))->wear();
        add_money("coin", 100);
}
void init()
{
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list","list");
	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
	case 0: say( "������Ц������˵����ɫ��ķ����ա�\n"); break;
	case 1: say( "���������ַ�����ǰ��ǳ��һ��˵���������ɫ��ķ��\n"); break;
	}
}
