//flowray 2005.6.16
#include <ansi.h>


inherit SPEC;


void create()
{
	set_name (HIR"ԧ�����"NOR, ({ "jingpa"}));
	set("long",HIM" һ�����Ļ���Ľ��������������ֻ��ͷԧ��Ϸˮ���Ա����ż���С��:\n"HIW
   " �����Ż�
  ԧ��֯����˫��
  ����δ��ͷ�Ȱ�
  �̲�����
  �����
  ���ԡ���¡�\n\n"NOR
 "�������黹��"HIY"guihuan"NOR"����ʧ���ɡ�\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
        set("no_give",1);
        set("no_drop",1);	
        set("no_get",1);
	set("degree",1);
	set("flag","spec/jingpa");
	set("rest",10);
	set("desc","��ȡ����ʱ���Ĺ������ʱ�䡣(VIPר��)");
	set("credit",20);
	setup();
}

void init()
{
	add_action("do_back","guihuan");   
}

int do_back(string str)
{
	object my_object,me = this_player();
	int this_week = time()/86400/7;
	
	if (!me->is_vip())
		return notify_fail("ֻ�й����Ҳ���ʹ�ý�����\n");
		
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
	
	if (!str)
		return notify_fail("��Ҫ�Ѷ�����˭����\n");
    
	if (!(my_object = present(str, environment(me))))
		return notify_fail("��Ҫ�ҵ��˲������ȥ�����ҿ��ɡ�\n");
	
	if ( str != "ying gu")
		return notify_fail("����˺�����ʧ���ɣ�\n");
    
	if (!living(my_object))
		return notify_fail("Ŷ������Ȱ���Ū����˵��\n");
	
	if (me->query("ggs/left_time")>25200 || me->query("ggs/last_week")!=this_week)
		return notify_fail("�㿴�˿������ְ����Ż��˻��\n");
	
		
	me->add("ggs/left_time",10800);
	write("�������һ��"HIR"ԧ�����\n"NOR);
	write("������૵���������δ��ͷ�Ȱס���ͷ�Ȱס�������Ȼ������һ����Һ��ӵ��������ȻҪ���������Ĺ����������\n");
	write("���ø�������������ʱ���Ĺ������ʱ��\n");
	
	degree();
	
	return 1;
}	 