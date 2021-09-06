// nigu.c  ���

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���", ({ "ni gu", "ni", "gu" }) );
	set("gender", "Ů��" );
	set("age", 34);
	set("long", "��λ����������̵��ϣ�˫���������������������дʡ�\n");
	set("combat_exp", 700);
	set("attitude", "peaceful");
	set("rank_info/respect", "���");
	setup();
	carry_object("/d/emei/obj/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "���ʩ��һ��˵������λ" + RANK_D->query_respect(ob) + "������˴���Ϊ������һ�������ɡ�\n");
			break;
		case 1:
			say( "���˵������λ" + RANK_D->query_respect(ob) + "����л������Ը���汣�ӡ�\n");
			break;
	}
}
