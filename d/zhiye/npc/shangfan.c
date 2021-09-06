// xiao shangfan ����С��
// by augx@sj  9/7/2001

// Modified by mxzhao 2004/03/06 
// delete /d/zhiye/obj/fangsuo

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����С��",({ "dali xiaofan", "xiaofan" }) );
	set("gender", "����" );
	set("age", 36);
	set("long", "��λС������Ц���������æ��������ʱ�к������Ŀ��ˡ�\n");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);

	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("literate", 150);
	
	set("max_qi", 39999);
	set("max_neili", 49999);
	set("max_jing", 29999);
	set("eff_jingli", 29999);

	set("no_get", 1);

	set_temp("apply/dodge",288);
	set_temp("apply/force",288);
	set_temp("apply/attack",288);
	set_temp("apply/damage",233);
	set_temp("apply/armor",288);
	
	set("unique",1);
	
	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/tiechui","number":20]),
		//(["name":"/d/zhiye/obj/fangsuo","number":20]),
		(["name":"/d/zhiye/obj/jiandao","number":20]),
		(["name":"/d/zhiye/obj/yaochui","number":20]),
		(["name":"/d/zhiye/obj/yaochu", "number":20]),
	}));
	
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin",99);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say ��ֻ��һ��������С�̷���ΪʲôҪɱ���أ�");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say ��ֻ��һ��������С�̷���ΪʲôҪɱ���أ�");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
