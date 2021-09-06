// /d/dali/npc/maihua.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��������", ({ "maihua guniang", "guniang", }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("per", 26);
	set("unique", 1);
	set("long","��λ������æ���к����ˣ�����ʱ�����Ļ�����ˮ��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		(["name":__DIR__"obj/hua","number":20]),
	}));
	setup();
	carry_object("/clone/armor/cloth")->wear();
}

void init()
{
	object ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
		if ( ob->query("family/family_name") == "ؤ��" && ob->query("gb/bags") < 2 ){
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
	object me = this_object();
	if( !ob || environment(ob) != environment() ) return;
	if ( ! me || file_name(environment(me)) != me->query("startroom")) return;
	switch( random(2) ) {
		case 0:
			say( "��������Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�����������軨�ɡ�\n");
			break;
		case 1:
			say( "��������������н�����ˮ����˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

void saying(object ob)
{
	object me = this_object();
	if( !ob || environment(ob) != environment() ) return;
	if ( ! me || file_name(environment(me)) != me->query("startroom")) return;
	say("\n������������ü,˵��:�Բ���,С����ջ�û�������軨,��ȥ�𴦰ɣ�\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/dali/dongjie7");
	message("vision","ֻ������һ��̾Ϣ," +  ob->query("name") +
		"�޿��κε��뿪�˻��ꡣ\n", environment(ob), ob);
}
