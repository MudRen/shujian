// xiaoer2.c �Ƶ�С��

inherit WAITER;
inherit F_VENDOR;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long", "��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 3800);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		(["name": FOOD_D("xiaren"), "number": 10]),
		(["name": FOOD_D("huotui"), "number": 10]),
		(["name": FOOD_D("dongsun"),"number": 10]),
		(["name": FOOD_D("kaoya"), "number":15]),
		(["name": FOOD_D("hdjiudai"), "number":18]),
		(["name": FOOD_D("bbaozi"), "number":20])
	}));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	object ob = this_player();

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob) && !is_fighting() ) {
		if ( ob->query("family/family_name") == "ؤ��"
		 && ob->query("gb/bags") < 2 ) {
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
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0: say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob) + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1: say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob) + "����������\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	ob->move("/d/hz/qsddao6");
	message("vision","ֻ����ƹ����һ����" +  ob->query("name")+"���˴�����¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
