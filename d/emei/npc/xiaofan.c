// xiaofan.c С����

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С����", ({ "xiao fan", "xiao", "fan" }) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"��λС������Ц���������æ��������ʱ�к������Ŀ��˽�����\n");
	set("combat_exp", 300);
	set("attitude", "peaceful");
	set("rank_info/respect", "С����");
        set("vendor_goods", ({
		(["name":"/d/emei/obj/tieqiao" ,"number":5]),
		(["name":"/d/emei/obj/qingshui-hulu" ,"number":5]),
		(["name":BINGQI_D("zhujian"),"number": 10]),
		(["name":BINGQI_D("changjian"),"number": 10]),
                (["name":MISC_D("fire"),"number": 10]),
                (["name":MISC_D("xionghuang"),"number": 10]),
        }));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin", 90);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
