// /d/fuzhou/npc/flowergirl.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��������", ({ "maihua guniang", "guniang", "girl" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("per", 28);
        set("unique", 1);
        set("long","��λ������æ���к����ˣ�����ʱ�����Ļ�����ˮ��\n");
	set("combat_exp", 50000+random(50000));
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
        	(["name": MISC_D("chahua"),"number":5]),
        	(["name": MISC_D("chahua2"),"number":5]),
        	(["name": MISC_D("chahua3"),"number":5]),
        	(["name": MISC_D("chahua4"),"number":5]),
        	(["name": MISC_D("baichahua"),"number":5]),
        	(["name": MISC_D("chahua1"),"number":5]),
        	(["name": MISC_D("w-rose"),"number":3]),
        	(["name": MISC_D("r-rose"),"number":2]),
        	(["name": MISC_D("baihehua"),"number":2]),
		(["name": MISC_D("suoluohua"),"number":5]),
		(["name": MISC_D("huilanhua"),"number":4]),
        }));
        setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
        object ob;
        mapping myfam;

        ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family"))
                && myfam["family_name"] == "ؤ��"
                && ob->query("gb_bags") < 2 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "��������Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����������軨�ɡ�\n");
                        break;
                case 1:
                        say( "��������Цӯӯ��˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        say("\n������������ü,˵��:�Բ���,С����ջ�û�������軨,��ȥ�𴦰ɣ�\n\n");
        remove_call_out("kicking");
        call_out("kicking", 1, ob);

}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/fuzhou/xixiang3");
        message("vision","ֻ������һ��̾Ϣ," +  ob->query("name") +
                "�޿��κε��뿪�˻��ꡣ\n", environment(ob), ob);
}
