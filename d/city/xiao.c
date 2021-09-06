// by ����Ӣ��
// Ϊ�� yeju@SJ

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

string ask_for(string verb);
string ask_title();
string ask_prise();

void create()
{
	set_name("���ϰ�", ({ "xiao laoban", "xiao", "laoban" }));
	set("shen_type", 1);
	set("gender", "����");
	set("age", 40);
	set("long", "��λ�ϰ���Ȼ�����ţ����������ƶ��ʷ����ֵġ�\n");
	set_skill("unarmed", 25);
	set_skill("dodge", 22);
	set_temp("apply/damage", 20);

	set_skill("literate", 150);
	set_skill("string", 200);
	set_skill("flute", 200);

	set("inquiry", ([
		"�ټ�" : (: ask_for, "string" :),
		"string" : (: ask_for, "string" :),
		"�＼" : (: ask_for, "flute" :),
		"flute" : (: ask_for, "flute" :),
         	"ͷ��" : (: ask_title :),
		"ѧ��" : (: ask_prise :),
	]) );

	set("combat_exp", 9000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		(["name":__DIR__"obj/xiao","number":10]),
		(["name":__DIR__"obj/pipa","number":8]),
		(["name":__DIR__"obj/yqin","number":8]),
		(["name":__DIR__"obj/dongbula","number":5])
	}));
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/armor/shoes")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

string ask_for(string verb)
{
	object me = this_player();

	int money;
	int improve;

	if( !verb ) return 0;
	if( is_busy() ) return 0;

	if( me->query_skill(verb, 1) < 30 )
		return "�������һ�����������ģ�����˵˿��û�����ֻ���������ѧ����ʲô������";

	if( me->query_skill(verb, 1) >= 200 )
		return RANK_D->query_respect(me) + "�Ѿ��Ǻ���֪���Ĵ���ʦ����Ȼ�������С�ܣ�����θҵ�����";

	if( me->query("potential") < 5 )
		return RANK_D->query_respect(me) + "�����Ǳ�ܲ���������ѧ����ʲô������";

	money = 200;
	if( me->query_skill(verb, 1) > 60 ) money = 500;
	if( me->query_skill(verb, 1) > 90 ) money = 1000;
	if( me->query_skill(verb, 1) > 120 ) money = 1500;
	if( me->query_skill(verb, 1) > 150 ) money = 2000;
	if( me->query_skill(verb, 1) > 180 ) money = 2500;

	switch( MONEY_D->player_pay(me, money) ) {
		case 0:
		case 2:
		command("beg2 "+me->query("id"));
		return 0;				
	}

	improve = random(me->query_int() * 3 / 4) + random(me->query_skill(verb, 1) / 10) + me->query_int() / 4;
	improve = improve*3.5;	// �ο��ɸߵ��˵ı���
	improve = improve*2;		// 100% С�� 280 level

	if( me->query("registered") == 3 && me->query_temp("ggs/started") && me->query("ggs/started") ) {
		improve = improve*2;
		if( !random(4) ) message_vision("$N�����Լ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ���������Լ�ѧϰ�����°빦����\n",me);
	}

	me->add("potential", -5);	
	message_vision(CYN"$N�˷ܵ�˵�������Ϸ�������Ȥ�����о�̽�������ء�����\n"NOR,this_object());
	switch( random(5) ) {
                case 0:tell_object(me, CYN"���ϰ�ָ������һЩ����"HIG"���硻"NOR); break;
                case 1:tell_object(me, CYN"���ϰ�ָ������һЩ����"HIW"������"NOR); break;
                case 2:tell_object(me, CYN"���ϰ�ָ������һЩ����"HIM"����"NOR); break;
                case 3:tell_object(me, CYN"���ϰ�ָ������һЩ����"HIY"���̡�"NOR); break;
                case 4:tell_object(me, CYN"���ϰ�ָ������һЩ����"MAG"���ǡ�"NOR); break;
                case 5:tell_object(me, CYN"���ϰ�ָ������һЩ����"BLU"��������"NOR); break;
        }
	if( verb == "string" ) tell_object(me, CYN"����֮����\n"NOR);
	else tell_object(me, CYN"����֮����\n"NOR);
	me->improve_skill(verb, improve);
	return "";
}

string ask_prise()
{
	int m, n, i , j;

	i = this_player()->query_skill("string", 1);
	j = this_player()->query_skill("flute", 1);
	m = 200;
	if( i > 60 ) m = 500;
	if( i > 90 ) m = 1000;
	if( i > 120 ) m = 1500;
	if( i > 150 ) m = 2000;
	if( i > 180 ) m = 2500;

	n = 200;
	if( j > 60 ) n = 500;
	if( j > 90 ) n = 1000;
	if( j > 120 ) n = 1500;
	if( j > 150 ) n = 2000;
	if( j > 180 ) n = 2500;

	return "���������Ҫ��������أ�ѧ���ǣ�
		�����ټ� ÿ��" + MONEY_D->money_str(m) + "
		�����＼ ÿ��" + MONEY_D->money_str(n) + 
		"\n���Լ�������Ǯ��\n";
}

string ask_title()
{
	object me = this_player();
	string title, newtitle;
	int level;

	level = me->query_skill("string", 1);

	if( me->query_skill("flute", 1) > level )
		level = me->query_skill("flute", 1);

	if( !level || level < 1 ) return 0;

	if( level < 30 )
		newtitle = HIG"����ѧͽ"NOR;
	else if( level < 50 )
		newtitle = HIY"˾�ֹ�"NOR;
	else if( level < 100 )
		newtitle = YEL"˾��ʦ"NOR;
        else if( level < 150 )
		newtitle = GRN"֪���ſ�"NOR;
	else if( level < 200 )
		newtitle = HIW"���ִ�ʦ"NOR;
	else if( level < 300 )
		newtitle = HIR"��ɽ����"NOR;
	else if( level < 380 )
		newtitle = CYN"��������"NOR;
	else newtitle = HIM"ǧ�ž���"NOR;

	title =  newtitle + " " + me->query("name") + "(" + capitalize(me->query("id")) + ")";
	me->set_temp("apply/short", ({title}));
	return "���Ϸ򿴣����µ�������Ϊ�����Գƺ�Ϊ"+newtitle+"��";
}
