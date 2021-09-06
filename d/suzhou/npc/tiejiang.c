// tiejiang.c ����

inherit NPC;
inherit F_VENDOR;
int ask_me(); 
//int ask_yiechu();
 
void create()
{
	set_name("����", ({ "tie jiang", "tie", "jiang" }) );
	set("gender", "����" );
	set("age", 34);
	set("long", "����һλλ�������Ŵ����������������Ĵ�����������\n");
	set("combat_exp", 30000);
	set("attitude", "peaceful");
	set("rank_info/respect", "����");
	set("vendor_goods", ({
		(["name":__DIR__"obj/changjian","number":15]),
		(["name":__DIR__"obj/gangjian","number":20]),
		(["name":__DIR__"obj/gangdao","number":15]),
		(["name":__DIR__"obj/caidao","number":10]),
		(["name":__DIR__"obj/tiechui","number":10]),
		(["name":__DIR__"obj/bishou","number":10])
	}));
	set("inquiry", ([
		"name" : "������������С��ס�����ݳǣ�������ɶ��\n",
		"rumors" : "�ҵ�����͢��ȥ���˺ӣ������˼����ӹǲ��ã�ǰЩ�첻����ȥ�ˡ�\n",
		"here" : "�����ǳ���Ψһ�Ĵ������ˣ�ʲô�˶�����������������\n",
		"����": (: ask_me :),
		"��ͷ": "��ͷ... ��Ǹ����ͷ�Ѿ�������...", 
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{       
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "����Ц�����˵������λ" + RANK_D->query_respect(ob) + "������ֻҪ�����ļһӦ�о��С�\n");
			break;
		case 1:
			say( "����Ц�Ǻǵ�˵����λ" + RANK_D->query_respect(ob) + "������Ҫ��ʲô��\n");
			break;
	}
}

int ask_me()
{
	object chu, me, ob;

	me = this_object();
	ob = this_player();
        
	if ( present("tie chu", ob) ) {
		command("say �㲻�������𣬻���Ҫʲ�᣿\n");
		return 1;
	}
	command("look " + ob->query("id")); 
	command("say ����������һ������ûʲ���ã���Ҫ����ȥ�ɡ�\n");
	chu = new("/d/huashan/jinshe/obj/tiechu");
	chu->set("no_sell", 1);
	chu->move(ob);
	message_vision("$N����$nһ��������\n", me, ob);
	return 1;
}
