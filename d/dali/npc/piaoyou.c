// piaoyou.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ʊ��", ({ "piao you", "piao", "you" }) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"��λ�۾�����ؿ���Ϸ����Ҫ�ǹ�ȥ���к������϶��᲻�ͷ��ġ�\n");
	set("combat_exp", 1500);
	set("attitude", "peaceful");
	set("rank_info/respect", "Ʊ��");
	
	setup();
        carry_object("/clone/misc/cloth")->wear();
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
			say( "Ʊ�����������˵������ѽ�������Ϸ�����Ǳ��ڼҴ���ǿ���ˡ���\n");
			break;
		case 1:
			say( "Ʊ�Ѷ��������ĵ�˵����λ" + RANK_D->query_respect(ob)
				+ "��ǧ�������������������\n");
			break;
	}
}
