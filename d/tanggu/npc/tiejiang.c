inherit NPC;
inherit F_VENDOR;
 
void create()
{
	set_name("����", ({ "tie jiang", "tie", "jiang" }) );
	set("gender", "����" );
	set("age", 34);
	set("long", "����һλ�������Ŵ����������������ش�����������\n");
	set("combat_exp", 3000);
	set("attitude", "peaceful");
	set("rank_info/respect", "����");
	set("vendor_goods", ({
                (["name": BINGQI_D("changjian"), "number": 10]),
                (["name": BINGQI_D("gangjian"), "number": 15]),
                (["name": ARMOR_D("armor"), "number": 15]),
                (["name": BINGQI_D("blade"), "number": 15]),
        }));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "������ֻҪ�����ļһӦ�о��С�\n");
			break;
		case 1:
			say( "����Ц�Ǻǵ�˵����λ" + RANK_D->query_respect(ob)			+ "������Ҫ��ʲô��\n");
			break;
	}
}
