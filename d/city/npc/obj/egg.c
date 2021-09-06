// egg.c ����ʥ��
// created by campsun 2003/12/17
#include <ansi.h>

inherit ITEM;

int do_qiao(string);
string gGetRndColor();
void create()
{
    set_name(CYN "����ʥ��" NOR, ({ "piggy's egg","egg" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ʥ�������ĵ������濴�����������̵ģ���֪��������ʲô���������������"HIW"����(Qiao)"NOR"���������ʲô�ö�����\n");
		set("treasure",1);
		set("value", 10);
		set("no_give",1);
		set("no_drop",1);
		set("qiao",1);
		set("egg",1);
		set("material", "paper");
             }
	setup();
}
void init()
{
   	add_action("do_qiao", "qiao");
}

int do_qiao(string arg)
{
	object me,ob;	
	string strString;
	me=this_player();
	ob=this_object();

	if (arg!="egg") 
	{
		message_vision(HIR"$N�������Լ��������Ϻݺݵ�����һ�£��۵���ð���ǡ�\n"NOR,me );	
		return 1;
	}
	if (!ob->query("qiao"))
	{ 
		tell_object(me,"����΢��һ�����á�\n");	
		return 1;
	}

	switch (ob->query("egg"))
	{
		case 1:
			strString = HIG"$N���š�$n"HIG"������"+gGetRndColor()+"��"HIG"������"+gGetRndColor()+"��"HIG"������"+gGetRndColor()+"��"HIG"���������泩��Խ�����ÿ��ֿ��ġ�";
			ob->set("qiao",0);
			call_out("up_level2",10);
		break;
		case 2:
			strString = HIG"$N���š�$n"HIG"������"+gGetRndColor()+"��"HIG"������"+gGetRndColor()+"��"HIG"������"+gGetRndColor()+"��"HIG"������������Ȼ���������Լ�����������еĵ��εΡ�";
			ob->set("qiao",0);
			call_out("give_reward",5,me);
		break;
	}
	message_vision(strString + "\n"NOR,me,ob);
	return 1;
		
}
void up_level2()
{
	this_object()->set("qiao",1);
	this_object()->set("egg",2);	
	return;
}
void give_reward(object me)
{
	object cash;
	object *list;
	int number;	
	if(!objectp(me)) return;
	message_vision(HIG"�п��֡����ˡ��ж���ʧ�䡢���ġ�Թ�ޡ����Ρ��˷ܡ��ɾ͡����ꡭ��\n"NOR,me);
	message_vision(HIY"��������"+gGetRndColor()+"��������������������������������������������������������\\����/������ �� ������������\n"NOR,me);
	message_vision(HIY"��"HIW"ףʥ������"HIY"��"+gGetRndColor()+"�����������������ߡ������ߡ��������������ߣߡ����������� \\��/ ������/��\\�������ߣߡ�\n"NOR,me);
	message_vision(HIY"�򡡡�"HIW"������"HIY"��"+gGetRndColor()+"��������������������������\\ ��  ��������������������������\\/������ /�ߣ�\\������ ����\n"NOR,me);
	message_vision(HIY"��������"+gGetRndColor()+"���������ߣߡ������������� \\���ߡ��ߡ��ߣߡ�����������������������/������\\���ߣߡ���\n"NOR,me);
	message_vision(HIG"$N����ˡ�"HIW"һ����ǧ��ʵս���顢���ٵ�Ǳ�ܡ�ʮ�����������ʮ���������ʮ����Ʊ"HIG"���Ľ�����\n"NOR,me);
	me->add("combat_exp",15000);
	me->add("potential",200);
	me->add("max_neili",10);
	me->add("max_jingli",10);
	cash = new("/clone/money/thousand-cash");
	cash->set_amount(10);
	cash->move(me);
	log_file("quest/sdgift",sprintf("%s %s(%s)�ÿ�����ʥ���õ�������\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id"))));

	
	list = filter_array(children(USER_OB), (: userp($1) && environment($1) :));

	for(number=0;number<sizeof(list);number++)
	{
		if (list[number]->query_temp("havegong")<=5) continue;
		if (list[number]->query("id")==me->query("id")) continue;
		if (list[number]->query("family/family_name")!=me->query("family/family_name")) continue;
		message_vision(HIG"$N��Ϊ�������빰�����ˡ�"HIW"���ٵ�Ǳ�ܡ���������������������"HIG"���Ľ�����\n"NOR,list[number]);
		list[number]->add("potential",200);
		list[number]->add("max_neili",10);
		list[number]->add("max_jingli",10);
		//cash = new("/clone/money/thousand-cash");
		//cash->set_amount(5);
		//cash->move(list[number]);
		log_file("quest/sdgift",sprintf("%s %s(%s)�������빰��õ�������\n",
                  ctime(time())[4..19],me->name(1),capitalize(me->query("id"))));
		list[number]->delete_temp("havegong");	
	}
	destruct(this_object());	
}

string gGetRndColor()
{
	string* color = ({RED,GRN,YEL,BLU,MAG,CYN,HIR,HIG,HIY,HIB,HIM,HIC,HIW});
	return color[random(sizeof(color))];
}