// ʮ����������
// by emnil	2/15/2k

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

string setcolor();

void create()
{
	set_name(HIW"ʮ����������"NOR, ({ "shisan longxiang" ,"longxiang jiasha", "jiasha", "shisan jiasha" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("text" , "����һ�����ﴩ�����ģ���������Щ���ģ�������ͨ��ȴ�Ǵ����¿���ʼ���������������ġ�\n"
				+"��������Ϊ����ʱ�䱻�����������֣�����Ҳ�ƺ����˴��������Ĺ�Ч�����������ע������(longxiang)��\n"NOR);
		set("long",HIW+query("text") );

		set("material", "silk");
		set("unit", "��");
		set("unique", 1);
		set("value", 10000000);
		set("treasure", 1);
		set("wear_msg", HIW"ֻ��$N"HIW"˫��һ�������һ������͸����ɫ��ʵ����Ĵ��������ϡ�\n" NOR);
		set("armor_prop/armor", 80);

		set("owner","no owner");
		set("neili",0);
        }
        setup();
}

void init()
{
	add_action("do_longxiang","longxiang");
}

int do_longxiang(string arg)
{
	int cost;
	object me = this_player();

	if( query("neili") >= 13990 )
		return notify_fail("�������Ѿ�����������������Ҳ�޷�ע���ˣ�\n");

	if( me->query_skill("force") < 160 )
		return notify_fail("����ڹ��ȼ��������޷�ע��������\n");

	if( me->query_skill("longxiang-boruo",1)>100 && me->query_skill_mapped("force")=="longxiang-boruo" )
		cost = 1000;
	else
		cost = 1200;

	if( cost > me->query("neili") )
		return notify_fail("����������㣬�޷�ע���㹻��������\n");

	if( query("owner")!=me->query("id") && query("owner")!="no owner" ) {
		set("neili" , query("neili")/2);
		message_vision(MAG"$N"MAG"�������������������ԭ�е��������ͻ����Ȼ���ջ���ע����������������Ѿ���ʧ�˲��١�\n",me);
	}
	set("owner" , me->query("id"));

	add("neili" ,  1000);
	if (query("neili") > 13990) set("neili" , 13990);
	me->add("neili" , -cost);

	if( cost<=1000 )
		message_vision(MAG"$N"MAG"���Ϸ���һ��������������˫���鰴ʮ���������ģ�����������ע������֮�С�\n"NOR,me);
	else
		message_vision(HIC"$N"HIC"Ǳ���ڹ���Ŭ��������ע��ʮ���������ģ������Ȼ�ɹ�����Ϊ���������������໨�˵�������\n"NOR,me);
	
	setcolor();

	return 1;
}

mixed ob_hit()
{
	int times , qi , cost , charge = 16;
	object target;
	object me;
	int damage;
	string color;
	
	::ob_hit();
	if(query("neili")<= 0 || damage<250)
		return 0;

	if(query("owner") == me->query("id"))
		times = 10;
	else 
		times = 15;

	cost = (damage / 2)*charge/10*times/10;
	qi = damage/2;
	if( cost > query("neili") ) {
		qi = qi * query("neili") / cost ;
		cost = query("neili");
	}		
	add("neili" , -cost);

	if(wizardp(me) && me->query("env/test")) 
		tell_object(me,sprintf("qi:%d , neili:%d   ",qi,cost));

	color = setcolor();	
	if( times<=10 )
		message_vision(query("name")+color+"ͻȻ����ҫ�۵Ĺ�â���ֵ���$N"+color+"�Ĳ��ֹ��ƣ�\n"NOR,target);
	else
		message_vision(query("name")+color+"ͻȻ����ҫ�۵Ĺ�â���ֵ���$N"+color+
					"�Ĳ��ֹ��ƣ�����Ϊ�ڹ���ͻ���˷��˲��ٴ����������\n"NOR,target);

	return -qi;
}

string setcolor()
{
	int lvl;
	string color , s;

	if ( query("neili") != 0 )
		lvl = query("neili") / 1000;
	else
		lvl = 0;
	switch (lvl)  {
		case  0:
		case  1:
		case  2: color = HIW;break;
		case  3:
		case  4: color = HIC;break;
		case  5:
		case  6: color = CYN;break;
		case  7:
		case  8: color = HIB;break;
		case  9:
		case 10: color = BLU;break;
		case 11:
		case 12: color = HIM;break;
		case 13: color = MAG;break;
		default: color = HIW;
	}
	set("name" , color+"ʮ����������"NOR );
	
	if( lvl > 0 )
		s = color+"����֮���Ѿ�ע��"+CHINESE_D->chinese_number(lvl)+"��������\n"NOR;
	else
		s = "";
	set("long" , color+query("text")+s);

	return color;
}
